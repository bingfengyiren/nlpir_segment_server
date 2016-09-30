/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Histogram.h : ֱ��ͼ��Histogram������ 
//
// �汾��v1.0 - 2011.12.26 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_HISTOGRAM_H
#define _FENGYOUNG_API_HISTOGRAM_H

#include <vector>
#include <map>
using namespace std;
#include <stdint.h>

namespace fengyoung
{

// ������Histogram
// ˵����ֱ��ͼ��
class Histogram
{
public:
	// ���캯�� & ��������
	Histogram(const double fStep);
	Histogram(const double max, const double min, const uint32_t seg); 
	virtual ~Histogram();

	// ��ȡֱ��ͼ
	void Extract(vector<double>& vtrValue);

	// ��ȡֱ��ͼ���
	uint32_t GetHist(vector<pair<double,uint32_t> >& vtrHist);	
	
private:
	double m_fStep;	// ���ڲ���
	map<int32_t,uint32_t> m_mapHist;	// ֱ��ͼӳ���
};

}

#endif /* _FENGYOUNG_API_HISTOGRAM_H */

