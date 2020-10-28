//RSA Problem
#pragma warning(disable:4996)
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int Mod_Exp(int a,int  b,int n){
    int c = 0;
    int D = 1;
    int count = 0;
    
    int arr[1000];
    
    for(int i = 0; b > 0; i++){
        arr[i] = b % 2;
        count++;
        b = b / 2;
    }
    for(int j = count - 1;j >=0;j--){
        c = 2*c;
        D = (D*D)%n;
        if(arr[j] == 1){
            c+=1;
            if(a != 0){
                D = (D * a) % n;
            }
        }
    }
    return D;
    
}


int main(){
    int M;
    scanf("%d", &M);
    int p, q;
    scanf("%d %d", &p, &q);
    
    int n = p*q;
    int pe = (p-1)*(q-1);
    int e = 1;
    for(int i = 2;i<pe;i++){
        if(i % 2 != 0 && pe % i != 0){
            e = i;
            break;
        }
    }
    
    int d;
    for(int i = e; i > 0;i--){
        d = (i * pe  + 1) / e;
        if(d < pe)
            break;
    }
    
    
    int P;
    int Q;
    P = Mod_Exp(M,e,n);
    printf("%d\n",P);
    Q = Mod_Exp(P,d,n);
    printf("%d\n", Q);
    


}
