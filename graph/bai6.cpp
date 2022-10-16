#include<stdio.h>
#include<conio.h>
int A[100][100],n;
FILE *f1;
FILE *f2;
void docfile(){
int i=0,j;
char c;
fscanf(f1,"%d",&n);
while(i<=n){
fscanf(f1,"%c",&c);
if(c=='\n')
i++;
else if(c!=' '){
    j=c-'0';
    A[i][j]=1;
}
}
}
void ghimatran(){
fprintf(f2,"%d\n",n);
int i,j;
for(i=1;i<=n;i++){
    for(j=1;j<=n;j++)
    fprintf(f2,"%d ",A[i][j]);
    fprintf(f2,"\n");
}
}
void ghidscanh(){
    int i,j;
    fprintf(f2,"\n");
    for(i=1;i<=n;i++)
    for(j=1;j<=n;j++)
        if(A[i][j]==1){
            fprintf(f2,"\n%d %d",i,j);
        }
}
int main(){
f1 = fopen("input2_1.txt","r");
f2 = fopen("output2_1.txt","w");
docfile();
ghimatran();
for(int i=1;i<=n;i++){
    int sum = 0;
    for(int j=1;j<=n;j++){
        sum+=A[i][j];
    }
    fprintf(f2,"Bac cua %d la %d\n",i,sum);
}
ghidscanh();
getch();
fclose(f1);
fclose(f2);
return 0;
}