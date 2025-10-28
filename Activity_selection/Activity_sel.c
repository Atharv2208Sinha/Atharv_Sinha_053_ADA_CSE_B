#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

typedef struct activities{
    //char name;
    int S;
    int E;
} A;

typedef struct ret{
    A *Sel;
    int size;
} R;

void gen_acts(A* acts, int n);
void merge(A *act, int s, int m, int e);
void mergesort(A *act, int s, int e);
R Sel_act(A *act, int N);

int main(){
    clock_t S1, S2, S3, S4, S5, E1, E2, E3, E4, E5;
    double T1, T2, T3, T4, T5;
    R K;

    printf("Max end-time = 200\n");

    A Acts[100];
    gen_acts(Acts,100);
    S1 = clock();
    for(int i=1;i<=1000;i++){
        K = Sel_act(Acts,20);
        free(K.Sel);
    }
    E1 = clock();
    T1 = (double)(E1-S1)/(CLOCKS_PER_SEC);
    printf("Running Time for N=20: %lf ms\n",T1);

    S2 = clock();
    for(int i=1;i<=1000;i++){
        K = Sel_act(Acts,40);
        free(K.Sel); 
    }
    E2 = clock();
    T2 = (double)(E2-S2)/(CLOCKS_PER_SEC);
    printf("Running Time for N=40: %lf ms\n",T2);

     S3 = clock();
    for(int i=1;i<=1000;i++){
        K = Sel_act(Acts,60);
        free(K.Sel); 
    }
    E3 = clock();
    T3 = (double)(E3-S3)/(CLOCKS_PER_SEC);
    printf("Running Time for N=60: %lf ms\n",T3);

    S4 = clock();
    for(int i=1;i<=1000;i++){
        K = Sel_act(Acts,80);
        free(K.Sel);
    }
    E4 = clock();
    T4 = (double)(E4-S4)/(CLOCKS_PER_SEC);
    printf("Running Time for N=80: %lf ms\n",T4);

    S5 = clock();
    for(int i=1;i<=1000;i++){
        K = Sel_act(Acts,100);
        free(K.Sel); 
    }
    E5 = clock();
    T5 = (double)(E5-S5)/(CLOCKS_PER_SEC);
    printf("Running Time for N=100: %lf ms\n",T5);

    /*int N;
    printf("Enter no. of activities: "); scanf("%d",&N);
    
    A act[N];
    for(int i=0;i<N;i++){
        //printf("Name (char): "); scanf(" %c",&act[i].name);
        
        printf("Start: "); 
        scanf("%d",&act[i].S);
        
        printf("End: ");
        scanf("%d",&act[i].E);
    }

    R K = Sel_act(act,N);
    printf("\nItinerary:\n");
    for(int z=0;z<K.size;z++){
        printf("Activity %d:\n",z+1);
        //printf("Name: %c\n",K.Sel[z].name);
        printf("Start: %d\n",K.Sel[z].S);
        printf("End: %d\n",K.Sel[z].E);
    }

    free(K.Sel);*/
    return 0;
}

void gen_acts(A* acts, int n){
    srand(time(NULL));
    for(int i=0;i<n;i++){        
        acts[i].S = (rand() %201);
        
        acts[i].E = (rand() %(201-acts[i].S)) + acts[i].S+1;
    }
}

void merge(A *act, int s, int m, int e){
    int s1=m-s+1, s2=e-m;
    A a1[s1],a2[s2];
    int i=0, j=0, k=0;
    
    while(i<s1){a1[i]=act[s+i]; ++i;}
    while(j<s2){a2[j]=act[m+1+j]; ++j;}
    
    i=0; j=0;
    
    while(i<s1 && j<s2){
        if(a1[i].E < a2[j].E){act[s+k]=a1[i]; ++i; ++k;}
        else if(a1[i].E == a2[j].E){
            if(a1[i].S <= a2[j].S){ act[s+k]=a1[i]; ++i; ++k; }
            else{ act[s+k]=a2[j]; ++j; ++k; }
        }
        else{act[s+k]=a2[j]; ++j; ++k;}
    }

    while(i<s1){act[s+k]=a1[i]; ++i; ++k;}

    while(j<s2){act[s+k]=a2[j]; ++j; ++k;}
}

void mergesort(A *act, int s, int e){
    if(s>=e){return;}
    int m=(s+e)/2;
    mergesort(act,s,m);
    mergesort(act,m+1,e);
    merge(act,s,m,e);
}

R Sel_act(A *act, int N){
    if(N<=0){R r;r.Sel=NULL; r.size=0; return r;}
    mergesort(act,0,N-1);

    A *Sel; Sel = (A*)malloc(N*sizeof(A)); if(Sel==NULL){R r;r.Sel=NULL; r.size=0; return r;}
    A temp;
    int c=0;
    Sel[0] = act[0];

    for(int i=1;i<N;i++){
        temp = act[i];
        if(Sel[c].E <= act[i].S){ ++c; Sel[c]=act[i]; }
    }

    R r; r.Sel=Sel; r.size=c+1;
    return r;
}