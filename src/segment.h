#ifndef _NLPIR_SEGMENT_H
#define _NLPIR_SEGMENT_H

#include "NLPIR.h"
#include "uchardet.h"
#include "json/json.h"
#include "fengyoung_api.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <iostream>
#include <string>

struct WORD_CELL
{
	int start;
	int length;
	char sPos[POS_SIZE];
	int iPos;
	int word_ID;
	int word_type;
	int weight;
}

class CSegement
{
	public:
		CSegement();
		~CSegment();
	
	public:
		int init_segment(const string p_Data);
		int segement_work(const string in_string,const int type,string& out_string);
	
	private:
		int return_json_str();
		int segment_core_words(const string in_string, string& out_string);
		int segment_words(const string in_string, string& out_string, int posTag);
		int segment_cate();
}

#endif
