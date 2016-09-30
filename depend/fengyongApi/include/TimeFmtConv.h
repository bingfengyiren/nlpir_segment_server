/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// TimeFmtConv.h : ʱ���ʽת����TimeFmtConv������
//
// �汾��v1.0 - 2011.04.11 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_TIME_FMT_CONV_H 
#define _FENGYOUNG_API_TIME_FMT_CONV_H 

#include <string>
using namespace std;
#include <stdint.h>

namespace fengyoung
{

// ʱ����ַ�����ʽ����
enum ETimeFmtType
{
	_TIME_FMT_STD,		// ��׼��ʽ��"YYYY-MM-DD hh:mm:ss"
	_TIME_FMT_NOBLANK,	// �޿ո��ʽ��"YYYY-MM-DD_hh:mm:ss"
	_TIME_FMT_COMPACT	// ���ո�ʽ��"YYYYMMDDhhmmss"
};


// ���ڵ��ַ�����ʽ����
enum EDateFmtType
{
	_DATE_FMT_STD,		// ��׼��ʽ��"YYYY-MM-DD"
	_DATE_FMT_COMPACT	// ���ո�ʽ��"YYYYMMDD"
};


// ������TimeFmtConv
// ˵����ʱ���ʽת����
class TimeFmtConv
{
private:
	// ���캯�� & ��������
	TimeFmtConv();
	virtual ~TimeFmtConv();

public:
	// ��������CurTimeStamp
	// ˵������ȡ��ǰʱ���
	// ����ֵ��32λ��ʱ���
	static uint32_t CurTimeStamp();

	// ��������CurTime_asStr
	// ˵������ȡ��ǰʱ�䣨��ȷ���룩���������ַ�����ʽ����
	// ������
	//	[IN] eOutFmt - �����ʱ���ַ����ĸ�ʽ
	// ����ֵ����ʾ��ǰʱ����ַ���
	static string CurTime_asStr(const ETimeFmtType eOutFmt = _TIME_FMT_STD);

	// ��������TimeConv_Uint32ToStr
	// ˵������32λ��ʱ���ת�����ַ���
	// ������
	//	[IN] unTimeStamp - �����ʱ���
	//	[IN] eOutFmt - �����ʱ���ַ����ĸ�ʽ
	// ����ֵ����ʾʱ����ַ���
	static string TimeConv_Uint32ToStr(const uint32_t unTimeStamp, const ETimeFmtType eOutFmt = _TIME_FMT_STD);
	
	// ��������TimeConv_StrToUint32
	// ˵�������ַ�����ʽ��ʱ��ת����32λ��ʱ���
	// ������
	//	[IN] sTime - �����ʱ���ַ���
	//	[IN] eInFmt - �����ʱ���ַ����ĸ�ʽ
	// ����ֵ��32λʱ���
	static uint32_t TimeConv_StrToUint32(const char* sTime, const ETimeFmtType eInFmt = _TIME_FMT_STD);

	// ��������DateConv_Uint32ToStr
	// ˵������32λ����ת�����ַ���
	// ������
	//	[IN] unTimeStamp - �����ʱ���
	//	[IN] eOutFmt - ����������ַ����ĸ�ʽ
	// ����ֵ���ַ�����ʽ�����ڣ������ʽ��YYYY-MM-DD
	static string DateConv_Uint32ToStr(const uint32_t unTimeStamp, const EDateFmtType eOutFmt = _DATE_FMT_STD);
	
	// ��������DateConv_StrToUint32
	// ˵�������ַ�����ʽ������ת����32λ��ʱ���
	// ������
	//	[IN] sDate - ����������ַ�������ʽ��YYYY-MM-DD
	// ����ֵ��32λʱ���
	static uint32_t DateConv_StrToUint32(const char* sDate);
};

}


#endif /* _FENGYOUNG_API_TIME_FMT_CONV_H */

