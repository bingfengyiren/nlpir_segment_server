/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StrHash.h : �ַ���hash�㷨�ӿ�����
//
// �汾��v1.0 - 2012.05.29 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STR_HASH_H
#define _FENGYOUNG_API_STR_HASH_H

#include <stdint.h>

namespace fengyoung
{

// ������StrHash
// ˵�����ַ���hash�㷨
class StrHash
{
private: 
	// ���캯�� & ��������
	StrHash(); 
	virtual ~StrHash(); 

public:
	// BKDR�㷨	
	static uint32_t BKDRHash_asUint32(const char* sStr); 
	static uint64_t BKDRHash_asUint64(const char* sStr);

	// �ַ���hash
	static uint32_t HashCode_asUint32(const char* sStr, const uint32_t unHashCnt);  
	static uint64_t HashCode_asUint64(const char* sStr, const uint64_t unHashCnt);  
};

}

#endif /* _FENGYOUNG_API_STR_HASH_H */


