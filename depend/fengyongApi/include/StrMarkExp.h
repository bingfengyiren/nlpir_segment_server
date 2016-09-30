/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StrMarkExp.h : �ַ�����ǲ�����StrMarkExp����
//
// �汾��v1.0 - 2011.04.11 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STR_MARK_EXP_H 
#define _FENGYOUNG_API_STR_MARK_EXP_H 

#include <set> 
using namespace std; 
#include <stdint.h> 
#include "BiChar.h"


namespace fengyoung
{

// �ո�����ö��
enum EBlankType
{
	_BLANK_EN,	// ' '
	_BLANK_CN,	// '��'
	_BLANK_TAB,	// '\t'
	_BLANK_NOT	// �ǿո�
}; 


// ������StrMarkExp
//	�ַ�����ǲ����� 
class StrMarkExp 
{
private:
	// ���캯�� & ��������	
	StrMarkExp(); 
	virtual ~StrMarkExp(); 
public:
       	// ���ַ����е�����СдӢ���ַ���Ϊ��д 	
	static void ConvEnUp(char* sBuf); 
       	// ���ַ����е����д�дӢ���ַ���ΪСд 	
	static void ConvEnLow(char* sBuf); 

	// ��������FilterShortURL
	// ˵���������ı��еĶ���
	// ������
	//      [IN/OUT] sBuf - ������ַ��������ʱ���˵�����
	// ����ֵ�����ع��˵���<������, ���˵����ַ�������>
	static pair<uint32_t,uint32_t> FilterShortURL(char* sBuf); 

	// ��ȡ�ı��еĶ���
	static uint32_t ExtShortURL(set<string>& setURLs, char* sBuf); 
	
	// ��������FilterExpSymbol
	// ˵���������ַ����еı���� 
	// ������
	//      [IN/OUT] sBuf - ������ַ��������ʱ���˵������
	// ����ֵ�����ع��˵���<������, ���˵����ַ�������>
	static pair<uint32_t,uint32_t> FilterExpSymbol(char* sBuf);

	// ��������FilterGreeting
	// ˵���������ַ����еġ�@$��
	// ������
	//      [IN/OUT] sBuf - ������ַ��������ʱ���˵�"@$"
	// ����ֵ�����ع��˵���<@��Ŀ, ���˵����ַ�������>
	static pair<uint32_t,uint32_t> FilterGreeting(char* sBuf); 

	// ��������IgnoreHTMLSign
	// ˵�����޳�һ���ַ����е�html��� 
	// ������
	//	[IN/OUT] sBuf - ������ַ��������ʱ����HTML��� 
	// ����ֵ�����޳����ַ����ܳ���
	static uint32_t IgnoreHTMLSign(char* sBuf); 

	// ��������IgnoreSignTerm	
	// ˵�������˵�һЩ����ı�Ǵ�
	// ������
	//	[IN/OUT] sBuf - ������ַ��������ʱ����HTML��� 
	//	[IN] sSignTerm - ��Ҫ���޳��Ĵ�
	// ����ֵ�����޳����ַ����ܳ���
	static uint32_t IgnoreSignTerm(char* sBuf, const char* sSignTerm);

	// ��������FilterTag
	// ˵���������ı��еı�ע"����"
	// ������
	//      [IN/OUT] sBuf - ������ַ��������ʱ����"����"�е����� 
	// ����ֵ�����ع��˵���<��ע����Ŀ,���˵����ַ�������>
	static pair<uint32_t,uint32_t> FilterTag(char* sBuf); 
	
	// ��������IsPureNum
	// ˵�����ж�һ���ַ����Ƿ��Ǵ����֣���������ִ���㰴�����ֶԴ���
	// ������
	//	[IN] sStr - �������ַ���
	static bool IsPureNum(const char* sStr);

	// ��������ConvNumCnToArab
	// ˵�������ַ����е���������ת���ɰ���������
	// ������
	//      [IN/OUT] sBuf - ������ַ��������ʱ�����е���������ת���ɰ���������(���)
	// ����ֵ������ַ����ĳ���
	static uint32_t ConvNumCnToArab(char* sBuf); 

	// ��������NumRate
	// ˵��������һ���ַ��������֣����������֣�ռ��
	// ������
	//	[IN] sStr - �������ַ���
	static double NumRate(const char* sStr); 

	// ��������NoCnRate
	// ˵��������һ���ַ����зǺ���ռ�ȣ����ı�㲻�㺺�֣�
	// ������
	//	[IN] sStr - �������ַ���
	//	[IN] bExceptCnNum - �Ƿ��������ֲ���������
	static double NoCnRate(const char* sStr, const bool bExceptCnNum = false); 

	// ��������IgnoreBlanks
	// ˵�����޳����ַ����еĶ���ո񣬰���ȫ�ǿո񡢰�ǿո�tab
	// ������
	//      [IN/OUT] sBuf - ������ַ��������ʱ���˵��������еĶ���ո�
	// ����ֵ�����޳����ַ����ܳ���
	static uint32_t IgnoreBlanks(char* sBuf);

	// ��������IgnoreEnPunctFrontBack
	// ˵�����޳�һ���ַ���ǰ���Ӣ�ı����� 
	// ������
	//	[IN/OUT] sBuf - ������ַ��������ʱ���˵���β��Ӣ�ı�����
	// ����ֵ�����޳����ַ����ܳ���
	static uint32_t IgnoreEnPunctFrontBack(char* sBuf); 

	// ��������IgnoreCnPunctFrontBack
	// ˵�����޳�һ���ַ���ǰ������ı����� 
	// ������
	//	[IN/OUT] sBuf - ������ַ��������ʱ���˵���β�����ı�����
	// ����ֵ�����޳����ַ����ܳ���
	static uint32_t IgnoreCnPunctFrontBack(char* sBuf); 
	
	// ��������IgnorePunctFrontBack
	// ˵�����޳�һ���ַ���ǰ����С�Ӣ�ı����� 
	// ������
	//	[IN/OUT] sBuf - ������ַ��������ʱ���˵���β���С�Ӣ�ı�����
	// ����ֵ�����޳����ַ����ܳ���
	static uint32_t IgnorePunctFrontBack(char* sBuf); 

	// �ж�һ�������ַ����Ƿ���AAB��ABB��AABBģʽ
	static bool IsCnAAB(const char* sStr); 
	static bool IsCnABB(const char* sStr); 
	static bool IsCnAABB(const char* sStr); 
private:
	// ��ʼ��Ӣ�ı�㼯 
	static void InitEnPunctSet();  
	// ��ʼ�����ı�㼯 
	static void InitCnPunctSet(); 
	// ʶ��һ���ַ�����ƫ������ʼ�Ŀո�����
	static EBlankType BlankType(const char* sStr, const uint32_t unOffset = 0);
	// �ж�һ���ַ�����ƫ������ʼ�Ƿ���Ӣ�ı��
	static bool IsEnPunctuation(const char* sStr, const uint32_t unOffset = 0); 
	// �ж�һ���ַ�����ƫ������ʼ�Ƿ��������ı��
	static bool IsCnPunctuation(const char* sStr, const uint32_t unOffset = 0); 
	// ��ƫ��λ��ʼ�����ҽ��ڵ�����Ӣ�ģ������֣������ַ������������Ӵ����ȡ����������������Ӣ���Ӵ����򷵻�0
	static uint32_t NeighborEnSubStrLen(const char* sStr, const uint32_t unOffset = 0);
	// ��ƫ��λ��ʼ�����ҽ��ڵ������Ƿָ�������Ӣ�ı�㡢�ո񣩵����ַ������������ִ����ȡ�����������������Ӵ����򷵻�0
	static uint32_t NeighborSubStrLen(const char* sStr, const uint32_t unOffset = 0);

	static set<char> m_setEnPunct;		// Ӣ�ı�㼯  
	static set<BiChar> m_setCnPunct; 	// ���ı�㼯
}; 

}

#endif /* _FENGYOUNG_API_STR_MARK_EXP_H */ 

 
