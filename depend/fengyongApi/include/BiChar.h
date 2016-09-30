/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// BiChar.h : ˫���ַ���BiChar���� 
//
// �汾��v1.0 - 2011.04.11 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_BI_CHAR_H 
#define _FENGYOUNG_API_BI_CHAR_H 

#include <iostream>
using namespace std; 
#include <stdint.h>


namespace fengyoung
{

// ������BiChar
// ˵����˫���ַ� 
class BiChar
{
public:
	// ���캯�� & ��������
	BiChar();
	BiChar(const char* sStr);
	BiChar(const char ch_0, const char ch_1);
	BiChar(const BiChar& bi_char);
	virtual ~BiChar();
	
	// ���ز�����
	BiChar& operator = (const BiChar& bi_char);
	bool operator == (const BiChar& bi_char) const;
	bool operator != (const BiChar& bi_char) const;
	bool operator > (const BiChar& bi_char) const;
	bool operator < (const BiChar& bi_char) const;
	
	// ���˫���ַ�ռ�ڴ��С
	uint32_t SizeOf();

public: 
	char data[3];
};

}

#endif /* _FENGYOUNG_API_BI_CHAR_H */ 

