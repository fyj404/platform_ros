// server.h
// Linux server class declaration
// Du Jianrui 2022.1.4

#pragma once

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

class Server
{
public:
    Server(const char* ip = "127.0.0.1", int port = 1234, int bufferSize = 100);
    Server& operator=(const Server& anotherServer) = default;

    void listen();
	void accept();
	void disconnect();

	int send(const char* str);
	int receive(char* str);

    ~Server();

private:
    const char* ip_;
	int port_;
	int bufferSize_;

    int serverSocket_;
	sockaddr_in serverAddress_;

	int clientSocket_;
	sockaddr_in clientAddress_;
};
