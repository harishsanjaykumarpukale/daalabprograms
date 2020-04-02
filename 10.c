#include<stdio.h>
int n,d,sum=0,rwt=0,a[10],s[10],flag=0;
int j;
void sumOfSubset(int i){
    if(sum+s[i] <= d){
        sum+=s[i];
        rwt-=s[i];
        a[i]=1;
        if(sum == d){
            flag=1;
            printf("\nSubset with elements positioned:");
            for(j=0;j<n;j++)
                if(a[j]==1)
                    printf("\t%d",j+1);
        }
        if(i+1<n)
            sumOfSubset(i+1);
        sum-=s[i];
        rwt+=s[i];
        a[i]=0;
    }
    if(rwt - s[i] >= d-sum){
        rwt-=s[i];
        if(i+1<n)
            sumOfSubset(i+1);
        rwt += s[i];
    }
}
void main(){
    printf("\nEnter the size of set:");
    scanf("%d",&n);
    
    printf("\nEnter the elements of set:");
    for(j=0;j<n;j++){
        scanf("%d",&s[j]);
        rwt+=s[j];
    }
    printf("\nEnter the sum value:");
    scanf("%d",&d);
    
    sumOfSubset(0);
    
    if(flag==0)
        printf("\nNone of the subset matches required condition.\n");
    
}
