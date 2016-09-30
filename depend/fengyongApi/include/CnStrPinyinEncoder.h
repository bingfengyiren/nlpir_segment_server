/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CnStrPinyinEncoder.h : ���ִ�ƴ��������CnStrPinyinEncoder����
//
// �汾��v1.0 - 2013.04.09 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_CN_STR_PINYIN_ENCODER_H 
#define _FENGYOUNG_API_CN_STR_PINYIN_ENCODER_H 

#include <set>
#include <string>
using namespace std; 
#include <stdint.h>
#include "PinyinMap.h"

namespace fengyoung
{

// ������CnStrPinyinEncoder
// ˵���������ַ���������
class CnStrPinyinEncoder
{
public:
	// ���캯�� & ��������
	CnStrPinyinEncoder(); 
	virtual ~CnStrPinyinEncoder(); 

	// ��������LoadPinyinMap
	// ˵��������ƴ��ӳ���
	// ������
	//	[IN] sPinyinMapFile - ƴ������ļ�
	// ����ֵ������ɹ�����true�����򷵻�false
	bool LoadPinyinMap(const char* sPinyinMapFile);

	// ��������PinyinCode
	// ˵�������ַ�������ƴ�����룬����ƴ�����봮
	// ������
	//	[OUT] encoded - ƴ�����봮 
	// 	[IN] sStr - ��������ַ���
	// ����ֵ��ƴ�����봮�ĳ���
	uint32_t PinyinCode(uint8_t* encoded, const char* sStr);

	// ��������Encode_8CnChar / Encode_4CnChar / Encode_2CnChar
	// ˵�������ַ�������ƴ�����룬ÿn������ƴ������һ�������루n=8,4,2)
	// ������
	//	[OUT] setPinyinCode - ƴ�����뼯��
	//	[IN] sStr - ��������ַ���
	void Encode_8CnChar(set<uint64_t>& setPinyinCode, const char* sStr);  
	void Encode_4CnChar(set<uint32_t>& setPinyinCode, const char* sStr);  
	void Encode_2CnChar(set<uint16_t>& setPinyinCode, const char* sStr);  

	// ��������EncodeToPyStr
	// ˵�������ַ���ת��Ϊƴ������Ӣ�ı�����
	// ������
	//	[OUT] sPyStr - ƴ����
	//	[IN] sStr - ��������ַ���
	// ����ֵ��ƴ��������	
	int32_t EncodeToPyStr(char* sPyStr, const char* sStr); 	

protected:
	PinyinMap m_pinyinMap;	// ƴ������ӳ���
};

}

#endif /* _FENGYOUNG_API_CN_STR_PINYIN_ENCODER_H */

