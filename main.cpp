//
//  main.cpp
//  nlpir_segment_server
//
//  Created by cuiming on 16/9/23.
//  Copyright © 2016年 cuiming. All rights reserved.
//

#include "NLPIR.h"
#include "json/json.h"
#include "uchardet.h"
#include "fengyoung_api.h"
#include "segment.h"
#include <string>
#include <string.h>
#include <iostream>

using namespace std;
using namespace fengyoung;
/*
struct result_t
{
	int start;
	int length;
	char sPos[POS_SIZE];
	int iPos;
	int word_ID;
	int word_type;
	int weight;
};
*/
char* detect(const char* str,int len)
{
	char* charset;
	uchardet_t handle = uchardet_new();
	int retval = uchardet_handle_data(handle,str,len);
	if (retval != 0)
	{
		cout<<"uchardet-tests: handle data error."<<endl;
	}
	uchardet_data_end(handle);
	charset = strdup(uchardet_get_charset(handle));
	uchardet_delete(handle);
	return charset;
}

int main() {
    Json::Reader reader;
    Json::FastWriter writer;
	int iRet = 0;
	string data_file="../resource";
	CSegment* seg = new CSegment();
	iRet = seg->init_segment(data_file);
	if(iRet != 0 )
	{
		char tmp[1024];
		sprintf(tmp,"usage:%s",data_file.c_str());
		cout<<"init nlpir environment failed!\n"<<tmp<<endl;
	}
	/*
	char sentence[100] = "Bill Clinton 是美国总统,好像没来过北京理工大学";
	int nCount;
	const result_t* result = NLPIR_ParagraphProcessA(sentence,&nCount,true);
	for(int i=0;i<nCount;i++)
	{
		char tmp[2000];
		sprintf(tmp,"Start=%d Length=%d Word_Id=%d Pos_ID=%d\n weight=%d",
						result[i].start,
						result[i].length,
						result[i].word_ID,
						result[i].iPOS,
						result[i].weight);
		int start = result[i].start;
		int length = result[i].length;
		char t[200];
		strncpy(t,tmp + start,length);
		cout<<t<<endl;
	}
	//cout<<strlen(detect(result,strlen(result)))<<endl;
	StringSplitter* ss = new StringSplitter(result," ");
	string sub = ss->GetSubString();
	while(sub!="")
	{
		cout<<sub<<endl;
		sub = ss->GetSubString();
	}
	*/	
	//cout<<result<<endl;
	NLPIR_Exit();
    return 0;
}
