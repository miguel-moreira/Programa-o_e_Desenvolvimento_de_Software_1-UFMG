#include <stdio.h>

int fib(int n){
    if (n == 1 || n == 2) return 1;
    else return fib(n-1) + fib(n-2);
}

int main(){
    int t=0, res=0;
    scanf("%d",&t);
    res = fib(t);
    printf("%d",res);
}