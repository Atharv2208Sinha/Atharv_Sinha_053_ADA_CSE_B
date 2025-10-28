#include<stdio.h>
#include<stdlib.h>
#include<time.h>

unsigned long long int p_fibonacci(int n, unsigned long long int *F);
unsigned long long int Fibonacci(int n); // Prints Fibonacci series till nth term

int main(){
    clock_t S1, S2, E1, E2;
    double T1, T2, T3, T4, T5;
    volatile unsigned long long int a = 0;

    S1 = clock();
    for(int i=1;i<=1000000;i++){
        a = Fibonacci(30);
    }
    E1 = clock();
    T1 = (double)(E1-S1)/CLOCKS_PER_SEC;
    printf("Running Time for n=30: %lf ns\n",T1*1000);

    S2 = clock();
    for(int i=1;i<=1000000;i++){
        a = Fibonacci(35);
    }
    E2 = clock();
    T2 = (double)(E2-S2)/CLOCKS_PER_SEC;
    printf("Running Time for n=35: %lf ns\n",T2*1000);
    return 0;
}

unsigned long long int p_fibonacci(int n, unsigned long long int *F){
    if(n<=1){ return n; }

    if(F[n]!=0){return F[n];}

    F[n] = p_fibonacci(n-2,F) + p_fibonacci(n-1,F);
    //printf("%d, ",F[n]);
    printf("");
    return F[n];
}

unsigned long long int Fibonacci(int n){
    if(n<0){return 0;}
    unsigned long long int *F; F = (unsigned long long int*)calloc(n+1,sizeof(unsigned long long int));
    if(n==0){
        //printf("0");
        printf("");
        free(F); 
        return 0;
    }
    printf("");
    //printf("0, 1, ");
    unsigned long long int a;
    a = p_fibonacci(n,F);
    free(F);
    return a;
}