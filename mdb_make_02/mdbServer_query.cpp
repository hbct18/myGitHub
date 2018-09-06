// ********************************************************************
// 
// Generating date: 2018-08-20
// ********************************************************************


#include <string.h>
#include <iterator>
#include <public/sdl/sdl_session.h>
#include <public/sdl/sdl_basic.h>
#include <public/sdl/sdl_stream.h>
#include <cdk/foundation/cdk_threadlocal.h>
#include <cdk/foundation/cdk_log.h>
#include <cdk/foundation/cdk_aitime.h>

#include "mdbServer_query.h"

using namespace sdl;

static const char* __SZ_FILE_VERSION = "0.10";

namespace mdbquery
{

    struct TlsPerfStatInner
    {   
        int64 m_lStreamInUsec;	
        int64 m_lStreamOutUsec;
    };
    thread_local TlsPerfStatInner m_PerfStatTlsInner;

    struct TlsRequestResponseInner
    {
        sal::CRequest m_request;
        sal::CResponse m_response;
    };
    thread_local TlsRequestResponseInner m_RequestResponseTlsInner;

    /*Querymdbinfo TLS VAR declaration*/
    struct QuerymdbinfoTlsInner
    {
    //out_param
        MMdbQueryDef::SMdbQueryReturn m_MMdbQueryDefSMdbQueryReturnOut;
    //In_param
        MMdbQueryDef::SMdbQuery m_MMdbQueryDefSMdbQueryIn;
    //Splitted In_param list
        MMdbQueryDef::SMdbQueryList m_MMdbQueryDefSMdbQueryInLst;
    //routeInfo list for splitted In_param list
        MRouteDef::SRouteInfoList m_RouteInfoLst;
    //postexception list for results of request or reponse
        MSalExpDef::SPostExceptionList m_PostExceptionLst;
    //out_param list : output of splitted In_param list 
        MMdbQueryDef::SMdbQueryReturnList  m_MMdbQueryDefSMdbQueryReturnOutLst;
    };
    thread_local QuerymdbinfoTlsInner m_QuerymdbinfoTlsInner;
    /*Mdblogin TLS VAR declaration*/
    struct MdbloginTlsInner
    {
    //out_param
        MMdbQueryDef::SMdbSecLoginReturn m_MMdbQueryDefSMdbSecLoginReturnOut;
    //In_param
        MMdbQueryDef::SMdbSecLogin m_MMdbQueryDefSMdbSecLoginIn;
    //Splitted In_param list
        MMdbQueryDef::SMdbSecLoginList m_MMdbQueryDefSMdbSecLoginInLst;
    //routeInfo list for splitted In_param list
        MRouteDef::SRouteInfoList m_RouteInfoLst;
    //postexception list for results of request or reponse
        MSalExpDef::SPostExceptionList m_PostExceptionLst;
    //out_param list : output of splitted In_param list 
        MMdbQueryDef::SMdbSecLoginReturnList  m_MMdbQueryDefSMdbSecLoginReturnOutLst;
    };
    thread_local MdbloginTlsInner m_MdbloginTlsInner;
    /*Queryratmdbinfo TLS VAR declaration*/
    struct QueryratmdbinfoTlsInner
    {
    //out_param
        MMdbQueryDef::SMdbQueryReturn m_MMdbQueryDefSMdbQueryReturnOut;
    //In_param
        MMdbQueryDef::SMdbQuery m_MMdbQueryDefSMdbQueryIn;
    //Splitted In_param list
        MMdbQueryDef::SMdbQueryList m_MMdbQueryDefSMdbQueryInLst;
    //routeInfo list for splitted In_param list
        MRouteDef::SRouteInfoList m_RouteInfoLst;
    //postexception list for results of request or reponse
        MSalExpDef::SPostExceptionList m_PostExceptionLst;
    //out_param list : output of splitted In_param list 
        MMdbQueryDef::SMdbQueryReturnList  m_MMdbQueryDefSMdbQueryReturnOutLst;
    };
    thread_local QueryratmdbinfoTlsInner m_QueryratmdbinfoTlsInner;
    /*Ratmdblogin TLS VAR declaration*/
    struct RatmdbloginTlsInner
    {
    //out_param
        MMdbQueryDef::SMdbSecLoginReturn m_MMdbQueryDefSMdbSecLoginReturnOut;
    //In_param
        MMdbQueryDef::SMdbSecLogin m_MMdbQueryDefSMdbSecLoginIn;
    //Splitted In_param list
        MMdbQueryDef::SMdbSecLoginList m_MMdbQueryDefSMdbSecLoginInLst;
    //routeInfo list for splitted In_param list
        MRouteDef::SRouteInfoList m_RouteInfoLst;
    //postexception list for results of request or reponse
        MSalExpDef::SPostExceptionList m_PostExceptionLst;
    //out_param list : output of splitted In_param list 
        MMdbQueryDef::SMdbSecLoginReturnList  m_MMdbQueryDefSMdbSecLoginReturnOutLst;
    };
    thread_local RatmdbloginTlsInner m_RatmdbloginTlsInner;

    // state_mgr: "CMdbQuery"
    CMdbQuery::CMdbQuery(sal::CTransaction* trans)
        : m_bIsOwnTrans(trans == 0), m_pTrans(trans)
    {
        if ( m_bIsOwnTrans )
            m_pTrans = new sal::CTransaction("kv");
    }


    CMdbQuery::~CMdbQuery()
    {
        if ( m_bIsOwnTrans )
        {
            delete m_pTrans;
            m_pTrans = 0;
        }
    }

    const sal::CUri CMdbQuery::kUri4Querymdbinfo = "kv:/user_info/services/QueryMdbInfo?200";

    void CMdbQuery::Post4Querymdbinfo(
    const MMdbQueryDef::SMdbQuery& cParamIn,
    MMdbQueryDef::SMdbQueryReturn& cParamOut,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Querymdbinfo;

        int64 llSalOpStartUsec = cdk::time::GetCurrentUs();

        //ref map_reduce related TLS list var
        MMdbQueryDef::SMdbQueryList& lstParamIn = m_QuerymdbinfoTlsInner.m_MMdbQueryDefSMdbQueryInLst;
        MRouteDef::SRouteInfoList& lstRouteInfo = m_QuerymdbinfoTlsInner.m_RouteInfoLst;
        MSalExpDef::SPostExceptionList& lstPostException = m_QuerymdbinfoTlsInner.m_PostExceptionLst;
        MMdbQueryDef::SMdbQueryReturnList& lstParamOut = m_QuerymdbinfoTlsInner.m_MMdbQueryDefSMdbQueryReturnOutLst;	

        //clear map_reduce related TLS list var
        lstParamIn.clear();
        lstParamOut.clear();
        lstRouteInfo.clear();
        lstPostException.clear();

        //reset performance stat tls var
        m_PerfStatTlsInner.m_lStreamInUsec = 0;    
        m_PerfStatTlsInner.m_lStreamOutUsec = 0;

        //Test if this mdb domain support cloud
        if(sal::IsDomainSupportCloud(__uri)) {
            //If have implemented map_reduce method, then map In_param to splitted In_param list and corresponding routeInfo list
            if(Map4Querymdbinfo(cParamIn,lstParamIn,lstRouteInfo,pOBSession) != sal::ESAL_MAPREDUCE_UNIMPLEMENT){

                Request4Querymdbinfo(lstParamIn, lstRouteInfo, lstPostException, pOBSession);	
                    
                Response4Querymdbinfo(lstParamOut, lstRouteInfo, lstPostException, pOBSession);
                
                //reduce all out_params from  every splitted In_param upto origianl cParamOut
                Reduce4Querymdbinfo(cParamIn,lstParamIn,lstRouteInfo,lstPostException,lstParamOut,cParamOut,pOBSession);
            }
            else
            {
                THROW_SAL(sal::ENotImpMapReduce, "uri '?' support cloud but not implement mapreduce method")
                                << __uri.ToString().CStr();
            }
        }
        else{ 
            sal::CRequest& __request = m_RequestResponseTlsInner.m_request;
            sal::CResponse& __response = m_RequestResponseTlsInner.m_response;

            int64 llStreamInStartUsec = cdk::time::GetCurrentUs();
            sal::stream_in(cParamIn,__request,false,m_pTrans);
            m_PerfStatTlsInner.m_lStreamInUsec += cdk::time::GetCurrentUs() - llStreamInStartUsec;

            m_pTrans->Post(__uri, __request, __response,pOBSession);

            int64 llStreamOutStartUsec = cdk::time::GetCurrentUs();
            sal::stream_out(cParamOut,__response);
            m_PerfStatTlsInner.m_lStreamOutUsec += cdk::time::GetCurrentUs() - llStreamOutStartUsec;
        }

        int64 llPostCostUsec = cdk::time::GetCurrentUs() - llSalOpStartUsec;    
        if(llPostCostUsec >= sal::g_SalOpTimeout)    
        {    	   
            LOG_FATAL(0, "Sal::Post(): timeout occured, uri = %s, total cost %lld usec, "
                        "stream_in cost %lld usec, stream_out cost %lld usec.",
                        __uri.ToString().CStr(), llPostCostUsec, m_PerfStatTlsInner.m_lStreamInUsec,     
                        m_PerfStatTlsInner.m_lStreamOutUsec);    
        }
    }

    void CMdbQuery::Asyn4Querymdbinfo(
    const MMdbQueryDef::SMdbQuery& cParamIn,
    sal::CMessageSequence& cMsgSeq,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Querymdbinfo;

        int64 llSalOpStartUsec = cdk::time::GetCurrentUs();

        //ref map_reduce related TLS list var
        MMdbQueryDef::SMdbQueryList& lstParamIn = m_QuerymdbinfoTlsInner.m_MMdbQueryDefSMdbQueryInLst;
        MRouteDef::SRouteInfoList& lstRouteInfo = m_QuerymdbinfoTlsInner.m_RouteInfoLst;
        MSalExpDef::SPostExceptionList& lstPostException = m_QuerymdbinfoTlsInner.m_PostExceptionLst;

        //clear map_reduce related TLS list var
        lstParamIn.clear();
        lstRouteInfo.clear();
        lstPostException.clear();

        //reset performance stat tls var
        m_PerfStatTlsInner.m_lStreamInUsec = 0;    
        m_PerfStatTlsInner.m_lStreamOutUsec = 0;

        m_QuerymdbinfoTlsInner.m_MMdbQueryDefSMdbQueryIn = cParamIn;
        //Test if the mdb domain support cloud
        if(sal::IsDomainSupportCloud(__uri)) {
            //If have implemented map_reduce method, then map In_param to splitted In_param list and corresponding routeInfo list
            if(Map4Querymdbinfo(cParamIn,lstParamIn,lstRouteInfo,pOBSession) != sal::ESAL_MAPREDUCE_UNIMPLEMENT){
                Request4Querymdbinfo(lstParamIn, lstRouteInfo, lstPostException, pOBSession);	
            }
            else
            {
                THROW_SAL(sal::ENotImpMapReduce, "uri '?' support cloud but not implement mapreduce method")
                                << __uri.ToString().CStr();
            }
        }
        else{
            sal::CRequest& __request = m_RequestResponseTlsInner.m_request;

            int64 llStreamInStartUsec = cdk::time::GetCurrentUs();
            sal::stream_in(cParamIn,__request,false,m_pTrans);
            m_PerfStatTlsInner.m_lStreamInUsec += cdk::time::GetCurrentUs() - llStreamInStartUsec;
            
            m_pTrans->Request(__uri, __request,pOBSession);
        }

        int64 llAsynCostUsec = cdk::time::GetCurrentUs() - llSalOpStartUsec;    
        if(llAsynCostUsec >= sal::g_SalOpTimeout)    
        {    	   
            LOG_FATAL(0, "Sal::Asyn(): timeout occured, uri = %s, total cost %lld usec, " 
                        "stream_in cost %lld usec, stream_out cost %lld usec.",
                        __uri.ToString().CStr(), llAsynCostUsec, m_PerfStatTlsInner.m_lStreamInUsec,                
                        m_PerfStatTlsInner.m_lStreamOutUsec);    
        }
    }

    MMdbQueryDef::SMdbQueryReturn& CMdbQuery::Ret4Querymdbinfo(
    const sal::CMessageSequence& cMsgSeq,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Querymdbinfo;

        int64 llSalOpStartUsec = cdk::time::GetCurrentUs();

        //ref map_reduce related TLS list var
        MMdbQueryDef::SMdbQuery& cParamIn = m_QuerymdbinfoTlsInner.m_MMdbQueryDefSMdbQueryIn;
        MMdbQueryDef::SMdbQueryReturn& cParamOut = m_QuerymdbinfoTlsInner.m_MMdbQueryDefSMdbQueryReturnOut;
        MMdbQueryDef::SMdbQueryList& lstParamIn = m_QuerymdbinfoTlsInner.m_MMdbQueryDefSMdbQueryInLst;
        MRouteDef::SRouteInfoList& lstRouteInfo = m_QuerymdbinfoTlsInner.m_RouteInfoLst;
        MSalExpDef::SPostExceptionList& lstPostException = m_QuerymdbinfoTlsInner.m_PostExceptionLst;
        MMdbQueryDef::SMdbQueryReturnList& lstParamOut = m_QuerymdbinfoTlsInner.m_MMdbQueryDefSMdbQueryReturnOutLst;	

        //clear map_reduce related TLS list var
        lstParamOut.clear();
        cParamOut.Clear();

        //reset performance stat tls var
        m_PerfStatTlsInner.m_lStreamInUsec = 0;    
        m_PerfStatTlsInner.m_lStreamOutUsec = 0;

        //if mapped routeInfo list not empty, then need to reduce all splitted requests
        if(lstRouteInfo.size() > 0){
            //wait response of every single splitted In_param request
            Response4Querymdbinfo(lstParamOut, lstRouteInfo,lstPostException, pOBSession);
                    
            //reduce all out_params from  every splitted In_param upto origianl cParamOut
            Reduce4Querymdbinfo(cParamIn,lstParamIn,lstRouteInfo,lstPostException,lstParamOut,cParamOut,pOBSession);
        }
        //if mapped routeInfo list empty, then no mdb cloud support, Response directly
        else{
            sal::CResponse& __response = m_RequestResponseTlsInner.m_response;
            m_pTrans->Response(__uri,__response,pOBSession);

            int64 llStreamOutStartUsec = cdk::time::GetCurrentUs();
            sal::stream_out(cParamOut,__response);
            m_PerfStatTlsInner.m_lStreamOutUsec += cdk::time::GetCurrentUs() - llStreamOutStartUsec; 
        }

        int64  llRetCostUsec = cdk::time::GetCurrentUs() - llSalOpStartUsec;    
        if(llRetCostUsec >= sal::g_SalOpTimeout)    
        {    	   
            LOG_FATAL(0, "Sal::Ret(): timeout occured, uri = %s, total cost %lld usec, "
                        "stream_in cost %lld usec, stream_out cost %lld usec.",
                        __uri.ToString().CStr(), llRetCostUsec, m_PerfStatTlsInner.m_lStreamInUsec,           
                        m_PerfStatTlsInner.m_lStreamOutUsec);    
        }
        return cParamOut;
    }



    void CMdbQuery::Request4Querymdbinfo(
    const MMdbQueryDef::SMdbQueryList& lstParamIn,
    const MRouteDef::SRouteInfoList& lstRouteInfo,
    MSalExpDef::SPostExceptionList& lstPostException,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Querymdbinfo;

        sal::CRequest& __request = m_RequestResponseTlsInner.m_request;

        MMdbQueryDef::SMdbQueryList::const_iterator itParam = lstParamIn.begin();
        MRouteDef::SRouteInfoList::const_iterator it = lstRouteInfo.begin();
        MSalExpDef::SPostException sPostException;
        int64 llTmpStartUsec;
        //request with every single splited In_param and its routeInfo
        for(; it != lstRouteInfo.end(); ++it,++itParam){
            __request.clear();
            sPostException.Clear();
            
            llTmpStartUsec = cdk::time::GetCurrentUs();
            sal::stream_in(*itParam,__request,false,m_pTrans);
            m_PerfStatTlsInner.m_lStreamInUsec += cdk::time::GetCurrentUs() - llTmpStartUsec;
            
            m_pTrans->Request(__uri,*it, __request, sPostException, pOBSession);
            lstPostException.push_back(sPostException);
        }
    }

    void CMdbQuery::Response4Querymdbinfo(
    MMdbQueryDef::SMdbQueryReturnList& lstParamOut,
    const MRouteDef::SRouteInfoList& lstRouteInfo,
    MSalExpDef::SPostExceptionList& lstPostException,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Querymdbinfo;

        sal::CResponse& __response = m_RequestResponseTlsInner.m_response;

        MRouteDef::SRouteInfoList::const_iterator it = lstRouteInfo.begin();
        MSalExpDef::SPostExceptionList::iterator postExpIt = lstPostException.begin();
        int64 llTmpStartUsec;
        //wait response of every single splitted In_param request
        for(; it != lstRouteInfo.end(); ++it, ++postExpIt){
            __response.clear();
            m_pTrans->Response(__uri,*it,__response, *postExpIt, pOBSession);
            lstParamOut.push_back(MMdbQueryDef::SMdbQueryReturn());
            if(0 == postExpIt->get_errorCode())
            {//unmarshalling response from MDB server to paramout if no error occured
                llTmpStartUsec = cdk::time::GetCurrentUs();
                sal::stream_out(lstParamOut.back(),__response);
                m_PerfStatTlsInner.m_lStreamOutUsec += cdk::time::GetCurrentUs() - llTmpStartUsec;
            }
        }
    }

    const sal::CUri CMdbQuery::kUri4Mdblogin = "kv:/user_info/services/mdblogin?403";

    void CMdbQuery::Post4Mdblogin(
    const MMdbQueryDef::SMdbSecLogin& cParamIn,
    MMdbQueryDef::SMdbSecLoginReturn& cParamOut,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Mdblogin;

        int64 llSalOpStartUsec = cdk::time::GetCurrentUs();

        //ref map_reduce related TLS list var
        MMdbQueryDef::SMdbSecLoginList& lstParamIn = m_MdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginInLst;
        MRouteDef::SRouteInfoList& lstRouteInfo = m_MdbloginTlsInner.m_RouteInfoLst;
        MSalExpDef::SPostExceptionList& lstPostException = m_MdbloginTlsInner.m_PostExceptionLst;
        MMdbQueryDef::SMdbSecLoginReturnList& lstParamOut = m_MdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginReturnOutLst;	

        //clear map_reduce related TLS list var
        lstParamIn.clear();
        lstParamOut.clear();
        lstRouteInfo.clear();
        lstPostException.clear();

        //reset performance stat tls var
        m_PerfStatTlsInner.m_lStreamInUsec = 0;    
        m_PerfStatTlsInner.m_lStreamOutUsec = 0;

        //Test if this mdb domain support cloud
        if(sal::IsDomainSupportCloud(__uri)) {
            //If have implemented map_reduce method, then map In_param to splitted In_param list and corresponding routeInfo list
            if(Map4Mdblogin(cParamIn,lstParamIn,lstRouteInfo,pOBSession) != sal::ESAL_MAPREDUCE_UNIMPLEMENT){

                Request4Mdblogin(lstParamIn, lstRouteInfo, lstPostException, pOBSession);	
                    
                Response4Mdblogin(lstParamOut, lstRouteInfo, lstPostException, pOBSession);
                
                //reduce all out_params from  every splitted In_param upto origianl cParamOut
                Reduce4Mdblogin(cParamIn,lstParamIn,lstRouteInfo,lstPostException,lstParamOut,cParamOut,pOBSession);
            }
            else
            {
                THROW_SAL(sal::ENotImpMapReduce, "uri '?' support cloud but not implement mapreduce method")
                                << __uri.ToString().CStr();
            }
        }
        else{ 
            sal::CRequest& __request = m_RequestResponseTlsInner.m_request;
            sal::CResponse& __response = m_RequestResponseTlsInner.m_response;

            int64 llStreamInStartUsec = cdk::time::GetCurrentUs();
            sal::stream_in(cParamIn,__request,true,m_pTrans);
            m_PerfStatTlsInner.m_lStreamInUsec += cdk::time::GetCurrentUs() - llStreamInStartUsec;

            m_pTrans->Post(__uri, __request, __response,pOBSession);

            int64 llStreamOutStartUsec = cdk::time::GetCurrentUs();
            sal::stream_out(cParamOut,__response);
            m_PerfStatTlsInner.m_lStreamOutUsec += cdk::time::GetCurrentUs() - llStreamOutStartUsec;
        }

        int64 llPostCostUsec = cdk::time::GetCurrentUs() - llSalOpStartUsec;    
        if(llPostCostUsec >= sal::g_SalOpTimeout)    
        {    	   
            LOG_FATAL(0, "Sal::Post(): timeout occured, uri = %s, total cost %lld usec, "
                        "stream_in cost %lld usec, stream_out cost %lld usec.",
                        __uri.ToString().CStr(), llPostCostUsec, m_PerfStatTlsInner.m_lStreamInUsec,     
                        m_PerfStatTlsInner.m_lStreamOutUsec);    
        }
    }

    void CMdbQuery::Asyn4Mdblogin(
    const MMdbQueryDef::SMdbSecLogin& cParamIn,
    sal::CMessageSequence& cMsgSeq,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Mdblogin;

        int64 llSalOpStartUsec = cdk::time::GetCurrentUs();

        //ref map_reduce related TLS list var
        MMdbQueryDef::SMdbSecLoginList& lstParamIn = m_MdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginInLst;
        MRouteDef::SRouteInfoList& lstRouteInfo = m_MdbloginTlsInner.m_RouteInfoLst;
        MSalExpDef::SPostExceptionList& lstPostException = m_MdbloginTlsInner.m_PostExceptionLst;

        //clear map_reduce related TLS list var
        lstParamIn.clear();
        lstRouteInfo.clear();
        lstPostException.clear();

        //reset performance stat tls var
        m_PerfStatTlsInner.m_lStreamInUsec = 0;    
        m_PerfStatTlsInner.m_lStreamOutUsec = 0;

        m_MdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginIn = cParamIn;
        //Test if the mdb domain support cloud
        if(sal::IsDomainSupportCloud(__uri)) {
            //If have implemented map_reduce method, then map In_param to splitted In_param list and corresponding routeInfo list
            if(Map4Mdblogin(cParamIn,lstParamIn,lstRouteInfo,pOBSession) != sal::ESAL_MAPREDUCE_UNIMPLEMENT){
                Request4Mdblogin(lstParamIn, lstRouteInfo, lstPostException, pOBSession);	
            }
            else
            {
                THROW_SAL(sal::ENotImpMapReduce, "uri '?' support cloud but not implement mapreduce method")
                                << __uri.ToString().CStr();
            }
        }
        else{
            sal::CRequest& __request = m_RequestResponseTlsInner.m_request;

            int64 llStreamInStartUsec = cdk::time::GetCurrentUs();
            sal::stream_in(cParamIn,__request,true,m_pTrans);
            m_PerfStatTlsInner.m_lStreamInUsec += cdk::time::GetCurrentUs() - llStreamInStartUsec;
            
            m_pTrans->Request(__uri, __request,pOBSession);
        }

        int64 llAsynCostUsec = cdk::time::GetCurrentUs() - llSalOpStartUsec;    
        if(llAsynCostUsec >= sal::g_SalOpTimeout)    
        {    	   
            LOG_FATAL(0, "Sal::Asyn(): timeout occured, uri = %s, total cost %lld usec, " 
                        "stream_in cost %lld usec, stream_out cost %lld usec.",
                        __uri.ToString().CStr(), llAsynCostUsec, m_PerfStatTlsInner.m_lStreamInUsec,                
                        m_PerfStatTlsInner.m_lStreamOutUsec);    
        }
    }

    MMdbQueryDef::SMdbSecLoginReturn& CMdbQuery::Ret4Mdblogin(
    const sal::CMessageSequence& cMsgSeq,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Mdblogin;

        int64 llSalOpStartUsec = cdk::time::GetCurrentUs();

        //ref map_reduce related TLS list var
        MMdbQueryDef::SMdbSecLogin& cParamIn = m_MdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginIn;
        MMdbQueryDef::SMdbSecLoginReturn& cParamOut = m_MdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginReturnOut;
        MMdbQueryDef::SMdbSecLoginList& lstParamIn = m_MdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginInLst;
        MRouteDef::SRouteInfoList& lstRouteInfo = m_MdbloginTlsInner.m_RouteInfoLst;
        MSalExpDef::SPostExceptionList& lstPostException = m_MdbloginTlsInner.m_PostExceptionLst;
        MMdbQueryDef::SMdbSecLoginReturnList& lstParamOut = m_MdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginReturnOutLst;	

        //clear map_reduce related TLS list var
        lstParamOut.clear();
        cParamOut.Clear();

        //reset performance stat tls var
        m_PerfStatTlsInner.m_lStreamInUsec = 0;    
        m_PerfStatTlsInner.m_lStreamOutUsec = 0;

        //if mapped routeInfo list not empty, then need to reduce all splitted requests
        if(lstRouteInfo.size() > 0){
            //wait response of every single splitted In_param request
            Response4Mdblogin(lstParamOut, lstRouteInfo,lstPostException, pOBSession);
                    
            //reduce all out_params from  every splitted In_param upto origianl cParamOut
            Reduce4Mdblogin(cParamIn,lstParamIn,lstRouteInfo,lstPostException,lstParamOut,cParamOut,pOBSession);
        }
        //if mapped routeInfo list empty, then no mdb cloud support, Response directly
        else{
            sal::CResponse& __response = m_RequestResponseTlsInner.m_response;
            m_pTrans->Response(__uri,__response,pOBSession);

            int64 llStreamOutStartUsec = cdk::time::GetCurrentUs();
            sal::stream_out(cParamOut,__response);
            m_PerfStatTlsInner.m_lStreamOutUsec += cdk::time::GetCurrentUs() - llStreamOutStartUsec; 
        }

        int64  llRetCostUsec = cdk::time::GetCurrentUs() - llSalOpStartUsec;    
        if(llRetCostUsec >= sal::g_SalOpTimeout)    
        {    	   
            LOG_FATAL(0, "Sal::Ret(): timeout occured, uri = %s, total cost %lld usec, "
                        "stream_in cost %lld usec, stream_out cost %lld usec.",
                        __uri.ToString().CStr(), llRetCostUsec, m_PerfStatTlsInner.m_lStreamInUsec,           
                        m_PerfStatTlsInner.m_lStreamOutUsec);    
        }
        return cParamOut;
    }



    void CMdbQuery::Request4Mdblogin(
    const MMdbQueryDef::SMdbSecLoginList& lstParamIn,
    const MRouteDef::SRouteInfoList& lstRouteInfo,
    MSalExpDef::SPostExceptionList& lstPostException,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Mdblogin;

        sal::CRequest& __request = m_RequestResponseTlsInner.m_request;

        MMdbQueryDef::SMdbSecLoginList::const_iterator itParam = lstParamIn.begin();
        MRouteDef::SRouteInfoList::const_iterator it = lstRouteInfo.begin();
        MSalExpDef::SPostException sPostException;
        int64 llTmpStartUsec;
        //request with every single splited In_param and its routeInfo
        for(; it != lstRouteInfo.end(); ++it,++itParam){
            __request.clear();
            sPostException.Clear();
            
            llTmpStartUsec = cdk::time::GetCurrentUs();
            sal::stream_in(*itParam,__request,true,m_pTrans);
            m_PerfStatTlsInner.m_lStreamInUsec += cdk::time::GetCurrentUs() - llTmpStartUsec;
            
            m_pTrans->Request(__uri,*it, __request, sPostException, pOBSession);
            lstPostException.push_back(sPostException);
        }
    }

    void CMdbQuery::Response4Mdblogin(
    MMdbQueryDef::SMdbSecLoginReturnList& lstParamOut,
    const MRouteDef::SRouteInfoList& lstRouteInfo,
    MSalExpDef::SPostExceptionList& lstPostException,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Mdblogin;

        sal::CResponse& __response = m_RequestResponseTlsInner.m_response;

        MRouteDef::SRouteInfoList::const_iterator it = lstRouteInfo.begin();
        MSalExpDef::SPostExceptionList::iterator postExpIt = lstPostException.begin();
        int64 llTmpStartUsec;
        //wait response of every single splitted In_param request
        for(; it != lstRouteInfo.end(); ++it, ++postExpIt){
            __response.clear();
            m_pTrans->Response(__uri,*it,__response, *postExpIt, pOBSession);
            lstParamOut.push_back(MMdbQueryDef::SMdbSecLoginReturn());
            if(0 == postExpIt->get_errorCode())
            {//unmarshalling response from MDB server to paramout if no error occured
                llTmpStartUsec = cdk::time::GetCurrentUs();
                sal::stream_out(lstParamOut.back(),__response);
                m_PerfStatTlsInner.m_lStreamOutUsec += cdk::time::GetCurrentUs() - llTmpStartUsec;
            }
        }
    }

    const sal::CUri CMdbQuery::kUri4Queryratmdbinfo = "kv:/rat_mdb/services/QueryRatMdbInfo?200";

    void CMdbQuery::Post4Queryratmdbinfo(
    const MMdbQueryDef::SMdbQuery& cParamIn,
    MMdbQueryDef::SMdbQueryReturn& cParamOut,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Queryratmdbinfo;

        int64 llSalOpStartUsec = cdk::time::GetCurrentUs();

        //ref map_reduce related TLS list var
        MMdbQueryDef::SMdbQueryList& lstParamIn = m_QueryratmdbinfoTlsInner.m_MMdbQueryDefSMdbQueryInLst;
        MRouteDef::SRouteInfoList& lstRouteInfo = m_QueryratmdbinfoTlsInner.m_RouteInfoLst;
        MSalExpDef::SPostExceptionList& lstPostException = m_QueryratmdbinfoTlsInner.m_PostExceptionLst;
        MMdbQueryDef::SMdbQueryReturnList& lstParamOut = m_QueryratmdbinfoTlsInner.m_MMdbQueryDefSMdbQueryReturnOutLst;	

        //clear map_reduce related TLS list var
        lstParamIn.clear();
        lstParamOut.clear();
        lstRouteInfo.clear();
        lstPostException.clear();

        //reset performance stat tls var
        m_PerfStatTlsInner.m_lStreamInUsec = 0;    
        m_PerfStatTlsInner.m_lStreamOutUsec = 0;

        //Test if this mdb domain support cloud
        if(sal::IsDomainSupportCloud(__uri)) {
            //If have implemented map_reduce method, then map In_param to splitted In_param list and corresponding routeInfo list
            if(Map4Queryratmdbinfo(cParamIn,lstParamIn,lstRouteInfo,pOBSession) != sal::ESAL_MAPREDUCE_UNIMPLEMENT){

                Request4Queryratmdbinfo(lstParamIn, lstRouteInfo, lstPostException, pOBSession);	
                    
                Response4Queryratmdbinfo(lstParamOut, lstRouteInfo, lstPostException, pOBSession);
                
                //reduce all out_params from  every splitted In_param upto origianl cParamOut
                Reduce4Queryratmdbinfo(cParamIn,lstParamIn,lstRouteInfo,lstPostException,lstParamOut,cParamOut,pOBSession);
            }
            else
            {
                THROW_SAL(sal::ENotImpMapReduce, "uri '?' support cloud but not implement mapreduce method")
                                << __uri.ToString().CStr();
            }
        }
        else{ 
            sal::CRequest& __request = m_RequestResponseTlsInner.m_request;
            sal::CResponse& __response = m_RequestResponseTlsInner.m_response;

            int64 llStreamInStartUsec = cdk::time::GetCurrentUs();
            sal::stream_in(cParamIn,__request,false,m_pTrans);
            m_PerfStatTlsInner.m_lStreamInUsec += cdk::time::GetCurrentUs() - llStreamInStartUsec;

            m_pTrans->Post(__uri, __request, __response,pOBSession);

            int64 llStreamOutStartUsec = cdk::time::GetCurrentUs();
            sal::stream_out(cParamOut,__response);
            m_PerfStatTlsInner.m_lStreamOutUsec += cdk::time::GetCurrentUs() - llStreamOutStartUsec;
        }

        int64 llPostCostUsec = cdk::time::GetCurrentUs() - llSalOpStartUsec;    
        if(llPostCostUsec >= sal::g_SalOpTimeout)    
        {    	   
            LOG_FATAL(0, "Sal::Post(): timeout occured, uri = %s, total cost %lld usec, "
                        "stream_in cost %lld usec, stream_out cost %lld usec.",
                        __uri.ToString().CStr(), llPostCostUsec, m_PerfStatTlsInner.m_lStreamInUsec,     
                        m_PerfStatTlsInner.m_lStreamOutUsec);    
        }
    }

    void CMdbQuery::Asyn4Queryratmdbinfo(
    const MMdbQueryDef::SMdbQuery& cParamIn,
    sal::CMessageSequence& cMsgSeq,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Queryratmdbinfo;

        int64 llSalOpStartUsec = cdk::time::GetCurrentUs();

        //ref map_reduce related TLS list var
        MMdbQueryDef::SMdbQueryList& lstParamIn = m_QueryratmdbinfoTlsInner.m_MMdbQueryDefSMdbQueryInLst;
        MRouteDef::SRouteInfoList& lstRouteInfo = m_QueryratmdbinfoTlsInner.m_RouteInfoLst;
        MSalExpDef::SPostExceptionList& lstPostException = m_QueryratmdbinfoTlsInner.m_PostExceptionLst;

        //clear map_reduce related TLS list var
        lstParamIn.clear();
        lstRouteInfo.clear();
        lstPostException.clear();

        //reset performance stat tls var
        m_PerfStatTlsInner.m_lStreamInUsec = 0;    
        m_PerfStatTlsInner.m_lStreamOutUsec = 0;

        m_QueryratmdbinfoTlsInner.m_MMdbQueryDefSMdbQueryIn = cParamIn;
        //Test if the mdb domain support cloud
        if(sal::IsDomainSupportCloud(__uri)) {
            //If have implemented map_reduce method, then map In_param to splitted In_param list and corresponding routeInfo list
            if(Map4Queryratmdbinfo(cParamIn,lstParamIn,lstRouteInfo,pOBSession) != sal::ESAL_MAPREDUCE_UNIMPLEMENT){
                Request4Queryratmdbinfo(lstParamIn, lstRouteInfo, lstPostException, pOBSession);	
            }
            else
            {
                THROW_SAL(sal::ENotImpMapReduce, "uri '?' support cloud but not implement mapreduce method")
                                << __uri.ToString().CStr();
            }
        }
        else{
            sal::CRequest& __request = m_RequestResponseTlsInner.m_request;

            int64 llStreamInStartUsec = cdk::time::GetCurrentUs();
            sal::stream_in(cParamIn,__request,false,m_pTrans);
            m_PerfStatTlsInner.m_lStreamInUsec += cdk::time::GetCurrentUs() - llStreamInStartUsec;
            
            m_pTrans->Request(__uri, __request,pOBSession);
        }

        int64 llAsynCostUsec = cdk::time::GetCurrentUs() - llSalOpStartUsec;    
        if(llAsynCostUsec >= sal::g_SalOpTimeout)    
        {    	   
            LOG_FATAL(0, "Sal::Asyn(): timeout occured, uri = %s, total cost %lld usec, " 
                        "stream_in cost %lld usec, stream_out cost %lld usec.",
                        __uri.ToString().CStr(), llAsynCostUsec, m_PerfStatTlsInner.m_lStreamInUsec,                
                        m_PerfStatTlsInner.m_lStreamOutUsec);    
        }
    }

    MMdbQueryDef::SMdbQueryReturn& CMdbQuery::Ret4Queryratmdbinfo(
    const sal::CMessageSequence& cMsgSeq,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Queryratmdbinfo;

        int64 llSalOpStartUsec = cdk::time::GetCurrentUs();

        //ref map_reduce related TLS list var
        MMdbQueryDef::SMdbQuery& cParamIn = m_QueryratmdbinfoTlsInner.m_MMdbQueryDefSMdbQueryIn;
        MMdbQueryDef::SMdbQueryReturn& cParamOut = m_QueryratmdbinfoTlsInner.m_MMdbQueryDefSMdbQueryReturnOut;
        MMdbQueryDef::SMdbQueryList& lstParamIn = m_QueryratmdbinfoTlsInner.m_MMdbQueryDefSMdbQueryInLst;
        MRouteDef::SRouteInfoList& lstRouteInfo = m_QueryratmdbinfoTlsInner.m_RouteInfoLst;
        MSalExpDef::SPostExceptionList& lstPostException = m_QueryratmdbinfoTlsInner.m_PostExceptionLst;
        MMdbQueryDef::SMdbQueryReturnList& lstParamOut = m_QueryratmdbinfoTlsInner.m_MMdbQueryDefSMdbQueryReturnOutLst;	

        //clear map_reduce related TLS list var
        lstParamOut.clear();
        cParamOut.Clear();

        //reset performance stat tls var
        m_PerfStatTlsInner.m_lStreamInUsec = 0;    
        m_PerfStatTlsInner.m_lStreamOutUsec = 0;

        //if mapped routeInfo list not empty, then need to reduce all splitted requests
        if(lstRouteInfo.size() > 0){
            //wait response of every single splitted In_param request
            Response4Queryratmdbinfo(lstParamOut, lstRouteInfo,lstPostException, pOBSession);
                    
            //reduce all out_params from  every splitted In_param upto origianl cParamOut
            Reduce4Queryratmdbinfo(cParamIn,lstParamIn,lstRouteInfo,lstPostException,lstParamOut,cParamOut,pOBSession);
        }
        //if mapped routeInfo list empty, then no mdb cloud support, Response directly
        else{
            sal::CResponse& __response = m_RequestResponseTlsInner.m_response;
            m_pTrans->Response(__uri,__response,pOBSession);

            int64 llStreamOutStartUsec = cdk::time::GetCurrentUs();
            sal::stream_out(cParamOut,__response);
            m_PerfStatTlsInner.m_lStreamOutUsec += cdk::time::GetCurrentUs() - llStreamOutStartUsec; 
        }

        int64  llRetCostUsec = cdk::time::GetCurrentUs() - llSalOpStartUsec;    
        if(llRetCostUsec >= sal::g_SalOpTimeout)    
        {    	   
            LOG_FATAL(0, "Sal::Ret(): timeout occured, uri = %s, total cost %lld usec, "
                        "stream_in cost %lld usec, stream_out cost %lld usec.",
                        __uri.ToString().CStr(), llRetCostUsec, m_PerfStatTlsInner.m_lStreamInUsec,           
                        m_PerfStatTlsInner.m_lStreamOutUsec);    
        }
        return cParamOut;
    }



    void CMdbQuery::Request4Queryratmdbinfo(
    const MMdbQueryDef::SMdbQueryList& lstParamIn,
    const MRouteDef::SRouteInfoList& lstRouteInfo,
    MSalExpDef::SPostExceptionList& lstPostException,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Queryratmdbinfo;

        sal::CRequest& __request = m_RequestResponseTlsInner.m_request;

        MMdbQueryDef::SMdbQueryList::const_iterator itParam = lstParamIn.begin();
        MRouteDef::SRouteInfoList::const_iterator it = lstRouteInfo.begin();
        MSalExpDef::SPostException sPostException;
        int64 llTmpStartUsec;
        //request with every single splited In_param and its routeInfo
        for(; it != lstRouteInfo.end(); ++it,++itParam){
            __request.clear();
            sPostException.Clear();
            
            llTmpStartUsec = cdk::time::GetCurrentUs();
            sal::stream_in(*itParam,__request,false,m_pTrans);
            m_PerfStatTlsInner.m_lStreamInUsec += cdk::time::GetCurrentUs() - llTmpStartUsec;
            
            m_pTrans->Request(__uri,*it, __request, sPostException, pOBSession);
            lstPostException.push_back(sPostException);
        }
    }

    void CMdbQuery::Response4Queryratmdbinfo(
    MMdbQueryDef::SMdbQueryReturnList& lstParamOut,
    const MRouteDef::SRouteInfoList& lstRouteInfo,
    MSalExpDef::SPostExceptionList& lstPostException,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Queryratmdbinfo;

        sal::CResponse& __response = m_RequestResponseTlsInner.m_response;

        MRouteDef::SRouteInfoList::const_iterator it = lstRouteInfo.begin();
        MSalExpDef::SPostExceptionList::iterator postExpIt = lstPostException.begin();
        int64 llTmpStartUsec;
        //wait response of every single splitted In_param request
        for(; it != lstRouteInfo.end(); ++it, ++postExpIt){
            __response.clear();
            m_pTrans->Response(__uri,*it,__response, *postExpIt, pOBSession);
            lstParamOut.push_back(MMdbQueryDef::SMdbQueryReturn());
            if(0 == postExpIt->get_errorCode())
            {//unmarshalling response from MDB server to paramout if no error occured
                llTmpStartUsec = cdk::time::GetCurrentUs();
                sal::stream_out(lstParamOut.back(),__response);
                m_PerfStatTlsInner.m_lStreamOutUsec += cdk::time::GetCurrentUs() - llTmpStartUsec;
            }
        }
    }

    const sal::CUri CMdbQuery::kUri4Ratmdblogin = "kv:/rat_mdb/services/ratmdblogin?403";

    void CMdbQuery::Post4Ratmdblogin(
    const MMdbQueryDef::SMdbSecLogin& cParamIn,
    MMdbQueryDef::SMdbSecLoginReturn& cParamOut,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Ratmdblogin;

        int64 llSalOpStartUsec = cdk::time::GetCurrentUs();

        //ref map_reduce related TLS list var
        MMdbQueryDef::SMdbSecLoginList& lstParamIn = m_RatmdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginInLst;
        MRouteDef::SRouteInfoList& lstRouteInfo = m_RatmdbloginTlsInner.m_RouteInfoLst;
        MSalExpDef::SPostExceptionList& lstPostException = m_RatmdbloginTlsInner.m_PostExceptionLst;
        MMdbQueryDef::SMdbSecLoginReturnList& lstParamOut = m_RatmdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginReturnOutLst;	

        //clear map_reduce related TLS list var
        lstParamIn.clear();
        lstParamOut.clear();
        lstRouteInfo.clear();
        lstPostException.clear();

        //reset performance stat tls var
        m_PerfStatTlsInner.m_lStreamInUsec = 0;    
        m_PerfStatTlsInner.m_lStreamOutUsec = 0;

        //Test if this mdb domain support cloud
        if(sal::IsDomainSupportCloud(__uri)) {
            //If have implemented map_reduce method, then map In_param to splitted In_param list and corresponding routeInfo list
            if(Map4Ratmdblogin(cParamIn,lstParamIn,lstRouteInfo,pOBSession) != sal::ESAL_MAPREDUCE_UNIMPLEMENT){

                Request4Ratmdblogin(lstParamIn, lstRouteInfo, lstPostException, pOBSession);	
                    
                Response4Ratmdblogin(lstParamOut, lstRouteInfo, lstPostException, pOBSession);
                
                //reduce all out_params from  every splitted In_param upto origianl cParamOut
                Reduce4Ratmdblogin(cParamIn,lstParamIn,lstRouteInfo,lstPostException,lstParamOut,cParamOut,pOBSession);
            }
            else
            {
                THROW_SAL(sal::ENotImpMapReduce, "uri '?' support cloud but not implement mapreduce method")
                                << __uri.ToString().CStr();
            }
        }
        else{ 
            sal::CRequest& __request = m_RequestResponseTlsInner.m_request;
            sal::CResponse& __response = m_RequestResponseTlsInner.m_response;

            int64 llStreamInStartUsec = cdk::time::GetCurrentUs();
            sal::stream_in(cParamIn,__request,true,m_pTrans);
            m_PerfStatTlsInner.m_lStreamInUsec += cdk::time::GetCurrentUs() - llStreamInStartUsec;

            m_pTrans->Post(__uri, __request, __response,pOBSession);

            int64 llStreamOutStartUsec = cdk::time::GetCurrentUs();
            sal::stream_out(cParamOut,__response);
            m_PerfStatTlsInner.m_lStreamOutUsec += cdk::time::GetCurrentUs() - llStreamOutStartUsec;
        }

        int64 llPostCostUsec = cdk::time::GetCurrentUs() - llSalOpStartUsec;    
        if(llPostCostUsec >= sal::g_SalOpTimeout)    
        {    	   
            LOG_FATAL(0, "Sal::Post(): timeout occured, uri = %s, total cost %lld usec, "
                        "stream_in cost %lld usec, stream_out cost %lld usec.",
                        __uri.ToString().CStr(), llPostCostUsec, m_PerfStatTlsInner.m_lStreamInUsec,     
                        m_PerfStatTlsInner.m_lStreamOutUsec);    
        }
    }

    void CMdbQuery::Asyn4Ratmdblogin(
    const MMdbQueryDef::SMdbSecLogin& cParamIn,
    sal::CMessageSequence& cMsgSeq,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Ratmdblogin;

        int64 llSalOpStartUsec = cdk::time::GetCurrentUs();

        //ref map_reduce related TLS list var
        MMdbQueryDef::SMdbSecLoginList& lstParamIn = m_RatmdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginInLst;
        MRouteDef::SRouteInfoList& lstRouteInfo = m_RatmdbloginTlsInner.m_RouteInfoLst;
        MSalExpDef::SPostExceptionList& lstPostException = m_RatmdbloginTlsInner.m_PostExceptionLst;

        //clear map_reduce related TLS list var
        lstParamIn.clear();
        lstRouteInfo.clear();
        lstPostException.clear();

        //reset performance stat tls var
        m_PerfStatTlsInner.m_lStreamInUsec = 0;    
        m_PerfStatTlsInner.m_lStreamOutUsec = 0;

        m_RatmdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginIn = cParamIn;
        //Test if the mdb domain support cloud
        if(sal::IsDomainSupportCloud(__uri)) {
            //If have implemented map_reduce method, then map In_param to splitted In_param list and corresponding routeInfo list
            if(Map4Ratmdblogin(cParamIn,lstParamIn,lstRouteInfo,pOBSession) != sal::ESAL_MAPREDUCE_UNIMPLEMENT){
                Request4Ratmdblogin(lstParamIn, lstRouteInfo, lstPostException, pOBSession);	
            }
            else
            {
                THROW_SAL(sal::ENotImpMapReduce, "uri '?' support cloud but not implement mapreduce method")
                                << __uri.ToString().CStr();
            }
        }
        else{
            sal::CRequest& __request = m_RequestResponseTlsInner.m_request;

            int64 llStreamInStartUsec = cdk::time::GetCurrentUs();
            sal::stream_in(cParamIn,__request,true,m_pTrans);
            m_PerfStatTlsInner.m_lStreamInUsec += cdk::time::GetCurrentUs() - llStreamInStartUsec;
            
            m_pTrans->Request(__uri, __request,pOBSession);
        }

        int64 llAsynCostUsec = cdk::time::GetCurrentUs() - llSalOpStartUsec;    
        if(llAsynCostUsec >= sal::g_SalOpTimeout)    
        {    	   
            LOG_FATAL(0, "Sal::Asyn(): timeout occured, uri = %s, total cost %lld usec, " 
                        "stream_in cost %lld usec, stream_out cost %lld usec.",
                        __uri.ToString().CStr(), llAsynCostUsec, m_PerfStatTlsInner.m_lStreamInUsec,                
                        m_PerfStatTlsInner.m_lStreamOutUsec);    
        }
    }

    MMdbQueryDef::SMdbSecLoginReturn& CMdbQuery::Ret4Ratmdblogin(
    const sal::CMessageSequence& cMsgSeq,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Ratmdblogin;

        int64 llSalOpStartUsec = cdk::time::GetCurrentUs();

        //ref map_reduce related TLS list var
        MMdbQueryDef::SMdbSecLogin& cParamIn = m_RatmdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginIn;
        MMdbQueryDef::SMdbSecLoginReturn& cParamOut = m_RatmdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginReturnOut;
        MMdbQueryDef::SMdbSecLoginList& lstParamIn = m_RatmdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginInLst;
        MRouteDef::SRouteInfoList& lstRouteInfo = m_RatmdbloginTlsInner.m_RouteInfoLst;
        MSalExpDef::SPostExceptionList& lstPostException = m_RatmdbloginTlsInner.m_PostExceptionLst;
        MMdbQueryDef::SMdbSecLoginReturnList& lstParamOut = m_RatmdbloginTlsInner.m_MMdbQueryDefSMdbSecLoginReturnOutLst;	

        //clear map_reduce related TLS list var
        lstParamOut.clear();
        cParamOut.Clear();

        //reset performance stat tls var
        m_PerfStatTlsInner.m_lStreamInUsec = 0;    
        m_PerfStatTlsInner.m_lStreamOutUsec = 0;

        //if mapped routeInfo list not empty, then need to reduce all splitted requests
        if(lstRouteInfo.size() > 0){
            //wait response of every single splitted In_param request
            Response4Ratmdblogin(lstParamOut, lstRouteInfo,lstPostException, pOBSession);
                    
            //reduce all out_params from  every splitted In_param upto origianl cParamOut
            Reduce4Ratmdblogin(cParamIn,lstParamIn,lstRouteInfo,lstPostException,lstParamOut,cParamOut,pOBSession);
        }
        //if mapped routeInfo list empty, then no mdb cloud support, Response directly
        else{
            sal::CResponse& __response = m_RequestResponseTlsInner.m_response;
            m_pTrans->Response(__uri,__response,pOBSession);

            int64 llStreamOutStartUsec = cdk::time::GetCurrentUs();
            sal::stream_out(cParamOut,__response);
            m_PerfStatTlsInner.m_lStreamOutUsec += cdk::time::GetCurrentUs() - llStreamOutStartUsec; 
        }

        int64  llRetCostUsec = cdk::time::GetCurrentUs() - llSalOpStartUsec;    
        if(llRetCostUsec >= sal::g_SalOpTimeout)    
        {    	   
            LOG_FATAL(0, "Sal::Ret(): timeout occured, uri = %s, total cost %lld usec, "
                        "stream_in cost %lld usec, stream_out cost %lld usec.",
                        __uri.ToString().CStr(), llRetCostUsec, m_PerfStatTlsInner.m_lStreamInUsec,           
                        m_PerfStatTlsInner.m_lStreamOutUsec);    
        }
        return cParamOut;
    }



    void CMdbQuery::Request4Ratmdblogin(
    const MMdbQueryDef::SMdbSecLoginList& lstParamIn,
    const MRouteDef::SRouteInfoList& lstRouteInfo,
    MSalExpDef::SPostExceptionList& lstPostException,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Ratmdblogin;

        sal::CRequest& __request = m_RequestResponseTlsInner.m_request;

        MMdbQueryDef::SMdbSecLoginList::const_iterator itParam = lstParamIn.begin();
        MRouteDef::SRouteInfoList::const_iterator it = lstRouteInfo.begin();
        MSalExpDef::SPostException sPostException;
        int64 llTmpStartUsec;
        //request with every single splited In_param and its routeInfo
        for(; it != lstRouteInfo.end(); ++it,++itParam){
            __request.clear();
            sPostException.Clear();
            
            llTmpStartUsec = cdk::time::GetCurrentUs();
            sal::stream_in(*itParam,__request,true,m_pTrans);
            m_PerfStatTlsInner.m_lStreamInUsec += cdk::time::GetCurrentUs() - llTmpStartUsec;
            
            m_pTrans->Request(__uri,*it, __request, sPostException, pOBSession);
            lstPostException.push_back(sPostException);
        }
    }

    void CMdbQuery::Response4Ratmdblogin(
    MMdbQueryDef::SMdbSecLoginReturnList& lstParamOut,
    const MRouteDef::SRouteInfoList& lstRouteInfo,
    MSalExpDef::SPostExceptionList& lstPostException,
    SOBSession* pOBSession)
    {

        const sal::CUri& __uri = kUri4Ratmdblogin;

        sal::CResponse& __response = m_RequestResponseTlsInner.m_response;

        MRouteDef::SRouteInfoList::const_iterator it = lstRouteInfo.begin();
        MSalExpDef::SPostExceptionList::iterator postExpIt = lstPostException.begin();
        int64 llTmpStartUsec;
        //wait response of every single splitted In_param request
        for(; it != lstRouteInfo.end(); ++it, ++postExpIt){
            __response.clear();
            m_pTrans->Response(__uri,*it,__response, *postExpIt, pOBSession);
            lstParamOut.push_back(MMdbQueryDef::SMdbSecLoginReturn());
            if(0 == postExpIt->get_errorCode())
            {//unmarshalling response from MDB server to paramout if no error occured
                llTmpStartUsec = cdk::time::GetCurrentUs();
                sal::stream_out(lstParamOut.back(),__response);
                m_PerfStatTlsInner.m_lStreamOutUsec += cdk::time::GetCurrentUs() - llTmpStartUsec;
            }
        }
    }


}; // namespace mdbquery



// struct definition for SMdbQuery
const uint64 SMdbQuery::BIT_FLAG = I64(0x1);
const uint64 SMdbQuery::BIT_TABLE_NAME = I64(0x2);
const uint64 SMdbQuery::BIT_QUERY = I64(0x4);
const uint64 SMdbQuery::BITS_DB_MARKER = I64(0x0);
const uint64 SMdbQuery::BITS_NOT_NULL_MARKER_ARR[] = {I64(0x0)};
const uint64 SMdbQuery::BITS_DB_MARKER_ARR[] = {I64(0x0)};
const int SMdbQuery::IMPORT_TABLE_COUNT = 0;
const int SMdbQuery::MEMBER_FIELD_COUNT = 3;
const char* SMdbQuery::SZ_TYPE_NAME = "SMdbQuery";

void inline SMdbQuery::init()
{
    for(int i=0;i<1;i++)
    {
        m_arrllMarker[i] = 0;
        m_arrllUsedMarker[i] = 0;
    }
    m_pllUsedMarker = m_arrllUsedMarker;
    m_pllMarker = m_arrllMarker;
    m_pllNotNullMarker = const_cast<uint64*>(BITS_NOT_NULL_MARKER_ARR);
    m_pllDbMarker = const_cast<uint64*>(BITS_DB_MARKER_ARR);
    m_iMarkerNum = 1;
    m_iFieldNum = 3;
 /* do nothing */ 
}

SMdbQuery::SMdbQuery() : sdl::CSdlBasicStructObject(),
    m_llFlag(0),
    m_strTableName(),
    m_strQuery()
{
	init();
}

SMdbQuery::~SMdbQuery()
{ 
}

void SMdbQuery::Clear()
{
	for(int i=0;i<1;i++)
	{
		m_arrllMarker[i] = 0;
		m_arrllUsedMarker[i] = 0;
	}
    m_llFlag = 0;
    m_strTableName.clear();
    m_strQuery.clear();
}

void SMdbQuery::Clear4Pool()
{
	for(int i=0;i<1;i++)
	{
		m_arrllMarker[i] = 0;
		m_arrllUsedMarker[i] = 0;
	}
    m_llFlag = 0;
    m_strTableName.clear();
    m_strQuery.clear();
}

CSdlBasicObject* SMdbQuery::create_object()
{
    return new SMdbQuery();
}



// list definition for SMdbQueryList
SMdbQueryList::SMdbQueryList() : sdl::CSdlBasicListObject(),poolvector<SMdbQuery>()
{
}
void SMdbQueryList::Clear()
{
	clear();
}



// struct definition for SMdbQueryReturn
const uint64 SMdbQueryReturn::BIT_RESULT = I64(0x1);
const uint64 SMdbQueryReturn::BITS_DB_MARKER = I64(0x0);
const uint64 SMdbQueryReturn::BITS_NOT_NULL_MARKER_ARR[] = {I64(0x0)};
const uint64 SMdbQueryReturn::BITS_DB_MARKER_ARR[] = {I64(0x0)};
const int SMdbQueryReturn::IMPORT_TABLE_COUNT = 0;
const int SMdbQueryReturn::MEMBER_FIELD_COUNT = 1;
const char* SMdbQueryReturn::SZ_TYPE_NAME = "SMdbQueryReturn";

void inline SMdbQueryReturn::init()
{
    for(int i=0;i<1;i++)
    {
        m_arrllMarker[i] = 0;
        m_arrllUsedMarker[i] = 0;
    }
    m_pllUsedMarker = m_arrllUsedMarker;
    m_pllMarker = m_arrllMarker;
    m_pllNotNullMarker = const_cast<uint64*>(BITS_NOT_NULL_MARKER_ARR);
    m_pllDbMarker = const_cast<uint64*>(BITS_DB_MARKER_ARR);
    m_iMarkerNum = 1;
    m_iFieldNum = 1;
 /* do nothing */ 
}

SMdbQueryReturn::SMdbQueryReturn() : sdl::CSdlBasicStructObject(),
    m_strResult()
{
	init();
}

SMdbQueryReturn::~SMdbQueryReturn()
{ 
}

void SMdbQueryReturn::Clear()
{
	for(int i=0;i<1;i++)
	{
		m_arrllMarker[i] = 0;
		m_arrllUsedMarker[i] = 0;
	}
    m_strResult.clear();
}

void SMdbQueryReturn::Clear4Pool()
{
	for(int i=0;i<1;i++)
	{
		m_arrllMarker[i] = 0;
		m_arrllUsedMarker[i] = 0;
	}
    m_strResult.clear();
}

CSdlBasicObject* SMdbQueryReturn::create_object()
{
    return new SMdbQueryReturn();
}


// list definition for SMdbQueryReturnList
SMdbQueryReturnList::SMdbQueryReturnList() : sdl::CSdlBasicListObject(),poolvector<SMdbQueryReturn>()
{
}
void SMdbQueryReturnList::Clear()
{
	clear();
}



// struct definition for SMdbSecLogin
const uint64 SMdbSecLogin::BIT_USER_NAME = I64(0x1);
const uint64 SMdbSecLogin::BIT_PASSWD = I64(0x2);
const uint64 SMdbSecLogin::BITS_DB_MARKER = I64(0x0);
const uint64 SMdbSecLogin::BITS_NOT_NULL_MARKER_ARR[] = {I64(0x0)};
const uint64 SMdbSecLogin::BITS_DB_MARKER_ARR[] = {I64(0x0)};
const int SMdbSecLogin::IMPORT_TABLE_COUNT = 0;
const int SMdbSecLogin::MEMBER_FIELD_COUNT = 2;
const char* SMdbSecLogin::SZ_TYPE_NAME = "SMdbSecLogin";

void inline SMdbSecLogin::init()
{
    for(int i=0;i<1;i++)
    {
        m_arrllMarker[i] = 0;
        m_arrllUsedMarker[i] = 0;
    }
    m_pllUsedMarker = m_arrllUsedMarker;
    m_pllMarker = m_arrllMarker;
    m_pllNotNullMarker = const_cast<uint64*>(BITS_NOT_NULL_MARKER_ARR);
    m_pllDbMarker = const_cast<uint64*>(BITS_DB_MARKER_ARR);
    m_iMarkerNum = 1;
    m_iFieldNum = 2;
 /* do nothing */ 
}

SMdbSecLogin::SMdbSecLogin() : sdl::CSdlBasicStructObject(),
    m_strUserName(),
    m_strPasswd()
{
	init();
}

SMdbSecLogin::~SMdbSecLogin()
{ 
}

void SMdbSecLogin::Clear()
{
	for(int i=0;i<1;i++)
	{
		m_arrllMarker[i] = 0;
		m_arrllUsedMarker[i] = 0;
	}
    m_strUserName.clear();
    m_strPasswd.clear();
}

void SMdbSecLogin::Clear4Pool()
{
	for(int i=0;i<1;i++)
	{
		m_arrllMarker[i] = 0;
		m_arrllUsedMarker[i] = 0;
	}
    m_strUserName.clear();
    m_strPasswd.clear();
}

CSdlBasicObject* SMdbSecLogin::create_object()
{
    return new SMdbSecLogin();
}



// list definition for SMdbSecLoginList
SMdbSecLoginList::SMdbSecLoginList() : sdl::CSdlBasicListObject(),poolvector<SMdbSecLogin>()
{

void SMdbSecLoginList::Clear()
{
	clear();
}


// struct definition for SMdbSecLoginReturn
const uint64 SMdbSecLoginReturn::BIT_LOGIN_FLAG = I64(0x1);
const uint64 SMdbSecLoginReturn::BIT_MSG = I64(0x2);
const uint64 SMdbSecLoginReturn::BITS_DB_MARKER = I64(0x0);
const uint64 SMdbSecLoginReturn::BITS_NOT_NULL_MARKER_ARR[] = {I64(0x0)};
const uint64 SMdbSecLoginReturn::BITS_DB_MARKER_ARR[] = {I64(0x0)};
const int SMdbSecLoginReturn::IMPORT_TABLE_COUNT = 0;
const int SMdbSecLoginReturn::MEMBER_FIELD_COUNT = 2;
const char* SMdbSecLoginReturn::SZ_TYPE_NAME = "SMdbSecLoginReturn";

void inline SMdbSecLoginReturn::init()
{
    for(int i=0;i<1;i++)
    {
        m_arrllMarker[i] = 0;
        m_arrllUsedMarker[i] = 0;
    }
    m_pllUsedMarker = m_arrllUsedMarker;
    m_pllMarker = m_arrllMarker;
    m_pllNotNullMarker = const_cast<uint64*>(BITS_NOT_NULL_MARKER_ARR);
    m_pllDbMarker = const_cast<uint64*>(BITS_DB_MARKER_ARR);
    m_iMarkerNum = 1;
    m_iFieldNum = 2;
 /* do nothing */ 
}

SMdbSecLoginReturn::SMdbSecLoginReturn() : sdl::CSdlBasicStructObject(),
    m_iLoginFlag(0),
    m_strMsg()
{
	init();
}

SMdbSecLoginReturn::~SMdbSecLoginReturn()
{ 
}

void SMdbSecLoginReturn::Clear()
{
	for(int i=0;i<1;i++)
	{
		m_arrllMarker[i] = 0;
		m_arrllUsedMarker[i] = 0;
	}
    m_iLoginFlag = 0;
    m_strMsg.clear();
}

void SMdbSecLoginReturn::Clear4Pool()
{
	for(int i=0;i<1;i++)
	{
		m_arrllMarker[i] = 0;
		m_arrllUsedMarker[i] = 0;
	}
    m_iLoginFlag = 0;
    m_strMsg.clear();
}

CSdlBasicObject* SMdbSecLoginReturn::create_object()
{
    return new SMdbSecLoginReturn();
}


// list definition for SMdbSecLoginReturnList
SMdbSecLoginReturnList::SMdbSecLoginReturnList() : sdl::CSdlBasicListObject(),poolvector<SMdbSecLoginReturn>()
{
}
void SMdbSecLoginReturnList::Clear()
{
	clear();
}
