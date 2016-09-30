/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StringSplitter.h : �ַ����з���StringSplitter������
//
// �汾��v3.0 - 2011.02.12 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STRING_SPLITTER_H 
#define _FENGYOUNG_API_STRING_SPLITTER_H 

#include <string> 
using namespace std; 
#include <stdint.h> 


namespace fengyoung
{

// ������StringSplitter 
// ˵�����ַ����з�  
class StringSplitter 
{ 
public: 
	// ��������StringSplitter & ~StringSplitter 
	// ˵�������캯�� & �������� 
	// ������
	//	[IN] sStr - ���������ַ���
	//	[IN] sDilm - �ָ��� 
	//	[IN] bIgnoreSpace - �Ƿ������λ�ո񣨻�\t���ı�־  
	StringSplitter(const char* sStr, const char* sDilm, const bool bIgnoreSpace = true);  
	virtual ~StringSplitter();  

	// ��������GetSubString 
	// ˵������ȡ���ַ���
	// ������
	//	[IN] bIsFront - trueȡ�ָ���ǰ������ַ�����falseȡ�ָ�����������ַ���
	// ����ֵ�����ַ���  
	string GetSubString(const bool bIsFront = true) const; 
private: 
	// �����ַ��������շָ������ַ������зָ� 
	void DoSplit(const char* sStr, const char* sDilm, const bool bIgnoreSpace); 
	// ���Ե�һ���ַ�����λ�Ŀո��Լ�\t 
	void IgnoreSpace(string& str);  

	string m_strFront;	// ǰһ�����ַ��� 
	string m_strBack;	// ��һ�����ַ��� 
}; 

}

#endif /* _FENGYOUNG_API_STRING_SPLITTER_H */ 

