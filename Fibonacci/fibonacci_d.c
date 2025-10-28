#include<stdio.h>
#include<stdlib.h>
#include<time.h>

unsigned long long int n_fibonacci(int n); // gives nth term of fibonacci series

int main(){
    clock_t S1, S2, E1, E2;
    double T1, T2, T3, T4, T5;
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

unsigned long long int n_fibonacci(int n){
    if(n<0){return 0;}
    if(n<=1){return n;}
    unsigned long long int A[n+1];
    A[0] = 0;
    A[1] = 1;

    for(int i = 2; i<=n; i++){
        A[i] = A[i-1] + A[i-2];
    } 
    return A[n];
}