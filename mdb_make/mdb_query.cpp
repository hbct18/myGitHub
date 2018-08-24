/**************************************************************************************
*
* File Name:    mdb_query.cpp
* Company:      Asiainfo @ Hangzhou
* Date:         Created at 2004/02/27 by Xing Rui
* Desc:         This program is to query mdb data via IMSI or MSISDN
* 2018/5/11  hanmeng  refactored
**************************************************************************************/
#include <iostream>
#include "cdk/foundation/cdk_basedef.h"
#include "config/app_config.h"
#include "mdbin_pkg.h"
#include "mdbServer_logic.h"
#include "xc/xc.h"

int queryType = 0;
aistring strInput;

void* do_query(void *arg)
{
	MdbServerLogic* logic = (MdbServerLogic*) arg;
	int32 nQuit = 0;
		switch (queryType)
		{
		case TOKEN_IMSI:
			logic->queryMDB(strInput, TOKEN_IMSI);
			break;

		case TOKEN_MSISDN:
			logic->queryMDB(strInput, TOKEN_MSISDN);
			break;

		case TOKEN_QUIT:
			nQuit = 1;
			break;

		default:
			break;
		}
}


//-------------------------------------------------------------------------------------
//  main Function
//-------------------------------------------------------------------------------------
int32 main(int argc, char** argv)
{

	extern char * optarg;
	extern int optind;

	aistring strConfigFile = "mdb_query.xml";
	aistring strModuleName = "mdb_query";
	aistring strlogfile = "./mdb_query.log";
	int32  nOpt;

	static aistring strUserName, strPasswd, strRatUserName, strRatPasswd = "";
    static aistring strXcKeyPath = "";

	while ((nOpt = getopt( argc, argv, "i:I:m:M:t:T:n:N:")) != EOF )
	{
		switch (nOpt)
		{
		case	'i':
		case	'I':
		{
			strConfigFile = optarg;
			break;
		}
		case	'm':
		case	'M':
		{
			strModuleName = optarg;
			break;
		}
		case	't':
		case	'T':
		{
			queryType = atoi(optarg);
			break;
		}
		case	'n':
		case	'N':
		{
			strInput = optarg;
			break;
		}
		}
	}

	aiconfig::AiConfig *pConfig = aiconfig::AiConfig::GetInstance();
	if (-1 == pConfig->InitConfigData(aiconfig::XML_FILE, strConfigFile.c_str()))
	{
		printf("InitConfigData Error\n");
		return -1;
	}
	pConfig->ReadVal(pConfig->GetConfigContainer(), "/root/common_config/xc_key_path", strXcKeyPath);
	aistring strVal;
	if (-1 == cdk::strings::ConvertEnv(strXcKeyPath, strVal))
	{
		LOG_ERROR(0, "xc_key_path env error!\n");
	}
	//pConfig->ReadVal(pConfig->GetConfigContainer(), "/root/mdb_query/passwd", strPasswd);
	pConfig->ReadVal(pConfig->GetConfigContainer(), "/root/mdb_query/user_name", strUserName);
	pConfig->ReadVal(pConfig->GetConfigContainer(), "/root/mdb_query/passwd", strPasswd);
	strRatUserName = strUserName;
	strRatPasswd = strPasswd;
	pConfig->ReadVal(pConfig->GetConfigContainer(), "/root/mdb_query/rat_user_name", strRatUserName);
	pConfig->ReadVal(pConfig->GetConfigContainer(), "/root/mdb_query/rat_passwd", strRatPasswd);
	//pConfig->ReadVal(pConfig->GetConfigContainer(), "/root/mdb_query/log_file", strlogfile);
	cdk::log::SetFileLogger(strlogfile.c_str());

	MdbServerLogic logic;
	logic.strUserName = strUserName;
    logic.strPasswd = strPasswd;
    logic.strRatUserName = strRatUserName;
    logic.strRatPasswd = strRatPasswd;
    logic.strXcKeyPath = strXcKeyPath;

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
	}
	catch (...)
	{
		LOG_ERROR(0, "xc attach fail!\n");
		return -1;
	}

	LOG_INFO("Procedure %s begins ", strModuleName.c_str());

	pthread_t ntid;
	pthread_create(&ntid, NULL, do_query, (void*)&logic);

	pthread_join(ntid, NULL);
	sal::Shutdown();

	LOG_INFO("Procedure %s end ", strModuleName.c_str());

	return 1;
}

