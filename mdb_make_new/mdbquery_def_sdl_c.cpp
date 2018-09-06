//******************************************************************
//* Copyright (c) 2003-2009, Asiainfo HangZhou. All rights reserved.
//* SDL generated C++ client skeleton cpp file.
//* Source filename: mdbquery_def.sdl
//* Generated date:  2018-07-03 13:13:37
//* Note: This is a auto-generated file, DON'T MODIFY IT!
//******************************************************************

#include <string.h>
#include <iterator>
#include <public/sdl/sdl_session.h>
#include <public/sdl/sdl_basic.h>
#include "mdbquery_def_sdl_c.h"

using namespace sdl;

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

#if !defined(SDL_SELECTED_API) || defined(SDL_USE_MMDBQUERYDEF_SMDBQUERY)
// struct definition for MMdbQueryDef::SMdbQuery
static sdl::CSdlTypeInfo s_cTypeInfo4MMdbQueryDef_SMdbQuery(SDL_STRUCT, "MMdbQueryDef::SMdbQuery",
    sdl::CSdlTypeInfo::create_typeDescription(__get_sourceFileName().c_str(),
        __LINE__, s_szCompileDate, s_szCompileTime).c_str(),
    sizeof(MMdbQueryDef::SMdbQuery), 3,
    "int64", SDL_INT64,
    "aistring", SDL_STRING,
    "aistring", SDL_STRING);
static sdl::CSdlTypeInfoImpl s_cTypeInfoImpl4MMdbQueryDef_SMdbQuery(s_cTypeInfo4MMdbQueryDef_SMdbQuery);

static sdl::SSdlMemberTypeInfo s_MMdbQueryDef_SMdbQuery_MemberTypeInfo[3 + 1] =
{
    { SDL_INT64, "FLAG", sizeof(int64), -1, 0, reinterpret_cast<FuncSdlAssign>(sdl_assignInt64),I64(0x1),0,"int64",0},
    { SDL_STRING, "TABLE_NAME", sizeof(aistring), -1, 0, reinterpret_cast<FuncSdlAssign>(sdl_assignString),I64(0x2),1,"aistring",0},
    { SDL_STRING, "QUERY", sizeof(aistring), -1, 0, reinterpret_cast<FuncSdlAssign>(sdl_assignString),I64(0x4),2,"aistring",0},
    { -1, 0, 0, 0, 0, 0 ,0}
};

extern "C" sdl::SSdlMemberTypeAddress get_MMdbQueryDef_SMdbQuery_MemberTypeAddress()
{
    sdl::SSdlMemberTypeAddress Addr;
    Addr.addr = s_MMdbQueryDef_SMdbQuery_MemberTypeInfo;
    Addr.size = 3;
    return Addr;
}
extern "C" const char* get_MMdbQueryDef_SMdbQuery_MemberType_IndexString4Lua()
{
    static char MMdbQueryDef_SMdbQuery_MemberType_IndexString[] = 
"\
local MMdbQueryDef_SMdbQuery_FLAG=0;\n\
local MMdbQueryDef_SMdbQuery_TABLE_NAME=1;\n\
local MMdbQueryDef_SMdbQuery_QUERY=2;\n\
";
    return MMdbQueryDef_SMdbQuery_MemberType_IndexString;
}
//static Mapsdl::SSdlMemberTypeInfo map_MMdbQueryDef_SMdbQuery_MapMemberTypeInfo;
//static SMapSSdlMemberTypeInfo s_MMdbQueryDef_SMdbQuery_MapMemberTypeInfo = {map_MMdbQueryDef_SMdbQuery_MapMemberTypeInfo};
static SMapSSdlMemberTypeInfo s_MMdbQueryDef_SMdbQuery_MapMemberTypeInfo;
static CMapSdlStructMemberTypeInitializer s_MapMMdbQueryDef_SMdbQuery(&s_MMdbQueryDef_SMdbQuery_MapMemberTypeInfo,s_MMdbQueryDef_SMdbQuery_MemberTypeInfo,3);
static CSdlStructMemberTypeInitializer s_MMdbQueryDef_SMdbQuery(s_MMdbQueryDef_SMdbQuery_MemberTypeInfo,
    MMdbQueryDef::SMdbQuery());

const uint64 MMdbQueryDef::SMdbQuery::BIT_FLAG = I64(0x1);
const uint64 MMdbQueryDef::SMdbQuery::BIT_TABLE_NAME = I64(0x2);
const uint64 MMdbQueryDef::SMdbQuery::BIT_QUERY = I64(0x4);
const uint64 MMdbQueryDef::SMdbQuery::BITS_ALL_MARKER = I64(0x7);
const uint64 MMdbQueryDef::SMdbQuery::BITS_NOT_NULL_MARKER = I64(0x0);
const uint64 MMdbQueryDef::SMdbQuery::BITS_DB_MARKER = I64(0x0);
const uint64 MMdbQueryDef::SMdbQuery::BITS_NOT_NULL_MARKER_ARR[] = {I64(0x0)};
const uint64 MMdbQueryDef::SMdbQuery::BITS_DB_MARKER_ARR[] = {I64(0x0)};
const int MMdbQueryDef::SMdbQuery::IMPORT_TABLE_COUNT = 0;
const int MMdbQueryDef::SMdbQuery::MEMBER_FIELD_COUNT = 3;
const char* MMdbQueryDef::SMdbQuery::SZ_TYPE_NAME = "MMdbQueryDef::SMdbQuery";
const sdl::SSdlMemberTypeInfo* MMdbQueryDef::SMdbQuery::ARRAY_MEMBER_TYPE_INFO = s_MMdbQueryDef_SMdbQuery_MemberTypeInfo;
const char* MMdbQueryDef::SMdbQuery::ARRAY_IMPORT_TABLES[] = 
{
    0
};

void inline MMdbQueryDef::SMdbQuery::init()
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

MMdbQueryDef::SMdbQuery::SMdbQuery() : sdl::CSdlBasicStructObject(),
    m_llFlag(0),
    m_strTableName(),
    m_strQuery()
{
	init();
}

MMdbQueryDef::SMdbQuery::SMdbQuery(obb_stream& stream) : sdl::CSdlBasicStructObject() ,
    m_llFlag(0),
    m_strTableName(),
    m_strQuery()
{ 
	init();
	stream >> *this;
}

MMdbQueryDef::SMdbQuery::SMdbQuery(const SMdbQuery& rhs) : sdl::CSdlBasicStructObject(rhs),
    m_llFlag(0),
    m_strTableName(),
    m_strQuery()
{ 
    init();
    m_iMarkerNum = rhs.m_iMarkerNum;
    m_iFieldNum = rhs.m_iFieldNum;
    for(int i=0;i<rhs.get_markerNum();i++)
    {
        m_pllUsedMarker[i] = rhs.m_pllUsedMarker[i];
        m_pllMarker[i] = rhs.m_pllMarker[i];
    }
    if (rhs.m_pllUsedMarker[0] & BIT_FLAG)
        m_llFlag = rhs.m_llFlag;
    if (rhs.m_pllUsedMarker[0] & BIT_TABLE_NAME)
        m_strTableName = rhs.m_strTableName;
    if (rhs.m_pllUsedMarker[0] & BIT_QUERY)
        m_strQuery = rhs.m_strQuery;
}

MMdbQueryDef::SMdbQuery::~SMdbQuery()
{ 
}

MMdbQueryDef::SMdbQuery& MMdbQueryDef::SMdbQuery::operator=(const MMdbQueryDef::SMdbQuery& rhs) 
{
    if ( this != &rhs )
    {
        Clear();
        sdl::CSdlBasicStructObject::operator = (rhs);
        m_iMarkerNum = rhs.m_iMarkerNum;
        m_iFieldNum = rhs.m_iFieldNum;
        for(int i=0;i<rhs.get_markerNum();i++)
        {
            m_pllUsedMarker[i] = rhs.m_pllUsedMarker[i];
            m_pllMarker[i] = rhs.m_pllMarker[i];
        }
        if (rhs.m_pllUsedMarker[0] & BIT_FLAG)
            m_llFlag = rhs.m_llFlag;
        if (rhs.m_pllUsedMarker[0] & BIT_TABLE_NAME)
            m_strTableName = rhs.m_strTableName;
        if (rhs.m_pllUsedMarker[0] & BIT_QUERY)
            m_strQuery = rhs.m_strQuery;
    }
    return *this;
}

bool MMdbQueryDef::SMdbQuery::operator==(const MMdbQueryDef::SMdbQuery& rhs) const
{
    if ( this == &rhs ) return true;
    if(m_iMarkerNum != rhs.m_iMarkerNum) return false;
    if(m_iFieldNum != rhs.m_iFieldNum) return false;
    for(int i=0;i<m_iMarkerNum;i++)
    {
        if ( m_pllUsedMarker[i] != rhs.m_pllUsedMarker[i] || m_pllMarker[i] != rhs.m_pllMarker[i] )
        {
            return false;
        }
    }
    if ((m_pllMarker[0]&BIT_FLAG) && !(m_llFlag == rhs.m_llFlag)) return false;
    if ((m_pllMarker[0]&BIT_TABLE_NAME) && !(m_strTableName == rhs.m_strTableName)) return false;
    if ((m_pllMarker[0]&BIT_QUERY) && !(m_strQuery == rhs.m_strQuery)) return false;
    return true;
}

bool MMdbQueryDef::SMdbQuery::operator<(const MMdbQueryDef::SMdbQuery& rhs) const
{
    return !( *this == rhs );
/*
	else
	{
		return m_pComparer->lessThan(this,&rhs);
	}
*/
}

const sdl::CSdlTypeInfo& MMdbQueryDef::SMdbQuery::get_typeInfo() const
{
    return s_cTypeInfo4MMdbQueryDef_SMdbQuery;
}

const sdl::CSdlBasicStructObject::CClassDesc& MMdbQueryDef::SMdbQuery::class_desc() const
{
    static const sdl::CSdlBasicStructObject::CClassDesc cClassDesc(BITS_ALL_MARKER,
        BITS_NOT_NULL_MARKER, BITS_DB_MARKER, IMPORT_TABLE_COUNT, MEMBER_FIELD_COUNT,
        SZ_TYPE_NAME, ARRAY_IMPORT_TABLES, s_MMdbQueryDef_SMdbQuery_MemberTypeInfo,&s_MMdbQueryDef_SMdbQuery_MapMemberTypeInfo);
    return cClassDesc;
}

void MMdbQueryDef::SMdbQuery::Clear()
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

void MMdbQueryDef::SMdbQuery::Clear4Pool()
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

CSdlBasicObject* MMdbQueryDef::SMdbQuery::create_object()
{
    return new MMdbQueryDef::SMdbQuery();
}
static CSdlCreateObjectInitializer s_MMdbQueryDef_SMdbQuery_SdlCreateObjectInitializer("MMdbQueryDef::SMdbQuery", MMdbQueryDef::SMdbQuery::create_object);

const void* MMdbQueryDef::SMdbQuery::get_addressTable(const void* pTable[3]) const
{
    if ( pTable != 0 )
    {
        int i = 0;
        pTable[i++] = &m_llFlag;
        pTable[i++] = &m_strTableName;
        pTable[i++] = &m_strQuery;
    }
    return &m_llFlag;
}
#endif

#if !defined(SDL_SELECTED_API) || defined(SDL_USE_MMDBQUERYDEF_SMDBQUERYLIST)
// list definition for MMdbQueryDef::SMdbQueryList
MMdbQueryDef::SMdbQueryList::SMdbQueryList() : sdl::CSdlBasicListObject(),poolvector<MMdbQueryDef::SMdbQuery>()
{
}
MMdbQueryDef::SMdbQueryList::SMdbQueryList(obb_stream& stream) : sdl::CSdlBasicListObject(),poolvector<MMdbQueryDef::SMdbQuery>()
{
	stream >> *this;
}
void MMdbQueryDef::SMdbQueryList::Clear()
{
	clear();
}

void* MMdbQueryDef::SMdbQueryList::append_item()
{
	;
    return &(*(insert(end(), MMdbQueryDef::SMdbQuery())));
}

void MMdbQueryDef::SMdbQueryList::change_size(const int iNewSize)
{
    //resize(iNewSize > 0 ? iNewSize : 0 );
    resize(iNewSize > 0 ? iNewSize : 0);
   //if(iNewSize > 0) resize(iNewSize);
   //else clear();
}

const void* MMdbQueryDef::SMdbQueryList::get_addrOfFirstItem() const
{
    return size() > 0 ? &(*begin()) : 0;
}

int MMdbQueryDef::SMdbQueryList::get_containerType() const
{
    return LT_POOLVECTOR;
}

int MMdbQueryDef::SMdbQueryList::get_itemSize() const
{
    return sizeof(MMdbQueryDef::SMdbQuery);
}

int MMdbQueryDef::SMdbQueryList::get_itemType() const
{
    return SDL_STRUCT;
}

int MMdbQueryDef::SMdbQueryList::get_size() const
{
    return size();
}

const void* MMdbQueryDef::SMdbQueryList::get(int index) const
{
    return &operator[](index);
}

void* MMdbQueryDef::SMdbQueryList::get(int index)
{
    return &operator[](index);
}

void MMdbQueryDef::SMdbQueryList::Erase(int index)
{
    erase(begin() + index);
}

CSdlBasicObject* MMdbQueryDef::SMdbQueryList::create_object()
{
    return new MMdbQueryDef::SMdbQueryList();
}
static CSdlCreateObjectInitializer s_MMdbQueryDef_SMdbQueryList_SdlCreateObjectInitializer("MMdbQueryDef::SMdbQueryList", MMdbQueryDef::SMdbQueryList::create_object);

static sdl::CSdlTypeInfo s_cTypeInfo4MMdbQueryDef_SMdbQueryList(SDL_LIST, "MMdbQueryDef::SMdbQueryList",
    sdl::CSdlTypeInfo::create_typeDescription(__get_sourceFileName().c_str(),
        __LINE__, s_szCompileDate, s_szCompileTime).c_str(),
    sizeof(MMdbQueryDef::SMdbQueryList), 1, "MMdbQueryDef::SMdbQuery", SDL_STRUCT);
static sdl::CSdlTypeInfoImpl s_cTypeInfoImpl4MMdbQueryDef_SMdbQueryList(s_cTypeInfo4MMdbQueryDef_SMdbQueryList);

const sdl::CSdlTypeInfo& MMdbQueryDef::SMdbQueryList::get_typeInfo() const
{
    return s_cTypeInfo4MMdbQueryDef_SMdbQueryList;
}
#endif

#if !defined(SDL_SELECTED_API) || defined(SDL_USE_MMDBQUERYDEF_SMDBQUERYRETURN)
// struct definition for MMdbQueryDef::SMdbQueryReturn
static sdl::CSdlTypeInfo s_cTypeInfo4MMdbQueryDef_SMdbQueryReturn(SDL_STRUCT, "MMdbQueryDef::SMdbQueryReturn",
    sdl::CSdlTypeInfo::create_typeDescription(__get_sourceFileName().c_str(),
        __LINE__, s_szCompileDate, s_szCompileTime).c_str(),
    sizeof(MMdbQueryDef::SMdbQueryReturn), 1,
    "aistring", SDL_STRING);
static sdl::CSdlTypeInfoImpl s_cTypeInfoImpl4MMdbQueryDef_SMdbQueryReturn(s_cTypeInfo4MMdbQueryDef_SMdbQueryReturn);

static sdl::SSdlMemberTypeInfo s_MMdbQueryDef_SMdbQueryReturn_MemberTypeInfo[1 + 1] =
{
    { SDL_STRING, "RESULT", sizeof(aistring), -1, 0, reinterpret_cast<FuncSdlAssign>(sdl_assignString),I64(0x1),0,"aistring",0},
    { -1, 0, 0, 0, 0, 0 ,0}
};

extern "C" sdl::SSdlMemberTypeAddress get_MMdbQueryDef_SMdbQueryReturn_MemberTypeAddress()
{
    sdl::SSdlMemberTypeAddress Addr;
    Addr.addr = s_MMdbQueryDef_SMdbQueryReturn_MemberTypeInfo;
    Addr.size = 1;
    return Addr;
}
extern "C" const char* get_MMdbQueryDef_SMdbQueryReturn_MemberType_IndexString4Lua()
{
    static char MMdbQueryDef_SMdbQueryReturn_MemberType_IndexString[] = 
"\
local MMdbQueryDef_SMdbQueryReturn_RESULT=0;\n\
";
    return MMdbQueryDef_SMdbQueryReturn_MemberType_IndexString;
}
//static Mapsdl::SSdlMemberTypeInfo map_MMdbQueryDef_SMdbQueryReturn_MapMemberTypeInfo;
//static SMapSSdlMemberTypeInfo s_MMdbQueryDef_SMdbQueryReturn_MapMemberTypeInfo = {map_MMdbQueryDef_SMdbQueryReturn_MapMemberTypeInfo};
static SMapSSdlMemberTypeInfo s_MMdbQueryDef_SMdbQueryReturn_MapMemberTypeInfo;
static CMapSdlStructMemberTypeInitializer s_MapMMdbQueryDef_SMdbQueryReturn(&s_MMdbQueryDef_SMdbQueryReturn_MapMemberTypeInfo,s_MMdbQueryDef_SMdbQueryReturn_MemberTypeInfo,1);
static CSdlStructMemberTypeInitializer s_MMdbQueryDef_SMdbQueryReturn(s_MMdbQueryDef_SMdbQueryReturn_MemberTypeInfo,
    MMdbQueryDef::SMdbQueryReturn());

const uint64 MMdbQueryDef::SMdbQueryReturn::BIT_RESULT = I64(0x1);
const uint64 MMdbQueryDef::SMdbQueryReturn::BITS_ALL_MARKER = I64(0x1);
const uint64 MMdbQueryDef::SMdbQueryReturn::BITS_NOT_NULL_MARKER = I64(0x0);
const uint64 MMdbQueryDef::SMdbQueryReturn::BITS_DB_MARKER = I64(0x0);
const uint64 MMdbQueryDef::SMdbQueryReturn::BITS_NOT_NULL_MARKER_ARR[] = {I64(0x0)};
const uint64 MMdbQueryDef::SMdbQueryReturn::BITS_DB_MARKER_ARR[] = {I64(0x0)};
const int MMdbQueryDef::SMdbQueryReturn::IMPORT_TABLE_COUNT = 0;
const int MMdbQueryDef::SMdbQueryReturn::MEMBER_FIELD_COUNT = 1;
const char* MMdbQueryDef::SMdbQueryReturn::SZ_TYPE_NAME = "MMdbQueryDef::SMdbQueryReturn";
const sdl::SSdlMemberTypeInfo* MMdbQueryDef::SMdbQueryReturn::ARRAY_MEMBER_TYPE_INFO = s_MMdbQueryDef_SMdbQueryReturn_MemberTypeInfo;
const char* MMdbQueryDef::SMdbQueryReturn::ARRAY_IMPORT_TABLES[] = 
{
    0
};

void inline MMdbQueryDef::SMdbQueryReturn::init()
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

MMdbQueryDef::SMdbQueryReturn::SMdbQueryReturn() : sdl::CSdlBasicStructObject(),
    m_strResult()
{
	init();
}

MMdbQueryDef::SMdbQueryReturn::SMdbQueryReturn(obb_stream& stream) : sdl::CSdlBasicStructObject() ,
    m_strResult()
{ 
	init();
	stream >> *this;
}

MMdbQueryDef::SMdbQueryReturn::SMdbQueryReturn(const SMdbQueryReturn& rhs) : sdl::CSdlBasicStructObject(rhs),
    m_strResult()
{ 
    init();
    m_iMarkerNum = rhs.m_iMarkerNum;
    m_iFieldNum = rhs.m_iFieldNum;
    for(int i=0;i<rhs.get_markerNum();i++)
    {
        m_pllUsedMarker[i] = rhs.m_pllUsedMarker[i];
        m_pllMarker[i] = rhs.m_pllMarker[i];
    }
    if (rhs.m_pllUsedMarker[0] & BIT_RESULT)
        m_strResult = rhs.m_strResult;
}

MMdbQueryDef::SMdbQueryReturn::~SMdbQueryReturn()
{ 
}

MMdbQueryDef::SMdbQueryReturn& MMdbQueryDef::SMdbQueryReturn::operator=(const MMdbQueryDef::SMdbQueryReturn& rhs) 
{
    if ( this != &rhs )
    {
        Clear();
        sdl::CSdlBasicStructObject::operator = (rhs);
        m_iMarkerNum = rhs.m_iMarkerNum;
        m_iFieldNum = rhs.m_iFieldNum;
        for(int i=0;i<rhs.get_markerNum();i++)
        {
            m_pllUsedMarker[i] = rhs.m_pllUsedMarker[i];
            m_pllMarker[i] = rhs.m_pllMarker[i];
        }
        if (rhs.m_pllUsedMarker[0] & BIT_RESULT)
            m_strResult = rhs.m_strResult;
    }
    return *this;
}

bool MMdbQueryDef::SMdbQueryReturn::operator==(const MMdbQueryDef::SMdbQueryReturn& rhs) const
{
    if ( this == &rhs ) return true;
    if(m_iMarkerNum != rhs.m_iMarkerNum) return false;
    if(m_iFieldNum != rhs.m_iFieldNum) return false;
    for(int i=0;i<m_iMarkerNum;i++)
    {
        if ( m_pllUsedMarker[i] != rhs.m_pllUsedMarker[i] || m_pllMarker[i] != rhs.m_pllMarker[i] )
        {
            return false;
        }
    }
    if ((m_pllMarker[0]&BIT_RESULT) && !(m_strResult == rhs.m_strResult)) return false;
    return true;
}

bool MMdbQueryDef::SMdbQueryReturn::operator<(const MMdbQueryDef::SMdbQueryReturn& rhs) const
{
    return !( *this == rhs );
/*
	else
	{
		return m_pComparer->lessThan(this,&rhs);
	}
*/
}

const sdl::CSdlTypeInfo& MMdbQueryDef::SMdbQueryReturn::get_typeInfo() const
{
    return s_cTypeInfo4MMdbQueryDef_SMdbQueryReturn;
}

const sdl::CSdlBasicStructObject::CClassDesc& MMdbQueryDef::SMdbQueryReturn::class_desc() const
{
    static const sdl::CSdlBasicStructObject::CClassDesc cClassDesc(BITS_ALL_MARKER,
        BITS_NOT_NULL_MARKER, BITS_DB_MARKER, IMPORT_TABLE_COUNT, MEMBER_FIELD_COUNT,
        SZ_TYPE_NAME, ARRAY_IMPORT_TABLES, s_MMdbQueryDef_SMdbQueryReturn_MemberTypeInfo,&s_MMdbQueryDef_SMdbQueryReturn_MapMemberTypeInfo);
    return cClassDesc;
}

void MMdbQueryDef::SMdbQueryReturn::Clear()
{
	for(int i=0;i<1;i++)
	{
		m_arrllMarker[i] = 0;
		m_arrllUsedMarker[i] = 0;
	}
    m_strResult.clear();
}

void MMdbQueryDef::SMdbQueryReturn::Clear4Pool()
{
	for(int i=0;i<1;i++)
	{
		m_arrllMarker[i] = 0;
		m_arrllUsedMarker[i] = 0;
	}
    m_strResult.clear();
}

CSdlBasicObject* MMdbQueryDef::SMdbQueryReturn::create_object()
{
    return new MMdbQueryDef::SMdbQueryReturn();
}
static CSdlCreateObjectInitializer s_MMdbQueryDef_SMdbQueryReturn_SdlCreateObjectInitializer("MMdbQueryDef::SMdbQueryReturn", MMdbQueryDef::SMdbQueryReturn::create_object);

const void* MMdbQueryDef::SMdbQueryReturn::get_addressTable(const void* pTable[1]) const
{
    if ( pTable != 0 )
    {
        int i = 0;
        pTable[i++] = &m_strResult;
    }
    return &m_strResult;
}
#endif

#if !defined(SDL_SELECTED_API) || defined(SDL_USE_MMDBQUERYDEF_SMDBQUERYRETURNLIST)
// list definition for MMdbQueryDef::SMdbQueryReturnList
MMdbQueryDef::SMdbQueryReturnList::SMdbQueryReturnList() : sdl::CSdlBasicListObject(),poolvector<MMdbQueryDef::SMdbQueryReturn>()
{
}
MMdbQueryDef::SMdbQueryReturnList::SMdbQueryReturnList(obb_stream& stream) : sdl::CSdlBasicListObject(),poolvector<MMdbQueryDef::SMdbQueryReturn>()
{
	stream >> *this;
}
void MMdbQueryDef::SMdbQueryReturnList::Clear()
{
	clear();
}

void* MMdbQueryDef::SMdbQueryReturnList::append_item()
{
	;
    return &(*(insert(end(), MMdbQueryDef::SMdbQueryReturn())));
}

void MMdbQueryDef::SMdbQueryReturnList::change_size(const int iNewSize)
{
    //resize(iNewSize > 0 ? iNewSize : 0 );
    resize(iNewSize > 0 ? iNewSize : 0);
   //if(iNewSize > 0) resize(iNewSize);
   //else clear();
}

const void* MMdbQueryDef::SMdbQueryReturnList::get_addrOfFirstItem() const
{
    return size() > 0 ? &(*begin()) : 0;
}

int MMdbQueryDef::SMdbQueryReturnList::get_containerType() const
{
    return LT_POOLVECTOR;
}

int MMdbQueryDef::SMdbQueryReturnList::get_itemSize() const
{
    return sizeof(MMdbQueryDef::SMdbQueryReturn);
}

int MMdbQueryDef::SMdbQueryReturnList::get_itemType() const
{
    return SDL_STRUCT;
}

int MMdbQueryDef::SMdbQueryReturnList::get_size() const
{
    return size();
}

const void* MMdbQueryDef::SMdbQueryReturnList::get(int index) const
{
    return &operator[](index);
}

void* MMdbQueryDef::SMdbQueryReturnList::get(int index)
{
    return &operator[](index);
}

void MMdbQueryDef::SMdbQueryReturnList::Erase(int index)
{
    erase(begin() + index);
}

CSdlBasicObject* MMdbQueryDef::SMdbQueryReturnList::create_object()
{
    return new MMdbQueryDef::SMdbQueryReturnList();
}
static CSdlCreateObjectInitializer s_MMdbQueryDef_SMdbQueryReturnList_SdlCreateObjectInitializer("MMdbQueryDef::SMdbQueryReturnList", MMdbQueryDef::SMdbQueryReturnList::create_object);

static sdl::CSdlTypeInfo s_cTypeInfo4MMdbQueryDef_SMdbQueryReturnList(SDL_LIST, "MMdbQueryDef::SMdbQueryReturnList",
    sdl::CSdlTypeInfo::create_typeDescription(__get_sourceFileName().c_str(),
        __LINE__, s_szCompileDate, s_szCompileTime).c_str(),
    sizeof(MMdbQueryDef::SMdbQueryReturnList), 1, "MMdbQueryDef::SMdbQueryReturn", SDL_STRUCT);
static sdl::CSdlTypeInfoImpl s_cTypeInfoImpl4MMdbQueryDef_SMdbQueryReturnList(s_cTypeInfo4MMdbQueryDef_SMdbQueryReturnList);

const sdl::CSdlTypeInfo& MMdbQueryDef::SMdbQueryReturnList::get_typeInfo() const
{
    return s_cTypeInfo4MMdbQueryDef_SMdbQueryReturnList;
}
#endif

#if !defined(SDL_SELECTED_API) || defined(SDL_USE_MMDBQUERYDEF_SMDBSECLOGIN)
// struct definition for MMdbQueryDef::SMdbSecLogin
static sdl::CSdlTypeInfo s_cTypeInfo4MMdbQueryDef_SMdbSecLogin(SDL_STRUCT, "MMdbQueryDef::SMdbSecLogin",
    sdl::CSdlTypeInfo::create_typeDescription(__get_sourceFileName().c_str(),
        __LINE__, s_szCompileDate, s_szCompileTime).c_str(),
    sizeof(MMdbQueryDef::SMdbSecLogin), 2,
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
//static Mapsdl::SSdlMemberTypeInfo map_MMdbQueryDef_SMdbSecLogin_MapMemberTypeInfo;
//static SMapSSdlMemberTypeInfo s_MMdbQueryDef_SMdbSecLogin_MapMemberTypeInfo = {map_MMdbQueryDef_SMdbSecLogin_MapMemberTypeInfo};
static SMapSSdlMemberTypeInfo s_MMdbQueryDef_SMdbSecLogin_MapMemberTypeInfo;
static CMapSdlStructMemberTypeInitializer s_MapMMdbQueryDef_SMdbSecLogin(&s_MMdbQueryDef_SMdbSecLogin_MapMemberTypeInfo,s_MMdbQueryDef_SMdbSecLogin_MemberTypeInfo,2);
static CSdlStructMemberTypeInitializer s_MMdbQueryDef_SMdbSecLogin(s_MMdbQueryDef_SMdbSecLogin_MemberTypeInfo,
    MMdbQueryDef::SMdbSecLogin());

const uint64 MMdbQueryDef::SMdbSecLogin::BIT_USER_NAME = I64(0x1);
const uint64 MMdbQueryDef::SMdbSecLogin::BIT_PASSWD = I64(0x2);
const uint64 MMdbQueryDef::SMdbSecLogin::BITS_ALL_MARKER = I64(0x3);
const uint64 MMdbQueryDef::SMdbSecLogin::BITS_NOT_NULL_MARKER = I64(0x0);
const uint64 MMdbQueryDef::SMdbSecLogin::BITS_DB_MARKER = I64(0x0);
const uint64 MMdbQueryDef::SMdbSecLogin::BITS_NOT_NULL_MARKER_ARR[] = {I64(0x0)};
const uint64 MMdbQueryDef::SMdbSecLogin::BITS_DB_MARKER_ARR[] = {I64(0x0)};
const int MMdbQueryDef::SMdbSecLogin::IMPORT_TABLE_COUNT = 0;
const int MMdbQueryDef::SMdbSecLogin::MEMBER_FIELD_COUNT = 2;
const char* MMdbQueryDef::SMdbSecLogin::SZ_TYPE_NAME = "MMdbQueryDef::SMdbSecLogin";
const sdl::SSdlMemberTypeInfo* MMdbQueryDef::SMdbSecLogin::ARRAY_MEMBER_TYPE_INFO = s_MMdbQueryDef_SMdbSecLogin_MemberTypeInfo;
const char* MMdbQueryDef::SMdbSecLogin::ARRAY_IMPORT_TABLES[] = 
{
    0
};

void inline MMdbQueryDef::SMdbSecLogin::init()
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

MMdbQueryDef::SMdbSecLogin::SMdbSecLogin() : sdl::CSdlBasicStructObject(),
    m_strUserName(),
    m_strPasswd()
{
	init();
}

MMdbQueryDef::SMdbSecLogin::SMdbSecLogin(obb_stream& stream) : sdl::CSdlBasicStructObject() ,
    m_strUserName(),
    m_strPasswd()
{ 
	init();
	stream >> *this;
}

MMdbQueryDef::SMdbSecLogin::SMdbSecLogin(const SMdbSecLogin& rhs) : sdl::CSdlBasicStructObject(rhs),
    m_strUserName(),
    m_strPasswd()
{ 
    init();
    m_iMarkerNum = rhs.m_iMarkerNum;
    m_iFieldNum = rhs.m_iFieldNum;
    for(int i=0;i<rhs.get_markerNum();i++)
    {
        m_pllUsedMarker[i] = rhs.m_pllUsedMarker[i];
        m_pllMarker[i] = rhs.m_pllMarker[i];
    }
    if (rhs.m_pllUsedMarker[0] & BIT_USER_NAME)
        m_strUserName = rhs.m_strUserName;
    if (rhs.m_pllUsedMarker[0] & BIT_PASSWD)
        m_strPasswd = rhs.m_strPasswd;
}

MMdbQueryDef::SMdbSecLogin::~SMdbSecLogin()
{ 
}

MMdbQueryDef::SMdbSecLogin& MMdbQueryDef::SMdbSecLogin::operator=(const MMdbQueryDef::SMdbSecLogin& rhs) 
{
    if ( this != &rhs )
    {
        Clear();
        sdl::CSdlBasicStructObject::operator = (rhs);
        m_iMarkerNum = rhs.m_iMarkerNum;
        m_iFieldNum = rhs.m_iFieldNum;
        for(int i=0;i<rhs.get_markerNum();i++)
        {
            m_pllUsedMarker[i] = rhs.m_pllUsedMarker[i];
            m_pllMarker[i] = rhs.m_pllMarker[i];
        }
        if (rhs.m_pllUsedMarker[0] & BIT_USER_NAME)
            m_strUserName = rhs.m_strUserName;
        if (rhs.m_pllUsedMarker[0] & BIT_PASSWD)
            m_strPasswd = rhs.m_strPasswd;
    }
    return *this;
}

bool MMdbQueryDef::SMdbSecLogin::operator==(const MMdbQueryDef::SMdbSecLogin& rhs) const
{
    if ( this == &rhs ) return true;
    if(m_iMarkerNum != rhs.m_iMarkerNum) return false;
    if(m_iFieldNum != rhs.m_iFieldNum) return false;
    for(int i=0;i<m_iMarkerNum;i++)
    {
        if ( m_pllUsedMarker[i] != rhs.m_pllUsedMarker[i] || m_pllMarker[i] != rhs.m_pllMarker[i] )
        {
            return false;
        }
    }
    if ((m_pllMarker[0]&BIT_USER_NAME) && !(m_strUserName == rhs.m_strUserName)) return false;
    if ((m_pllMarker[0]&BIT_PASSWD) && !(m_strPasswd == rhs.m_strPasswd)) return false;
    return true;
}

bool MMdbQueryDef::SMdbSecLogin::operator<(const MMdbQueryDef::SMdbSecLogin& rhs) const
{
    return !( *this == rhs );
/*
	else
	{
		return m_pComparer->lessThan(this,&rhs);
	}
*/
}

const sdl::CSdlTypeInfo& MMdbQueryDef::SMdbSecLogin::get_typeInfo() const
{
    return s_cTypeInfo4MMdbQueryDef_SMdbSecLogin;
}

const sdl::CSdlBasicStructObject::CClassDesc& MMdbQueryDef::SMdbSecLogin::class_desc() const
{
    static const sdl::CSdlBasicStructObject::CClassDesc cClassDesc(BITS_ALL_MARKER,
        BITS_NOT_NULL_MARKER, BITS_DB_MARKER, IMPORT_TABLE_COUNT, MEMBER_FIELD_COUNT,
        SZ_TYPE_NAME, ARRAY_IMPORT_TABLES, s_MMdbQueryDef_SMdbSecLogin_MemberTypeInfo,&s_MMdbQueryDef_SMdbSecLogin_MapMemberTypeInfo);
    return cClassDesc;
}

void MMdbQueryDef::SMdbSecLogin::Clear()
{
	for(int i=0;i<1;i++)
	{
		m_arrllMarker[i] = 0;
		m_arrllUsedMarker[i] = 0;
	}
    m_strUserName.clear();
    m_strPasswd.clear();
}

void MMdbQueryDef::SMdbSecLogin::Clear4Pool()
{
	for(int i=0;i<1;i++)
	{
		m_arrllMarker[i] = 0;
		m_arrllUsedMarker[i] = 0;
	}
    m_strUserName.clear();
    m_strPasswd.clear();
}

CSdlBasicObject* MMdbQueryDef::SMdbSecLogin::create_object()
{
    return new MMdbQueryDef::SMdbSecLogin();
}
static CSdlCreateObjectInitializer s_MMdbQueryDef_SMdbSecLogin_SdlCreateObjectInitializer("MMdbQueryDef::SMdbSecLogin", MMdbQueryDef::SMdbSecLogin::create_object);

const void* MMdbQueryDef::SMdbSecLogin::get_addressTable(const void* pTable[2]) const
{
    if ( pTable != 0 )
    {
        int i = 0;
        pTable[i++] = &m_strUserName;
        pTable[i++] = &m_strPasswd;
    }
    return &m_strUserName;
}
#endif

#if !defined(SDL_SELECTED_API) || defined(SDL_USE_MMDBQUERYDEF_SMDBSECLOGINLIST)
// list definition for MMdbQueryDef::SMdbSecLoginList
MMdbQueryDef::SMdbSecLoginList::SMdbSecLoginList() : sdl::CSdlBasicListObject(),poolvector<MMdbQueryDef::SMdbSecLogin>()
{
}
MMdbQueryDef::SMdbSecLoginList::SMdbSecLoginList(obb_stream& stream) : sdl::CSdlBasicListObject(),poolvector<MMdbQueryDef::SMdbSecLogin>()
{
	stream >> *this;
}
void MMdbQueryDef::SMdbSecLoginList::Clear()
{
	clear();
}

void* MMdbQueryDef::SMdbSecLoginList::append_item()
{
	;
    return &(*(insert(end(), MMdbQueryDef::SMdbSecLogin())));
}

void MMdbQueryDef::SMdbSecLoginList::change_size(const int iNewSize)
{
    //resize(iNewSize > 0 ? iNewSize : 0 );
    resize(iNewSize > 0 ? iNewSize : 0);
   //if(iNewSize > 0) resize(iNewSize);
   //else clear();
}

const void* MMdbQueryDef::SMdbSecLoginList::get_addrOfFirstItem() const
{
    return size() > 0 ? &(*begin()) : 0;
}

int MMdbQueryDef::SMdbSecLoginList::get_containerType() const
{
    return LT_POOLVECTOR;
}

int MMdbQueryDef::SMdbSecLoginList::get_itemSize() const
{
    return sizeof(MMdbQueryDef::SMdbSecLogin);
}

int MMdbQueryDef::SMdbSecLoginList::get_itemType() const
{
    return SDL_STRUCT;
}

int MMdbQueryDef::SMdbSecLoginList::get_size() const
{
    return size();
}

const void* MMdbQueryDef::SMdbSecLoginList::get(int index) const
{
    return &operator[](index);
}

void* MMdbQueryDef::SMdbSecLoginList::get(int index)
{
    return &operator[](index);
}

void MMdbQueryDef::SMdbSecLoginList::Erase(int index)
{
    erase(begin() + index);
}

CSdlBasicObject* MMdbQueryDef::SMdbSecLoginList::create_object()
{
    return new MMdbQueryDef::SMdbSecLoginList();
}
static CSdlCreateObjectInitializer s_MMdbQueryDef_SMdbSecLoginList_SdlCreateObjectInitializer("MMdbQueryDef::SMdbSecLoginList", MMdbQueryDef::SMdbSecLoginList::create_object);

static sdl::CSdlTypeInfo s_cTypeInfo4MMdbQueryDef_SMdbSecLoginList(SDL_LIST, "MMdbQueryDef::SMdbSecLoginList",
    sdl::CSdlTypeInfo::create_typeDescription(__get_sourceFileName().c_str(),
        __LINE__, s_szCompileDate, s_szCompileTime).c_str(),
    sizeof(MMdbQueryDef::SMdbSecLoginList), 1, "MMdbQueryDef::SMdbSecLogin", SDL_STRUCT);
static sdl::CSdlTypeInfoImpl s_cTypeInfoImpl4MMdbQueryDef_SMdbSecLoginList(s_cTypeInfo4MMdbQueryDef_SMdbSecLoginList);

const sdl::CSdlTypeInfo& MMdbQueryDef::SMdbSecLoginList::get_typeInfo() const
{
    return s_cTypeInfo4MMdbQueryDef_SMdbSecLoginList;
}
#endif

#if !defined(SDL_SELECTED_API) || defined(SDL_USE_MMDBQUERYDEF_SMDBSECLOGINRETURN)
// struct definition for MMdbQueryDef::SMdbSecLoginReturn
static sdl::CSdlTypeInfo s_cTypeInfo4MMdbQueryDef_SMdbSecLoginReturn(SDL_STRUCT, "MMdbQueryDef::SMdbSecLoginReturn",
    sdl::CSdlTypeInfo::create_typeDescription(__get_sourceFileName().c_str(),
        __LINE__, s_szCompileDate, s_szCompileTime).c_str(),
    sizeof(MMdbQueryDef::SMdbSecLoginReturn), 2,
    "int32", SDL_INT32,
    "aistring", SDL_STRING);
static sdl::CSdlTypeInfoImpl s_cTypeInfoImpl4MMdbQueryDef_SMdbSecLoginReturn(s_cTypeInfo4MMdbQueryDef_SMdbSecLoginReturn);

static sdl::SSdlMemberTypeInfo s_MMdbQueryDef_SMdbSecLoginReturn_MemberTypeInfo[2 + 1] =
{
    { SDL_INT32, "LOGIN_FLAG", sizeof(int32), -1, 0, reinterpret_cast<FuncSdlAssign>(sdl_assignInt32),I64(0x1),0,"int32",0},
    { SDL_STRING, "MSG", sizeof(aistring), -1, 0, reinterpret_cast<FuncSdlAssign>(sdl_assignString),I64(0x2),1,"aistring",0},
    { -1, 0, 0, 0, 0, 0 ,0}
};

extern "C" sdl::SSdlMemberTypeAddress get_MMdbQueryDef_SMdbSecLoginReturn_MemberTypeAddress()
{
    sdl::SSdlMemberTypeAddress Addr;
    Addr.addr = s_MMdbQueryDef_SMdbSecLoginReturn_MemberTypeInfo;
    Addr.size = 2;
    return Addr;
}
extern "C" const char* get_MMdbQueryDef_SMdbSecLoginReturn_MemberType_IndexString4Lua()
{
    static char MMdbQueryDef_SMdbSecLoginReturn_MemberType_IndexString[] = 
"\
local MMdbQueryDef_SMdbSecLoginReturn_LOGIN_FLAG=0;\n\
local MMdbQueryDef_SMdbSecLoginReturn_MSG=1;\n\
";
    return MMdbQueryDef_SMdbSecLoginReturn_MemberType_IndexString;
}
//static Mapsdl::SSdlMemberTypeInfo map_MMdbQueryDef_SMdbSecLoginReturn_MapMemberTypeInfo;
//static SMapSSdlMemberTypeInfo s_MMdbQueryDef_SMdbSecLoginReturn_MapMemberTypeInfo = {map_MMdbQueryDef_SMdbSecLoginReturn_MapMemberTypeInfo};
static SMapSSdlMemberTypeInfo s_MMdbQueryDef_SMdbSecLoginReturn_MapMemberTypeInfo;
static CMapSdlStructMemberTypeInitializer s_MapMMdbQueryDef_SMdbSecLoginReturn(&s_MMdbQueryDef_SMdbSecLoginReturn_MapMemberTypeInfo,s_MMdbQueryDef_SMdbSecLoginReturn_MemberTypeInfo,2);
static CSdlStructMemberTypeInitializer s_MMdbQueryDef_SMdbSecLoginReturn(s_MMdbQueryDef_SMdbSecLoginReturn_MemberTypeInfo,
    MMdbQueryDef::SMdbSecLoginReturn());

const uint64 MMdbQueryDef::SMdbSecLoginReturn::BIT_LOGIN_FLAG = I64(0x1);
const uint64 MMdbQueryDef::SMdbSecLoginReturn::BIT_MSG = I64(0x2);
const uint64 MMdbQueryDef::SMdbSecLoginReturn::BITS_ALL_MARKER = I64(0x3);
const uint64 MMdbQueryDef::SMdbSecLoginReturn::BITS_NOT_NULL_MARKER = I64(0x0);
const uint64 MMdbQueryDef::SMdbSecLoginReturn::BITS_DB_MARKER = I64(0x0);
const uint64 MMdbQueryDef::SMdbSecLoginReturn::BITS_NOT_NULL_MARKER_ARR[] = {I64(0x0)};
const uint64 MMdbQueryDef::SMdbSecLoginReturn::BITS_DB_MARKER_ARR[] = {I64(0x0)};
const int MMdbQueryDef::SMdbSecLoginReturn::IMPORT_TABLE_COUNT = 0;
const int MMdbQueryDef::SMdbSecLoginReturn::MEMBER_FIELD_COUNT = 2;
const char* MMdbQueryDef::SMdbSecLoginReturn::SZ_TYPE_NAME = "MMdbQueryDef::SMdbSecLoginReturn";
const sdl::SSdlMemberTypeInfo* MMdbQueryDef::SMdbSecLoginReturn::ARRAY_MEMBER_TYPE_INFO = s_MMdbQueryDef_SMdbSecLoginReturn_MemberTypeInfo;
const char* MMdbQueryDef::SMdbSecLoginReturn::ARRAY_IMPORT_TABLES[] = 
{
    0
};

void inline MMdbQueryDef::SMdbSecLoginReturn::init()
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

MMdbQueryDef::SMdbSecLoginReturn::SMdbSecLoginReturn() : sdl::CSdlBasicStructObject(),
    m_iLoginFlag(0),
    m_strMsg()
{
	init();
}

MMdbQueryDef::SMdbSecLoginReturn::SMdbSecLoginReturn(obb_stream& stream) : sdl::CSdlBasicStructObject() ,
    m_iLoginFlag(0),
    m_strMsg()
{ 
	init();
	stream >> *this;
}

MMdbQueryDef::SMdbSecLoginReturn::SMdbSecLoginReturn(const SMdbSecLoginReturn& rhs) : sdl::CSdlBasicStructObject(rhs),
    m_iLoginFlag(0),
    m_strMsg()
{ 
    init();
    m_iMarkerNum = rhs.m_iMarkerNum;
    m_iFieldNum = rhs.m_iFieldNum;
    for(int i=0;i<rhs.get_markerNum();i++)
    {
        m_pllUsedMarker[i] = rhs.m_pllUsedMarker[i];
        m_pllMarker[i] = rhs.m_pllMarker[i];
    }
    if (rhs.m_pllUsedMarker[0] & BIT_LOGIN_FLAG)
        m_iLoginFlag = rhs.m_iLoginFlag;
    if (rhs.m_pllUsedMarker[0] & BIT_MSG)
        m_strMsg = rhs.m_strMsg;
}

MMdbQueryDef::SMdbSecLoginReturn::~SMdbSecLoginReturn()
{ 
}

MMdbQueryDef::SMdbSecLoginReturn& MMdbQueryDef::SMdbSecLoginReturn::operator=(const MMdbQueryDef::SMdbSecLoginReturn& rhs) 
{
    if ( this != &rhs )
    {
        Clear();
        sdl::CSdlBasicStructObject::operator = (rhs);
        m_iMarkerNum = rhs.m_iMarkerNum;
        m_iFieldNum = rhs.m_iFieldNum;
        for(int i=0;i<rhs.get_markerNum();i++)
        {
            m_pllUsedMarker[i] = rhs.m_pllUsedMarker[i];
            m_pllMarker[i] = rhs.m_pllMarker[i];
        }
        if (rhs.m_pllUsedMarker[0] & BIT_LOGIN_FLAG)
            m_iLoginFlag = rhs.m_iLoginFlag;
        if (rhs.m_pllUsedMarker[0] & BIT_MSG)
            m_strMsg = rhs.m_strMsg;
    }
    return *this;
}

bool MMdbQueryDef::SMdbSecLoginReturn::operator==(const MMdbQueryDef::SMdbSecLoginReturn& rhs) const
{
    if ( this == &rhs ) return true;
    if(m_iMarkerNum != rhs.m_iMarkerNum) return false;
    if(m_iFieldNum != rhs.m_iFieldNum) return false;
    for(int i=0;i<m_iMarkerNum;i++)
    {
        if ( m_pllUsedMarker[i] != rhs.m_pllUsedMarker[i] || m_pllMarker[i] != rhs.m_pllMarker[i] )
        {
            return false;
        }
    }
    if ((m_pllMarker[0]&BIT_LOGIN_FLAG) && !(m_iLoginFlag == rhs.m_iLoginFlag)) return false;
    if ((m_pllMarker[0]&BIT_MSG) && !(m_strMsg == rhs.m_strMsg)) return false;
    return true;
}

bool MMdbQueryDef::SMdbSecLoginReturn::operator<(const MMdbQueryDef::SMdbSecLoginReturn& rhs) const
{
    return !( *this == rhs );
/*
	else
	{
		return m_pComparer->lessThan(this,&rhs);
	}
*/
}

const sdl::CSdlTypeInfo& MMdbQueryDef::SMdbSecLoginReturn::get_typeInfo() const
{
    return s_cTypeInfo4MMdbQueryDef_SMdbSecLoginReturn;
}

const sdl::CSdlBasicStructObject::CClassDesc& MMdbQueryDef::SMdbSecLoginReturn::class_desc() const
{
    static const sdl::CSdlBasicStructObject::CClassDesc cClassDesc(BITS_ALL_MARKER,
        BITS_NOT_NULL_MARKER, BITS_DB_MARKER, IMPORT_TABLE_COUNT, MEMBER_FIELD_COUNT,
        SZ_TYPE_NAME, ARRAY_IMPORT_TABLES, s_MMdbQueryDef_SMdbSecLoginReturn_MemberTypeInfo,&s_MMdbQueryDef_SMdbSecLoginReturn_MapMemberTypeInfo);
    return cClassDesc;
}

void MMdbQueryDef::SMdbSecLoginReturn::Clear()
{
	for(int i=0;i<1;i++)
	{
		m_arrllMarker[i] = 0;
		m_arrllUsedMarker[i] = 0;
	}
    m_iLoginFlag = 0;
    m_strMsg.clear();
}

void MMdbQueryDef::SMdbSecLoginReturn::Clear4Pool()
{
	for(int i=0;i<1;i++)
	{
		m_arrllMarker[i] = 0;
		m_arrllUsedMarker[i] = 0;
	}
    m_iLoginFlag = 0;
    m_strMsg.clear();
}

CSdlBasicObject* MMdbQueryDef::SMdbSecLoginReturn::create_object()
{
    return new MMdbQueryDef::SMdbSecLoginReturn();
}
static CSdlCreateObjectInitializer s_MMdbQueryDef_SMdbSecLoginReturn_SdlCreateObjectInitializer("MMdbQueryDef::SMdbSecLoginReturn", MMdbQueryDef::SMdbSecLoginReturn::create_object);

const void* MMdbQueryDef::SMdbSecLoginReturn::get_addressTable(const void* pTable[2]) const
{
    if ( pTable != 0 )
    {
        int i = 0;
        pTable[i++] = &m_iLoginFlag;
        pTable[i++] = &m_strMsg;
    }
    return &m_iLoginFlag;
}
#endif

#if !defined(SDL_SELECTED_API) || defined(SDL_USE_MMDBQUERYDEF_SMDBSECLOGINRETURNLIST)
// list definition for MMdbQueryDef::SMdbSecLoginReturnList
MMdbQueryDef::SMdbSecLoginReturnList::SMdbSecLoginReturnList() : sdl::CSdlBasicListObject(),poolvector<MMdbQueryDef::SMdbSecLoginReturn>()
{
}
MMdbQueryDef::SMdbSecLoginReturnList::SMdbSecLoginReturnList(obb_stream& stream) : sdl::CSdlBasicListObject(),poolvector<MMdbQueryDef::SMdbSecLoginReturn>()
{
	stream >> *this;
}
void MMdbQueryDef::SMdbSecLoginReturnList::Clear()
{
	clear();
}

void* MMdbQueryDef::SMdbSecLoginReturnList::append_item()
{
	;
    return &(*(insert(end(), MMdbQueryDef::SMdbSecLoginReturn())));
}

void MMdbQueryDef::SMdbSecLoginReturnList::change_size(const int iNewSize)
{
    //resize(iNewSize > 0 ? iNewSize : 0 );
    resize(iNewSize > 0 ? iNewSize : 0);
   //if(iNewSize > 0) resize(iNewSize);
   //else clear();
}

const void* MMdbQueryDef::SMdbSecLoginReturnList::get_addrOfFirstItem() const
{
    return size() > 0 ? &(*begin()) : 0;
}

int MMdbQueryDef::SMdbSecLoginReturnList::get_containerType() const
{
    return LT_POOLVECTOR;
}

int MMdbQueryDef::SMdbSecLoginReturnList::get_itemSize() const
{
    return sizeof(MMdbQueryDef::SMdbSecLoginReturn);
}

int MMdbQueryDef::SMdbSecLoginReturnList::get_itemType() const
{
    return SDL_STRUCT;
}

int MMdbQueryDef::SMdbSecLoginReturnList::get_size() const
{
    return size();
}

const void* MMdbQueryDef::SMdbSecLoginReturnList::get(int index) const
{
    return &operator[](index);
}

void* MMdbQueryDef::SMdbSecLoginReturnList::get(int index)
{
    return &operator[](index);
}

void MMdbQueryDef::SMdbSecLoginReturnList::Erase(int index)
{
    erase(begin() + index);
}

CSdlBasicObject* MMdbQueryDef::SMdbSecLoginReturnList::create_object()
{
    return new MMdbQueryDef::SMdbSecLoginReturnList();
}
static CSdlCreateObjectInitializer s_MMdbQueryDef_SMdbSecLoginReturnList_SdlCreateObjectInitializer("MMdbQueryDef::SMdbSecLoginReturnList", MMdbQueryDef::SMdbSecLoginReturnList::create_object);

static sdl::CSdlTypeInfo s_cTypeInfo4MMdbQueryDef_SMdbSecLoginReturnList(SDL_LIST, "MMdbQueryDef::SMdbSecLoginReturnList",
    sdl::CSdlTypeInfo::create_typeDescription(__get_sourceFileName().c_str(),
        __LINE__, s_szCompileDate, s_szCompileTime).c_str(),
    sizeof(MMdbQueryDef::SMdbSecLoginReturnList), 1, "MMdbQueryDef::SMdbSecLoginReturn", SDL_STRUCT);
static sdl::CSdlTypeInfoImpl s_cTypeInfoImpl4MMdbQueryDef_SMdbSecLoginReturnList(s_cTypeInfo4MMdbQueryDef_SMdbSecLoginReturnList);

const sdl::CSdlTypeInfo& MMdbQueryDef::SMdbSecLoginReturnList::get_typeInfo() const
{
    return s_cTypeInfo4MMdbQueryDef_SMdbSecLoginReturnList;
}
#endif

