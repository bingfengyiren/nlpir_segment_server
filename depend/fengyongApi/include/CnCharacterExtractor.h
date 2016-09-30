/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// CnCharacterExtractor.h : ������ȡ��CnCharacterExtractor����
//
// �汾��v1.0 - 2013.04.09 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_CN_CHARACTER_EXTRACTOR_H 
#define _FENGYOUNG_API_CN_CHARACTER_EXTRACTOR_H 

#include <map>
using namespace std;
#include <stdint.h>
#include "PinyinMap.h"
#include "TradSimpConv.h"


namespace fengyoung
{

// ������CnCharacterExtractor 
// ˵����������ȡ�������ڴ��ַ�������ȡ����
class CnCharacterExtractor : public PinyinMap, public TradSimpConv
{
public:
	// ���캯�� & ��������	
	CnCharacterExtractor(); 
	virtual ~CnCharacterExtractor(); 

	// ������LoadResource
	// ˵����������Դ
	// ������
	//	[IN] sPinyinMapFile - ƴ������ļ�
	//	[IN] sTradSimpFile - ���ַ������Ӧ��(����to����)
	// ����ֵ������ɹ�����true�����򷵻�false
	bool LoadResource(const char* sPinyinMapFile, const char* sTradSimpFile);

	// ��������GetCnCh_asSimp / GetCnCh_asTrad
	// ˵������ȡ�ַ����еļ��� / ���� ���ִ�(�������з�����ת��)
	// ������
	//	[IN] sIn - ������ַ���
	//	[OUT] sOut - ������ַ���
	// ����ֵ��������
	uint32_t GetCnCh_asSimp(const char* sIn, char* sOut);
	uint32_t GetCnCh_asTrad(const char* sIn, char* sOut);

};

}

#endif /* _FENGYOUNG_API_CN_CHARACTER_EXTRACTOR_H */
