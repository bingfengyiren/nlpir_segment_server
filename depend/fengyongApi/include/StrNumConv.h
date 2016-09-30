/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StrNumConv.h : �ַ������ֺ���ֵ������ת����StrNumConv������
//
// �汾��v1.0 - 2012.02.12 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STR_NUMERIC_CONV_H 
#define _FENGYOUNG_API_STR_NUMERIC_CONV_H 

#include <string>
using namespace std; 
#include <stdint.h>

#define _DOUBLE_MAX_ACCURACY	16	// double����󾫶ȣ�double����󾫶�Ϊ15~16λ�����һλ�޷���֤׼ȷ�ԣ�
#define _FLOAT_MAX_ACCURACY	7	// float����󾫶ȣ�float����󾫶�Ϊ6~7λ�����һλ�޷���֤׼ȷ�ԣ�


namespace fengyoung
{

// ��ֵ����ö��
enum ENumericCodec 
{
	_NUMERIC_CODEC_HEX,		// 16����
	_NUMERIC_CODEC_DEC,		// 10����
	_NUMERIC_CODEC_BIN,		// 2����
};


// ������StrNumConv
//	�ַ���������֮���ת����
class StrNumConv
{
private:
	// ���캯�� & ��������	
	StrNumConv(); 
	virtual ~StrNumConv(); 
public:
	// ��������BitmapToStr
	// ˵����bitmap ת str
	// ������
	// 	[IN] unBitmap - bitmap
	// 	[IN] bits - λ��
	// ����ֵ��bitmap�ַ���
	static string BitmapToStr(const uint32_t unBitmap, const uint32_t bits = 32);
	
	// ��������StrToBitmap
	// ˵����str ת bitmap
	// ������
	// 	[IN] sStrBitmap - bitmap�ַ���
	// ����ֵ��bitmap
	static uint32_t StrToBitmap(const char* sStrBitmap); 

	// ��������DoubleToStr
	// ˵����double ת str
	// ������
	//	[IN] num - ��ת����double����ֵ
	//	[IN] accuracy - ���ȣ���ȷ��С������λ������������Χ��<0�������󾫶ȣ�ȡ��󾫶�
	// ����ֵ���ַ�������ֵ
	static string DoubleToStr(const double num, const int32_t accuracy = _DOUBLE_MAX_ACCURACY); 
	static string DoubleToString(const double num); 

	// ��������FloatToStr
	// ˵����float ת str
	// ������
	//	[IN] num - ��ת����float����ֵ
	//	[IN] accuracy - ���ȣ���ȷ��С������λ������������Χ��<0�������󾫶ȣ�ȡ��󾫶�
	// ����ֵ���ַ�������ֵ
	static string FloatToStr(const float num, const int32_t accuracy = _FLOAT_MAX_ACCURACY); 

	// ��������StrToDouble
	// ˵����str ת double
	// ������
	//	[IN] sNum - ��ת�����ַ�����ֵ
	// ����ֵ��double��ֵ
	static double StrToDouble(const char* sNum);

	// ��������StrToUint32 / StrToUint64
	// ˵�����ַ����޷�������ת uint32_t / uint64_t
	// ������
	//	[IN] sNum - ��ת�����ַ�����ֵ
	//	[IN] eInCodec - ����Ľ�������
	// ����ֵ��uint32_t / uint64_t ����ֵ
	static uint32_t StrToUint32(const char* sNum, const ENumericCodec eInCodec = _NUMERIC_CODEC_DEC);
	static uint64_t StrToUint64(const char* sNum, const ENumericCodec eInCodec = _NUMERIC_CODEC_DEC);
	
	// ��������Uint32ToStr / Uint64ToStr
	// ˵����32λ / 64λ �޷�������תstring
	// ������
	//	[IN] num - ��ת�����޷���������ֵ
	//	[IN] align - ��С����λ����Ϊ��ֵ��Ч
	//	[IN] eOutCodec - ����Ľ�������
	// ����ֵ���ַ����͵��޷�������
	static string Uint32ToStr(const uint32_t num, const int32_t align = -1, const ENumericCodec eOutCodec = _NUMERIC_CODEC_DEC);
	static string Uint64ToStr(const uint64_t num, const int32_t align = -1, const ENumericCodec eOutCodec = _NUMERIC_CODEC_DEC);

private:
	// ��������Uint64toStr_asBinary
	// ˵����uint64_t ת���� �����Ʊ�ʾ��str
	// ������
	//	[IN] num - ��ת�����޷���������ֵ
	//	[IN] align - ��С����λ����Ϊ��ֵ��Ч
	// ����ֵ�������Ʊ�ʾ���ַ�������ֵ
	static string Uint64toStr_asBinary(const uint64_t num, const int32_t align); 

	// ��������StrToUint64_fromBinary
	// ˵���������Ʊ�ʾ��str ת���� uint64_t 
	// ������
	//	[IN] sNum - ��ת�����ַ�����ֵ
	// ����ֵ��64λ �޷���������ֵ
	static uint64_t StrToUint64_fromBinary(const char* sNum); 
};

}

#endif /* _FENGYOUNG_API_STR_NUMERIC_CONV_H */ 

