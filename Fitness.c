#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

#define openTime 10
typedef struct Person {
    char name[20];
    int waitingTime;
    int satisfaction;
    int dissatisfaction;
    int index;
}person;

int main() {
    person member[10];
    FILE* fp;
    fp = fopen("input1.txt", "r");
    int cnt = 0;
    for (int i = 0; i < 10; i++) {
        fscanf(fp, "%s %d %d %d", &member[i].name, &member[i].waitingTime, &member[i].satisfaction, &member[i].dissatisfaction);
        member[i].index = i;
        cnt++;
   }
    fclose(fp);
    for(int i = 0 ;i < cnt - 1;i++){
        for(int j = 0;j < cnt - i - 1;j++){
            if((double)member[j].dissatisfaction/ (double)member[j].waitingTime < (double)member[j+1].dissatisfaction/ (double)member[j+1].waitingTime){
                person temp = member[j+1];
                member[j+1] = member[j];
                member[j] = temp;
            }
            else if((double)member[j].dissatisfaction/ (double)member[j].waitingTime == (double)member[j+1].dissatisfaction/ (double)member[j+1].waitingTime){
                if(member[j].dissatisfaction > member[j+1].waitingTime * member[j+1].dissatisfaction){
                    continue;
                }
                else if(member[j].waitingTime > member[j+1].waitingTime){
                    person temp = member[j+1];
                    member[j+1] = member[j];
                    member[j] = temp;
                }
            }
            else
                continue;
    }
    }
    int tot_satisfaction = 0;
    printf("\nOrder of use: ");
    for(int i = 0;i < cnt;i++){
        printf(" %d", member[i].index);
        tot_satisfaction += member[i].satisfaction - ((member[i].index - member[i].waitingTime)*member[i].dissatisfaction);
    }printf("\n");
    printf("Total satisfaction: %d", tot_satisfaction);
   /*for (int i = 0; i < 2; i++) {
      printf("%s %d %d %d\n", member[i].name, member[i].waitingTime, member[i].satisfaction, member[i].dissatisfaction);
   }*/
    
    
    
}
