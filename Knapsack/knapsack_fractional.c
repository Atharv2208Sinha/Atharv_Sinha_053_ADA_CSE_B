#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

typedef struct items{
    //char name;
    double profit;
    double weight;
    double p_w;
    bool sel;
} I;

typedef struct ret{
    I *keep;
    int size;
} R;

void gen_items(I* items, int n);
R knapsack(I *items,int W, int n);

int main(){
    int N, W;
    clock_t S1, S2, S3, S4, E1, E2, E3, E4;
    double T1, T2, T3, T4, p=0;
    R K;

    I items[120];
    gen_items(items,120);
    S1 = clock();
    for(int i=1;i<=1000000;i++){
        K = knapsack(items,100,100);
        free(K.keep);
    }
    E1 = clock();
    T1 = (double)(E1-S1)/(CLOCKS_PER_SEC*1000);
    printf("Running Time for W=100 & N=100: %lf ms\n",T1);

    S2 = clock();
    for(int i=1;i<=1000000;i++){
        K = knapsack(items,200,100);
        free(K.keep); 
    }
    E2 = clock();
    T2 = (double)(E2-S2)/(CLOCKS_PER_SEC*1000);
    printf("Running Time for W=200 & N=100: %lf ms\n",T2);

    S3 = clock();
    for(int i=1;i<=1000000;i++){
        K = knapsack(items,100,120);
        free(K.keep);
    }
    E3 = clock();
    T3 = (double)(E3-S3)/(CLOCKS_PER_SEC*1000);
    printf("Running Time for W=100 & N=120: %lf ms\n",T3);

    S4 = clock();
    for(int i=1;i<=1000000;i++){
        K = knapsack(items,200,120);
        free(K.keep); 
    }
    E4 = clock();
    T4 = (double)(E4-S4)/(CLOCKS_PER_SEC*1000);
    printf("Running Time for W=200 & N=120: %lf ms\n",T4);
    
    /*printf("Enter no. of items: "); scanf("%d",&N);
    printf("Enter Max Weight: "); scanf("%d",&W);
    
    I items[N];
    for(int i=0;i<N;i++){
        printf("Name (char): "); scanf(" %c",&items[i].name);
        
        printf("Profit: "); 
        scanf("%lf",&items[i].profit);
        
        printf("Weight: ");
        scanf("%lf",&items[i].weight);
        
        items[i].p_w = items[i].profit/items[i].weight;
        items[i].sel = false;
    }

    R K = knapsack(items, W, N);
    printf("\nInventory:\n");
    for(int z=0;z<K.size;z++){
        printf("Item %d:\n",z+1);
        //printf("Name: %c\n",K.keep[z].name);
        printf("Profit: %lf\n",K.keep[z].profit);
        printf("Weight: %lf\n",K.keep[z].weight);
        p += K.keep[z].profit;
    }
    printf("Total Profit: %lf",p);

    free(K.keep);*/
    return 0;
}

void gen_items(I* items, int n){
    srand(time(NULL));
    for(int i=0;i<n;i++){        
        items[i].profit = (double)(rand() %20) +1;
        
        items[i].weight = (double)(rand() %20) +1;
        
        items[i].p_w = items[i].profit/items[i].weight;
        items[i].sel = false;
    }
}

R knapsack(I *items,int W, int n){
    if(n<=0){R r;r.keep=NULL; r.size=0; return r;}
    int c=0;
    double max_p_w = 0 , w=0;
    I *keep; keep = (I*)malloc(n*sizeof(I)); if(keep==NULL){R r;r.keep=NULL; r.size=0; return r;}

    for(int i=0;i<n;i++){
        max_p_w = 0;
        for(int j=0;j<n;j++){
            if(items[j].sel == true){continue;}
            if(items[j].p_w > max_p_w){max_p_w = items[j].p_w; c=j;}
        }

        keep[i] = items[c];
        items[c].sel=true;
        w += items[c].weight;
        if(w>=W){ 
            keep[i].weight -= (w-W);
            keep[i].profit *= (keep[i].weight/items[c].weight);
            c=i; break;
        }
    }

    keep = realloc(keep,sizeof(I)*(c+1));
    R r; r.keep = keep; r.size = c+1;
    return r;
}