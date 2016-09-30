/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Attenuation.h : ˥������������ 
//
// �汾��v1.0 - 2012.08.13 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_ATTENUATION_H 
#define _FENGYOUNG_API_ATTENUATION_H 

#include <stdint.h>


namespace fengyoung
{

// ������Attenuation 
// ˵����˥������
class Attenuation 
{
private:
	// ���캯�� & ��������
	Attenuation();
	virtual ~Attenuation(); 

public:
	// ��������Linear
	// ˵��������˥�� y = f(x) = ax+b
	//	 a = - r / (2*h)��rΪ˥�����ȣ�hΪ��˥��
	//	 b = r + 1
	// ������
	//	[IN] x - x����
	//	[IN] att_range - ˥������
	// 	[IN] half_lift - ��˥��	
	// ����ֵ��˥��ֵ
	static double Linear(const double x, const double att_range, const double half_life); 

	// ��������Exponential
	// ˵����ָ��˥�� y = f(x) = exp[b/(1+x/a)]; 
	//	 a = h * ln((r+2)/2) / ln((2r+2)/(r+2))��rΪ˥�����ȣ�hΪ��˥�� 
	//	 b = ln(r+1)
	// ������
	//	[IN] x - x����
	//	[IN] att_range - ˥������
	// 	[IN] half_lift - ��˥��	
	// ����ֵ��˥��ֵ
	static double Exponential(const double x, const double att_range, const double half_life); 
};

}

#endif /* _FENGYOUNG_API_ATTENUATION_H */ 


