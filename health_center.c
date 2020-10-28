#include<stdio.h>
#define INF 100000;
typedef struct{
    int v1;
    int v2;
    int d;
    int index;
}PLACE;
int main(){
    int f, I;
    scanf("%d %d", &f, &I);
    int C;
    scanf("%d", &C);
    PLACE pla[I];
    for(int i = 0;i < I;i++){
        scanf("%d %d %d", &pla[i].v1, &pla[i].v2, &pla[i].d);
        pla[i].index = i;
    }
    PLACE stat;
    int path[I][I];
    for(int i = 0;i < I;i++){
        stat = pla[f];
        if(dep == i){
            for(int j = 0;j < I;j++){
                if(pla[j].v2 == pla[j+1].v1){
                    stat = pla[j+1];
                }
            }
        }
    }
}
