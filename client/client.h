// client.h
// Linux client class declaration
// Du Jianrui 2022.1.5

#pragma once

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

class Client
{
public:
    Client(const char* ip = "127.0.0.1", int port = 1234, int bufferSize = 100);
	Client& operator=(const Client& anotherClient) = default;

    void connect();
	void disconnect();

	int send(const char* str);
	int receive(char* str);

    ~Client();

private:
    const char* ip_;
	int port_;
	int bufferSize_;

	int socket_;
	sockaddr_in socketAddress_;
};
