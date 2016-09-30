/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// UintHash.h : �޷���������hash�㷨�ӿ�����
//
// �汾��v1.0 - 2011.03.10 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_UINT_HASH_H
#define _FENGYOUNG_API_UINT_HASH_H

#include <stdint.h>

namespace fengyoung
{

// ������UintHash
// ˵�����޷���������hash�㷨
class UintHash
{
private: 
	// ���캯�� & ��������
	UintHash(); 
	virtual ~UintHash(); 

public: 
	// �޷�������hash����
	static uint32_t Uint32HashCode(const uint32_t unKey, const uint32_t unHashCnt);
	static uint32_t Uint64HashCode(const uint64_t unKey, const uint32_t unHashCnt);
};

}

#endif /* _FENGYOUNG_API_UINT_HASH_H */


