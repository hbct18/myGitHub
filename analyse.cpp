#include <iostream>

//socknotify.h
class CNotify
{
public:
    enum { DATA_CONNECTION = 0, FRONT_CONNECTION, BACK_CONNECTION };

    enum
	{
		NOTIFY_LEN = 12,
		RESERVE_LEN = 16,
		DATAOFF_LEN = 4,
		STACK_NOTIFY_SIZE = 5120
	};
    // 构造函数
    CNotify(int nType, int nLen, int nBlock = 0)
	{
		m_nType = nType;
		m_nLen = nLen;
		m_nBlock = nBlock;
		m_nSize = STACK_NOTIFY_SIZE;
		m_pData = m_cData;
		resize( nLen);
	}

    int	resize(int nLen)
	{ 
		int nSize = nLen + RESERVE_LEN;
		if( m_nSize < nSize)
		{
			if (nSize > STACK_NOTIFY_SIZE)
			{
				if( m_pData != m_cData) 
				{
					delete[] m_pData;
				}
				m_nLen = nLen;
				m_nSize = nSize;
				m_pData = new char[m_nSize];
			}
			else
			{
				m_nLen = nLen;
				m_nSize = STACK_NOTIFY_SIZE;
			}
		}
		m_nLen = nLen;
		return nLen;
	}

    template<class TYPE>
	char*	get_data(TYPE* p)
	{
		TYPE* pType = (TYPE*)(m_pData + RESERVE_LEN);
#ifdef NEED_NET_TRANS
		pType->ntoh(m_nLen);
#endif
		return m_pData + RESERVE_LEN;
	}    

private:
	int	m_nType;
	int	m_nLen;		//message length
	int	m_nBlock;
	int	m_nSize;	//memory allocate size
	char*	m_pData;
	char m_cData[STACK_NOTIFY_SIZE];  // If notify length less than STACK_NOTIFY_SIZE, m_pData point to m_cData
};

//ratms_manage_client.h
class CQryFreeResClientReturn 
{
public:
	long	m_nNumber;	//CFreeResClientDetail个数
	
BEGIN_SOCK_PKG_DESC
	PKG_SOCK_FIELD(m_nNumber)
	PKG_SOCK_FIELD_LIST(m_nNumber, CFreeResClientDetail)
END_SOCK_PKG_DESC
	
public:
	CQryFreeResClientReturn()	{ memset( (void*) this, 0, sizeof( *this ) ); }
};

// 需求
void query_freeres() {
    printf("Query ServID, All item num");
}

// 需求
void query_ratingAddedUp() {
    printf("Query ServID, All item num");
}

void query_limitApportInfo() {
    //
}

void query_BudgetInfo() {
    //
}

// 需求
void query_itemAddedUp() {
    //
}

void deduct_freeres() {} //2

void update_freeres() {} //2