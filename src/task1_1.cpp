#include<iostream>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<stdio.h>
#include<fcntl.h>
using namespace std;

int main() {
	int fd = mkfifo("MYPIPE", 0666);
	int fd1 = mkfifo("MYPIPE1", 0666);
	char str[100];

	if (fd < 0) {
		cout << "MYPIPE already created" << endl;
	}

	else {
		cout << "MYPIPE created" << endl;
	}

	if (fd1 < 0) {
		cout << "MYPIPE1 already created" << endl;
	}

	else {
		cout << "MYPIPE1 created" << endl;
	}

	fd = open("MYPIPE", O_WRONLY);
	fd1 = open("MYPIPE1", O_RDONLY);

	if (fd < 0 || fd1 < 0) {
		cout << "Error" << endl;
	}

	while(str[0] != 'Q') {
		cout << "Enter message to send(Q to quit): ";
		cin >> str;
		write(fd, str, sizeof(str));
		cout << "Messaged Recieved: ";
		read(fd1, str, sizeof(str));
		cout << str << endl;
	}

	close(fd);
	close(fd1);

	return 0;
}