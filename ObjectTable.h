#pragma once

const long m_dwMaxObjectCount = 500;

template<class T> class CObjectTable  
{
public:
	CObjectTable(){};
	virtual ~CObjectTable(){};

protected:

	static long m_dwClassTableClasses[m_dwMaxObjectCount]; //Initialized below
	static long m_dwClassTableIdents[m_dwMaxObjectCount+1];

public:

	static void AddToClassTable(T* pClass, long dwIdent)
	{
		if (pClass == NULL)
			return;

		if (m_dwClassTableClasses[0] == 0)
		{
			//First instanciation
			m_dwClassTableIdents[m_dwMaxObjectCount] = 0;
		}

		long dwClass = (long) pClass;

		m_dwClassTableClasses[(m_dwClassTableIdents[m_dwMaxObjectCount])] = dwClass;
		m_dwClassTableIdents[(m_dwClassTableIdents[m_dwMaxObjectCount])] = dwIdent;

		m_dwClassTableIdents[m_dwMaxObjectCount] = m_dwClassTableIdents[m_dwMaxObjectCount] + 1;
	}

	static T* GetClassFromClassTable(long idClass)
	{
		long idCount = m_dwClassTableIdents[m_dwMaxObjectCount];
		for (int i=0; i<idCount;i++)
		{
			if (m_dwClassTableIdents[i] == idClass)
			{
				return ((T*)m_dwClassTableClasses[i]);
			}
		}

		return NULL;
	}

	static void RemoveFromClassTable(long idClass)
	{
	}

};

template<class T> 
long CObjectTable<T>::m_dwClassTableClasses[m_dwMaxObjectCount] = {0,0};

template<class T>
long CObjectTable<T>::m_dwClassTableIdents[m_dwMaxObjectCount+1] = {0,0};
