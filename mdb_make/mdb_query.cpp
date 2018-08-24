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
MdbServerLogic logic;

void* do_query(void*)
{
	logic.queryMDB(strInput, queryType);
}


//-------------------------------------------------------------------------------------
//  main Function
//-------------------------------------------------------------------------------------
int32 main(int argc, char** argv)
{

	extern char * optarg;
	int32  nOpt;

	while ((nOpt = getopt( argc, argv, "t:T:n:N:")) != EOF )
	{
		switch (nOpt)
		{
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

	logic.init();

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
		xc::Attach(logic.strVal.c_str());
	}
	catch (...)
	{
		LOG_ERROR(0, "xc attach fail!\n");
		return -1;
	}

	pthread_t ntid;
	pthread_create(&ntid, NULL, do_query, NULL);
	pthread_join(ntid, NULL);

	sal::Shutdown();

	return 1;
}

