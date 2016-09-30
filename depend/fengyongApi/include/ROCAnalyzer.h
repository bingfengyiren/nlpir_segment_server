/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// ROCAnalyzer.h : ROC������ROCAnalyzer������
//
// �汾��v1.0 - 2013.07.25 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_ROC_ANALYZER_H 
#define _FENGYOUNG_API_ROC_ANALYZER_H 

#include <vector>
#include <map>
#include <algorithm>
using namespace std; 
#include <stdint.h>


namespace fengyoung
{

// ��ǩ����(����������)
enum ELabelType
{
	_POSITIVE,	// ������
	_NEGATIVE	// ������
};

// Positive & Negative �ж�����
enum EPNDetType
{
	_TP,
	_FN,
	_FP,
	_TN
}; 

// Positive & Negative �ж�ͳ�Ʊ�
// +---------+-----------------------------------------+
// |         |                  Ԥ��                   |
// |         +--------------------+--------------------+
// |         |    P(positive)     |    N(negative)     |
// |-----+---+--------------------+--------------------+
// |     | P | tp(true positive)  | fn(false negative) |
// |ʵ�� +---+--------------------+--------------------+
// |     | N | fp(false positive) | tn(true negative)  |
// +-----+---+--------------------+--------------------+
class PNDetTable
{
public: 
	// ���캯�� & ��������
	PNDetTable(); 
	PNDetTable(const PNDetTable& table); 
	virtual ~PNDetTable();

	// ���
	void Clear(); 

	// ���ظ�ֵ������	
	PNDetTable& operator = (const PNDetTable& table); 

	// ������: SampleCnt
	// ˵��: ��ȡ��������
	uint32_t SampleCnt(); 
	
	// ������: RealPositiveCnt / PredPositiveCnt
	// ˵��: ��ȡʵ��/Ԥ����������
	uint32_t RealPositiveCnt(); 
	uint32_t PredPositiveCnt();
	
	// ������: RealNegativeCnt / PredNegativeCnt
	// ˵��: ��ȡʵ��/Ԥ�⸺������
	uint32_t RealNegativeCnt(); 
	uint32_t PredNegativeCnt(); 

	// ������: TPR
	// ˵����TPR = TP / (TP + FN)
	double TPR(); 

	// ������: FPR 
	// ˵����FPR = FP / (FP + TN)
	double FPR(); 

	// ��������TNR
	// ˵����TNR = TN / (FP + TN) 
	double TNR(); 

	// ������: Precision
	// ˵��: ����׼ȷ��, precision = TP / (TP + FP)
	double Precision(); 

	// ������: Recall
	// ˵��: �����ٻ���, recall = TP / (TP + FN) = sensitivity
	double Recall(); 

public: 
	uint32_t m_unCnt[4]; 
}; 


// ������ROCAnalyzer
// ˵����ROC(Receiver Operating Characteristic)������
class ROCAnalyzer
{
public:
	// ���캯�� & ��������
	ROCAnalyzer(const double dScoreFrom, const double dScoreTo); 
	virtual ~ROCAnalyzer();

	// ��������Clear
	// ˵������յ�ǰ������
	void Clear(); 

	// ��������Insert
	// ˵��������һ������ʵ�ʱ�ǩ & ��ֵ
	// ������
	// 	[IN] label_type - ����ʵ�ʱ�ǩ(������ or ������)
	// 	[IN] dScore - �����ж���ֵ
	void Insert(ELabelType label_type, const double dScore); 

	// ��������AUCValue
	// ˵��������AUC(Area Under ROC Curve)ֵ
	double AUCValue(); 

	// ��������ROCCurve
	// ˵������ȡROC���߲���
	// ������
	// 	[OUT] curve - ROC���߲���(�ж���ֵ & PN�ж�ͳ�Ʊ�)
	// 	[IN] step - ��ֵ����
	void ROCCurve(vector<pair<double, PNDetTable> >& curve, const double step); 

	uint32_t Count(const ELabelType eType); 

private:
	// �Ƚ�������ֵ
	static bool Comp(pair<ELabelType,double> a, pair<ELabelType, double> b); 

private: 
	double m_dScoreFrom;	// ��ֵ(��)�����½�
	double m_dScoreTo;		// ��ֵ(��)�����Ͻ�
	uint32_t m_unPositiveCnt; // ��������
	uint32_t m_unNegativeCnt; // ��������

	vector<pair<ELabelType,double> > m_vtrLabelScore;	// ����ʵ�ʱ�ǩ(������) & ��ֵ�б�	
}; 

}

#endif /* _FENGYOUNG_API_ROC_ANALYZER_H */ 


