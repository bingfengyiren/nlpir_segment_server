/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// PinyinMap.h : ƴ��ӳ�����PinyinMap����
//
// �汾��v1.0 - 2013.04.09 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_PINYIN_MAP_H 
#define _FENGYOUNG_API_PINYIN_MAP_H 

#include <map>
using namespace std;
#include <stdint.h>
#include "BiChar.h"

namespace fengyoung
{

// ������PinyinMap
// ˵����ƴ��ӳ���
class PinyinMap 
{
public:
	// ���캯�� & �������� 
	PinyinMap();
	virtual ~PinyinMap();

	// ��������ReadPinyinMap
	// ˵�������ļ��ж�ȡƴ��ӳ��
	// ������
	//	[IN] sFile - ƴ��ӳ�����
	// ����ֵ����ȡ�ɹ�����true�����򷵻�false
	bool ReadPinyinMap(const char* sFile);

	// ��������GetCode
	// ˵������ȡ���ֵ�ƴ������
	// ������
	//	[OUT] code - ƴ������
	//	[IN] sCh - �����ַ�
	bool GetCode(uint8_t& code, const char* sCh);

	// ��������GetPinyin
	// ˵������ȡ���ֵ�ƴ��
	// ������
	//	[IN] sCh - �����ַ�
	// ����ֵ�������ַ���Ӧ��ƴ��
	string GetPinyin(const char* sCh); 

protected:
	uint8_t m_maxPinyinCode;	// ����ƴ������
	map<BiChar, pair<string,uint8_t> > m_mapBiChar2PinyinCode;	// �����ַ�->ƴ������ ӳ���
};

}

#endif /* _FENGYOUNG_API_PINYIN_MAP_H */


