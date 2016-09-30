/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// BinarySearch.h : ���ֲ��ҷ���(ģ�庯��)������ & ����
//
// �汾��v1.0 - 2013.04.01 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_BINARY_SEARCH_H 
#define _FENGYOUNG_API_BINARY_SEARCH_H

#include <vector>
#include <map>
using namespace std;


namespace fengyoung
{

// ��������BinarySearch
// ˵������������н��ж��ֲ���
// ������
//	[IN] vtrSorted - �������
//	[IN] key - �����ҵ�key
//	[IN] _start_pos - ���в��ҵ���ʼλ�ã�С��0����0Ϊ��ʼλ�ã�
//	[IN] _end_pos - ���в��ҵ���ֹλ�ã�С��0����ڶ��е���ĩλ�����Զ�����ĩλΪ��ֹλ�ã�
// ����ֵ��key���ڵ�λ��
template <class _K>
int32_t BinarySearch(vector<_K>& vtrSorted, const _K key, const int32_t _start_pos = -1, const int32_t _end_pos = -1); 

// ��������BinarySearch
// ˵��������key-value����н��ж��ֲ���
// ������
//	[IN] vtrSortedMap - �����key-value����
//	[IN] key - �����ҵ�key
//	[IN] _start_pos - ���в��ҵ���ʼλ�ã�С��0����0Ϊ��ʼλ�ã�
//	[IN] _end_pos - ���в��ҵ���ֹλ�ã�С��0����ڶ��е���ĩλ�����Զ�����ĩλΪ��ֹλ�ã�
// ����ֵ��key���ڵ�λ��
template <class _K, class _V>
int32_t BinarySearch(vector<pair<_K,_V> >& vtrSortedMap, const _K key, const int32_t _start_pos = -1, const int32_t _end_pos = -1); 

}



// ��������н��ж��ֲ���
template <class _K>
int32_t fengyoung::BinarySearch(vector<_K>& vtrSorted, const _K key, const int32_t _start_pos, const int32_t _end_pos)
{
	int32_t size = (int32_t)vtrSorted.size(); 
	if(size <= 0)
	  return -1; 
	if(_start_pos > _end_pos && (_start_pos >= 0 || _end_pos >= 0))
	  return -1;

	int32_t left = _start_pos >= 0 ? _start_pos : 0;	// ��߽�
	int32_t right = ((_end_pos >= 0) && (_end_pos < size)) ? _end_pos : (size - 1);		// �ұ߽�
	int32_t mid;	// ��ֵ 

	while(left <= right)
	{
		mid = (left + right) / 2; 
		if(key < vtrSorted[mid])
		{
			right = mid - 1; 
		}
		else if(key > vtrSorted[mid])
		{
			left = mid + 1; 
		}
		else
		{
			return mid; 
		}
	}

	return -1; 
}


// ����key-value����н��ж��ֲ���
template <class _K, class _V>
int32_t fengyoung::BinarySearch(vector<pair<_K,_V> >& vtrSortedMap, const _K key, const int32_t _start_pos, const int32_t _end_pos)
{
	int32_t size = (int32_t)vtrSortedMap.size(); 
	if(size <= 0)
	  return -1; 
	if(_start_pos > _end_pos && (_start_pos >= 0 || _end_pos >= 0))
	  return -1;

	int32_t left = _start_pos >= 0 ? _start_pos : 0;	// ��߽�
	int32_t right = ((_end_pos >= 0) && (_end_pos < size)) ? _end_pos : (size - 1);		// �ұ߽�
	int32_t mid;	// ��ֵ 

	while(left <= right)
	{
		mid = (left + right) / 2; 
		if(key < vtrSortedMap[mid].first)
		{
			right = mid - 1; 
		}
		else if(key > vtrSortedMap[mid].first)
		{
			left = mid + 1; 
		}
		else
		{
			return mid; 
		}
	}

	return -1; 
}


#endif /* _FENGYOUNG_API_BINARY_SEARCH_H */


