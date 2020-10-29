//Connecting Freckles
#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct edge{
    int v1, v2;
    double length;
}EDGE;

int cmp(const void*a, const void *b){//conpare length of edge a and b
    if(((EDGE*)a)->length > ((EDGE*)b)->length)
        return 1;
    if(((EDGE*)a)->length < ((EDGE*)b)->length)
        return -1;
    return 0;
}

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 0;t < T;t++){
        int N;
        scanf("%d", &N);
        EDGE edge[N*N];
        double point[N][N];
        
        for(int i = 0;i < N;i++){
            scanf("\n%lf %lf", &point[i][0],&point[i][1]);
            if(point[i][0] < 0 || point[i][0] > 30 ||point[i][1] < 0 || point[i][1] > 30){
                printf("\nINVALID");
                break;
            }
        }
        int a = 0;
        for(int i = 0;i < N - 1 ;i++){
            for(int j = i+1;j < N;j++){
                edge[a].v1 = i;
                edge[a].v2 = j;
                edge[a++].length =sqrt(pow(point[i][0] - point[j][0],2) + pow(point[i][1] - point[j][1],2));//get length of link
            }
        }
       
        qsort(edge,a,sizeof(EDGE), cmp); //quick sort edge
        
        int save[1000];
        for(int i = 0;i < N;i++){
            save[i] = i;
        }//create variable save
        float sum = 0;
        for(int i = 0;i < N; i++){
            if(save[edge[i].v1] != save[edge[i].v2]){//if two edges are different
                int temp = save[edge[i].v1];
                for(int j = 0;j < N;j++){
                    if(save[j] == temp)//if save[j] is same with sage[edge[i].v1]
                        save[j] = save[edge[i].v2];//value of save[edge[i].v2] is inserted into save[j]
                }
                sum += edge[i].length;//get sum
            }
        }
        printf("\n%.2f", sum);
    }
    return 0;
   
}
