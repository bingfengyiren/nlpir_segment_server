#include "fengyoung_api.h"
using namespace fengyoung;
#include <iostream>
using namespace std;

int main(int argc,char** argv)
{
	ConfigFile conf;
	string conf_path = "../conf/nlpir_segment_server.conf";
	conf.ReadFromConfigFile(conf_path.c_str());
	cout<<conf.GetValueAsInt("port")<<endl;
	return 0;
}
