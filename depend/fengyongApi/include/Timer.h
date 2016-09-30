/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Timer.h : ��ʱ����Timer������
//
// �汾��v1.0 - 2011.04.11 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_TIMER_H 
#define _FENGYOUNG_API_TIMER_H 

#include <string>
#include <vector>
using namespace std;
#include <stdint.h>
#include <sys/time.h>

namespace fengyoung
{

// ������Timer  
// ˵������ʱ��
class Timer
{
public:
	// ���캯�� & ��������
	Timer();
	Timer(const Timer& timer);
	virtual ~Timer();

	// ���ظ�ֵ������
	Timer& operator = (const Timer& timer);
	
	// ��յ�ǰ��ʱ��
	void Clear();

	// ��ʼ��ʱ
	void Start();
	// ֹͣ��ʱ
	void Stop();
	// ��ȡʱ�����Ŀ
	uint32_t SegCount();

	// ��ȡ���һ�μ�ʱ
	int32_t GetLast_asUSec();
	float GetLast_asMSec();
	float GetLast_asSec();
	float GetLast_asMinute();
	float GetLast_asHour();

	// ��ȡһ�μ�ʱ
	pair<uint32_t,uint32_t> Get(const uint32_t unSeg); 
	int32_t Get_asUSec(const uint32_t unSeg);
	float Get_asMSec(const uint32_t unSeg);
	float Get_asSec(const uint32_t unSeg);
	float Get_asMinute(const uint32_t unSeg);
	float Get_asHour(const uint32_t unSeg);

	// ��ȡ�ܼ�ʱ
	int32_t GetTotal_asUSec(); 
	float GetTotal_asMSec(); 
	float GetTotal_asSec(); 
	float GetTotal_asMinute(); 
	float GetTotal_asHour(); 

	string ToString_asMS(); 
	bool FromString_asMS(const char* sStr); 

	void CombineWith(Timer& timer); 
	

public: 
	timeval m_laststart;    // ���һ����ʼʱ��
	bool m_bPingPang;       // ��ʱ����
	vector<pair<uint32_t, uint32_t> > m_vtrSeg; 	// ��ʱʱ���<�룬΢��>
};

}

#endif /* _FENGYOUNG_API_TIMER_H */ 


