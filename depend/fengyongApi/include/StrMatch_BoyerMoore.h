/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// StrMatch_BoyerMoore.h : ����Boyer-Moore�㷨���Ӵ�ƥ��������
//
// Boyer-Moore�ַ��������㷨��һ�ַǳ���Ч���ַ��������㷨������Bob Boyer��J Strother Moore�����1977�ꡣ
// ���㷨��������Ŀ���ַ������ؼ��֣�����Ԥ�������Ǳ��������ַ�������ȻBoyer-Moore�㷨��ִ��ʱ��ͬ����
// �������ڱ������ַ����Ĵ�С������ͨ����Ϊ�����㷨��һС���֣�������Ҫ�Ա��������ַ����е��ַ�������һ
// �Ƚϣ�������������ĳЩ���֡�ͨ�������ؼ���Խ�����㷨�ٶ�Խ�졣����Ч����������������ʵ������ÿһ��ʧ��
// ��ƥ�䳢�ԣ��㷨���ܹ�ʹ����Щ��Ϣ���ų������ܶ���޷�ƥ���λ�á�
//
// �汾��v1.0 - 2011.04.11 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_STR_MATCH_BOYER_MOORE_H 
#define _FENGYOUNG_API_STR_MATCH_BOYER_MOORE_H

#include <map>
#include <vector>
#include <string>
using namespace std; 
#include <stdint.h> 


namespace fengyoung
{

// ������StrMatch_BoyerMoore
//	����Boyer-Moore�㷨���Ӵ�ƥ����
class StrMatch_BoyerMoore
{
private:
	// ���캯�� & ��������
	StrMatch_BoyerMoore(); 
	virtual ~StrMatch_BoyerMoore(); 

public: 
	// ��������Find
	// ˵�����Ӵ�����
	// ������
	//	[IN] sStr - �ַ���
	//	[IN] sSub - �Ӵ�
	// ����ֵ���Ӵ����ַ����е���ʼλ�ã�����Ӵ����ܴ��ڷ���-1
	static int32_t Find(const char* sStr, const char* sSub);

private:
	// ��������SuffixAndCharMap
	// ˵���������׺λ���Լ��ַ�λ��ӳ���
	// ������
	//	[IN] sStr - �ַ���
	//	[OUT] mapSuffix - ��׺λ��ӳ���
	//	[OUT] mapChar - �ַ�λ��ӳ���
	static void SuffixAndCharMap(const char* sStr, map<string,vector<int32_t> >& mapSuffix, map<char,vector<int32_t> >& mapChar); 

	// ��������RFindBandChar
	// ˵����������ҵ�һ�����ַ�(�ַ����е��ַ�)�����ظ��ַ����ַ����е����λ��
	// ������
	//	[IN] sStr - �ַ���
	//	[IN] sSub - �Ӵ�
	//	[IN] nSubLen - �Ӵ�����
	//	[IN] offset - �ַ���ƫ����
	// ����ֵ����һ�����ַ����Ӵ��е�λ�ã���������ڻ��ַ��򷵻�-1
	static int32_t RFindBandChar(const char* sStr, const char* sSub, const int32_t nSubLen, const int32_t offset);

	// ��������CharLastPos
	// ˵������ȡ�Ӵ���ĳ���ַ����Ӵ����ϴγ��ֵ�λ��
	// ������
	//	[IN] cChar - �������ַ�
	//	[IN] sSub - �Ӵ�
	//	[IN] nCurPos - ��ǰλ��
	// ����ֵ���ַ����Ӵ����ϴγ��ֵ�λ�ã����û�з���-1
	static int32_t CharLastPos(const char cBadChar, const char* sSub, const int32_t nCurPos);

	// ��������SuffixLastPos
	// ˵������ȡ�Ӵ���ĳ����׺���Ӵ����ϴγ��ֵ�λ��
	// ������
	//	[IN] sSub - �Ӵ�
	//	[IN] sSubLen - �Ӵ�����
	//	[IN] nSuffixLen - ��׺����
	//	[IN] mapSuffix - ��׺λ��ӳ���
	static int32_t SuffixLastPos(const char* sSub, const int32_t nSubLen, const int32_t nSuffixLen, map<string,vector<int32_t> >& mapSuffix);
};

}

#endif /* _FENGYOUNG_API_STR_MATCH_BOYER_MOORE_H */
