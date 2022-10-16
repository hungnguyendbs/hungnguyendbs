#include<stdio.h>
FILE *f1,*f2;
long n,m,flag[1000][1000];
long u,v;
void nhap_DSC(){
    f1=fopen("input1_2.txt","r");
    fscanf(f1,"%d",&n);
    fscanf(f1,"%d",&m);
    //khoi tao
    for(int i=0;i<n;i++)
         for(int j=0;j<n;j++)
             flag[i][j]=0;
     //doc du lieu
     for(long i=0;i<m;i++){
        fscanf(f1,"%d%d",&u,&v);
        flag[u-1][v-1]=flag[v-1][u-1]=1;

     }
    fclose(f1);
}

void xuat_MTK(){
     f2=fopen("output1_2.txt","w");
        //xuat ma tran ke
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 fprintf(f2,"%d ",flag[i][j]);
             }
             fprintf(f2,"\n");
         }
}

void xuat_DSK(){
        //xuat danh sach ke
         fprintf(f2,"\n");
         for(int i=0;i<n;i++){
             for(int j=0;j<n;j++){
                 if(flag[i][j] == 1){
                     fprintf(f2,"%d ",j+1);
                 }
             }
             fprintf(f2,"\n");
         }
}


int main(){
    nhap_DSC();
    xuat_MTK();
    xuat_DSK();
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<n;j++){
            if(flag[i][j]==1) sum++;
        }
        fprintf(f2,"Bac cua %d la %d\n",i+1,sum);
    }
    fclose(f2);
    return 0;
}