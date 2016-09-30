/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StringArray.h : �ַ���������StringArray������
//
// �汾��v1.0 - 2011.04.11 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STRING_ARRAY_H 
#define _FENGYOUNG_API_STRING_ARRAY_H 

#include <string> 
#include <vector> 
using namespace std; 
#include <stdint.h> 

namespace fengyoung
{

// ����: StringArray 
// ˵��: �ַ��������� 
class StringArray 
{
public: 
	// ���캯�� & ��������  
	// ������
	//	[IN] sStr - �������������ַ����������ַ���
	//	[IN] sDilm - �ָ���  
	StringArray(const char* sStr, const char* sDilm);   
	virtual ~StringArray(); 

	// ��������GetString 
	// ˵������ȡһ���ַ��� 
	// ������
	//	[IN] unIdx - �ַ����ڵ�ǰ�����е������� 
	// ����ֵ�������Ŷ�Ӧ���ַ���  
	string GetString(const uint32_t unIdx) const; 
	
	// ��������Count
	// ˵������ȡ��ǰ�����е��ַ�����Ŀ
	// ����ֵ����ǰ�����е��ַ�����Ŀ
	uint32_t Count() const; 
private: 
	// ��һ�������������ַ������зֽ⣬��ȡ����  
	void Decompose(const char* sStr, const char* sDilm); 
	
	vector<string> m_vtrString; 	// �ַ������� 
};  

}

#endif /* _FENGYOUNG_API_STRING_ARRAY_H */ 

