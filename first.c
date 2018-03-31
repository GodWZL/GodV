#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int a;
    printf("请选择彩票获取方式\n");
    printf("       随机请输入1    \n");
    printf("       自己输入请输入2\n");
    scanf("%d", &a); 
    if(a == 1){
        int a[8];
        int i,j;
        srand(time(NULL));
        for(i=0;i<9;i++){
            int j=0;
            a[i] = rand()%10;
            printf("%d\t",a[i]);
        }
    printf("这是你的号码\n");
         for(int i=0;i<9;i++){
            printf("%d",a[i]);
        }
    return 0;
    }
    if(a == 2){

        int b[8];
        for(int i=0;i<9;i++){
            printf("请输入号码\n");
            scanf("%d",&b[i]);
        }
    printf("这是你的号码\n");    
        for(int i=0;i<9;i++){
            printf("%d",b[i]);
        }
    return 0;
    }
    if(a == 8495){
        printf("欢迎进入管理员系统\n");
    }
    else{
        printf("输入无效，请输入有效编号\n");
    }
}