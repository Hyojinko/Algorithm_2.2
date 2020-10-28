#include<stdio.h>
int main(){
    int s;
    int i;
    printf("Enter the number of pancakes: ");
    scanf("%d", &s);
    if(s < 1 || s > 30){
        printf("invalid");
    }
    
    int cake[s];
    printf("\nEnter the diameter of pancakes: ");
    for(i = 0;i < s;i++){
        scanf("%d", &cake[i]);
        if(cake[i] < 1 || cake[i] > 30){
            printf("\nInvalid");
            break;
        }
    }
    
    int max = cake[0], max_num = 0;
    int temp = 0;
    int num = s;
    while(num > 1){
        for(i = 0;i < num; i++){
            if(cake[i] > max){
                max = cake[i];
                max_num = i;
            }
        }
        if(max_num!=0){
            for(i = 0; i <= max_num/2; i++){
                temp = cake[i];
                cake[i] = cake[max_num-i];
                cake[max_num- i] = temp;
            }
        }
        
        for(i = 0;i < num/2; i++){
            temp = cake[i];
            cake[i]= cake[num - i - 1];
            cake[num - i -1] = temp;
            }
        
        num--;
    }
    printf("\n");
    for(i = 0;i < s;i++){
        printf("%d ",cake[i]);
    }
    
}
