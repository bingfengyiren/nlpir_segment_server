#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>

///C++ head
#include <string>
#include <iostream>
using namespace std;
#include "fengyoung_api.h"
using namespace fengyoung;

#include "woo/log.h"
#include "woo/tcpserver.h"
#include "woo/config.h"


struct conf_t
{
	string log_path;
	string log_type;
	string log_flush_type;
	size_t log_buf_size;
	string ip;
	size_t port;
	bool long_conn;
	size_t thread_num;
	size_t recv_buf_size;
	size_t send_buf_size;
	size_t recv_to;
	size_t send_to;
};

conf_t load_conf(const string conf_path)
{
	conf_t g_conf;
	ConfigFile conf;
	conf.ReadFromConfigFile(conf_path.c_str());
	g_conf.log_path = conf.GetValueAsString("log_path");
	g_conf.log_type = conf.GetValueAsString("log_type");
	g_conf.log_flush_type = conf.GetValueAsString("log_flush_type");
	g_conf.log_buf_size = conf.GetValueAsInt("log_buf_size");
	g_conf.ip = conf.GetValueAsString("ip");
	g_conf.port = conf.GetValueAsInt("port");
	g_conf.recv_buf_size = conf.GetValueAsInt("recv_buf_size");
	g_conf.send_buf_size = conf.GetValueAsInt("send_buf_size");
	g_conf.recv_to = conf.GetValueAsInt("recv_timeout");
	g_conf.send_to = conf.GetValueAsInt("send_timeout");
	g_conf.long_conn = conf.GetValueAsBool("long_conn");
	g_conf.thread_num = conf.GetValueAsInt("thread_num");
	return g_conf;
}

int main(int argc,char** argv)
{
	signal(SIGPIPE,SIG_IGN);
	
	if(argc < 2)
	{
		char tmp[1024];
		sprintf(tmp,"usage:%s",argv[0]);
		cout<<tmp<<endl;
	}
	const string conf_path(argv[1]);
	conf_t g_conf = load_conf(conf_path);
	woo::open_log(g_conf.log_path.c_str(), g_conf.log_buf_size, g_conf.log_type.c_str(), g_conf.log_flush_type.c_str());
	woo::tcp_server_t *server = woo::tcp_server_create();
	/*
	 *
	 * */	

	void **query_handle_data = create_query_handle_data(g_conf.thread_num);
	if(! query_handle_data)
	{
		LOG_ERROR("create query_handle error");
		return -1;
	}
	woo::tcp_server_open(server, g_conf.ip, g_conf, port, woo::binary_recv, req_handle, query_handle_data,
					g_conf.thread_num, g_conf.long_conn, g_conf.recv_buf_size, g_conf.send_buf_size, g_conf.recv_to, g_conf.send_to);
	woo::tcp_server_run(server);
	woo::tcp_server_wait(server);
	woo::tcp_server_destory(server);
	return 0;	
}
