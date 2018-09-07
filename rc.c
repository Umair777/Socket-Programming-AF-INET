#include"headers.h"
int main()
{
	char buff = 'A';
	int cfd,len;
	struct sockaddr_in csock;
	cfd = socket(AF_INET,SOCK_STREAM,0);
	csock.sin_family = AF_INET;
	csock.sin_port = htons(7000);
	csock.sin_addr.s_addr = inet_addr("127.0.0.1");
	len = sizeof(struct sockaddr_in);
	if((connect(cfd,(struct sockaddr*)&csock,len))==0)
		printf("connection successful\n");
	write(cfd,&buff,1);
	read(cfd,&buff,1);
		printf("server sent %c \n",buff);
	return 0;
}
