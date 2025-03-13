#include<stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main(){
    int n=4;
    int cap=2;
    int lr[]={1,2,5,10};
    int rr[]={-1,-1,-1,-1};
    int lcap=n;
    int time=0;
    while(lcap>0){
        if(lcap-1>cap){
            int i=0;
            int cur=0;
            while(cur<cap){
                if(lr[i]!=-1)
                {
                    rr[i]=lr[i];
                    lr[i]=-1;
                    cur++;
                    lcap--;
                }
                i++;
            }
                time=time+rr[i-1];
            i=0;
            while(rr[i]==-1)
            i++;
            lr[i]=rr[i];
            rr[i]=-1;
            lcap++;
            time=time+lr[i];
        }
        
        if(lcap-1<=cap){
            int cur=0;
            int timex=0;
            int i=n-1;           
            while(cur<cap){
                    if(lr[i]!=-1){
                        rr[i]=lr[i];
                        lr[i]=-1;
                        cur++;
                        lcap--;
                        timex=max(timex,rr[i]);
                    }
                    i--;
                }
               if(lcap>0){
                    i=0;
                    while(rr[i]==-1)
                    i++;
                    lr[i]=rr[i];
                    rr[i]=-1;
                    lcap++;
                    time=time+lr[i];
                }
                time=time+timex;
            }
        }
        printf("%d",time);
}
