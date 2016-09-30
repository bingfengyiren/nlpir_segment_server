/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Statistic.h : ͳ���ೣ�ù�ʽ����
//
// �汾��v1.0 - 2011.12.26 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_MATH_STATISTIC_H
#define _FENGYOUNG_API_MATH_STATISTIC_H

#include <vector>
#include <set>
using namespace std;
#include <stdint.h>

namespace fengyoung
{

// ������Statistic
// ˵����ͳ����
class Statistic
{
private:
	// ���캯�� & ��������
	Statistic();
	virtual ~Statistic();

public:
	// ����������ֵ
	static float SampleMean(vector<float>& vtrValue);
	// ������������
	static float SampleVariance(vector<float>& vtrValue);
	// ��������	
	static set<float> Mode(vector<float>& vtrValue);
	// ����������
	static float Midrange(vector<float>& vtrValue);
	// ��С & ���ֵ
	static pair<float,float> MinAndMax(vector<float>& vtrValue);

	// ����Э����
	static float Covariance(vector<float>& vtrValue1, vector<float>& vtrValue2);

private:
	// �Ƚ�����pair
	static float PairCmp_Second(pair<float,uint32_t> a, pair<float,uint32_t> b);
};

}

#endif /* _FENGYOUNG_API_MATH_STATISTIC_H */

