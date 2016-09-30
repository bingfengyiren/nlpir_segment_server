/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Random.h : ����������������� 
//
// �汾��v1.0 - 2011.03.10 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_RANDOM_H
#define _FENGYOUNG_API_RANDOM_H

#include <set>
using namespace std; 
#include <stdint.h>


namespace fengyoung
{

class Random 
{
private:
	// ���캯�� & ��������
	Random();
	virtual ~Random();

public:
	// ��������RandomDistri
	// ˵����������ֲ�����һ�����ֵ
	// ������
	//	[IN] unLowerLimit - �������� 
	//	[IN] unUpperLimit - ��������
	// ����ֵ��(������)��������ֲ������ֵ	
	static uint32_t RandomDistri();
	static uint32_t RandomDistri(const uint32_t unLowerLimit, const uint32_t unUpperLimit); 

	// ��������RandomDistriN
	// ˵����������ֲ�����N����ͬ�����ֵ
	// ������
	// 	[OUT] setRandom - ���ֵ����
	//	[IN] unLowerLimit - �������� 
	//	[IN] unUpperLimit - ��������
	//	[IN] n - ���ֵ����
	// ����ֵ��ʵ�ʲ��������ֵ����
	static uint32_t RandomDistriN(set<uint32_t>& setRandom, const uint32_t n);
	static uint32_t RandomDistriN(set<uint32_t>& setRandom, const uint32_t unLowerLimit, 
			const uint32_t unUpperLimit, const uint32_t n); 

private:	
	static uint32_t HRandomDistriN(set<uint32_t>& setRandom, const uint32_t unLowerLimit, 
			const uint32_t unUpperLimit, const uint32_t n); 
};

}

#endif /* _FENGYOUNG_API_RANDOM_H */

