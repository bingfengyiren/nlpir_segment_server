/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// MathMethod.h : ������ѧ��ʽ������ 
//
// �汾��v1.0 - 2011.09.26 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_MATH_METHOD_H 
#define _FENGYOUNG_API_MATH_METHOD_H 

#include <stdint.h>

#define PI	3.14159265358979323846	// Բ����
#define EULER	2.71828182845904523536	// ��Ȼ����e


namespace fengyoung
{

// ������MathMethod
//	����һЩ��ѧ�����ʵ��
class MathMethod
{ 
public: 
	MathMethod();  
	virtual ~MathMethod(); 

	// ��������LogN
	// ˵��������nΪ�ף�a�Ķ���
	// ������
	//	[IN] n - ����
	//	[IN] a - ָ��
	// ����ֵ����nΪ�ף�a�Ķ��� 
	static double LogN(const double n, const double a); 
	
	// ��������Ln
	// ˵����������Ȼ��Ϊ�ף�a�Ķ���
	// ������
	//	[IN] a - ָ��
	// ����ֵ��ln(a)
	static double Ln(const double a); 

	// ��������Exp
	// ˵��������Ȼ����a����
	// ������
	//	[IN] a - ��ָ��
	// ����ֵ��exp(a)
	static double Exp(const double a); 

	// �Ƚ�a��b���������е����ֵ 
	static double Max(const double a, const double b);
 
	// �Ƚ�a��b���������е���Сֵ 
	static double Min(const double a, const double b); 

	// ��ȡһ����ʵ����������
	static int32_t Magnitude(const double a); 

	//////////////////////////////////////////////////////////////////////
	// ���Ǻ���
	// 

	// ��������Sin Cos Tan Cot
	// ˵���������ҡ����ҡ����С�����
	static double Sin(const double x); 
	static double Cos(const double x); 
	static double Tan(const double x); 
	static double Cot(const double x); 
	
	// ��������ArcSin ArcCos ArcTan ArcCot
	// ˵���������ҡ������ҡ������С�������
	static double ArcSin(const double x); 
	static double ArcCos(const double x); 
	static double ArcTan(const double x); 
	static double ArcCot(const double x); 

	// EOF 	
	//////////////////////////////////////////////////////////////////////
}; 

}

#endif /* _FENGYOUNG_API_MATH_METHOD_H */ 

