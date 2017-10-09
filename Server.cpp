/*
 * Server.cpp
 *
 *  Created on: 2017年10月9日
 *      Author: wensheng
 */

#include "Server.h"
#include <iostream>


using namespace std;

Server::Server() {
	// TODO Auto-generated constructor stub
	cout << "Constructor has been executed." << endl;

}

Server::~Server() {
	// TODO Auto-generated destructor stub
}

bool Server::Run(){
	int skt = socket(AF_INET, SOCK_STREAM, 0);
	if(skt == -1){
		perror("failed to initialize socket");
		return false;
	}

	struct sockaddr_in addr;
	memset(addr.sin_zero, 0, 8);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port 	= htons(SERVER_PORT);	// 端口
	addr.sin_family	= AF_INET;


	int bind_ret = bind(skt, (struct sockaddr*)(&addr), sizeof(sockaddr) );
	if(bind_ret == -1){
		perror("failed to bind socket");
		return false;
	}


	int lstn_ret = listen(skt , MAX_WAITING_ACCEPT);
	if(-1 == lstn_ret){
		perror("failed to listen socket");
		return false;
	}

	struct sockaddr_in *clinet_addr = NULL;
	const int max_size = 1024;
	char buf[max_size];
	memset(buf, 0, max_size);

	int add_len = sizeof(sockaddr_in);

	while(true){
		int session_skt = accept(skt, (struct sockaddr*)clinet_addr, (socklen_t*)&add_len);

		memset(buf,0, max_size);


		int request_info = recv(session_skt, buf, max_size, 0);
		if(-1 == request_info){
			perror("error occurred while receiving data from requesting.");
			continue;
		}

		cout << buf <<endl;

		char* str_msg = "HTTP/1.1 400 NotOK \r\nContent-Type: text/html\r\n\r\n<h1>Hey!</h1>This message was send by wensheng's FILE_SERVER.\r\n";

		send(session_skt,str_msg, strlen(str_msg), 0 );

		close(session_skt);
	}


	close(skt);
	return true;
}
