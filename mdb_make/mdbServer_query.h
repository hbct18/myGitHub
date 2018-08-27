// ********************************************************************
// 
// Generating date: 2018-08-20
// ********************************************************************

#ifndef __MDB_SERVER_QUERY_H__
#define __MDB_SERVER_QUERY_H__

#include <cdk/foundation/cdk_aivector.h>
#include <cdk/foundation/cdk_aiset.h>
#include <cdk/foundation/cdk_aimap.h>
#include <public/sdl/sdl_session.h>
#include <public/sdl/sdl_basic.h>
#include <public/sdl/sdl_stream.h>

#include "sal/sal.h"


namespace MMdbQueryDef
{
    class SMdbQuery : public sdl::CSdlBasicStructObject
    {
    public:
        static const uint64     BIT_FLAG;
        static const uint64     BIT_TABLE_NAME;
        static const uint64     BIT_QUERY;
        static const uint64     BITS_ALL_MARKER;
        static const uint64     BITS_NOT_NULL_MARKER;
        static const uint64     BITS_DB_MARKER;
        static const uint64     BITS_NOT_NULL_MARKER_ARR[];
        static const uint64     BITS_DB_MARKER_ARR[];
        static const int        IMPORT_TABLE_COUNT;
        static const int        MEMBER_FIELD_COUNT;
        static const char*      SZ_TYPE_NAME;
        static const char*      ARRAY_IMPORT_TABLES[];
        static const            sdl::SSdlMemberTypeInfo* ARRAY_MEMBER_TYPE_INFO;

    private:
    	uint64	m_arrllMarker[1];
    	uint64	m_arrllUsedMarker[1];
    	void	inline init();

    public:
        SMdbQuery();
        ~SMdbQuery();

        const sdl::CSdlTypeInfo& get_typeInfo() const;
        const CClassDesc& class_desc() const;
        const void* get_addressTable(const void* pTable[3]) const;

        void Clear();

    public:
        inline void set_flag(const int64& value)
        {
            m_llFlag = value;
            m_pllMarker[0] |= BIT_FLAG;
            m_pllUsedMarker[0] |= BIT_FLAG;
        }

        inline void set_tableName(const aistring& value)
        {
            m_strTableName = value;
            m_pllMarker[0] |= BIT_TABLE_NAME;
            m_pllUsedMarker[0] |= BIT_TABLE_NAME;
        }

        inline void set_query(const aistring& value)
        {
            m_strQuery = value;
            m_pllMarker[0] |= BIT_QUERY;
            m_pllUsedMarker[0] |= BIT_QUERY;
        }

    private: // data members
        int64		m_llFlag;
        aistring		m_strTableName;
        aistring		m_strQuery;
    };


    class SMdbQueryList : public sdl::CSdlBasicListObject, public poolvector<SMdbQuery>
    {
    public:
    	SMdbQueryList();
    	SMdbQueryList(obb_stream& stream);
        void* append_item();
        void change_size(const int iNewSize);
        const void* get_addrOfFirstItem() const;
        int get_size() const;
        void* get(int index);
        const void* get(int index) const;
        void Erase(int index);
    	void Clear();
        const sdl::CSdlTypeInfo& get_typeInfo() const;
        int get_itemType() const;
        int get_itemSize() const;
        int get_containerType() const;
    	static CSdlBasicObject* create_object();
    };


    class SMdbQueryReturn : public sdl::CSdlBasicStructObject
    {
    public: // constant definitions
        enum { // field indexes
            IDX_RESULT,
            MAX_FIELD_INDEX
        };

        static const uint64 BIT_RESULT;
        static const uint64    BITS_ALL_MARKER;
        static const uint64    BITS_NOT_NULL_MARKER;
        static const uint64    BITS_DB_MARKER;
        static const uint64    BITS_NOT_NULL_MARKER_ARR[];
        static const uint64    BITS_DB_MARKER_ARR[];
        static const int       IMPORT_TABLE_COUNT;
        static const int       MEMBER_FIELD_COUNT;
        static const char*     SZ_TYPE_NAME;
        static const char*     ARRAY_IMPORT_TABLES[];
        static const sdl::SSdlMemberTypeInfo* ARRAY_MEMBER_TYPE_INFO;

    private:
    	uint64	m_arrllMarker[1];
    	uint64	m_arrllUsedMarker[1];
    	void	inline init();

    public:
        SMdbQueryReturn();
        ~SMdbQueryReturn();

        const sdl::CSdlTypeInfo& get_typeInfo() const;
        const CClassDesc& class_desc() const;
        const void* get_addressTable(const void* pTable[1]) const;

    public:
      inline const aistring& get_result() const
        {
            return m_strResult;
        }

    private: // data members
        aistring		m_strResult;
    };


    class SMdbQueryReturnList : public sdl::CSdlBasicListObject, public poolvector<SMdbQueryReturn>
    {
    public:
    	SMdbQueryReturnList();
    	SMdbQueryReturnList(obb_stream& stream);
        void* append_item();
        void change_size(const int iNewSize);
        const void* get_addrOfFirstItem() const;
        int get_size() const;
        void* get(int index);
        const void* get(int index) const;
        void Erase(int index);
    	 void Clear();
        const sdl::CSdlTypeInfo& get_typeInfo() const;
        int get_itemType() const;
        int get_itemSize() const;
        int get_containerType() const;
    	static CSdlBasicObject* create_object();
    };


    class SMdbSecLogin : public sdl::CSdlBasicStructObject
    {
    public: // constant definitions
        enum { // field indexes
            IDX_USER_NAME,
            IDX_PASSWD,
            MAX_FIELD_INDEX
        };

        static const uint64 BIT_USER_NAME;
        static const uint64 BIT_PASSWD;
        static const uint64    BITS_ALL_MARKER;
        static const uint64    BITS_NOT_NULL_MARKER;
        static const uint64    BITS_DB_MARKER;
        static const uint64    BITS_NOT_NULL_MARKER_ARR[];
        static const uint64    BITS_DB_MARKER_ARR[];
        static const int       IMPORT_TABLE_COUNT;
        static const int       MEMBER_FIELD_COUNT;
        static const char*     SZ_TYPE_NAME;
        static const char*     ARRAY_IMPORT_TABLES[];
        static const sdl::SSdlMemberTypeInfo* ARRAY_MEMBER_TYPE_INFO;

    private:
    	uint64	m_arrllMarker[1];
    	uint64	m_arrllUsedMarker[1];
    	void	inline init();

    public:
        SMdbSecLogin();
        ~SMdbSecLogin();

        const sdl::CSdlTypeInfo& get_typeInfo() const;
        const CClassDesc& class_desc() const;
        const void* get_addressTable(const void* pTable[2]) const;

        void Clear();

    public:
        inline void set_userName(const aistring& value)
        {
            m_strUserName = value;
            m_pllMarker[0] |= BIT_USER_NAME;
            m_pllUsedMarker[0] |= BIT_USER_NAME;
        }

        inline void set_passwd(const aistring& value)
        {
            m_strPasswd = value;
            m_pllMarker[0] |= BIT_PASSWD;
            m_pllUsedMarker[0] |= BIT_PASSWD;
        }

    private: // data members
        aistring		m_strUserName;
        aistring		m_strPasswd;
    };


    class SMdbSecLoginList : public sdl::CSdlBasicListObject, public poolvector<SMdbSecLogin>
    {
    public:
    	SMdbSecLoginList();
    	SMdbSecLoginList(obb_stream& stream);
        void* append_item();
        void change_size(const int iNewSize);
        const void* get_addrOfFirstItem() const;
        int get_size() const;
        void* get(int index);
        const void* get(int index) const;
        void Erase(int index);
    	 void Clear();
        const sdl::CSdlTypeInfo& get_typeInfo() const;
        int get_itemType() const;
        int get_itemSize() const;
        int get_containerType() const;
    	static CSdlBasicObject* create_object();
    };


    class SMdbSecLoginReturn : public sdl::CSdlBasicStructObject
    {
    public: // constant definitions
        enum { // field indexes
            IDX_LOGIN_FLAG,
            IDX_MSG,
            MAX_FIELD_INDEX
        };

        static const uint64 BIT_LOGIN_FLAG;
        static const uint64 BIT_MSG;
        static const uint64    BITS_ALL_MARKER;
        static const uint64    BITS_NOT_NULL_MARKER;
        static const uint64    BITS_DB_MARKER;
        static const uint64    BITS_NOT_NULL_MARKER_ARR[];
        static const uint64    BITS_DB_MARKER_ARR[];
        static const int       IMPORT_TABLE_COUNT;
        static const int       MEMBER_FIELD_COUNT;
        static const char*     SZ_TYPE_NAME;
        static const char*     ARRAY_IMPORT_TABLES[];
        static const sdl::SSdlMemberTypeInfo* ARRAY_MEMBER_TYPE_INFO;

    private:
    	uint64	m_arrllMarker[1];
    	uint64	m_arrllUsedMarker[1];
    	void	inline init();

    public:
        SMdbSecLoginReturn();
        ~SMdbSecLoginReturn();

        const sdl::CSdlTypeInfo& get_typeInfo() const;
        const CClassDesc& class_desc() const;
        const void* get_addressTable(const void* pTable[2]) const;

        void Clear();

    private: // data members
        int32		m_iLoginFlag;
        aistring		m_strMsg;
    };


    class SMdbSecLoginReturnList : public sdl::CSdlBasicListObject, public poolvector<SMdbSecLoginReturn>
    {
    public:
    	SMdbSecLoginReturnList();
    	SMdbSecLoginReturnList(obb_stream& stream);
        void* append_item();
        void change_size(const int iNewSize);
        const void* get_addrOfFirstItem() const;
        int get_size() const;
        void* get(int index);
        const void* get(int index) const;
        void Erase(int index);
    	 void Clear();
        const sdl::CSdlTypeInfo& get_typeInfo() const;
        int get_itemType() const;
        int get_itemSize() const;
        int get_containerType() const;
    	static CSdlBasicObject* create_object();
    };

}; // namespace MMdbQueryDef


namespace mdbquery
{
    
    struct QuerymdbinfoTlsInner;
    
    
    struct MdbloginTlsInner;
    
    
    struct QueryratmdbinfoTlsInner;
    
    
    struct RatmdbloginTlsInner;
    
    struct TlsRequestResponseInner;

    struct TlsPerfStatInner;


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

}; // namespace mdbquery


#endif // __MDB_SERVER_QUERY_H__
