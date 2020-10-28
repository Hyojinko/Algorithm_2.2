#include<stdio.h>
int main(){
    int s;

    printf("enter the number of schedules: ");

    scanf("%d",&s);

    int time1_h[s], time2_h[s],time1_m[s],time2_m[s];
    char schedule[s][100];
    int i;

    for(i = 0;i < s; i++){
        scanf("%d %d %d %d %s",&time1_h[i],&time1_m[i],&time2_h[i],&time2_m[i],schedule[i]);
    }
    
    for(i = 0;i < s; i++){
        if(time1_h[i] == time2_h[i]){
            if(time1_m[i] >= time2_m[i])
                printf("unvalid time");
        }
        else{
            if(time1_h[i] < 10 || time2_h[i] < 10 || time1_h[i] > 18 || time2_h[i] > 18 || time1_m[i] < 0 || time1_m[i] > 59 || time2_m[i] < 0 || time2_m[i] > 59)
                printf("unvalid");
            else{
                if(time1_h[i] == 18){
                    if(time1_m[i] > 0)
                        printf("unvalid");}
                if(time2_h[i] == 18){
                    if(time2_m[i] > 0){
                       printf("unvalid");}
                       }
            }}
        for(i = 0;i <s; i++){
            printf("\n%d:%02d %d:%02d %s",time1_h[i],time1_m[i],time2_h[i],time2_m[i],schedule[i]);
    }
}
     int term[s];
      int max = term[0], maxH, maxM, max_num = 0;
      for(i = 0;i < s; i++){
          if(time2_h[i+1] == time1_h[i]){
              term[i] = time1_m[i+1] - time2_m[i];
          }
          else{
              if(time1_m[i+1] < time2_m[i]){
                  term[i] = (time1_h[i+1] - time2_h[i] - 1) * 60 + time2_m[i+1] - time1_m[i] + 60;
              }
              else{
                  term[i] = (time1_h[i+1] - time2_h[i]) * 60 + time1_m[i+1] - time2_m[i];
              }
          }
      }
      for(i = 0; i < s; i++){
          if(term[i] > max){
              max = term[i];
              max_num = i;
          }
      }
      if(max > 59){
          maxH = max / 60;
          maxM = max % 60;
          printf("\nDay #1: the longest nap starts at %d:%02d and will last for %d hours and %d minutes\n",time2_h[max_num],time2_m[max_num], maxH, maxM);
      }
      else{
          printf("\nDay #1: the longest nap starts at %d:%02d and will last for %d minutes\n",time2_h[max_num],time2_m[max_num], max);
      }
      return 0;
     
}
