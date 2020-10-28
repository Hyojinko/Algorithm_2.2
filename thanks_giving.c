#include<stdio.h>
int main(){
    int n;
    scanf("%d", &n);
    int i;
    int fee[n];
        
    for(i = 0;i < n; i++){
        scanf("%d",&fee[i]);
    }
    
    if(n > 100)
        printf("\nInvalid");
    int sum = 0, avg;
    
    
    for(i = 0;i < n; i++){
        sum += fee[i];
        if(fee[i] > 100000)
            printf("\nInvalid");
    }
    
    avg = sum / n;
    int charge_sum = 0;
    int charge;
    for(i = 0;i < n;i++){
        
        if(avg % 10 == 0){
            if(fee[i] >= avg)
                continue;
            else{
                charge = avg - fee[i];
                charge_sum += charge;
            }
        }
        else{
            if(fee[i] >= avg)
                continue;
            else{
                if(fee[i] % 10 != 0){
                    charge = avg - fee[i] + 10 - avg % 10;
                    charge_sum += charge;
                }
                else{
                    charge = avg - fee[i] - avg % 10;
                    charge_sum += charge;
                }
            }
        }
    }
    printf("\n%d", charge_sum);
        printf("\n");
        
    
}
