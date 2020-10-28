#include<stdio.h>

typedef struct elephant{
    int W;
    int S;
    int index;
}elephant;

int main(){
    
    int i,j;
    int N;
    scanf("%d",&N);
    elephant e[N];
    for(i = 0;i < N;i++){
        scanf("%d %d", &e[i].W, &e[i].S);
        e[i].index = i;
    }
    
    elephant S1[N], S2[N];

    for(i = 0;i < N-1;i++){
        for(j = 0;j < N- i - 1;j++){
            if(e[j].W > e[j+1].W){
                elephant tmp = e[j];
                e[j] = e[j+1];
                e[j+1] = tmp;
            }
        }
    }
    
    for(i = 0;i < N;i++){
        S1[i] = e[i];
    }
    
    for(i = 0;i < N-1;i++){
        for(j = 0;j < N- i - 1;j++){
            if(e[j].S < e[j+1].S){
                elephant tmp = e[j];
                e[j] = e[j+1];
                e[j+1] = tmp;
            }
        }
    }
    
    for(i = 0;i < N;i++){
        S2[i] = e[i];
    }
    
    int idx[N];
    
    for(i = 0;i < N;i++){
        for(j = 0;j < N;j++){
            if(S1[i].index == S2[j].index)
                idx[i] = j;
        }
    }
    int max;
    int cnt[N-1];
    int max_num[N];
    for(i = 0; i < N - 1;i++){
        max = idx[i];
        cnt[i] = 1;
        max_num[i] =i;
        for(j = i+1;j < N - i - 1;j++){
            if(idx[j] > max){
                max = idx[j];
                cnt[i]++;
            }
        }
    }
    
    int max_i = cnt[0], max_n = 0;
    
    for(i = 0;i < N - 1;i++){
        if(cnt[i] > max_i){
            max_i = cnt[i];
            max_n = max_num[i];
            
        }
    }
    max = idx[max_n];
   
    
    printf("\n%d", max_i);
    printf("\n%d", S2[max].index+1);
    
    for(i = max_n;i < max_n + max_i + 2;i++){
        if(idx[i] > max){
            max = idx[i];
            printf("\n%d",S2[max].index+1);
        }
    }
}
