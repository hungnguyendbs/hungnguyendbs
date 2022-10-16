#include <stdio.h>
#include <fstream> 
#include <iostream> 
int main() {
    int A[100][100];
    int n;

    FILE *f = fopen("input2.txt", "r");

    fscanf(f, "%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fscanf(f, "%d", &A[i][j]);
        }
    }


    // In ra màn hình Console
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    //chuyen ma tran ke sang danh sach ke
    FILE *fptr;
   fptr = fopen("input2_1.txt","w");
   fprintf(fptr,"%d\n",n);
	for(int i = 0; i <n; i++){
		for(int j = 0; j <n; j++){
			if(A[i][j]==1)
                fprintf(fptr,"%d ",j+1);
		}
        fprintf(fptr,"\n");
	}
       fclose(fptr);
    //Chuyen ma tran ke sang danh sach canh
   FILE *fptr1;
   fptr1 = fopen("input2_2.txt","w");
   int m = 0;
   fprintf(fptr1,"   \n");
	for(int i = 0; i <n; i++){
		for(int j =i+1; j<n; j++){
        
			if(A[i][j]==1){
                m++;
                fprintf(fptr1,"%d %d\n",i+1,j+1);
            }
		}
	}
    fseek(fptr1,0,SEEK_SET);
    fprintf(fptr1,"%d %d",n,m);
       fclose(fptr1);
   
}