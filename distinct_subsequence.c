#include<stdio.h>
#include<string.h>

int main(){
    int N;
    scanf("%d", &N);
    int i,j;
    char X[1000], Z[100];
    
    for(i = 0;i < N;i++){
        scanf("%s", X);
        if(strlen(X) > 10000){
            printf("Invalid");
            break;
        }
        scanf("%s",Z);
        if(strlen(Z) > 100){
            printf("invalid");
            break;
        }
        int arr[strlen(Z) + 1][strlen(X) + 1];
        
        for(i = 1; i < strlen(Z); i++){
            arr[i][0] = 0;
        }
        for(i = 0; i < strlen(X); i++){
            arr[0][i] = 1;
        }
        for(i = 1;i<=strlen(Z); i++){
            for(j = 1;j <= strlen(X); j++){
                if(Z[i-1] != X[j-1])
                    arr[i][j] = arr[i][j-1];
                else
                    arr[i][j] = arr[i][j-1] + arr[i-1][j-1];
            }
        }
        
        printf("\n%d", arr[strlen(Z)][strlen(X)]);
    }
}
