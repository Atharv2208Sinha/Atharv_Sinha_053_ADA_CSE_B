#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void freee(int **A, int n);
int **matrix_x(int **A, int **B, int m, int n, int o);

int main(){
    int m, n, o, z;
    clock_t start, end, B_start, B_end, Buffer=0;
    double time_taken;

    //printf("Enter no. of rows for first Matrix: "); scanf("%d",&m);
    //printf("Enter no. of columns for first Matrix: "); scanf("%d",&n);
    //printf("Enter no. of columns for second Matrix: "); scanf("%d",&o);

    printf("Enter order n of Matrices: "); scanf("%d",&n); m = o = n;

    int **A; A = (int**)malloc(m*sizeof(int*));
    for(int a=0;a<m;a++){ A[a] = (int*)calloc(n,sizeof(int));}
    int **B; B = (int**)malloc(n*sizeof(int*));
    for(int a=0;a<n;a++){ B[a] = (int*)calloc(o,sizeof(int));}

    /*printf("Enter first Matrix\n");
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&z);
            A[i][j]=z;
        }
    }

    printf("Enter second Matrix\n");
    for(int i=0;i<n;i++){
        for(int j=0;j<o;j++){
            scanf("%d",&z);
            B[i][j]=z;
        }
    }*/

    for(int i=0; i<n;i++){ A[i][i] = B[i][i] = 1; }

    int **C;
    int N; 
    if(n<=20){N=1000000;}
    else if(n<=50){N=10000;}
    else if(n<=200){N=1000;}
    else {N=100;}
    start = clock();
    for(int I=1;I<=N;I++){
        C = matrix_x(A,B,m,n,o);
        B_start = clock();
        freee(C,n);
        B_end = clock();
        Buffer += (B_end - B_start);
    }
    end = clock();
    time_taken = (double)(end-start-Buffer)/(CLOCKS_PER_SEC*1000);
    printf("Running Time for n=%d: %lf ms\n",n ,time_taken*(1000000/N));

    /*for(int i=0;i<m;i++){
        for(int j=0;j<o;j++){
            printf("%d  ",C[i][j]);
        }
        printf("\n");
    }*/

    freee(A,n);
    freee(B,n);
    return 0;
}

void freee(int **A, int n){
    if(A==NULL){return;}
    
    for(int i=0; i<n; i++){
        free(A[i]);
    }
}

int **matrix_x(int **A, int **B, int m, int n, int o){
    if(A==NULL || B==NULL){return NULL;}

    int **C; C = (int**)malloc(m*sizeof(int*));
    for(int z=0;z<m;z++){ C[z] = (int*)malloc(o*sizeof(int));}

    for(int a=0;a<m;a++){
        for(int b=0;b<o;b++){
            C[a][b]=0;
            for(int c=0;c<n;c++){
                C[a][b] += (A[a][c])*(B[c][b]);
            }
        }
    }

    return C;
}