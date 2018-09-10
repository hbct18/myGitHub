// ********************************************************************
// 
// Generating date: 2018-08-20
// ********************************************************************

#include "mdbServer_query.h"


MdbServerQuery::MdbServerQuery()
{
}

MdbServerQuery::~MdbServerQuery()
{
}

int32 MdbServerQuery::getUserInfoListFromBuf(const char * strBuf, 
    int32 nLen, AISTD set<int64_t> & setID, const int32& idType)
{
    char szID[128];
	int32 nNextPos = 0;
	int32 nLastPos = 0;
	char szTemp[8192];

	while (1)
	{
		memset(szID, 0, sizeof(szID));

		while (nNextPos < nLen && strBuf[nNextPos] != '\n')
		{
			++ nNextPos;
		}

		if (nNextPos >= nLen)
		{
			return 1;
		}

		strncpy(szTemp, strBuf + nLastPos, nNextPos - nLastPos + 1);
		szTemp[nNextPos - nLastPos + 1] = '\0';
		int32 nPosInTemp        = 0;
		int32 nPosFirstComma    = 0;
		int32 nPosSecondComma   = 0;
		int32 nPosThirdComma    = 0;
		int32 nPosFourthComma   = 0;
		int32 nCommaCount       = 0;
		//parsa szTemp
		while (nCommaCount != 4 && nPosInTemp < nNextPos - nLastPos + 1)
		{
			if (szTemp[nPosInTemp] == ',')
			{
				++ nCommaCount;
				if (nCommaCount == 1)
				{
					nPosFirstComma = nPosInTemp;
				}

				if (nCommaCount == 2)
				{
					nPosSecondComma = nPosInTemp;
				}

				if (nCommaCount == 3)
				{
					nPosThirdComma = nPosInTemp;
				}

				if (nCommaCount == 4)
				{
					nPosFourthComma = nPosInTemp;
				}
			}

			++ nPosInTemp;
		}

		if (nPosInTemp >= nNextPos - nLastPos + 1)
		{
			++ nNextPos;
			nLastPos = nNextPos;//for next record ,lqx

			continue;
		}
		if ( (idType == E_SERV_TYPR) || (idType == E_ACCT_TYPE) || idType == E_GROUP_TYPE )
		{
			snprintf(szID, nPosSecondComma - nPosFirstComma, "%s", szTemp + nPosFirstComma + 1);
		}
		else if (idType == E_CUST_TYPE)
		{
			snprintf(szID, nPosThirdComma - nPosSecondComma, "%s", szTemp + nPosSecondComma + 1);
		}
		setID.insert(cdk::strings::Atol64(szID));

		++ nNextPos;
		nLastPos = nNextPos;//for next record

	}
	return 0;
}

int32 MdbServerQuery::queryMDB(aistring & strInput, int32 nType, aistring & strOutput)
{
    AISTD set<int64_t> lstUserID;
	AISTD set<int64_t> lstAcctID;
	AISTD set<int64_t> lstCustID;
	AISTD set<int64_t> lstGroupId;
	AISTD set<int64_t> lstBillId;

	AISTD vector<AISTD set<int64_t>> vctBillIdList = {lstUserID, lstAcctID, lstGroupId, lstCustID};

	int32 nUserListNum;
	int32 nAcctNum;
	int32 nCustNum;

	loginmdb();
	
	int32 iCount = 0;
	int32 iIndexType = 1;
	for (auto tb : TableIndex)
	{
		g_cReturnMDB.Clear();
		iIndexType = tb.iIndexType;
		if (iIndexType <= 0)
		{
			iIndexType = 1;
		}
		lstBillId = vctBillIdList[iIndexType - 1];
		iCount++;

		result_ += cdk::strings::Itoa(iCount);
		result_ += " [{table_name:";
		result_ += tb.strTableName;
		result_ += " table_records:";

		if (tb.strTableName == "CUser" || tb.strTableName == "CUserMap")
		{
			queryUser(tb.strTableName.c_str(), nType, strInput.c_str());
		}
		else
		{
			queryTable(tb.strTableName.c_str(), tb.strIndexField.c_str(), lstBillId);
		}

		for (int32 pos = 0; pos < vctRelTable.size(); pos++)
		{
			if (tb.strTableName == vctRelTable[pos])
			{
				getUserInfoListFromBuf(g_cReturnMDB.get_result().c_str(), strlen(g_cReturnMDB.get_result().c_str()), vctBillIdList[pos], pos + 1);
			}
		}
		result_ += "\n";
	}
	strOutput = result_;
	return 0;
}

int32 MdbServerQuery::loginmdb()
{
    mdbquery::CMdbQuery g_cMdbQuery;
	MMdbQueryDef::SMdbSecLogin cMdbSecLogin;
	MMdbQueryDef::SMdbSecLoginReturn cMdbSecLoginReturn;
	cMdbSecLogin.Clear();
	cMdbSecLoginReturn.Clear();
	cMdbSecLogin.set_userName(strUserName);
	cMdbSecLogin.set_passwd(strPasswd);

	try
	{
		g_cMdbQuery.Post4Mdblogin(cMdbSecLogin, cMdbSecLoginReturn);
		cMdbSecLogin.Clear();
		cMdbSecLoginReturn.Clear();
		cMdbSecLogin.set_userName(strRatUserName);
		cMdbSecLogin.set_passwd(strRatPasswd);
		g_cMdbQuery.Post4Ratmdblogin(cMdbSecLogin, cMdbSecLoginReturn);
	}
	catch (err_info_service::CAIException& err)
	{
		LOG_ERROR(0, "err %s", err.get_message().c_str());
		return -1;
	}
	catch (...)
	{
		LOG_ERROR(0, "sys errno:%d, sys errmsg:%s !", errno, strerror(errno));
		return -1;
	}
	return 0;
}

int32 MdbServerQuery::postMdb(const char* strTableName, const char* szQuerySql)
{
    mdbquery::CMdbQuery g_cMdbQuery;
	g_cQueryMDB.Clear();
	g_cQueryMDB.set_tableName(strTableName);
	g_cQueryMDB.set_query(szQuerySql);
	g_cQueryMDB.set_flag(1);
	LOG_TRACE("g_cQueryMDB=%s", g_cQueryMDB.to_string().c_str());
	try
	{
		if (0 != strncmp(strTableName, "CAM", 3))
		{
			g_cMdbQuery.Post4Querymdbinfo(g_cQueryMDB, g_cReturnMDB);
		}
		else
		{
			g_cMdbQuery.Post4Queryratmdbinfo(g_cQueryMDB, g_cReturnMDB);
		}
	}
	catch (err_info_service::CAIException& err)
	{
		LOG_ERROR(0, "err %s", err.get_message().c_str());
		return -1;
	}
	catch (...)
	{
		LOG_ERROR(0, "sys errno:%d, sys errmsg:%s !", errno, strerror(errno));
		return -1;
	}
	aistring str = g_cReturnMDB.get_result();
	if (str.length() > 0)
		str.pop_back();

	result_ += str;
	result_ += "}]\n";

	return 0;
}

int32 MdbServerQuery::queryUser(const char* strTableName, int32 nType, const char* strBillId)
{
    char szQuerySql[512] = {0};
	if (nType == TOKEN_IMSI)
	{
		snprintf(szQuerySql, sizeof(szQuerySql) - 1, "select * from %s where m_szImsi = '%s';", strTableName, strBillId);
	}
	else if (nType == TOKEN_MSISDN)
	{
		if (0 == strcmp(strTableName, "CUserMap"))
		{
			snprintf(szQuerySql, sizeof(szQuerySql) - 1, "select * from %s where m_llMsisdn = %lld;", strTableName, cdk::strings::Atol64(strBillId));
		}
		else
		{
			snprintf(szQuerySql, sizeof(szQuerySql) - 1, "select * from %s where m_szMsisdn = '%s';", strTableName, strBillId);
		}
	}
	return postMdb(strTableName, szQuerySql);
}

int32 MdbServerQuery::queryTable(const char* strTableName, const char* strIdxField,
	AISTD set<int64_t>& lstBillId)
{
    for (SET_ITER itr = lstBillId.begin(); itr != lstBillId.end(); ++itr)
	{
		char szQuerySql[512] = {0};
		snprintf(szQuerySql, sizeof(szQuerySql) - 1, "select * from %s where %s = %lld;", strTableName, strIdxField, *itr);

		postMdb(strTableName, szQuerySql);
	}
	return 0;
}