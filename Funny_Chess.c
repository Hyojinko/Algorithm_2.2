#include<stdio.h>
int squares (int i) {
    if (i & 1)
        return i / 4 * 2 + 1;
    else
        return (i - 1) / 4 * 2 + 2;
}
double bishop_location(int N, int K){
    if (K > N * 2 - 1)
        return 0;
    double D[N * 2][K + 1];
    for(int i = 0;i < N * 2; i++){
        D[i][0] = 1;
    }
    D[1][1] = 1;
    for(int i = 2;i < N * 2;i++){
        for(int j = 1;j <= K; j++){
            D[i][j] = D[i-2][j] + D[i-2][j-1] * (squares(i) - j + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i <= K; ++i){
        ans += D[N*2-1][i] * D[N*2-2][K-i];}
        return ans;
}
int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0;i < T;i++){
        int n;
        int k;
        scanf("%d %d", &n, &k);
        double result;
        result = bishop_location(n,k);
        printf("\n%.0lf", result);
    }
    
    
}
