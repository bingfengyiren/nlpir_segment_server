/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TradSimpConv.h : ���ַ�����ת����TradSimpConv����
//
// �汾��v1.0 - 2013.04.09 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_TRAD_SIMP_CONV_H
#define _FENGYOUNG_API_TRAD_SIMP_CONV_H

#include <map>
using namespace std; 
#include <stdint.h>
#include "BiChar.h"

namespace fengyoung
{

// ������TradSimpConv
// ˵�������ַ�����ת��
class TradSimpConv
{
public:
	// ���캯�� & ��������
	TradSimpConv(); 
	virtual ~TradSimpConv();

	// ��������LoadTradSimpMapFromFile
	// ˵�������ļ������뺺�ַ������Ӧ��(����to����)
	// ������
	//	[IN] sFile - ���ַ������Ӧ��(����to����)
	// ����ֵ���ɹ�����true�����򷵻�false
	bool LoadTradSimpMapFromFile(const char* sFile); 

	// ��������Convert_TradToSimp / Convert_SimpToTrad
	// ˵��������ת���� / ����ת����
	// ������
	//	[IN] sIn - ������ַ���
	//	[OUT] sOut - ������ַ���
	// ����ֵ������ת���ĺ�����
	uint32_t Convert_TradToSimp(const char* sIn, char* sOut); 
	uint32_t Convert_SimpToTrad(const char* sIn, char* sOut); 


protected: 
	map<BiChar, BiChar> m_mapTradToSimp;	// ����to�������
	map<BiChar, BiChar> m_mapSimpToTrad;	// ����to�������
};

}

#endif /* _FENGYOUNG_API_TRAD_SIMP_CONV_H */ 

