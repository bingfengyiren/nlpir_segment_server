/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StrSim.h : �ַ���ƥ����StrSim����
//
// �汾��v1.0 - 2011.04.11 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STR_SIM
#define _FENGYOUNG_API_STR_SIM

#include <map>
#include <vector>
#include <string>
using namespace std; 
#include <stdint.h> 


namespace fengyoung
{

// ������StrSim
//	�ַ���ƥ�������
class StrSim
{
private:
	// ���캯�� & ��������
	StrSim(); 
	virtual ~StrSim(); 

public:
	// ��������EditDistance
	// ˵�������������ַ���֮��ı༭����
	// ������
	//	[IN] sSrc - Դ�ַ���
	//	[OUT] sTarget - Ŀ���ַ���
	// ����ֵ��Ŀ���ַ������Դ�ַ����ı༭����
	static int32_t EditDistance(const char* sSrc, const char* sTarget);
};

}

#endif /* _FENGYOUNG_API_STR_SIM */
