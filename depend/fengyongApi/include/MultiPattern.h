/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// MultiPattern.h : ��ģʽƥ����MultiPattern������
//
// �汾��v1.0 - 2011.04.11 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_MULTI_PATTERN_H
#define _FENGYOUNG_API_MULTI_PATTERN_H

#include <map>
#include <vector>
#include <string>
using namespace std; 
#include <stdint.h>
#include "strmatch_fengyoung.h"


#define _MULTIPATTERN_SUCCESS		1
#define _MULTIPATTERN_ERROR_INITFAILED	-1
#define _MULTIPATTERN_ERROR_LOADPATTERN	-2


namespace fengyoung
{

// ������MultiPattern
// ˵������ģʽƥ��
class MultiPattern
{
public:
	// ���캯�� & ��������
	MultiPattern();
	virtual ~MultiPattern();

	// ��������LoadPattern
	// ˵��������ģʽ
	// ������
	//	[IN] sFile - ģʽ�ļ�
	// ����ֵ������ɹ�����1�����򷵻ش�����루<0��
	int32_t LoadPattern(const char* sFile);

	// ��������InsertPattern
	// ˵��������ģʽ
	// ������
	//	[IN] sFile - ģʽ�ļ�
	// ����ֵ������ɹ�����1�����򷵻ش�����루<0��
	int32_t InsertPattern(const char* sPattern); 
	bool PreparePattern(); 

	// ��������Match
	// ˵����ִ�ж�ģʽƥ��
	// ������
	//	[OUT] mapMatched - "ƥ��ģʽ->ƥ����"ӳ���
	//	[OUT] vtrMatched - "<ƥ��ģʽ->ƥ����>"����
	//	[IN] sTxt - ��ƥ���ı�
	// ����ֵ��ƥ����Ŀ
	int32_t Match(map<string,int32_t>& mapMatched, const char* sTxt); 
	int32_t Match(vector<pair<string,int32_t> >& vtrMatched, const char* sTxt); 

private: 
	MATCHENTRY_FENGYOUNG* m_matchEntry;	// ƥ�����
};

}

#endif /* _FENGYOUNG_API_MULTI_PATTERN_H */

