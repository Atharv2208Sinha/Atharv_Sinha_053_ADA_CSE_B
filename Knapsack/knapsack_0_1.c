#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

typedef struct items{
    //char name;
    int profit;
    int weight;
} I;

typedef struct ret{
    I *keep;
    int size;
} Ret;

void gen_items(I* items, int n);
void swap(I *A, int a, int b);
void quick_sort(I *A, int s, int e);
int max(int A, int B);
Ret knapsack(I *items,int W, int n);

int main(){
    int N, W, p=0, w=0;
    clock_t S1, S2, S3, S4, S5, S6, E1, E2, E3, E4, E5, E6;
    double T1, T2, T3, T4, T5, T6;
    Ret K;
    
    I items[120];
    gen_items(items,120);
    S1 = clock();
    for(int i=1;i<=1000;i++){
        K = knapsack(items,50,100);
        free(K.keep);
    }
    E1 = clock();
    T1 = (double)(E1-S1)/(CLOCKS_PER_SEC);
    printf("Running Time for W=50 & N=100: %lf ms\n",T1);

    S2 = clock();
    for(int i=1;i<=1000;i++){
        K = knapsack(items,100,100);
        free(K.keep); 
    }
    E2 = clock();
    T2 = (double)(E2-S2)/(CLOCKS_PER_SEC);
    printf("Running Time for W=100 & N=100: %lf ms\n",T2);

     S3 = clock();
    for(int i=1;i<=1000;i++){
        K = knapsack(items,200,100);
        free(K.keep); 
    }
    E3 = clock();
    T3 = (double)(E3-S3)/(CLOCKS_PER_SEC);
    printf("Running Time for W=200 & N=100: %lf ms\n",T3);

    S4 = clock();
    for(int i=1;i<=1000;i++){
        K = knapsack(items,50,120);
        free(K.keep);
    }
    E4 = clock();
    T4 = (double)(E4-S4)/(CLOCKS_PER_SEC);
    printf("Running Time for W=50 & N=120: %lf ms\n",T4);

    S5 = clock();
    for(int i=1;i<=1000;i++){
        K = knapsack(items,100,120);
        free(K.keep); 
    }
    E5 = clock();
    T5 = (double)(E5-S5)/(CLOCKS_PER_SEC);
    printf("Running Time for W=100 & N=120: %lf ms\n",T5);

    S6 = clock();
    for(int i=1;i<=1000;i++){
        K = knapsack(items,200,120);
        free(K.keep); 
    }
    E6 = clock();
    T6 = (double)(E6-S6)/(CLOCKS_PER_SEC);
    printf("Running Time for W=200 & N=120: %lf ms\n",T6);



    /*printf("Enter no. of items: "); scanf("%d",&N);
    printf("Enter Max Weight: "); scanf("%d",&W);
    I items[N];
    for(int i=0;i<n;i++){
        printf("Name (char): "); scanf(" %c",&items[i].name);
        
        printf("Profit: "); 
        scanf("%d",&items[i].profit);
        
        printf("Weight: ");
        scanf("%d",&items[i].weight);
    }

    Ret K = knapsack(items, W, N);
    printf("\nInventory:\n");
    for(int z=K.size-1; z>=0;z--){
        printf("Item %d:\n", K.size-z);
        printf("Name: %c\n",K.keep[z].name);
        printf("Profit: %d\n",K.keep[z].profit);
        printf("Weight: %d\n",K.keep[z].weight);
        p += K.keep[z].profit;
        w += K.keep[z].weight;
    }
    printf("Total Profit: %d\n",p);
    printf("Total Weight: %d",w);

    free(K.keep);*/
    return 0;
}

void gen_items(I* items, int n){
    srand(time(NULL));
    for(int i=0;i<n;i++){        
        items[i].profit = (rand() %30) +1;
        
        items[i].weight = (rand() %30) +1;
    }
}

void swap(I *A, int a, int b){
    I temp;
    temp=A[a];
    A[a]=A[b];
    A[b]=temp;
}

void quick_sort(I *A, int s, int e){
    if(e<=s){return;}
    int c, sw, p;
    p=e;
    c=sw=s;
    while(c<=p){
        if(A[c].weight<=A[p].weight){ if(c!=sw){swap(A,c,sw);} ++c; ++sw;}
        else{++c;}
    }
    quick_sort(A,s,sw-2);
    quick_sort(A,sw,e);
}

int max(int A, int B){
    if(A>=B){return A;}
    return B;
}

Ret knapsack(I *items,int W, int N){
    if(N<=0){Ret r;r.keep=NULL; r.size=0; return r;}
    quick_sort(items,0,N-1);

    int T[N+1][W+1], J, H, c=0; for(int i=0;i<=W;i++){ T[0][i]=0; }

    for(int i=1;i<=N;i++){
        T[i][0]=0;
        for(int j=1;j<=W;j++){
            if( j - items[i-1].weight < 0 ){ J=0; }
            else{ J = T[i-1][j - items[i-1].weight] + items[i-1].profit; }
            T[i][j] = max(T[i-1][j], J);
        }
    }
    H=T[N][W];

    I *keep; keep = (I*)malloc(N*sizeof(I)); if(keep==NULL){Ret r;r.keep=NULL; r.size=0; return r;}
    bool in = false; J=N-1;

    while(H>0){
        for(int i=J;i>=0;i--){
            in = false;
            for(int j=1;j<=W;j++){
                if(T[i][j]==H){ in = true; break;}
            }
            if(in==false){J=i; break;}
        }
        keep[c]=items[J];
        H -= items[J].profit;
        ++c;
    }

    keep = realloc(keep,sizeof(I)*c);
    Ret r; r.keep = keep; r.size = c;
    return r;
}