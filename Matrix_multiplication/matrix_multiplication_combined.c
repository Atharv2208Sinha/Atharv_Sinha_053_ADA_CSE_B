#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

clock_t FBS_DnC, FBE_DnC, FB_DnC=0;
clock_t FBS_S, FBE_S, FB_S=0;

//Iterative
int **matrix_X(int **A, int **B, int N);

//Divide & Conquer
void freee(int **A, int n);
int *matrix_2x2(int **A, int **B, int Ai, int Aj, int Bi, int Bj, int n);
int *matrix_add(int *A, int *B, int n);
int *matrix_DC(int **A, int **B, int Ai, int Aj, int Bi, int Bj, int N);
int **matrix_DnC(int **A, int **B, int N);

// Strassen
void freee(int **A, int n);
int **matrix_2x2_S(int **A, int **B, int N);
int **matrix_add_S(int **A, int Ai, int Aj, int Bi, int Bj, int n);
int **matrix_sub_S(int **A, int Ai, int Aj, int Bi, int Bj, int n);
int **matrix_S(int **A, int **B, int N);

int main(){
    int N, pow2=2;
    clock_t S_X, E_X, BS_X, BE_X, B_X=0;
    clock_t S_DnC, E_DnC, BS_DnC, BE_DnC, B_DnC=0;
    clock_t S_S, E_S, BS_S, BE_S, B_S=0;
    double time_X, time_DnC, time_S;

    printf("Enter order N of Matrix [N should be power of 2]: "); scanf("%d",&N);
    bool N2=false;
    while(N2==false){
        while(pow2<=N){
            if(N==pow2){N2=true;}
            pow2 *= 2;
        }
        if(N2==false){printf("Please enter correct value for N: "); scanf("%d",&N);}
    }

    int **A; A = (int**)malloc(N*sizeof(int*));
    for(int a=0;a<N;a++){ A[a] = (int*)calloc(N,sizeof(int));}
    int **B; B = (int**)malloc(N*sizeof(int*));
    for(int a=0;a<N;a++){ B[a] = (int*)calloc(N,sizeof(int));}

    srand(time(NULL));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            A[i][j]= rand() %100;
        }
    }

    srand(time(NULL));
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            B[i][j]= rand() %100;
        }
    }

    //for(int i=0;i<N;i++){ A[i][i] = B[i][i] = 1; }

    int **C_X, **C_DnC, **C_S;
    int n; 
    if(N<=20){n=10000;}
    else if(N<=50){n=1000;}
    else if(N<=200){n=100;}
    else if(N<=500){n=10;}
    else {n=1;}

    S_X = clock();
    for(int I=1;I<=n;I++){
        C_X = matrix_X(A, B, N);
        BS_X = clock();
        freee(C_X,N);
        BE_X = clock();
        B_X += (BE_X - BS_X);
    }
    E_X = clock();

    time_X = (double)(E_X - S_X - B_X)*(1000/n)/(CLOCKS_PER_SEC*1000);
    printf("Running Time for n=%d by Iterative Method: %lf s\n",N ,time_X);

    S_DnC = clock();
    for(int I=1;I<=n;I++){
        C_DnC = matrix_DnC(A, B, N);
        BS_DnC = clock();
        freee(C_DnC,N);
        BE_DnC = clock();
        B_DnC += (BE_DnC - BS_DnC);
    }
    E_DnC = clock();

    time_DnC = (double)(E_DnC - S_DnC - B_DnC - FB_DnC)*(1000/n)/(CLOCKS_PER_SEC*1000);
    printf("Running Time for n=%d by Divide & Conquer Method: %lf s\n",N ,time_DnC);

    S_S = clock();
    for(int I=1;I<=n;I++){
        C_S = matrix_S(A, B, N);
        BS_S = clock();
        freee(C_S,N);
        BE_S = clock();
        B_S += (BE_S - BS_S);
    }
    E_S = clock();

    time_S = (double)(E_S - S_S - B_S - FB_S)*(1000/n)/(CLOCKS_PER_SEC*1000);
    printf("Running Time for n=%d by Strassen's Method: %lf s\n",N ,time_S);

    /*printf("Iterative Method:\n");
    C_X = matrix_X(A, B, N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d  ",C_X[i][j]);
        }
        printf("\n");
    }

    printf("Divide & Conquer Method:\n");
    C_DnC = matrix_DnC(A, B, N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d  ",C_DnC[i][j]);
        }
        printf("\n");
    }

    printf("Strassen's Method:\n");
    C_S = matrix_S(A, B, N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d  ",C_S[i][j]);
        }
        printf("\n");
    }

    freee(C_X,N);
    freee(C_DnC,N);
    freee(C_S,N);*/
    freee(A,N);
    freee(B,N);

    return 0;
}


void freee(int **A, int n){
    if(A==NULL){return;}

    for(int i=0; i<n; i++){
        free(A[i]);
    }
    free(A);
    return;
}

//Iterative
int **matrix_X(int **A, int **B, int N){
    if(A==NULL || B==NULL){return NULL;}

    int **C; C = (int**)malloc(N*sizeof(int*));
    for(int z=0;z<N;z++){ C[z] = (int*)malloc(N*sizeof(int));}

    for(int a=0;a<N;a++){
        for(int b=0;b<N;b++){
            C[a][b]=0;
            for(int c=0;c<N;c++){
                C[a][b] += (A[a][c])*(B[c][b]);
            }
        }
    }

    return C;
}

//Divide & Conquer
int *matrix_2x2(int **A, int **B, int Ai, int Aj, int Bi, int Bj, int n){
    if(n!=2){return NULL;}
    if(A==NULL || B==NULL){return NULL;}
    int *C; C = (int*)malloc(4*sizeof(int));
    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            C[(2*i)+j] = A[Ai+i][Aj]*B[Bi][Bj+j] + A[Ai+i][Aj+1]*B[Bi+1][Bj+j];
        }
    }
    return C;
}

int *matrix_add(int *A, int *B, int n){
    if(A==NULL || B==NULL){return NULL;}
    int *C; C = (int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++){
        C[i] = A[i] + B[i];
    }
    return C;
}

int *matrix_DC(int **A, int **B, int Ai, int Aj, int Bi, int Bj, int N){
    if(A==NULL || B==NULL){return NULL;}
    if(N<=2){return matrix_2x2(A, B, Ai, Aj, Bi, Bj, 2);}
    int *C; C = (int*)malloc(N*N*sizeof(int));
    
    int n=N/2;
    int part_size = n*n;
    int **c; c= (int**)malloc(4*sizeof(int*));
    int *cx1, *cx2;

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cx1 = matrix_DC(A, B, Ai+(i*n), Aj, Bi, Bj+(j*n), n);
            cx2 = matrix_DC(A, B, Ai+(i*n), Aj+n, Bi+n, Bj+(j*n), n);
            c[(2*i)+j] = matrix_add(cx1, cx2, part_size);
            FBS_DnC = clock();
            free(cx1); free(cx2);
            FBE_DnC = clock();
            FB_DnC += (FBE_DnC - FBS_DnC);
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<part_size;j++){
            C[(((j/n)+((i/2)*n)) * N)+ ((j%n)+((i%2)*n))] = c[i][j];
        }
    }

    FBS_DnC = clock();
    freee(c,4);
    FBE_DnC = clock();
    FB_DnC += (FBE_DnC - FBS_DnC);
    return C;
}

int **matrix_DnC(int **A, int **B, int N){
    if(A==NULL || B==NULL){return NULL;}
    int **C; C = (int**)malloc(N*sizeof(int*));
    for(int z=0;z<N;z++){ C[z] = (int*)malloc(N*sizeof(int));}

    if(N<=2){int *e; e = matrix_2x2(A, B, 0, 0, 0, 0, 2); if(e==NULL){return NULL;}
        for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                C[i][j] = e[(2*i)+j];
            }
        }

        free(e);
        return C;
    }

    int n=N/2;
    int part_size = n*n;
    int **c; c= (int**)malloc(4*sizeof(int*));
    int *cx1, *cx2;

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cx1 = matrix_DC(A, B, i*n, 0, 0, j*n, n);
            cx2 = matrix_DC(A, B, i*n, n, n, j*n, n);
            c[(2*i)+j] = matrix_add(cx1, cx2, part_size);
            FBS_DnC = clock();
            free(cx1); free(cx2);
            FBE_DnC = clock();
            FB_DnC += (FBE_DnC - FBS_DnC);
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<part_size;j++){
            C[(j/n)+((i/2)*n)][(j%n)+((i%2)*n)] = c[i][j];
        }
    }

    FBS_DnC = clock();
    freee(c,4);
    FBE_DnC = clock();
    FB_DnC += (FBE_DnC - FBS_DnC);
    return C;
}

// Strassen
int **matrix_2x2_S(int **A, int **B, int N){
    if(A==NULL || B==NULL){return NULL;}
    if(N!=2){return NULL;}
    int **C; C = (int**)malloc(2*sizeof(int*));
    for(int z=0;z<2;z++){ C[z] = (int*)malloc(2*sizeof(int));}

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            C[i][j] = A[i][0]*B[0][j] + A[i][1]*B[1][j];
        }
    }
    return C;
}

int **matrix_add_S(int **A, int Ai, int Aj, int Bi, int Bj, int n){
    if(A==NULL){return NULL;}
    
    int **C; C = (int**)malloc(n*sizeof(int*));
    for(int a=0;a<n;a++){ C[a] = (int*)malloc(n*sizeof(int));}

    if(Bi<0){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                C[i][j] = A[Ai+i][Aj+j];
            }
        }
        return C;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            C[i][j] = A[Ai+i][Aj+j] + A[Bi+i][Bj+j];
        }
    }
    return C;
}

int **matrix_sub_S(int **A, int Ai, int Aj, int Bi, int Bj, int n){
    if(A==NULL){return NULL;}
    int **C; C = (int**)malloc(n*sizeof(int*));
    for(int a=0;a<n;a++){ C[a] = (int*)malloc(n*sizeof(int));}

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            C[i][j] = A[Ai+i][Aj+j] - A[Bi+i][Bj+j];
        }
    }
    return C;
}

int **matrix_S(int **A, int **B, int N){
    if(A==NULL || B==NULL){return NULL;}
    if(N<=2){return matrix_2x2_S(A, B, N);}

    int **C; C = (int**)malloc(N*sizeof(int*));
    for(int z=0;z<N;z++){ C[z] = (int*)malloc(N*sizeof(int));}

    int n=N/2;
    int ***S, **cx1, **cx2; S= (int***)malloc(7*sizeof(int**));

    cx1 = matrix_sub_S(A, 0, n, n, n, n);
    cx2 = matrix_add_S(B, n, 0, n, n, n);
    S[0] = matrix_S(cx1, cx2, n);
    FBS_S = clock();
    freee(cx1,n);freee(cx2,n);
    FBE_S = clock();
    FB_S += (FBE_S - FBS_S);

    cx1 = matrix_add_S(A, 0, 0, n, n, n);
    cx2 = matrix_add_S(B, 0, 0, n, n, n);
    S[1] = matrix_S(cx1, cx2, n);
    FBS_S = clock();
    freee(cx1,n);freee(cx2,n);
    FBE_S = clock();
    FB_S += (FBE_S - FBS_S);

    cx1 = matrix_sub_S(A, n, 0, 0, 0, n);
    cx2 = matrix_add_S(B, 0, 0, 0, n, n);
    S[2] = matrix_S(cx1, cx2, n);
    FBS_S = clock();
    freee(cx1,n);freee(cx2,n);
    FBE_S = clock();
    FB_S += (FBE_S - FBS_S);

    cx1 = matrix_add_S(A, 0, 0, 0, n, n);
    cx2 = matrix_add_S(B, n, n, -1, 0, n);
    S[3] = matrix_S(cx1, cx2, n);
    FBS_S = clock();
    freee(cx1,n);freee(cx2,n);
    FBE_S = clock();
    FB_S += (FBE_S - FBS_S);

    cx1 = matrix_add_S(A, 0, 0, -1, 0, n);
    cx2 = matrix_sub_S(B, 0, n, n, n, n);
    S[4] = matrix_S(cx1, cx2, n);
    FBS_S = clock();
    freee(cx1,n);freee(cx2,n);
    FBE_S = clock();
    FB_S += (FBE_S - FBS_S);

    cx1 = matrix_add_S(A, n, n, -1, 0, n);
    cx2 = matrix_sub_S(B, n, 0, 0, 0, n);
    S[5] = matrix_S(cx1, cx2, n);
    FBS_S = clock();
    freee(cx1,n);freee(cx2,n);
    FBE_S = clock();
    FB_S += (FBE_S - FBS_S);

    cx1 = matrix_add_S(A, n, 0, n, n, n);
    cx2 = matrix_add_S(B, 0, 0, -1, 0, n);
    S[6] = matrix_S(cx1, cx2, n);
    FBS_S = clock();
    freee(cx1,n);freee(cx2,n);
    FBE_S = clock();
    FB_S += (FBE_S - FBS_S);

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            C[i][j] = S[0][i][j] + S[1][i][j] - S[3][i][j]  + S[5][i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            C[i][j+n] = S[3][i][j] + S[4][i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            C[i+n][j] = S[5][i][j] + S[6][i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            C[i+n][j+n] = S[1][i][j] + S[2][i][j] + S[4][i][j]  - S[6][i][j];
        }
    }

    FBS_S = clock();
    for(int i=0; i<7; i++){
        freee(S[i],n);
    }
    free(S);
    FBE_S = clock();
    FB_S += (FBE_S - FBS_S);

    return C;
}