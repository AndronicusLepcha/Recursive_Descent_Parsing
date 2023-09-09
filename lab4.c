#include<string.h>
#include<stdio.h>
#include<ctype.h>

char p1[10]="S->cAd";
char p2[10]="A->a|b";
char w[10]="cbd";

int dp=1;
int ip=0;
int idx=0;
int lenp1=0;
int lenw=0;

char buffer[10];

void main(){
    void backtrack(){
        printf("Dp is currently = %d\n",dp);
        dp--;
        printf("Back Track dp = %d\n",dp);
        //return dp;
    }

    void expandVariable(){
        int localindex=1;
        dp++;
        for(int i=0;i<strlen(p2);i++){
            if(p2[i] != '>'){
                localindex++;
            }
            localindex++;
            break;
        }
        //printf("%c",p2[localindex]);
        if(p2[localindex]==w[ip]){
            printf("\n%c character Accepted\n",w[ip]);
            backtrack();

        }
        else{
            printf("Wrong direction towards %c so bakctrack \n",p2[localindex]);
            int y=localindex+1;
            if(p2[y] == '|'){
                if(p2[y+1] == w[ip]){
                    printf("%c character Accepted \n",w[ip]);
                }
            }
            backtrack();
        }
    }

    void isAccepted(char ch){
        if(isupper(p1[idx])){
            printf("%c is Variable need to Expand\n",p1[idx]);
            idx++;
            printf("%d dp value \n",dp);
            expandVariable();
        }
        else{
            if(ch == p1[idx]){
                printf("%c Terminating Symbol Accepted\n",ch);
                printf("%d dp value\n",dp);
                idx++;
            }
        }
    }
    
    void findIndex(){
        while(p1[idx] != '>'){
            idx++;
        }
        idx++;
        //printf("Terminating Symbol %c \n",p1[idx]);
    }

    lenp1=strlen(p1);
    lenw=strlen(w);
    findIndex();

    while(ip < lenw){
        dp++;
        isAccepted(w[ip]);
        ip++;
    }
}