#include<stdio.h>
#define MAX 1000
typedef struct job{
    int S;
    int T;
    int idx;
}job;



int main(){
    int num;
    scanf("%d", &num);
    printf("\n");
    
    int i;
    for(i = 0;i < num;i++){
        int N;
        scanf("%d",&N);
        
        job jobs[MAX+1];
        
        for(int j = 0;j <N;j++){
            scanf("%d %d", &jobs[j].T, &jobs[j].S);
            jobs[j].idx = j+1;
            if(jobs[j].S < 0 || jobs[j].S > 1000 || jobs[j].T < 0 || jobs[j].T > 1000){
                printf("invalid");
                break;
            }
        }
    
        
        for(int k = 0;k < N-1;k++){
            for(int j = 0;j < N - k - 1;j++){
                if((double)jobs[j].S / (double)jobs[j].T < (double)jobs[j+1].S / (double)jobs[j+1].T){
                    job temp = jobs[j+1];
                    jobs[j+1] = jobs[j];
                    jobs[j] = temp;
                }
                else if((double)jobs[j].S / (double)jobs[j].T == (double)jobs[j+1].S / (double)jobs[j+1].T){
                    if(jobs[j].S > jobs[j+1].T * jobs[j+1].S){
                        continue;
                    }
                    else if(jobs[j].T > jobs[j+1].T){
                        job temp = jobs[j+1];
                        jobs[j+1] = jobs[j];
                        jobs[j] = temp;
                    }
                }
                else
                    continue;
            }}
        
        for(int j = 0;j < N;j++){
            printf("%d ", jobs[j].idx);
        }
        printf("\n");
    }
}
