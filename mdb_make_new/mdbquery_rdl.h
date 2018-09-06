// ********************************************************************
// This file is generated by rdl2cpp, DON'T EDIT IT!
// Generating date: 2018-07-03 13:13:37 +0800
// ********************************************************************

#ifndef __MDBQUERY_RDL_H__
#define __MDBQUERY_RDL_H__

#include "sal/sal.h"
#include "mdbquery_def_sdl_c.h"   // mdbquery_def.sdl


namespace mdbquery
{
    
    struct QuerymdbinfoTlsInner;
    
    
    struct MdbloginTlsInner;
    
    
    struct QueryratmdbinfoTlsInner;
    
    
    struct RatmdbloginTlsInner;
    
    struct TlsRequestResponseInner;

    struct TlsPerfStatInner;

// --------------------------------------------------------------------
// stateless APIs
// --------------------------------------------------------------------

// statefull APIs
// state_mgr: "CMdbQuery"
class CMdbQuery
{
public:
    CMdbQuery(sal::CTransaction* trans = 0);
    virtual ~CMdbQuery();

    static const sal::CUri kUri4Querymdbinfo;

     void Post4Querymdbinfo(
    	const MMdbQueryDef::SMdbQuery& cParamIn,
        MMdbQueryDef::SMdbQueryReturn& cParamOut,
    	SOBSession* pOBSession = NULL);
	
     void Asyn4Querymdbinfo(
    	const MMdbQueryDef::SMdbQuery& cParamIn,
        sal::CMessageSequence& cMsgSeq,
    	SOBSession* pOBSession = NULL);
	
     MMdbQueryDef::SMdbQueryReturn& Ret4Querymdbinfo(
    	const sal::CMessageSequence& cMsgSeq,
    	SOBSession* pOBSession = NULL);
	
    virtual int32 Map4Querymdbinfo(
    	const MMdbQueryDef::SMdbQuery& cParamIn,
        MMdbQueryDef::SMdbQueryList& lstParamIn,
        MRouteDef::SRouteInfoList& lstRouteInfo,
    	SOBSession* pOBSession = NULL);
	
    virtual int32 Reduce4Querymdbinfo(
    	const MMdbQueryDef::SMdbQuery& cParamIn,
        const MMdbQueryDef::SMdbQueryList& lstParamIn,
        const MRouteDef::SRouteInfoList& lstRouteInfo,
        const MSalExpDef::SPostExceptionList& lstPostException,
        const MMdbQueryDef::SMdbQueryReturnList& lstParamOut,
        MMdbQueryDef::SMdbQueryReturn& cParamOut,
    	SOBSession* pOBSession = NULL);
	
     void Request4Querymdbinfo(
    	const MMdbQueryDef::SMdbQueryList& lstParamIn,
        const MRouteDef::SRouteInfoList& lstRouteInfo,
        MSalExpDef::SPostExceptionList& lstPostException,
    	SOBSession* pOBSession = NULL);
	
     void Response4Querymdbinfo(
    	MMdbQueryDef::SMdbQueryReturnList& lstParamOut,
        const MRouteDef::SRouteInfoList& lstRouteInfo,
        MSalExpDef::SPostExceptionList& lstPostException,
    	SOBSession* pOBSession = NULL);
	
    static const sal::CUri kUri4Mdblogin;

     void Post4Mdblogin(
    	const MMdbQueryDef::SMdbSecLogin& cParamIn,
        MMdbQueryDef::SMdbSecLoginReturn& cParamOut,
    	SOBSession* pOBSession = NULL);
	
     void Asyn4Mdblogin(
    	const MMdbQueryDef::SMdbSecLogin& cParamIn,
        sal::CMessageSequence& cMsgSeq,
    	SOBSession* pOBSession = NULL);
	
     MMdbQueryDef::SMdbSecLoginReturn& Ret4Mdblogin(
    	const sal::CMessageSequence& cMsgSeq,
    	SOBSession* pOBSession = NULL);
	
    virtual int32 Map4Mdblogin(
    	const MMdbQueryDef::SMdbSecLogin& cParamIn,
        MMdbQueryDef::SMdbSecLoginList& lstParamIn,
        MRouteDef::SRouteInfoList& lstRouteInfo,
    	SOBSession* pOBSession = NULL);
	
    virtual int32 Reduce4Mdblogin(
    	const MMdbQueryDef::SMdbSecLogin& cParamIn,
        const MMdbQueryDef::SMdbSecLoginList& lstParamIn,
        const MRouteDef::SRouteInfoList& lstRouteInfo,
        const MSalExpDef::SPostExceptionList& lstPostException,
        const MMdbQueryDef::SMdbSecLoginReturnList& lstParamOut,
        MMdbQueryDef::SMdbSecLoginReturn& cParamOut,
    	SOBSession* pOBSession = NULL);
	
     void Request4Mdblogin(
    	const MMdbQueryDef::SMdbSecLoginList& lstParamIn,
        const MRouteDef::SRouteInfoList& lstRouteInfo,
        MSalExpDef::SPostExceptionList& lstPostException,
    	SOBSession* pOBSession = NULL);
	
     void Response4Mdblogin(
    	MMdbQueryDef::SMdbSecLoginReturnList& lstParamOut,
        const MRouteDef::SRouteInfoList& lstRouteInfo,
        MSalExpDef::SPostExceptionList& lstPostException,
    	SOBSession* pOBSession = NULL);
	
    static const sal::CUri kUri4Queryratmdbinfo;

     void Post4Queryratmdbinfo(
    	const MMdbQueryDef::SMdbQuery& cParamIn,
        MMdbQueryDef::SMdbQueryReturn& cParamOut,
    	SOBSession* pOBSession = NULL);
	
     void Asyn4Queryratmdbinfo(
    	const MMdbQueryDef::SMdbQuery& cParamIn,
        sal::CMessageSequence& cMsgSeq,
    	SOBSession* pOBSession = NULL);
	
     MMdbQueryDef::SMdbQueryReturn& Ret4Queryratmdbinfo(
    	const sal::CMessageSequence& cMsgSeq,
    	SOBSession* pOBSession = NULL);
	
    virtual int32 Map4Queryratmdbinfo(
    	const MMdbQueryDef::SMdbQuery& cParamIn,
        MMdbQueryDef::SMdbQueryList& lstParamIn,
        MRouteDef::SRouteInfoList& lstRouteInfo,
    	SOBSession* pOBSession = NULL);
	
    virtual int32 Reduce4Queryratmdbinfo(
    	const MMdbQueryDef::SMdbQuery& cParamIn,
        const MMdbQueryDef::SMdbQueryList& lstParamIn,
        const MRouteDef::SRouteInfoList& lstRouteInfo,
        const MSalExpDef::SPostExceptionList& lstPostException,
        const MMdbQueryDef::SMdbQueryReturnList& lstParamOut,
        MMdbQueryDef::SMdbQueryReturn& cParamOut,
    	SOBSession* pOBSession = NULL);
	
     void Request4Queryratmdbinfo(
    	const MMdbQueryDef::SMdbQueryList& lstParamIn,
        const MRouteDef::SRouteInfoList& lstRouteInfo,
        MSalExpDef::SPostExceptionList& lstPostException,
    	SOBSession* pOBSession = NULL);
	
     void Response4Queryratmdbinfo(
    	MMdbQueryDef::SMdbQueryReturnList& lstParamOut,
        const MRouteDef::SRouteInfoList& lstRouteInfo,
        MSalExpDef::SPostExceptionList& lstPostException,
    	SOBSession* pOBSession = NULL);
	
    static const sal::CUri kUri4Ratmdblogin;

     void Post4Ratmdblogin(
    	const MMdbQueryDef::SMdbSecLogin& cParamIn,
        MMdbQueryDef::SMdbSecLoginReturn& cParamOut,
    	SOBSession* pOBSession = NULL);
	
     void Asyn4Ratmdblogin(
    	const MMdbQueryDef::SMdbSecLogin& cParamIn,
        sal::CMessageSequence& cMsgSeq,
    	SOBSession* pOBSession = NULL);
	
     MMdbQueryDef::SMdbSecLoginReturn& Ret4Ratmdblogin(
    	const sal::CMessageSequence& cMsgSeq,
    	SOBSession* pOBSession = NULL);
	
    virtual int32 Map4Ratmdblogin(
    	const MMdbQueryDef::SMdbSecLogin& cParamIn,
        MMdbQueryDef::SMdbSecLoginList& lstParamIn,
        MRouteDef::SRouteInfoList& lstRouteInfo,
    	SOBSession* pOBSession = NULL);
	
    virtual int32 Reduce4Ratmdblogin(
    	const MMdbQueryDef::SMdbSecLogin& cParamIn,
        const MMdbQueryDef::SMdbSecLoginList& lstParamIn,
        const MRouteDef::SRouteInfoList& lstRouteInfo,
        const MSalExpDef::SPostExceptionList& lstPostException,
        const MMdbQueryDef::SMdbSecLoginReturnList& lstParamOut,
        MMdbQueryDef::SMdbSecLoginReturn& cParamOut,
    	SOBSession* pOBSession = NULL);
	
     void Request4Ratmdblogin(
    	const MMdbQueryDef::SMdbSecLoginList& lstParamIn,
        const MRouteDef::SRouteInfoList& lstRouteInfo,
        MSalExpDef::SPostExceptionList& lstPostException,
    	SOBSession* pOBSession = NULL);
	
     void Response4Ratmdblogin(
    	MMdbQueryDef::SMdbSecLoginReturnList& lstParamOut,
        const MRouteDef::SRouteInfoList& lstRouteInfo,
        MSalExpDef::SPostExceptionList& lstPostException,
    	SOBSession* pOBSession = NULL);
	

    void InitTls();
    
	void Commit()
	{
		if(m_pTrans) m_pTrans->Commit();
	}
		
	void Rollback()
	{
		if(m_pTrans) m_pTrans->Rollback();
	}

private:
    bool               m_bIsOwnTrans;
    sal::CTransaction* m_pTrans;

    CMdbQuery(const CMdbQuery& rhs) {}
    CMdbQuery& operator=(const CMdbQuery& rhs) { return *this; }
};

// ....................................................................

// --------------------------------------------------------------------
}; // namespace mdbquery

#endif
