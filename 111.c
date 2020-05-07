#include<stdio.h>
    int main(){
        int num,num1,i,ans,ans1;
        scanf("%d %d", &num, &num1);
        for (i=1; i <=1000; i++){
          if (i%num == 0){
            ans += i;
          }
          else if (i%num1 == 0){
            ans += i;
          }
          }          
        printf("total number is %d",ans);
        return 0;
    }