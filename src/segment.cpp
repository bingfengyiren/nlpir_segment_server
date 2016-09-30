#include "segment.h"

CSegement::CSegment()
{

}

CSegment::~CSegment()
{

}

int CSegment::init_segment(const string p_Data)
{
	int iRet = 0;
	if(!NLPIR_Init(p_Data.c_str()))
	{
		iRet = -1;
		return iRet;
	}
	return iRet;
}

int CSegment::segment_core_words(const string in_string, const int bPosTag,string& out_string)
{
	int iRet = 0;	
	return iRet;
}

int CSegment::segment_words(const string in_string, string& out_string,int posTag)
{
	int iRet = 0;
	const char* paragraph = in_string.c_str();
	const char* result = NLPIR_ParagraphProcess(paragraph,PosTag);
	const char* sDilm = " ";
	StringArray words_pos(result,sDlim);
	words_pos_cnt = words_pos.Count();
	for(uint32_t idx = 0;idx < words_pos_cnt;idx++)
	{
		sDilm = "/";
		StringSplitter word_pos(words_pos.GetString(idx).c_str(),sDilm);
		string word = word_pos.GetSubString(bIsFront = true);
		string pos = word_pos.GetSubString(bIsFront = false);
		cout<<word<<endl;
	}
	return iRet;
}

int CSegment::segment_cate()
{
	int iRet = 0;
	return iRet;
}
