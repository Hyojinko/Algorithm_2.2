#include<stdio.h>
#include<math.h>
#include<stdlib.h>

typedef struct edge{
    int v1, v2;
    double length;
}EDGE;
int cmp(const void*a, const void*b){
    if(((EDGE*)a)-> length > ((EDGE*)b)->length)
       return 1;
    if(((EDGE*)a)-> length < ((EDGE*)b)->length)
        return -1;
    return 0;
}
int main(){
    int T;
    scanf("%d", &T);
    EDGE edge[T];
    float point[T][T];
    for(int i = 0;i < T;i++){
        scanf("\n%f %f", &point[i][0], &point[i][1]);
    }
    float key;
    int a = 0;
    for(int i = 0;i < T;i++){
        for(int j = i + 1;j < T;j++){
            edge[a].v1 = i;
            edge[a].v2 = j;
            key = sqrt(pow(point[i][0] - point[j][0], 2) + pow(point[i][1] - point[j][1], 2));
            edge[a++].length = key;
            
        }
    }
    qsort(edge, a, sizeof(EDGE), cmp);
    int save[100];
    for(int i = 0;i < T;i++){
        save[i] = i;
    }
    float sum = 0;
    for(int i = 0;i < T;i++){
        if(save[edge[i].v1] != save[edge[i].v2])
        {
            int temp = save[edge[i].v1];
            for(int j = 0;j < T;j++){
                if(save[j] == temp)
                    save[j] = save[edge[i].v2];
            }
            sum += edge[i].length;
        }
    }
    printf("\nkruskal algorithm");
    printf("\n%.2f\n", sum);
    return 0;
    
}
