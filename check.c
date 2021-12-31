/* ************************************************************************
> File Name:     check.c
> Author:        Nate
> MAIL:          nathanag7griz@gmail.com
> Created Time:  2021年12月30日 星期四 10时53分29秒
> Description:   
 ************************************************************************/

#include"tic.h"

int check(int a,int b,char tic[N][N],char flagWin){
    int i,j,cou1=0,cou2=0;
    for(i=b+1;i<N;i++)
        if(tic[a][i]==flagWin)
            cou1++;
        else break;
    for(i=b-1;i>0;i--)
        if(tic[a][i]==flagWin) 
            cou1++;
        else break;
    if(cou1>=2)       
        return 1;
    cou1=0;


    
    for(i=a+1;i<N;i++)
        if(tic[i][b]==flagWin)
            cou1++;
        else break;
    for(i=a-1;i>0;i--)
        if(tic[i][b]==flagWin) 
            cou1++;
        else break;
    if(cou1>=2) 
        return 1;
    cou1=0;


    for(i=a+1,j=b+1;i<N,b<N;i++,j++)
        if(tic[i][j]==flagWin)
            cou1++;
        else break;
    for(i=a-1,j=b-1;i>0,b>0;i--,j--)
        if(tic[i][j]==flagWin)
            cou1++;
        else break;
    if(cou1>=2)      
        return 1;
    cou1=0;



    for(i=a-1,j=b+1;i>N,j<N;i++,j++)
        if(tic[i][j]==flagWin)
            cou1++;
        else break;
    for(i=a+1,j=b-1;i<N,j>0;i++,j--)
        if(tic[i][j]==flagWin)
            cou1++;
        else break;
    if(cou1>=2)
        return 1;
    return 0;
}
