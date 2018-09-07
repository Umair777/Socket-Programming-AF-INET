#include"headers.h"
#include"request.h"
int main(int argc , char* argv[])
{
        printf("processing client : begin\n");
        int wfd=atoi(argv[1]);
                printf("wfd : %d\n",wfd);
        int rfd=atoi(argv[2]);
                printf("rfd : %d\n",rfd);
        result res;
        request rq;
        read(rfd,&rq,sizeof(rq));
        res.pid=getpid();
        res.opr1=rq.opr1;
        res.opr2=rq.opr2;
        res.result=res.opr1+res.opr2;
        printf("rc1_pid :%d\noperation : %c\n",rq.pid,rq.opt);
        printf("pc1_pid :%d\noperation : %c is done and result is :%d\n",rq.pid,rq.opt,res.result);
        write(wfd,&res,sizeof(res));
        printf("processing client : End\n");
}
     
