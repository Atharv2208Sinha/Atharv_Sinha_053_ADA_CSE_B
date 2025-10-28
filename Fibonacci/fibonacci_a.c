#include<stdio.h>
#include<stdlib.h>
#include<time.h>

unsigned long long int n_fibonacci(int n); // gives nth term of fibonacci series

int main(){
    clock_t S1, S2, E1, E2;
    double T1, T2, T3, T4, T5;
    volatile unsigned long long int a = 0;

    S1 = clock();
    for(int i=1;i<=1000;i++){
        a = n_fibonacci(30);
    }
    E1 = clock();
    T1 = (double)(E1-S1)/(CLOCKS_PER_SEC);
    printf("Running Time for n=30: %lf ms\n",T1);

    S2 = clock();
    for(int i=1;i<=100;i++){
        a = n_fibonacci(35);
    }
    E2 = clock();
    T2 = (double)(E2-S2)*10/(CLOCKS_PER_SEC);
    printf("Running Time for n=35: %lf ms\n",T2);

    return 0;
}

unsigned long long int n_fibonacci(int n){
    if(n<=1){return (unsigned long long int)n;}
    return n_fibonacci(n-2) + n_fibonacci(n-1);
}