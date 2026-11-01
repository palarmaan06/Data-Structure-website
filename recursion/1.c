// CALCULATE FACTORIAL OF A NUMBER USING RECURSION
#include<stdio.h>
#include<stdlib.h>

int main(){
    int num,fac;
    printf("enter a number:");
    scanf("%d",&num);
    fac=fact(num);
    printf("Factorial of %d : %d",num,fac);
}
int fact(int num){
 if(num==0 || num==1){
    return 1;
 }
 else{
    return num*fact(num-1);
 }
}