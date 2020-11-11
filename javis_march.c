#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct Frosh{
    double x, y;
    double angle[100];
}Frosh;

int main(){
    int T;
    scanf("%d", &T);
    for(int i = 0;i < T;i++){
        int S;
        scanf("%d", &S);
        Frosh frosh[S];
        double dis = 0;
        int j;
        for(j = 0;j < S;j++){
            scanf("%lf %lf", &frosh[j].y, &frosh[j].x);
        }
        int min = 0;
        
        for(j = 0;j < S;j++){
            if(frosh[j].y < frosh[min].y){
                if(frosh[j].y == frosh[min].y){
                    if(frosh[j].x < frosh[min].x)
                        min = j;
                    else
                        continue;
                }else
                    min = j;
            }
        }
       
        int k;
        for(j = min; j < S;j++){
            for(k = 0;k < S;k++){
                if(k == j)
                    continue;
                else{
                    if((frosh[k].x - frosh[j].x > 0) && (frosh[k].y - frosh[j].y > 0))
                        frosh[j].angle[k] = fabs(frosh[k].y - frosh[j].y) / (fabs(frosh[k].x - frosh[j].x) + fabs(frosh[k].y - frosh[j].y));
                    else if((frosh[k].x - frosh[j].x > 0) && (frosh[k].y - frosh[j].y < 0))
                        frosh[j].angle[k] = 2 - (fabs(frosh[k].y - frosh[j].y) / (fabs(frosh[k].x - frosh[j].x) + fabs(frosh[k].y - frosh[j].y)));
                    else if((frosh[k].x - frosh[j].x > 0) && (frosh[k].y - frosh[j].y < 0))
                        frosh[j].angle[k] = 2 + (fabs(frosh[k].y - frosh[j].y) / (fabs(frosh[k].x - frosh[j].x) + fabs(frosh[k].y - frosh[j].y)));
                    else
                        frosh[j].angle[k] = 4 -  (fabs(frosh[k].y - frosh[j].y) / (fabs(frosh[k].x - frosh[j].x) +  fabs(frosh[k].y - frosh[j].y)));

                }
            }
        }
        int next;
        double min_angle[S];
        for(j = 0;j < S;j++){
            min_angle[j] = frosh[j].angle[0];
            for(k = 0;k <S;k++){
                if(frosh[j].angle[k] < min_angle[j]){
                    min_angle[j] = frosh[j].angle[k];
                    next = k;
                }
                dis += sqrt(pow(frosh[k].x - frosh[j].x, 2) + pow(frosh[k].y - frosh[j].y, 2));
                j = k;
               
            }
            
        }
        double min1 =sqrt(pow(frosh[0].x, 2) + pow(frosh[0].y, 2));
        double min2 = sqrt(pow(frosh[min].x, 2) + pow(frosh[min].y, 2));
        int min_n;
        for(j = 0;j < S;j++){
            
            if(sqrt(pow(frosh[j].x, 2) + pow(frosh[j].y, 2)) <= min){
                min1 =sqrt(pow(frosh[j].x, 2) + pow(frosh[j].y, 2));
                min_n = j;
            }
        }
        dis += min1;
        for(j = min_n;j < S;j++){
            
            if(sqrt(pow(frosh[j].x, 2) + pow(frosh[j].y, 2)) <= min2)
                min2 =sqrt(pow(frosh[j].x, 2) + pow(frosh[j].y, 2));
        }
        dis += min2;
        printf("\n%.2lf\n", dis + 2);
       
    }
}
