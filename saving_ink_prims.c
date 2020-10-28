#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define INF 100000;


int main(){
    int n;
    int i,j;
    scanf("%d", &n);
    if(n > 30 || n < 0)
        exit(-1);
    float point[n][2];
    for(i = 0;i < n;i++){
        scanf("\n%f %f", &point[i][0], &point[i][1]);
    }
    float G[n][n];
    int a = 0;
    
    for(i = 0;i < n - 1;i++){
        for(j = i+1;j < n;j++){
            G[i][a++] = sqrt(pow(point[i][0] - point[j][0], 2) + pow(point[i][1] - point[j][1], 2));
        }
        a = 0;
    }
    int v1, v2;
    float min;
    float distance[n],min_cost;
    int from[n];
    int visited[n];
    int end_edge;
    float cost[n][n];
    float spanning[n][n];
    
    for(i = 0;i < n - 1;i++){
        for(j = 0;j < n-i - 1;j++){
            if(G[i][j] == 0){
                cost[i][j] = INF;
            }
            else{
                cost[i][j] = G[i][j];
                spanning[i][j] = 0;
            }
        }
    }
    distance[0] = 0;
    visited[0] = 1;
    for(i = 0;i < n - 1;i++){
        for(j = 0;j < n - i - 1;j++){
            distance[i] = cost[0][j];
            from[i] = 0;
            visited[i] = 0;
        }
    }
    min_cost = 0.0;
    end_edge = n - 1;
    
    while(end_edge > 0){
        min = INF;
        for(i = 1;i < n;i++){
            if(visited[i] == 0 && distance[i] < min){
                v2 = n - i - 1;
                min = distance[i];
            }
        }
        v1 = from[v2];
        spanning[v1][v2] = distance[v2];
        spanning[v2][v1] = distance[v2];
        end_edge--;
        visited[v2] = 1;
        for(i = 1;i < n - 1;i++){
            if(visited[i] == 0 && cost[i][v2] < distance[i]){
                distance[i] = cost[i][v2];
                from[i] = v2;
            }
        }
        min_cost += cost[v1][v2];
    }
    printf("\nprim's algorithm");
    printf("\n%.2f", min_cost);

}
