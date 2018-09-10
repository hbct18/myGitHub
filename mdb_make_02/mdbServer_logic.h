// ********************************************************************
// 
// Generating date: 2018-08-20
// ********************************************************************

#ifndef __MDB_SERVER_LOGIC_H__
#define __MDB_SERVER_LOGIC_H__

#include "mdbServer_query.h"


class MdbServerLogic
{
public:
    MdbServerLogic(int queryFlag, aistring queryNum);
    ~MdbServerLogic();
	int32 init();
	void start();

public:
	int queryFlag;
	aistring queryNum;
    aistring strXcKeyPath;
	aistring strConfigFile;
	aistring strlogfile;
	aistring result_;
	MdbServerQuery query;


};

#endif // !__MDB_SERVER_LOGIC_H__