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
        static const uint64     BITS_NOT_NULL_MARKER_ARR[];
        static const uint64     BITS_DB_MARKER_ARR[];

    private:
    	uint64	m_arrllMarker[1];
    	uint64	m_arrllUsedMarker[1];
    	void	inline init();

    public:
        SMdbQuery();
        ~SMdbQuery();

        const sdl::CSdlTypeInfo& get_typeInfo() const{};
        const CClassDesc& class_desc() const{};
        const void* get_addressTable(const void* pTable[3]) const{};

        void Clear();
    public:
      inline  int64 get_flag() const
        {
            return m_llFlag;
        }

      inline int64& flag()
        {
            m_pllMarker[0] |= BIT_FLAG;
            m_pllUsedMarker[0] |= BIT_FLAG;
            return m_llFlag;
        }

      inline const aistring& get_tableName() const
        {
            return m_strTableName;
        }

      inline aistring& tableName()
        {
            m_pllMarker[0] |= BIT_TABLE_NAME;
            m_pllUsedMarker[0] |= BIT_TABLE_NAME;
            return m_strTableName;
        }

      inline const aistring& get_query() const
        {
            return m_strQuery;
        }

      inline aistring& query()
        {
            m_pllMarker[0] |= BIT_QUERY;
            m_pllUsedMarker[0] |= BIT_QUERY;
            return m_strQuery;
        }

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


    // list definition for SMdbQueryList
    class SMdbQueryList : public sdl::CSdlBasicListObject, public poolvector<SMdbQuery>
    {
    public:
    	SMdbQueryList();
    	void Clear();
        void* append_item(){};
        void change_size(const int iNewSize){};
        const void* get_addrOfFirstItem() const{};
        int get_size() const{};
        void* get(int index){};
        const void* get(int index) const{};
        void Erase(int index){};
        const sdl::CSdlTypeInfo& get_typeInfo() const{};
        int get_itemType() const{};
        int get_itemSize() const{};
        int get_containerType() const{};
    };


    class SMdbQueryReturn : public sdl::CSdlBasicStructObject
    {
    public:

        static const uint64     BIT_RESULT;
        static const uint64     BITS_NOT_NULL_MARKER_ARR[];
        static const uint64     BITS_DB_MARKER_ARR[];

    private:
    	uint64	m_arrllMarker[1];
    	uint64	m_arrllUsedMarker[1];
    	void	inline init();

    public:
        SMdbQueryReturn();
        ~SMdbQueryReturn();

        const sdl::CSdlTypeInfo& get_typeInfo() const{};
        const CClassDesc& class_desc() const{};
        const void* get_addressTable(const void* pTable[1]) const{};

        void Clear();
    public:
      inline const aistring& get_result() const
        {
            return m_strResult;
        }

      inline aistring& result()
        {
            m_pllMarker[0] |= BIT_RESULT;
            m_pllUsedMarker[0] |= BIT_RESULT;
            return m_strResult;
        }

    public:
        inline void set_result(const aistring& value)
        {
            m_strResult = value;
            m_pllMarker[0] |= BIT_RESULT;
            m_pllUsedMarker[0] |= BIT_RESULT;
        }

    private: // data members
        aistring		m_strResult;
    };


    // list definition for SMdbQueryReturnList
    class SMdbQueryReturnList : public sdl::CSdlBasicListObject, public poolvector<SMdbQueryReturn>
    {
    public:
    	SMdbQueryReturnList();
    	void Clear();
        void* append_item(){};
        void change_size(const int iNewSize){};
        const void* get_addrOfFirstItem() const{};
        int get_size() const{};
        void* get(int index){};
        const void* get(int index) const{};
        void Erase(int index){};
        const sdl::CSdlTypeInfo& get_typeInfo() const{};
        int get_itemType() const{};
        int get_itemSize() const{};
        int get_containerType() const{};
    };


    class SMdbSecLogin : public sdl::CSdlBasicStructObject
    {
    public:

        static const uint64     BIT_USER_NAME;
        static const uint64     BIT_PASSWD;
        static const uint64     BITS_NOT_NULL_MARKER_ARR[];
        static const uint64     BITS_DB_MARKER_ARR[];

    private:
    	uint64	m_arrllMarker[1];
    	uint64	m_arrllUsedMarker[1];
    	void	inline init();

    public:
        SMdbSecLogin();
        ~SMdbSecLogin();

        const sdl::CSdlTypeInfo& get_typeInfo() const{};
        const CClassDesc& class_desc() const{};
        const void* get_addressTable(const void* pTable[2]) const{};

        void Clear();
    public:
      inline const aistring& get_userName() const
        {
            return m_strUserName;
        }

      inline aistring& userName()
        {
            m_pllMarker[0] |= BIT_USER_NAME;
            m_pllUsedMarker[0] |= BIT_USER_NAME;
            return m_strUserName;
        }

      inline const aistring& get_passwd() const
        {
            return m_strPasswd;
        }

      inline aistring& passwd()
        {
            m_pllMarker[0] |= BIT_PASSWD;
            m_pllUsedMarker[0] |= BIT_PASSWD;
            return m_strPasswd;
        }

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


    // list definition for SMdbSecLoginList
    class SMdbSecLoginList : public sdl::CSdlBasicListObject, public poolvector<SMdbSecLogin>
    {
    public:
    	SMdbSecLoginList();
    	void Clear();
        void* append_item(){};
        void change_size(const int iNewSize){};
        const void* get_addrOfFirstItem() const{};
        int get_size() const{};
        void* get(int index){};
        const void* get(int index) const{};
        void Erase(int index){};
        const sdl::CSdlTypeInfo& get_typeInfo() const{};
        int get_itemType() const{};
        int get_itemSize() const{};
        int get_containerType() const{};
    };


    class SMdbSecLoginReturn : public sdl::CSdlBasicStructObject
    {
    public: 

        static const uint64     BIT_LOGIN_FLAG;
        static const uint64     BIT_MSG;
        static const uint64     BITS_NOT_NULL_MARKER_ARR[];
        static const uint64     BITS_DB_MARKER_ARR[];

    private:
    	uint64	m_arrllMarker[1];
    	uint64	m_arrllUsedMarker[1];
    	void	inline init();

    public:
        SMdbSecLoginReturn();
        ~SMdbSecLoginReturn();

        const sdl::CSdlTypeInfo& get_typeInfo() const{};
        const CClassDesc& class_desc() const{};
        const void* get_addressTable(const void* pTable[2]) const{};

        void Clear();
    public:
      inline  int32 get_loginFlag() const
        {
            return m_iLoginFlag;
        }

      inline int32& loginFlag()
        {
            m_pllMarker[0] |= BIT_LOGIN_FLAG;
            m_pllUsedMarker[0] |= BIT_LOGIN_FLAG;
            return m_iLoginFlag;
        }

      inline const aistring& get_msg() const
        {
            return m_strMsg;
        }

      inline aistring& msg()
        {
            m_pllMarker[0] |= BIT_MSG;
            m_pllUsedMarker[0] |= BIT_MSG;
            return m_strMsg;
        }

    public:
        inline void set_loginFlag(const int32& value)
        {
            m_iLoginFlag = value;
            m_pllMarker[0] |= BIT_LOGIN_FLAG;
            m_pllUsedMarker[0] |= BIT_LOGIN_FLAG;
        }

        inline void set_msg(const aistring& value)
        {
            m_strMsg = value;
            m_pllMarker[0] |= BIT_MSG;
            m_pllUsedMarker[0] |= BIT_MSG;
        }

    private: // data members
        int32		m_iLoginFlag;
        aistring		m_strMsg;
    };

    // list definition for SMdbSecLoginReturnList
    class SMdbSecLoginReturnList : public sdl::CSdlBasicListObject, public poolvector<SMdbSecLoginReturn>
    {
    public:
    	SMdbSecLoginReturnList();
    	void Clear();
        void* append_item(){};
        void change_size(const int iNewSize){};
        const void* get_addrOfFirstItem() const{};
        int get_size() const{};
        void* get(int index){};
        const void* get(int index) const{};
        void Erase(int index){};
        const sdl::CSdlTypeInfo& get_typeInfo() const{};
        int get_itemType() const{};
        int get_itemSize() const{};
        int get_containerType() const{};
    };

}; // namespace MMdbQueryDef


namespace mdbquery
{
    class CMdbQuery
    {
    public:
        CMdbQuery(sal::CTransaction* trans = 0);
        virtual ~CMdbQuery();

        
        void Post4Querymdbinfo(
            const MMdbQueryDef::SMdbQuery& cParamIn,
            MMdbQueryDef::SMdbQueryReturn& cParamOut,
            SOBSession* pOBSession = NULL);

        
        void Post4Mdblogin(
            const MMdbQueryDef::SMdbSecLogin& cParamIn,
            MMdbQueryDef::SMdbSecLoginReturn& cParamOut,
            SOBSession* pOBSession = NULL);

        
        void Post4Queryratmdbinfo(
            const MMdbQueryDef::SMdbQuery& cParamIn,
            MMdbQueryDef::SMdbQueryReturn& cParamOut,
            SOBSession* pOBSession = NULL);

        
        void Post4Ratmdblogin(
            const MMdbQueryDef::SMdbSecLogin& cParamIn,
            MMdbQueryDef::SMdbSecLoginReturn& cParamOut,
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
