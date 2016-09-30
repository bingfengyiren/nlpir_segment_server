/////////////////////////////////////////////////////////////////////////////////////////////////////
//
// NumFormulaTree.h ����������ֵ�����(NFT)��ͷ�ļ�
//
// �汾��v1.0 - 2013.08.08 by ����(fengyoung82@gmail.com) 
//
/////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _FENGYOUNG_API_NUM_FORMULA_TREE_H
#define _FENGYOUNG_API_NUM_FORMULA_TREE_H

#include <iostream>
#include <map>
#include <string>
using namespace std;
#include <stdint.h>

namespace fengyoung
{

// �ڵ�����ö��
enum ENumFormulaNodeType
{
	_NUM_VALUE,		// ��ֵ
	_NUM_DIM,		// ��λ
	_UNKNOWN		// δ֪����
};


// ������NumFormulaNode
// ˵������ֵ������Ľڵ���
class NumFormulaNode
{
public:
	// ���캯�� & ��������
	NumFormulaNode();
	NumFormulaNode(const ENumFormulaNodeType eType, const int32_t nVal);
	virtual ~NumFormulaNode();

public:
	ENumFormulaNodeType m_eType;// �ڵ�����
	int32_t m_nVal;					// �ڵ�����
	NumFormulaNode* m_pParent;	// ���ڵ�ָ��
	NumFormulaNode* m_pLeft;	// ���ӽڵ�ָ��
	NumFormulaNode* m_pRight;	// ���ӽڵ�ָ��
};


// ������NumFormulaTree
// ˵������ֵ�����������ת���ʹ洢���ĵ���ֵ���ʽ
class NumFormulaTree
{
public:
	// ���캯�� & ��������
	NumFormulaTree();
	virtual ~NumFormulaTree();

	// ��������Release
	// ˵�����ͷŵ�ǰ��ֵ�����������
	void Release();

	// ��������ReadFromNumString
	// ˵�������ַ����ж�ȡ��ֵ����������ǰ��ֵ�������
	// ������
	//	[IN] strNum - ������ֵ�ַ���
	//	[IN] sNum - ������ֵ�ַ���
	//	[IN] nLen - ������ֵ�ַ�������
	void ReadFromNumString(string& strNum);
	void ReadFromNumString(const char* sNum, const int32_t nLen);

	// ��������GetNumValue
	// ˵������ȡ��ǰ����ʾ����ֵ
	// ����ֵ����ǰ����ʾ����ֵ
	int32_t GetNumValue();

	// ��������GetRoot
	// ˵������ȡ���ڵ�
	// ����ֵ����ǰ��ֵ������ĸ��ڵ�
	NumFormulaNode* GetRoot();

	// ��������PrintTheTree
	// ˵������ӡ��ֵ�����
	// ������
	//	[IN|OUT] os - �����
	//	[IN] pStartNode - ����ӡ�����ĸ��ڵ㣬���ΪNULL�����ӡ��ǰ��������
	//	[IN] nLevel - ����ӡ�������ĸ��ڵ������Ĳ��
	// ����ֵ������ɹ�����true��ʧ�ܷ���false
	void PrintTheTree(ostream& os, NumFormulaNode* pStartNode = NULL, int32_t nLevel = 0);

private:
	// ��������InsertSubTree
	// ˵���������в���һ����������������Ϊָ���ڵ㣨����㣩������
	// ������
	//	[IN] pSubTree - �����������
	//	[IN] pWhere - �����
	//	[IN] bLeft - ������������Ϊ�����ڵ����������ʶ
	// ����ֵ������ɹ�����true��ʧ�ܷ���false
	bool InsertSubTree(NumFormulaTree* pSubTree, NumFormulaNode* pWhere, const bool bLeft = true);

	// ��������InsertNodeAsParent
	// ˵���������в���һ���ڵ㣬�ýڵ���Ϊָ���ڵ㣨����㣩���ӽڵ�
	// ������
	//	[IN] pNode - ������Ľڵ�
	//	[IN] pWhere - �����
	//	[IN] bLeft - ������ڵ���Ϊ�����ڵ�����ӱ�ʶ
	// ����ֵ������ɹ�����true��ʧ�ܷ���false
	bool InsertNodeAsChild(NumFormulaNode* pNode, NumFormulaNode* pWhere, const bool bLeft = true);

	// ��������InsertNodeAsParent
	// ˵���������в���һ���ڵ㣬�ýڵ���Ϊָ���ڵ㣨����㣩�ĸ��ڵ�
	// ������
	//	[IN] pNode - ������Ľڵ�
	//	[IN] pWhere - �����
	//	[IN] bLeft - �����ڵ���Ϊ������ڵ�����ӱ�ʶ
	// ����ֵ������ɹ�����true��ʧ�ܷ���false
	bool InsertNodeAsParent(NumFormulaNode* pNode, NumFormulaNode* pWhere, const bool bLeft = true);

	// �����в�����ֵ��0~9��
	void Insert_NumValue(NumFormulaNode*& pCurrNode, const int32_t nNumVal); 

	// �����в��롰ʮ������ʮ�����������п�����һ����λ��Ҳ���ܼ��е�λҲ����ֵ�Ĺ��ܣ�
	void Insert_Ten(NumFormulaNode*& pCurrNode, const int32_t nNumVal); 

	// �����в��뵥λ������1��10��100��1000��10000��100000000�ȣ�
	void Insert_Dim(NumFormulaNode*& pCurrNode, const int32_t nDimVal); 

	// ��������GetNumValue
	// ˵������ȡһ����������ֵ������ֵ��
	// ������
	// 	[IN] pStartNode - �����ĸ��ڵ�
	// ����ֵ����pStartNodeΪ���ڵ�������������ֵ
	int32_t GetNumValue(NumFormulaNode* pStartNode);

	// ��������HRelease
	// ˵�����ͷ�һ����pNodeΪ���ڵ������
	// ������
	//	[IN] pNode - ���ͷ������ĸ��ڵ�
	void HRelease(NumFormulaNode* pNode);

private:
	char m_cSign;				// ������
	NumFormulaNode* m_pRoot;	// ���ڵ�

	///////////////////////////////////////////////
	// Static operations and variables
public:
	// ����Ĭ��ģʽ��ʼ����ֵ����
	static void InitNumCodeAsDefualt();

	// ͨ�����ֲ�ѯ��ֵ��
	static int32_t QueryNumCode(const char* sSingleNum);

	// ͨ�����ֲ�ѯ�����ű���
	static char QuerySign(const char* sSingleSign);

	static map<string, int> m_mapNumCode;	// ��ֵ���루���� -> ���������֣�
	static map<string, char> m_mapSign;		// �����ű��루���� -> �����ţ�
};

}

#endif /* _FENGYOUNG_API_NUM_FORMULA_TREE_H */


