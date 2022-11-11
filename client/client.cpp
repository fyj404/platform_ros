// client.cpp
// Linux client class definition
// Du Jianrui 2022.1.5

#include "client.h"

Client::Client(const char* ip, int port, int bufferSize)
	: ip_(ip), port_(port), bufferSize_(bufferSize)
{
	// sends request to the server
	memset(&socketAddress_, 0, sizeof(socketAddress_));
	socketAddress_.sin_family = AF_INET;                  // IPv4
	socketAddress_.sin_addr.s_addr = inet_addr(ip_);      // host address
	socketAddress_.sin_port = htons(port_);               // port number
}

void Client::connect()
{
	// creates a socket
	socket_ = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	::connect(socket_, (sockaddr*)&socketAddress_, sizeof(socketAddress_));
}

void Client::disconnect()
{
	// closes sockets
	close(socket_);
}

int Client::send(const char* str)
{
	return write(socket_, str, strlen(str) + sizeof(char));
}

int Client::receive(char* str)
{
	return read(socket_, str, bufferSize_);
}

Client::~Client()
{

}
