#include<stdio.h>
int main(){
    int N;
    do{
        scanf("\n%d", &N);
        float c1, c2, n1, n2;
        scanf("%f %f", &c1, &n1);
        scanf("%f %f", &c2, &n2);
        int a = 0, b = 0 ;
        int i, j;
        if((c1/n1) < (c2 / n2)){
            for(i = N / n1 ;i >=0  ;i--){
                for(j = 0;j <= N / n2;j++){
                    if(n1*i + n2*j == N){
                        a = i;
                        b = j;
                    }
            }
        }
        }
        else{
            for(j = N / n2;j >=0 ;j--){
                for(i = 0;i <= N / n1;i++){
                    if(n1 *1 + n2*j == N){
                        a = i;
                        b = j;
                    }
            }
            
        }
        }
        if(a!=0 && b!= 0){
        printf("%d %d", a, b);
        }
        else
            printf("\nfailed");
        
        a = 0;
        b = 0;
        
    }while(N!= 0);
}
