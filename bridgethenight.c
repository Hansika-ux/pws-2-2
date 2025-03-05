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
//A group of walkers arrives at a river in the night. They want to cross a bridge, which can hold a limited number of walkers at a time. The walkers have just one torch, which needs to be used when crossing the bridge. Each walker takes a certain time to cross; a group crossing together must walk at the slowest walker’s pace. What is the shortest time it takes for all walkers to cross the bridge?
//For example, Sample Input 1 assumes the bridge can hold 2 walkers at a time and there are 4 walkers with crossing times 1 minute, 2 minutes, 5 minutes and 10 minutes, respectively. The shortest time of 17 minutes can be achieved.
//Input Constraints:
//n (2 ≤ n ≤ 104) is the number of walkers, and c (2 ≤ c ≤ 104) is the number of walkers the bridge can hold at a time.