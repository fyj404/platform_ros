// server.cpp
// Linux server class definition
// Du Jianrui 2022.1.4

#include "server.h"

Server::Server(const char* ip, int port, int bufferSize)
	: ip_(ip), port_(port), bufferSize_(bufferSize)
{
	// initializes the server socket
	serverSocket_ = socket(AF_INET, SOCK_STREAM, 0);

	// binds the socket
	memset(&serverAddress_, 0, sizeof(serverAddress_));
	serverAddress_.sin_family = AF_INET;                  // IPv4
	serverAddress_.sin_addr.s_addr = inet_addr(ip_);      // host address
	serverAddress_.sin_port = htons(port_);               // port number
	bind(serverSocket_, (sockaddr*)&serverAddress_, sizeof(serverAddress_));
}

void Server::listen()
{
	::listen(serverSocket_, 20);
}

void Server::accept()
{
	socklen_t socketAddressSize = sizeof(clientAddress_);
	clientSocket_ = ::accept(serverSocket_, (sockaddr*)&clientAddress_, &socketAddressSize);
}

void Server::disconnect()
{
	// closes sockets
	close(clientSocket_);
}

int Server::send(const char* str)
{
	return write(clientSocket_, str, strlen(str) + sizeof(char));
}

int Server::receive(char* str)
{
	return read(clientSocket_, str, bufferSize_);
}

Server::~Server()
{
	// closes sockets
	close(serverSocket_);
}
