/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// SimHash.h : �ı�SimHash�㷨�ӿ�����
//
// �汾��v1.0 - 2013.04.12 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_SIM_HASH_H
#define _FENGYOUNG_API_SIM_HASH_H

#include <vector>
#include <string>
using namespace std;
#include <stdint.h>


namespace fengyoung
{

// ������SimHash
// ˵�����ı�SimHash�㷨������ı��Ĺؼ������������ı�ָ��
class SimHash
{
private:
	// ���캯�� & ��������	
	SimHash(); 
	virtual ~SimHash(); 

public:
	// ��������TxtFingerprint32
	// ˵����ͨ��SimHash�㷨����32λ�ı�ָ��
	// ������
	//	[IN] vtrKeywrods - �ı��ؼ�������
	//	[IN] unMaxKeywordsCnt - �Թؼ����������ȵ����ƣ����Ϊ0��������
	// ����ֵ��32λ���ı�ָ��
	static uint32_t TxtFingerprint32(vector<pair<string,double> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);
	static uint32_t TxtFingerprint32(vector<pair<string,float> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);
	static uint32_t TxtFingerprint32(vector<pair<string,uint32_t> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);
	static uint32_t TxtFingerprint32(vector<pair<string,int32_t> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);

	// ��������TxtFingerprint64
	// ˵����ͨ��SimHash�㷨����64λ�ı�ָ��
	// ������
	//	[IN] vtrKeywrods - �ı��ؼ�������
	//	[IN] unMaxKeywordsCnt - �Թؼ����������ȵ����ƣ����Ϊ0��������
	// ����ֵ��64λ���ı�ָ��
	static uint64_t TxtFingerprint64(vector<pair<string,double> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);
	static uint64_t TxtFingerprint64(vector<pair<string,float> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);
	static uint64_t TxtFingerprint64(vector<pair<string,uint32_t> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);
	static uint64_t TxtFingerprint64(vector<pair<string,int32_t> >& vtrKeywords, const uint32_t unMaxKeywordsCnt = 0);

private:
	// �Թؼ�������32λ��������
	static void GenKeywordFeatArray32(double* pdArray32, const char* sKeyword, const double dWeight); 

	// �Թؼ�������64λ��������
	static void GenKeywordFeatArray64(double* pdArray64, const char* sKeyword, const double dWeight); 
};

}

#endif /* _FENGYOUNG_API_SIM_HASH_H */


