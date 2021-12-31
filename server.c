/* ************************************************************************
> File Name:     server.c
> Author:        Nate
> MAIL:          nathanag7griz@gmail.com
> Created Time:  2021年12月30日 星期四 15时06分03秒
> Description:   
 ************************************************************************/

#include"tic.h"
#include"my_socket.h"
#define IP "127.0.0.1"
#define PORT 8888

void tic_init(char tic[][4]){
    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            tic[i][j]= '_';
        }
    }
    for(i=0;i<N;i++)
        tic[0][i]=tic[i][0]=(i+'0');
}

void tic_show(char tic[][4]){

    int i,j;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            printf("%c",tic[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int msg[2];
    char tic[N][N];
    SA client_addr;
    int fd_socket,fd_client;
	my_socketSer(&fd_socket,MY_TCP,IP,PORT);
	my_listen(fd_socket,5);
	int sendlen=0,recvlen=0,len=0;
	int i,j,a,b;
    tic_init(tic);
    tic_show(tic);
    printf("welcome to the Tic_Tac_Toe game !\n");
    my_accept(&fd_client,fd_socket,(pSA)&client_addr,&len);
    while(1){
        printf("please wait for the client\n");
        my_recv(&recvlen,fd_client,msg,1024);
        tic[msg[0]][msg[1]]='0';
        tic_show(tic);
    loop:
        printf("please make a move\n");
        scanf("%d %d",&a,&b);
        if(a<1||a>N-1||b<1||b>N-1){
            printf("beyond the chessboard");
            goto loop;
        }
        if(tic[a][b]!='_'){
            printf("this position is occupied");
            goto loop;
        }
        tic[a][b]='x';
        tic_show(tic);
        if(check(a,b,tic,'x')){
            printf("nice,you win!");
            break;
        }
        msg[0]=a;
        msg[1]=b;
        my_send(&sendlen,fd_client,msg,recvlen);
    }
    my_close(fd_socket);
    my_close(fd_client);
}
