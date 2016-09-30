/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StringTokenizer.h : �ַ���Token������StringTokenizer������
//
// �汾��v3.0 - 2011.02.12 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STRING_TOKENIZER_H 
#define _FENGYOUNG_API_STRING_TOKENIZER_H 

#include <string> 
#include <queue> 
using namespace std; 
#include <stdint.h> 

namespace fengyoung
{

// ������StringTokenizer 
// ˵�����ַ���Token���� 
class StringTokenizer 
{ 
public: 
	// ��������StringTokenizer & ~StringTokenizer 
	// ˵�������캯�� & �������� 
	// ������
	//	[IN] sStr - ���������ַ���
	//	[IN] sDilm - token�ָ��� 
	//	[IN] bIgnoreSpace - �Ƿ������λ�ո񣨻�\t���ı�־  
	StringTokenizer(const char* sStr, const char* sDilm, const bool bIgnoreSpace = true);  
	virtual ~StringTokenizer(); 

	// ��������HasMoreToken 
	// ˵�����жϸ��ַ������Ƿ񻹰���token 
	// ����ֵ��true��ʾ������token��false��ʾ��û�и����token
	bool HasMoreToken() const; 
	
	// ��������NextToken 
	// ˵������ȡ��һ��token�ַ���
	// ����ֵ��token�ַ��� 
	string NextToken(); 

	// ��������TokenCount 
	// ˵������ȡtoken��Ŀ
	// ����ֵ��token��Ŀ 
	uint32_t TokenCount() const; 
 
private: 
	// �����ַ���������token�ָ������ַ������зָ� 
	void Decompose(const char* sStr, const char* sDilm, const bool bIgnoreSpace); 
	// ���Ե�һ���ַ�����λ�Ŀո��Լ�\t 
	void IgnoreSpace(string& str); 

	queue<string> m_queToken;	// token���� 
}; 

}

#endif /* _FENGYOUNG_API_STRING_TOKENIZER_H */  

