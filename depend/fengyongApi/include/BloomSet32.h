/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// BloomSet32.h : 32λbloom�����������
//
// �汾��v1.0 - 2013.04.01 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_BLOOM_SET32_H
#define _FENGYOUNG_API_BLOOM_SET32_H

#include <map>
#include <vector>
using namespace std; 
#include <stdint.h>

#define _BLOOM_SET32_BUFF_SIZE		(512*1024*1024)		// ���ݻ����С
#define _BLOOM_SET32_COMPRESS_RATE	8			// ѹ����


namespace fengyoung
{

// ������BloomSet32
// ˵����32λbloom����
class BloomSet32
{
public:
	// ���캯�� & ��������
	BloomSet32();
	virtual ~BloomSet32();

	// ��������Clear
	// ˵������ռ���
	void Clear(); 

	// ��������Insert
	// ˵��������һ������
	// ������
	//	[IN] unItem - ���������
	// ����ֵ������ɹ�����true�����򷵻�false���ö����Ѿ����ڣ�
	bool Insert(const uint32_t unItem);  

	// ��������IfExist
	// ˵�����ж�һ�������Ƿ����
	// ������
	//	[IN] unItem - ����
	// ����ֵ��������ڷ���true�����򷵻�fasle
	bool IfExist(const uint32_t unItem);

	// ��������Delete
	// ˵����ɾ��һ������
	// ������
	//	[IN] unItem - ����
	void Delete(const uint32_t unItem);

	// ��������GetFront
	// ˵������ǰ�����ȡ���ɶ������������������
	// ������
	//	[OUT] vtrItems - ����Ķ���
	//	[IN] unCnt - ����ȡ������
	// ����ֵ��ʵ�ʻ�ȡ������
	uint32_t GetFront(vector<uint32_t>& vtrItems, const uint32_t unCnt);
	
	// ��������GetBack
	// ˵�����Ӻ���ǰ��ȡ���ɶ����������������
	// ������
	//	[OUT] vtrItems - ����Ķ���
	//	[IN] unCnt - ����ȡ������
	// ����ֵ��ʵ�ʻ�ȡ������
	uint32_t GetBack(vector<uint32_t>& vtrItems, const uint32_t unCnt);

	// ��������DelFront
	// ˵������ǰ����ɾ�����ɶ���
	// ������
	//	[IN] unCnt - ��ɾ��������
	// ����ֵ����ɾ��������
	uint32_t DelFront(const uint32_t unCnt); 

	// ��������DelBack
	// ˵�����Ӻ���ǰɾ�����ɶ���
	// ������
	//	[IN] unCnt - ��ɾ��������
	// ����ֵ����ɾ��������
	uint32_t DelBack(const uint32_t unCnt); 

	// ��������Size
	// ˵������ȡ������
	// ����ֵ�������еĶ�����
	uint32_t Size(); 

private:
	// ��������CalcPos
	// ˵��������item�����ݻ����е�λ��
	// ������
	//	[IN] unItem - ����
	// ����ֵ�����������ݻ����е�λ�ã�<byte_pos, bit_pos>
	pair<int32_t,int32_t> CalcPos(const uint32_t unItem);

	// ��������CalcItem
	// ˵����ͨ�����������ݻ����е�λ�ü������ֵ
	// ������
	//	[IN] byte_pos - �ֽ�λ��
	//	[IN] bit_pos - λλ��
	// ����ֵ������ֵ
	uint32_t CalcItem(const int32_t byte_pos, const int32_t bit_pos);

private:
	uint32_t m_unItemCnt;	// ������
	uint8_t* m_pDataBuff;	// ���ݻ���
};

}

#endif /* _FENGYOUNG_API_BLOOM_SET32_H */

