#include<stdio.h>
int d, x, y;
int find_gcd(int ,int );
void Extended(int , int );
int main(){
    for(int i = 0;i < 2;i++){
        int A, B;
        scanf("%d %d", &A, &B);
        find_gcd(A, B);
        Extended(A, B);
     
        printf("\n%d %d %d",x,y,d);
        
    }
    return 0;
}
int find_gcd(int a,int b){
    if(b == 0)
        d = a;
    else
        d = find_gcd(b, a % b);
    return d;
}
void Extended(int a, int b){
    if(b == 0){
        x = 1;
        y = 0;
        return;
    }
    Extended(b, a%b);
    int x1 = x - (a / b) * y;
    x = y;
    y = x1;
    
    
    
}
