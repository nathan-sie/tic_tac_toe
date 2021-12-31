/* ************************************************************************
> File Name:     client.c
> Author:        Nate
> Mail:          nathanag7griz@gmail.com
> Created Time:  2021年12月30日 星期四 20时05分49秒
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
    SA server_addr;
    int fd_socket,index,sendlen=0,recvlen=0;
	my_socketCli(&fd_socket,MY_TCP,IP,PORT,&server_addr);
	my_connect(fd_socket,(pSA)&server_addr,sizeof(SA));
    printf("client start");
    tic_init(tic);
    int a,b;
    while(1){
loop:
        printf("please make your move : \n");
        scanf("%d %d",&a,&b);
        if(a<1||a>3||b<1||b>3){
            printf("beyond the chessboard \n");
            goto loop;
        }
        if(tic[a][b]!='_'){
            printf("this postion is occupied \n");
            goto loop;
        }
        tic[a][b]='0';
        tic_show(tic);
        if(check(a,b,tic,'0')){
            printf("nice, you win \n");
            break;
        }
        msg[0]=a;
        msg[1]=b;
        my_send(&sendlen,fd_socket,msg,8);
        printf("please wait for the other player \n");
        my_recv(&recvlen,fd_socket,msg,1024);
        tic[msg[0]][msg[1]]='x';
        tic_show(tic);
    }
    my_close(fd_socket);
}
