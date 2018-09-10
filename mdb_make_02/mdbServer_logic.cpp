// ********************************************************************
// 
// Generating date: 2018-08-20
// ********************************************************************

#include "mdbServer_logic.h"

void* do_query(void *arg)
{
	MdbServerLogic* logic = (MdbServerLogic*) arg;
	logic->query.queryMDB(logic->queryNum, logic->queryFlag, logic->result_);
}

MdbServerLogic::MdbServerLogic(int queryFlag, aistring queryNum)
	: queryFlag(queryFlag), queryNum(queryNum)
{
    strXcKeyPath = "$HOME/ipc/";
	strConfigFile = "mdb_query.xml";
	strlogfile = "mdb_query.log";
}

MdbServerLogic::~MdbServerLogic()
{
}

int32 MdbServerLogic::init()
{
	aiconfig::AiConfig *pConfig = aiconfig::AiConfig::GetInstance();
	if (-1 == pConfig->InitConfigData(aiconfig::XML_FILE, strConfigFile.c_str()))
	{
		LOG_ERROR(0, "InitConfigData Error");
		return -1;
	}
	pConfig->ReadVal(pConfig->GetConfigContainer(), "/root/common_config/xc_key_path", strXcKeyPath);
	aistring strVal;
	if (-1 == cdk::strings::ConvertEnv(strXcKeyPath, strVal))
	{
		LOG_ERROR(0, "xc_key_path env error!\n");
	}
	pConfig->ReadVal(pConfig->GetConfigContainer(), "/root/mdb_query/user_name", query.strUserName);
	pConfig->ReadVal(pConfig->GetConfigContainer(), "/root/mdb_query/passwd", query.strPasswd);
	query.strRatUserName = query.strUserName;
	query.strRatPasswd = query.strPasswd;
	pConfig->ReadVal(pConfig->GetConfigContainer(), "/root/mdb_query/rat_user_name", query.strRatUserName);
	pConfig->ReadVal(pConfig->GetConfigContainer(), "/root/mdb_query/rat_passwd", query.strRatPasswd);
	cdk::log::SetFileLogger(strlogfile.c_str());

	try
	{
		sal::Startup();
	}
	catch (SAL_EXCEPTION & e)
	{
		LOG_ERROR(0, "sal startup fail!%s\n", e.get_message().c_str());
		return -1;
	}
	try
	{
		xc::Attach(strVal.c_str());
		LOG_ERROR(0, strVal.c_str());
	}
	catch (...)
	{
		LOG_ERROR(0, "xc attach fail!\n");
		return -1;
	}
	return 0;
}

void MdbServerLogic::start()
{
	init();

	switch (queryFlag)
	{
		case TOKEN_IMSI:
		case TOKEN_MSISDN:
		{
			pthread_t ntid;
			pthread_create(&ntid, NULL, do_query, (void*)this);
			pthread_join(ntid, NULL);
			printf(result_.c_str());
			break;
		}
		default:
			printf("QueryFlag error, required is 1 or 2, %d is provided.\n", queryFlag);
			break;
	}

	sal::Shutdown();
}
