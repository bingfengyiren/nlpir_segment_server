/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ThreadRWLock.h : �̶߳�д��ThreadRWLock������
//
// �汾��v1.0 - 2015.01.09 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_THREAD_RW_LOCK_H 
#define _FENGYOUNG_API_THREAD_RW_LOCK_H 

#include <pthread.h>
#include <stdint.h>

namespace fengyoung
{

// ������ThreadRWLock 
//	�̶߳�д�� 
class ThreadRWLock
{ 
public:
	// ���캯�� & �������� 
	ThreadRWLock();
	virtual ~ThreadRWLock();

	//����
	void RdLock() const;
	void WrLock() const;

	//������
	bool TryRdLock() const;
	bool TryWrLock() const;

	//����
	void Unlock() const;

protected:
	mutable pthread_rwlock_t _rw_lock;	// ��д�� 
}; 

}

#endif /* _FENGYOUNG_API_THREAD_RW_LOCK_H */  
 
