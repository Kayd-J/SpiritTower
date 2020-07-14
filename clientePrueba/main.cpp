
#include <iostream>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

// Saves us from typing std::cout << etc. etc. etc.
using namespace std;

void main()
{
	WSADATA data;
	WORD version = MAKEWORD(2, 2);
	int wsOk = WSAStartup(version, &data);
	sockaddr_in server;
	server.sin_family = AF_INET; // AF_INET = IPv4 addresses
	server.sin_port = htons(54000); // Little to big endian conversion
	inet_pton(AF_INET, "127.0.0.1", &server.sin_addr); // Convert from string to byte array
	SOCKET out = socket(AF_INET, SOCK_DGRAM, 0);	
	char buffer[1024];
	string s = "{\"Matrix\":\"[[0, 0, 0, 0], [0, 0, 1, 0], [0, 0, 0, 1], [0, 1, 0, 1]]\",\"Player\":{\"Health\":100,\"Score\":10,\"Shield\":false,\"Sword\":true},\"Enemies\":{\"A\":{\"Alert\":true,\"Range\":2},\"B\":{\"Alert\":false,\"Range\":4}}}";

	int sendOk = sendto(out, s.c_str(), s.size() + 1, 0, (sockaddr*)&server, sizeof(server));
	recvfrom(out, buffer, sizeof(buffer), 0, (struct sockaddr*)NULL, NULL);
	puts(buffer);

	// Close the socket
	closesocket(out);

	// Close down Winsock
	WSACleanup();
}