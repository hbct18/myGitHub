/**************************************************************************************
*
* File Name:    mdb_query.cpp
* Company:      Asiainfo @ Hangzhou
* Date:         Created at 2004/02/27 by Xing Rui
**************************************************************************************/

#ifndef __MDB_SERVER_LOGIC_H__
#define __MDB_SERVER_LOGIC_H__

#include <iostream>
#include "cdk/foundation/cdk_basedef.h"
#include "config/app_config.h"
#include "mdbin_pkg.h"
#include "mdbServer_query.h"
#include "xc/xc.h"


typedef AISTD set<int64_t>::iterator SET_ITER ;
enum
{
	SIZE_OF_IMSI   = 15,
	SIZE_OF_MSISDN = 11
};

enum
{
	TOKEN_IMSI   = 1,
	TOKEN_MSISDN = 2,
	TOKEN_QUIT   = 3
};
enum
{
	E_SERV_TYPR   = 1,
	E_ACCT_TYPE = 2,
	E_GROUP_TYPE = 3,
	E_CUST_TYPE = 4
};

static AISTD vector<AISTD string> vctRelTable = {
	"CUser",
	"CUserAcctRel",
	"CUserGroup",
	"CUserCustRel"
};

struct Stable
{
	aistring strTableName;
	aistring strIndexField;
	int32 iIndexType;
};

//{"TableName","Index,IndexType"}
static AISTD vector<Stable> TableIndex = {
	{"CUser", "", 0},
	{"CUserAcctRel", "m_llServId", 1},
	{"CUserCustRel", "m_llServId", 1},
	{"CUserPlan", "m_llServId", 1},
	{"CUserCycle", "m_llServId", 1},
	{"CUserBillCycle", "m_llServId", 1},
	{"CUserProm", "m_llServId", 1},
	{"CUserGroup", "m_llServId", 1},
	{"CGroupProm", "m_llGroupId", 3},
	{"CGroupRela", "m_llGroupId", 3},
	{"CUserCell", "m_llServId", 1},
	{"CUserRela", "m_llServId", 1},
	{"CSpecProm", "m_llServId", 1},
	{"CPromPara", "m_llServId", 1},
	{"CUserSwitch", "m_llServId", 1},
	{"CUserMonitor", "m_llServId", 1},
	{"CAccProm", "m_llAcctId", 2},
	{"CUserPay", "m_llServId", 1},
	{"CCustomer", "m_llCustId", 4},
	{"CUserMsc", "m_llServId", 1},
	{"CUserMap", "", 0},
	{"CUserRedo", "m_llServId", 1},
	{"CUserPort", "m_llServId", 1},
	{"CAMTFreeResource", "m_llServID", 1},
	{"CAMTFreeResource", "m_llServID", 3},
	{"CAMTRatingAddedUp", "m_llServID", 1},
	{"CAMTRatingAddedUp", "m_llServID", 3},
	{"CAMTShareFreeResLog", "m_llServID", 1},
	{"CAMTItemAccumulate", "m_llServID", 1}
};

class MdbServerLogic
{
public:
    MdbServerLogic();
    ~MdbServerLogic();
	int32 init();
    int32 getUserInfoListFromBuf(const char * strBuf, int32 nLen, AISTD set<int64_t> & setID, const int32& idType);
    int32 queryMDB( aistring & strInput, int32 nType);
    int32 loginmdb();
    int32 postMdb(const char* strTableName, const char* szQuerySql);
    int32 queryUser(const char* strTableName, int32 nType, const char* strBillId);
    int32 queryTable(const char* strTableName, const char* strIdxField, int32 iIndexType, AISTD set<int64_t>& lstBillId);

public:
    aistring strTempBak;
    aistring strUserName;
    aistring strPasswd;
    aistring strRatUserName;
    aistring strRatPasswd;
    aistring strXcKeyPath;
	aistring strConfigFile;
	aistring strVal;
	aistring strlogfile;
    MMdbQueryDef::SMdbQueryReturn g_cReturnMDB;
    MMdbQueryDef::SMdbQuery g_cQueryMDB;

};

#endif // !__MDB_SERVER_LOGIC_H__