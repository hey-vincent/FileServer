/*
 * Server.h
 *
 *  Created on: 2017年10月9日
 *      Author: momo
 */

#ifndef SERVER_H_
#define SERVER_H_

#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT	1991
#define MAX_WAITING_ACCEPT	100


class Server {
public:
	Server();
	virtual ~Server();
	bool Run();

protected:

};

#endif /* SERVER_H_ */
