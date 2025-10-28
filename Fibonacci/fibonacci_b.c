#include<stdio.h>
#include<stdlib.h>
#include<time.h>

unsigned long long int p_fibonacci(int n); // Prints Fibonacci series till nth term

int main(){
    clock_t S1, S2, E1, E2;
    double T1, T2;
    volatile unsigned long long int a = 0;

    S1 = clock();
    for(int i=1;i<=1000000;i++){
        a = p_fibonacci(30);
    }
    E1 = clock();
    T1 = (double)(E1-S1)/CLOCKS_PER_SEC;
    printf("Running Time for n=30: %lf ns\n",T1*1000);

    S2 = clock();
    for(int i=1;i<=1000000;i++){
        a = p_fibonacci(35);
    }
    E2 = clock();
    T2 = (double)(E2-S2)/CLOCKS_PER_SEC;
    printf("Running Time for n=35: %lf ns\n",T2*1000);

    return 0;
}

unsigned long long int p_fibonacci(int n){
    if(n<=0){return 0;}
    unsigned long long int a=0, b=1, c;
    //printf("0, 1, ");
    printf("");
    for(int i = 2; i<=n; i++){
        c = a+b;
        //printf("%d, ",c);
        printf("");
        a = b;
        b = c;
    } 
    return b;
}