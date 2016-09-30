/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ThreadMutex.h : �̻߳�����ThreadMutex������
//
// �汾��v1.0 - 2011.04.11 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_THREAD_MUTEX_H 
#define _FENGYOUNG_API_THREAD_MUTEX_H 

#include <pthread.h>
#include <stdint.h>

namespace fengyoung
{

// ������ThreadMutex 
//	���û�����ʵ�ֵ��߳��� 
class ThreadMutex
{ 
public:
	// ���캯�� & �������� 
	ThreadMutex();
	virtual ~ThreadMutex();

	//����
	void Lock() const;

	//������
	bool TryLock() const;

	//����
	void Unlock() const;

protected:
	mutable pthread_mutex_t _mutex;	// ������ 
}; 

}

#endif /* _FENGYOUNG_API_THREAD_MUTEX_H */  
 
