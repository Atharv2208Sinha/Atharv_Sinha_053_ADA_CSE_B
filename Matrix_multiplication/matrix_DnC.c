#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>

clock_t FB_start, FB_end, FBuffer=0;

void freee(int **A, int n);
int *matrix_2x2(int **A, int **B, int Ai, int Aj, int Bi, int Bj, int n);
int *matrix_add(int *A, int *B, int n);
int *matrix_x(int **A, int **B, int Ai, int Aj, int Bi, int Bj, int N);
int **matrix_multiply(int **A, int **B, int N);

int main(){
    int N, Na, z, pow2=2;
    clock_t start, end, B_start, B_end, Buffer=0;
    double time_taken;

    printf("Enter order N of Matrix [N should be power of 2]: "); scanf("%d",&Na);
    bool N2=false;
    
    while(pow2<=Na){
        if(Na==pow2){N2=true; break;}
        pow2 *= 2;
    }
    if(N2==false){N=pow2;}
    else{N=Na;}

    int **A; A = (int**)malloc(N*sizeof(int*));
    for(int a=0;a<N;a++){ A[a] = (int*)calloc(N,sizeof(int));}
    int **B; B = (int**)malloc(N*sizeof(int*));
    for(int a=0;a<N;a++){ B[a] = (int*)calloc(N,sizeof(int));}

    /*printf("Enter first Matrix\n");
    for(int i=0;i<Na;i++){
        for(int j=0;j<Na;j++){
            scanf("%d",&z);
            A[i][j]=z;
        }
    }

    printf("Enter second Matrix\n");
    for(int i=0;i<Na;i++){
        for(int j=0;j<Na;j++){
            scanf("%d",&z);
            B[i][j]=z;
        }
    }*/

    for(int i=0;i<Na;i++){ A[i][i] = B[i][i] = 1; }

    int **C;
    /*int n; 
    if(N<=20){n=1000000;}
    else if(N<=50){n=10000;}
    else if(N<=200){n=1000;}
    else if(N<=500){n=100;}
    else {n=10;}
    start = clock();
    for(int I=1;I<=n;I++){
        C = matrix_multiply(A, B, N);
        B_start = clock();
        freee(C,N);
        B_end = clock();
        Buffer += (B_end - B_start);
    }
    end = clock();
    time_taken = (double)(end-start-Buffer-FBuffer)/(CLOCKS_PER_SEC*1000);
    time_taken = time_taken*(1000000/n);
    printf("Running Time for n=%d: %lf ms\n",N ,time_taken);*/

    C = matrix_multiply(A, B, N);
    for(int i=0;i<Na;i++){
        for(int j=0;j<Na;j++){
            printf("%d  ",C[i][j]);
        }
        printf("\n");
    }

    freee(A,N);
    freee(B,N);
    return 0;
}

void freee(int **A, int n){
    if(A==NULL){return;}
    for(int i=0; i<n; i++){
        free(A[i]);
    }
}

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

int *matrix_x(int **A, int **B, int Ai, int Aj, int Bi, int Bj, int N){
    if(A==NULL || B==NULL){return NULL;}
    if(N<=2){return matrix_2x2(A, B, Ai, Aj, Bi, Bj, N);}
    int *C; C = (int*)malloc(N*N*sizeof(int));
    
    int n=N/2;
    int part_size = n*n;
    int **c; c= (int**)malloc(4*sizeof(int*));
    int *cx1, *cx2;

    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            cx1 = matrix_x(A, B, Ai+(i*n), Aj, Bi, Bj+(j*n), n);
            cx2 = matrix_x(A, B, Ai+(i*n), Aj+n, Bi+n, Bj+(j*n), n);
            c[(2*i)+j] = matrix_add(cx1, cx2, part_size);
            FB_start = clock();
            free(cx1); free(cx2);
            FB_end = clock();
            FBuffer += (FB_end - FB_start);
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<part_size;j++){
            C[(((j/n)+((i/2)*n)) * N)+ ((j%n)+((i%2)*n))] = c[i][j];
        }
    }

    FB_start = clock();
    freee(c,4);
    FB_end = clock();
    FBuffer += (FB_end - FB_start);
    return C;
}

int **matrix_multiply(int **A, int **B, int N){
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
            cx1 = matrix_x(A, B, i*n, 0, 0, j*n, n);
            cx2 = matrix_x(A, B, i*n, n, n, j*n, n);
            c[(2*i)+j] = matrix_add(cx1, cx2, part_size);
            FB_start = clock();
            free(cx1); free(cx2);
            FB_end = clock();
            FBuffer += (FB_end - FB_start);
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<part_size;j++){
            C[(j/n)+((i/2)*n)][(j%n)+((i%2)*n)] = c[i][j];
        }
    }

    FB_start = clock();
    freee(c,4);
    FB_end = clock();
    FBuffer += (FB_end - FB_start);
    return C;
}