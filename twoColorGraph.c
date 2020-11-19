#include<stdio.h>
typedef struct POINT{
    int stat;
    int end;
    int index;
}Point;
int main(){
    int vertex;
    scanf("%d", &vertex);
    int link;
    scanf("%d", &link);
    Point point[link];
    for(int i = 0;i < link;i++){
        scanf("%d %d", &point[i].stat, &point[i].end);
    }
    int cnt = 0;
    for(int i = 0;i < link;i++){
        for(int j = 0;j < link;j++){
            if(point[i].stat == point[j].stat && point[i].end != point[j].stat && point[j].stat != point[i].end){
                cnt++;
            }
        }
    }
    if(cnt / link == link)
        printf("\ntwo-color");
    else
        printf("\nnon two-color");
    
    
    
}
