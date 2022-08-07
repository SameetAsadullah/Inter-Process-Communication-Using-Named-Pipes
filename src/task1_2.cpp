#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
using namespace std;

int main() {
	char str[100];

	int fd = open("MYPIPE", O_RDONLY);
	int fd1 = open("MYPIPE1", O_WRONLY);

	if (fd < 0 || fd1 < 0) {
		cout << "Error" << endl;
	}

	while(str[0] != 'Q') {
		read(fd, str, sizeof(str));
		cout << "Message Recieved: " << str << endl;
		cout << "Enter message to send(Q to exit): ";
		cin >> str;
		write(fd1, str, sizeof(str));
	}
	

	close(fd);
	close(fd1);

	return 0;
}