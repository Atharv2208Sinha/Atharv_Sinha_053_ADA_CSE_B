#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

clock_t FB_start, FB_end, FBuffer=0;

void freee(int **A, int n);
int **matrix_2x2(int **A, int **B, int N);
int **matrix_add(int **A, int Ai, int Aj, int Bi, int Bj, int n);
int **matrix_sub(int **A, int Ai, int Aj, int Bi, int Bj, int n);
int **matrix_strassen(int **A, int **B, int N);

int main(){
    int N, z, pow2=2;
    clock_t start, end, B_start, B_end, Buffer=0;
    double time_taken;

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

    printf("Enter first Matrix\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&z);
            A[i][j]=z;
        }
    }

    printf("Enter second Matrix\n");
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            scanf("%d",&z);
            B[i][j]=z;
        }
    }

    //for(int i=0;i<N;i++){ A[i][i] = B[i][i] = 1; }

    int **C;
    int n; 
    if(N<=20){n=10000;}
    else if(N<=50){n=1000;}
    else if(N<=200){n=100;}
    else if(N<=500){n=10;}
    else {n=1;}

    start = clock();
    for(int I=1;I<=n;I++){
        C = matrix_strassen(A, B, N);
        B_start = clock();
        freee(C,N);
        B_end = clock();
        Buffer += (B_end - B_start);
    }
    end = clock();

    time_taken = (double)(end-start-Buffer-FBuffer)/(CLOCKS_PER_SEC*1000);
    printf("Running Time for n=%d: %lf ms\n",N ,time_taken*(1000000/n));

    C = matrix_strassen(A, B, N);
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            printf("%d  ",C[i][j]);
        }
        printf("\n");
    }

    freee(C,N);
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
}

int **matrix_2x2(int **A, int **B, int N){
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

int **matrix_add(int **A, int Ai, int Aj, int Bi, int Bj, int n){
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

int **matrix_sub(int **A, int Ai, int Aj, int Bi, int Bj, int n){
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

int **matrix_strassen(int **A, int **B, int N){
    if(A==NULL || B==NULL){return NULL;}
    if(N<=2){return matrix_2x2(A, B, N);}

    int **C; C = (int**)malloc(N*sizeof(int*));
    for(int z=0;z<N;z++){ C[z] = (int*)malloc(N*sizeof(int));}

    int n=N/2;
    int ***S, **cx1, **cx2; S= (int***)malloc(7*sizeof(int**));

    cx1 = matrix_sub(A, 0, n, n, n, n);
    cx2 = matrix_add(B, n, 0, n, n, n);
    S[0] = matrix_strassen(cx1, cx2, n);
    FB_start = clock();
    freee(cx1,n);freee(cx2,n);
    FB_end = clock();
    FBuffer += (FB_end - FB_start);

    cx1 = matrix_add(A, 0, 0, n, n, n);
    cx2 = matrix_add(B, 0, 0, n, n, n);
    S[1] = matrix_strassen(cx1, cx2, n);
    FB_start = clock();
    freee(cx1,n);freee(cx2,n);
    FB_end = clock();
    FBuffer += (FB_end - FB_start);

    cx1 = matrix_sub(A, n, 0, 0, 0, n);
    cx2 = matrix_add(B, 0, 0, 0, n, n);
    S[2] = matrix_strassen(cx1, cx2, n);
    FB_start = clock();
    freee(cx1,n);freee(cx2,n);
    FB_end = clock();
    FBuffer += (FB_end - FB_start);

    cx1 = matrix_add(A, 0, 0, 0, n, n);
    cx2 = matrix_add(B, n, n, -1, 0, n);
    S[3] = matrix_strassen(cx1, cx2, n);
    FB_start = clock();
    freee(cx1,n);freee(cx2,n);
    FB_end = clock();
    FBuffer += (FB_end - FB_start);

    cx1 = matrix_add(A, 0, 0, -1, 0, n);
    cx2 = matrix_sub(B, 0, n, n, n, n);
    S[4] = matrix_strassen(cx1, cx2, n);
    FB_start = clock();
    freee(cx1,n);freee(cx2,n);
    FB_end = clock();
    FBuffer += (FB_end - FB_start);

    cx1 = matrix_add(A, n, n, -1, 0, n);
    cx2 = matrix_sub(B, n, 0, 0, 0, n);
    S[5] = matrix_strassen(cx1, cx2, n);
    FB_start = clock();
    freee(cx1,n);freee(cx2,n);
    FB_end = clock();
    FBuffer += (FB_end - FB_start);

    cx1 = matrix_add(A, n, 0, n, n, n);
    cx2 = matrix_add(B, 0, 0, -1, 0, n);
    S[6] = matrix_strassen(cx1, cx2, n);
    FB_start = clock();
    freee(cx1,n);freee(cx2,n);
    FB_end = clock();
    FBuffer += (FB_end - FB_start);

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

    FB_start = clock();
    for(int i=0; i<7; i++){
        freee(S[i],n);
    }
    free(S);
    FB_end = clock();
    FBuffer += (FB_end - FB_start);

    return C;
}
