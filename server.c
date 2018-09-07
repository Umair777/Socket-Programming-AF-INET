#include"headers.h"
#include"request.h"
int main()
{
	char ch;
	request rq;
	result res;
	int sfd,cfd,len,fret;
	struct sockaddr_in sock;
	sfd = socket(AF_INET,SOCK_STREAM,0);
	sock.sin_family=AF_INET;
	sock.sin_addr.s_addr=htonl(INADDR_ANY);
	sock.sin_port=htons(7500);
	len = sizeof(struct sockaddr_in);
	if((bind(sfd,(struct sockaddr*)&sock,len))==0)
	{
		printf("server socket name assigned\n");
	}
	listen(sfd,4);
	cfd = accept(sfd,(struct sockaddr*)&sock,&len);
	printf("client socket request is accepted\n");
	read(cfd,&rq,1);
	printf("server read %c\n",rq.opr);
	ch = rq.opt;
	switch(ch)
	{
	case '+':	res.resl = rq.opr1 + rq.opr2;
			write(cfd,&res.resl,sizeof(result));
	}
	return 0;
}
