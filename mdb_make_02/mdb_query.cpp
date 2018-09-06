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
	logic->start();
}


//-------------------------------------------------------------------------------------
//  main Function
//-------------------------------------------------------------------------------------
int32 main(int argc, char** argv)
{

	extern char * optarg;
	extern int optind;

	int32  nOpt;

	while ((nOpt = getopt( argc, argv, "i:I:m:M:t:T:n:N:")) != EOF )
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

	MdbServerLogic *logic = new MdbServerLogic(queryType,strInput);

	pthread_t ntid;
	pthread_create(&ntid, NULL, do_query, (void*)logic);

	pthread_join(ntid, NULL);

	return 1;
}
