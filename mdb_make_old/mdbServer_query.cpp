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


static const char* s_szCompilePath = "/data01/zjgrp/zjdev/source/ob_dev/verisbilling8_cmcc_zj/rating_billing/mdb/util/mdb_query/mapreduce";
static const char* s_szSourceFileName = __FILE__;
static const char* s_szCompileDate = __DATE__;
static const char* s_szCompileTime = __TIME__;

static aistring __get_sourceFileName()
{
    aistring s = s_szCompilePath;
#ifdef _Windows
    if ( s.length() > 0 ) s += "\\";
#else
    if ( s.length() > 0 ) s += '/';
#endif
    s += s_szSourceFileName;
    return s;
}

/*class SMdbQuery*/
const uint64 SMdbQuery::BIT_FLAG = I64(0x1);
const uint64 SMdbQuery::BIT_TABLE_NAME = I64(0x2);
const uint64 SMdbQuery::BIT_QUERY = I64(0x4);
const uint64 SMdbQuery::BITS_ALL_MARKER = I64(0x7);
const uint64 SMdbQuery::BITS_NOT_NULL_MARKER = I64(0x0);
const uint64 SMdbQuery::BITS_DB_MARKER = I64(0x0);
const uint64 SMdbQuery::BITS_NOT_NULL_MARKER_ARR[] = {I64(0x0)};
const uint64 SMdbQuery::BITS_DB_MARKER_ARR[] = {I64(0x0)};
const int SMdbQuery::IMPORT_TABLE_COUNT = 0;
const int SMdbQuery::MEMBER_FIELD_COUNT = 3;
const char* SMdbQuery::SZ_TYPE_NAME = "SMdbQuery";
const sdl::SSdlMemberTypeInfo* SMdbQuery::ARRAY_MEMBER_TYPE_INFO = s_MMdbQueryDef_SMdbQuery_MemberTypeInfo;
const char* SMdbQuery::ARRAY_IMPORT_TABLES[] = 
{
    0
};

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
/*End of class SMdbQuery*/


SMdbQueryList::SMdbQueryList() : sdl::CSdlBasicListObject(),poolvector<SMdbQuery>()
{
}
void SMdbQueryList::Clear()
{
	clear();
}

void* SMdbQueryList::append_item()
{
	;
    return &(*(insert(end(), SMdbQuery())));
}

void SMdbQueryList::change_size(const int iNewSize)
{
    resize(iNewSize > 0 ? iNewSize : 0);
}

const void* SMdbQueryList::get_addrOfFirstItem() const
{
    return size() > 0 ? &(*begin()) : 0;
}

int SMdbQueryList::get_containerType() const
{
    return LT_POOLVECTOR;
}

int SMdbQueryList::get_itemSize() const
{
    return sizeof(SMdbQuery);
}

int SMdbQueryList::get_itemType() const
{
    return SDL_STRUCT;
}

int SMdbQueryList::get_size() const
{
    return size();
}

const void* SMdbQueryList::get(int index) const
{
    return &operator[](index);
}

void* SMdbQueryList::get(int index)
{
    return &operator[](index);
}

void SMdbQueryList::Erase(int index)
{
    erase(begin() + index);
}

CSdlBasicObject* SMdbQueryList::create_object()
{
    return new SMdbQueryList();
}
static CSdlCreateObjectInitializer s_MMdbQueryDef_SMdbQueryList_SdlCreateObjectInitializer("SMdbQueryList", SMdbQueryList::create_object);

static sdl::CSdlTypeInfo s_cTypeInfo4MMdbQueryDef_SMdbQueryList(SDL_LIST, "SMdbQueryList",
    sdl::CSdlTypeInfo::create_typeDescription(__get_sourceFileName().c_str(),
        __LINE__, s_szCompileDate, s_szCompileTime).c_str(),
    sizeof(SMdbQueryList), 1, "SMdbQuery", SDL_STRUCT);
static sdl::CSdlTypeInfoImpl s_cTypeInfoImpl4MMdbQueryDef_SMdbQueryList(s_cTypeInfo4MMdbQueryDef_SMdbQueryList);

const sdl::CSdlTypeInfo& SMdbQueryList::get_typeInfo() const
{
    return s_cTypeInfo4MMdbQueryDef_SMdbQueryList;
}



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

const sdl::CSdlTypeInfo& SMdbQueryReturn::get_typeInfo() const
{
    return s_cTypeInfo4MMdbQueryDef_SMdbQueryReturn;
}



const void* SMdbQueryReturn::get_addressTable(const void* pTable[1]) const
{
    if ( pTable != 0 )
    {
        int i = 0;
        pTable[i++] = &m_strResult;
    }
    return &m_strResult;
}


SMdbQueryReturnList::SMdbQueryReturnList() : sdl::CSdlBasicListObject(),poolvector<SMdbQueryReturn>()
{
}
void SMdbQueryReturnList::Clear()
{
	clear();
}

void* SMdbQueryReturnList::append_item()
{
	;
    return &(*(insert(end(), SMdbQueryReturn())));
}

void SMdbQueryReturnList::change_size(const int iNewSize)
{
    resize(iNewSize > 0 ? iNewSize : 0);
}

const void* SMdbQueryReturnList::get_addrOfFirstItem() const
{
    return size() > 0 ? &(*begin()) : 0;
}

int SMdbQueryReturnList::get_containerType() const
{
    return LT_POOLVECTOR;
}

int SMdbQueryReturnList::get_itemSize() const
{
    return sizeof(SMdbQueryReturn);
}

int SMdbQueryReturnList::get_itemType() const
{
    return SDL_STRUCT;
}

int SMdbQueryReturnList::get_size() const
{
    return size();
}

const void* SMdbQueryReturnList::get(int index) const
{
    return &operator[](index);
}

void* SMdbQueryReturnList::get(int index)
{
    return &operator[](index);
}

void SMdbQueryReturnList::Erase(int index)
{
    erase(begin() + index);
}

CSdlBasicObject* SMdbQueryReturnList::create_object()
{
    return new SMdbQueryReturnList();
}
static CSdlCreateObjectInitializer s_MMdbQueryDef_SMdbQueryReturnList_SdlCreateObjectInitializer("SMdbQueryReturnList", SMdbQueryReturnList::create_object);

static sdl::CSdlTypeInfo s_cTypeInfo4MMdbQueryDef_SMdbQueryReturnList(SDL_LIST, "SMdbQueryReturnList",
    sdl::CSdlTypeInfo::create_typeDescription(__get_sourceFileName().c_str(),
        __LINE__, s_szCompileDate, s_szCompileTime).c_str(),
    sizeof(SMdbQueryReturnList), 1, "SMdbQueryReturn", SDL_STRUCT);
static sdl::CSdlTypeInfoImpl s_cTypeInfoImpl4MMdbQueryDef_SMdbQueryReturnList(s_cTypeInfo4MMdbQueryDef_SMdbQueryReturnList);

const sdl::CSdlTypeInfo& SMdbQueryReturnList::get_typeInfo() const
{
    return s_cTypeInfo4MMdbQueryDef_SMdbQueryReturnList;
}


static sdl::CSdlTypeInfo s_cTypeInfo4MMdbQueryDef_SMdbSecLogin(SDL_STRUCT, "SMdbSecLogin",
    sdl::CSdlTypeInfo::create_typeDescription(__get_sourceFileName().c_str(),
        __LINE__, s_szCompileDate, s_szCompileTime).c_str(),
    sizeof(SMdbSecLogin), 2,
    "aistring", SDL_STRING,
    "aistring", SDL_STRING);
static sdl::CSdlTypeInfoImpl s_cTypeInfoImpl4MMdbQueryDef_SMdbSecLogin(s_cTypeInfo4MMdbQueryDef_SMdbSecLogin);

static sdl::SSdlMemberTypeInfo s_MMdbQueryDef_SMdbSecLogin_MemberTypeInfo[2 + 1] =
{
    { SDL_STRING, "USER_NAME", sizeof(aistring), -1, 0, reinterpret_cast<FuncSdlAssign>(sdl_assignString),I64(0x1),0,"aistring",0},
    { SDL_STRING, "PASSWD", sizeof(aistring), -1, 0, reinterpret_cast<FuncSdlAssign>(sdl_assignString),I64(0x2),1,"aistring",0},
    { -1, 0, 0, 0, 0, 0 ,0}
};

extern "C" sdl::SSdlMemberTypeAddress get_MMdbQueryDef_SMdbSecLogin_MemberTypeAddress()
{
    sdl::SSdlMemberTypeAddress Addr;
    Addr.addr = s_MMdbQueryDef_SMdbSecLogin_MemberTypeInfo;
    Addr.size = 2;
    return Addr;
}
extern "C" const char* get_MMdbQueryDef_SMdbSecLogin_MemberType_IndexString4Lua()
{
    static char MMdbQueryDef_SMdbSecLogin_MemberType_IndexString[] = 
"\
local MMdbQueryDef_SMdbSecLogin_USER_NAME=0;\n\
local MMdbQueryDef_SMdbSecLogin_PASSWD=1;\n\
";
    return MMdbQueryDef_SMdbSecLogin_MemberType_IndexString;
}
static SMapSSdlMemberTypeInfo s_MMdbQueryDef_SMdbSecLogin_MapMemberTypeInfo;
static CMapSdlStructMemberTypeInitializer s_MapMMdbQueryDef_SMdbSecLogin(&s_MMdbQueryDef_SMdbSecLogin_MapMemberTypeInfo,s_MMdbQueryDef_SMdbSecLogin_MemberTypeInfo,2);
static CSdlStructMemberTypeInitializer s_MMdbQueryDef_SMdbSecLogin(s_MMdbQueryDef_SMdbSecLogin_MemberTypeInfo,
    SMdbSecLogin());

const uint64 SMdbSecLogin::BIT_USER_NAME = I64(0x1);
const uint64 SMdbSecLogin::BIT_PASSWD = I64(0x2);
const uint64 SMdbSecLogin::BITS_ALL_MARKER = I64(0x3);
const uint64 SMdbSecLogin::BITS_NOT_NULL_MARKER = I64(0x0);
const uint64 SMdbSecLogin::BITS_DB_MARKER = I64(0x0);
const uint64 SMdbSecLogin::BITS_NOT_NULL_MARKER_ARR[] = {I64(0x0)};
const uint64 SMdbSecLogin::BITS_DB_MARKER_ARR[] = {I64(0x0)};
const int SMdbSecLogin::IMPORT_TABLE_COUNT = 0;
const int SMdbSecLogin::MEMBER_FIELD_COUNT = 2;
const char* SMdbSecLogin::SZ_TYPE_NAME = "SMdbSecLogin";
const sdl::SSdlMemberTypeInfo* SMdbSecLogin::ARRAY_MEMBER_TYPE_INFO = s_MMdbQueryDef_SMdbSecLogin_MemberTypeInfo;
const char* SMdbSecLogin::ARRAY_IMPORT_TABLES[] = 
{
    0
};

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

const sdl::CSdlTypeInfo& SMdbSecLogin::get_typeInfo() const
{
    return s_cTypeInfo4MMdbQueryDef_SMdbSecLogin;
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

const void* SMdbSecLogin::get_addressTable(const void* pTable[2]) const
{
    if ( pTable != 0 )
    {
        int i = 0;
        pTable[i++] = &m_strUserName;
        pTable[i++] = &m_strPasswd;
    }
    return &m_strUserName;
}


SMdbSecLoginList::SMdbSecLoginList() : sdl::CSdlBasicListObject(),poolvector<SMdbSecLogin>()
{
}
void SMdbSecLoginList::Clear()
{
	clear();
}

void* SMdbSecLoginList::append_item()
{
	;
    return &(*(insert(end(), SMdbSecLogin())));
}

void SMdbSecLoginList::change_size(const int iNewSize)
{
    resize(iNewSize > 0 ? iNewSize : 0);
}

const void* SMdbSecLoginList::get_addrOfFirstItem() const
{
    return size() > 0 ? &(*begin()) : 0;
}

int SMdbSecLoginList::get_containerType() const
{
    return LT_POOLVECTOR;
}

int SMdbSecLoginList::get_itemSize() const
{
    return sizeof(SMdbSecLogin);
}

int SMdbSecLoginList::get_itemType() const
{
    return SDL_STRUCT;
}

int SMdbSecLoginList::get_size() const
{
    return size();
}

const void* SMdbSecLoginList::get(int index) const
{
    return &operator[](index);
}

void* SMdbSecLoginList::get(int index)
{
    return &operator[](index);
}

void SMdbSecLoginList::Erase(int index)
{
    erase(begin() + index);
}

CSdlBasicObject* SMdbSecLoginList::create_object()
{
    return new SMdbSecLoginList();
}
static CSdlCreateObjectInitializer s_MMdbQueryDef_SMdbSecLoginList_SdlCreateObjectInitializer("SMdbSecLoginList", SMdbSecLoginList::create_object);

static sdl::CSdlTypeInfo s_cTypeInfo4MMdbQueryDef_SMdbSecLoginList(SDL_LIST, "SMdbSecLoginList",
    sdl::CSdlTypeInfo::create_typeDescription(__get_sourceFileName().c_str(),
        __LINE__, s_szCompileDate, s_szCompileTime).c_str(),
    sizeof(SMdbSecLoginList), 1, "SMdbSecLogin", SDL_STRUCT);
static sdl::CSdlTypeInfoImpl s_cTypeInfoImpl4MMdbQueryDef_SMdbSecLoginList(s_cTypeInfo4MMdbQueryDef_SMdbSecLoginList);

const sdl::CSdlTypeInfo& SMdbSecLoginList::get_typeInfo() const
{
    return s_cTypeInfo4MMdbQueryDef_SMdbSecLoginList;
}


static sdl::CSdlTypeInfo s_cTypeInfo4MMdbQueryDef_SMdbSecLoginReturn(SDL_STRUCT, "SMdbSecLoginReturn",
    sdl::CSdlTypeInfo::create_typeDescription(__get_sourceFileName().c_str(),
        __LINE__, s_szCompileDate, s_szCompileTime).c_str(),
    sizeof(SMdbSecLoginReturn), 2,
    "int32", SDL_INT32,
    "aistring", SDL_STRING);

static sdl::SSdlMemberTypeInfo s_MMdbQueryDef_SMdbSecLoginReturn_MemberTypeInfo[2 + 1] =
{
    { SDL_INT32, "LOGIN_FLAG", sizeof(int32), -1, 0, reinterpret_cast<FuncSdlAssign>(sdl_assignInt32),I64(0x1),0,"int32",0},
    { SDL_STRING, "MSG", sizeof(aistring), -1, 0, reinterpret_cast<FuncSdlAssign>(sdl_assignString),I64(0x2),1,"aistring",0},
    { -1, 0, 0, 0, 0, 0 ,0}
};


static SMapSSdlMemberTypeInfo s_MMdbQueryDef_SMdbSecLoginReturn_MapMemberTypeInfo;

const uint64 SMdbSecLoginReturn::BIT_LOGIN_FLAG = I64(0x1);
const uint64 SMdbSecLoginReturn::BIT_MSG = I64(0x2);
const uint64 SMdbSecLoginReturn::BITS_ALL_MARKER = I64(0x3);
const uint64 SMdbSecLoginReturn::BITS_NOT_NULL_MARKER = I64(0x0);
const uint64 SMdbSecLoginReturn::BITS_DB_MARKER = I64(0x0);
const uint64 SMdbSecLoginReturn::BITS_NOT_NULL_MARKER_ARR[] = {I64(0x0)};
const uint64 SMdbSecLoginReturn::BITS_DB_MARKER_ARR[] = {I64(0x0)};
const int SMdbSecLoginReturn::IMPORT_TABLE_COUNT = 0;
const int SMdbSecLoginReturn::MEMBER_FIELD_COUNT = 2;
const char* SMdbSecLoginReturn::SZ_TYPE_NAME = "SMdbSecLoginReturn";
const sdl::SSdlMemberTypeInfo* SMdbSecLoginReturn::ARRAY_MEMBER_TYPE_INFO = s_MMdbQueryDef_SMdbSecLoginReturn_MemberTypeInfo;
const char* SMdbSecLoginReturn::ARRAY_IMPORT_TABLES[] = 
{
    0
};

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

const sdl::CSdlTypeInfo& SMdbSecLoginReturn::get_typeInfo() const
{
    return s_cTypeInfo4MMdbQueryDef_SMdbSecLoginReturn;
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

const void* SMdbSecLoginReturn::get_addressTable(const void* pTable[2]) const
{
    if ( pTable != 0 )
    {
        int i = 0;
        pTable[i++] = &m_iLoginFlag;
        pTable[i++] = &m_strMsg;
    }
    return &m_iLoginFlag;
}


SMdbSecLoginReturnList::SMdbSecLoginReturnList() : sdl::CSdlBasicListObject(),poolvector<SMdbSecLoginReturn>()
{
}
void SMdbSecLoginReturnList::Clear()
{
	clear();
}

void* SMdbSecLoginReturnList::append_item()
{
	;
    return &(*(insert(end(), SMdbSecLoginReturn())));
}

void SMdbSecLoginReturnList::change_size(const int iNewSize)
{
    resize(iNewSize > 0 ? iNewSize : 0);
}

const void* SMdbSecLoginReturnList::get_addrOfFirstItem() const
{
    return size() > 0 ? &(*begin()) : 0;
}

int SMdbSecLoginReturnList::get_containerType() const
{
    return LT_POOLVECTOR;
}

int SMdbSecLoginReturnList::get_itemSize() const
{
    return sizeof(SMdbSecLoginReturn);
}

int SMdbSecLoginReturnList::get_itemType() const
{
    return SDL_STRUCT;
}

int SMdbSecLoginReturnList::get_size() const
{
    return size();
}

const void* SMdbSecLoginReturnList::get(int index) const
{
    return &operator[](index);
}

void* SMdbSecLoginReturnList::get(int index)
{
    return &operator[](index);
}

void SMdbSecLoginReturnList::Erase(int index)
{
    erase(begin() + index);
}

CSdlBasicObject* SMdbSecLoginReturnList::create_object()
{
    return new SMdbSecLoginReturnList();
}

static sdl::CSdlTypeInfo s_cTypeInfo4MMdbQueryDef_SMdbSecLoginReturnList(SDL_LIST, "SMdbSecLoginReturnList",
    sdl::CSdlTypeInfo::create_typeDescription(__get_sourceFileName().c_str(),
        __LINE__, s_szCompileDate, s_szCompileTime).c_str(),
    sizeof(SMdbSecLoginReturnList), 1, "SMdbSecLoginReturn", SDL_STRUCT);

const sdl::CSdlTypeInfo& SMdbSecLoginReturnList::get_typeInfo() const
{
    return s_cTypeInfo4MMdbQueryDef_SMdbSecLoginReturnList;
}

