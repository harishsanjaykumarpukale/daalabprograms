#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char str[100],ptr[100];
int m,n,len,i,j,k,res,table[1000];
void shift(char p[])
{
	len=strlen(p);
	for (i=0;i<1000;i++)
	{
		table[i]=len;
		for (j=0;j<=len-2;j++)
			table[p[j]]=len-1-j;
	}
}

int hors(char p[],char t[])
{
	shift(p);
	m=strlen(p);
	n=strlen(t);
	i=m-1;
	while (i<=n-1)
	{
		k=0;
		while ((k<=m-1) && t[i-k]==p[m-1-k])
			k++;
		if (k==m)
			return i-m+1;
		else
			i=i+table[t[i]];
	}
	return -1;
}

void main()
{
	printf("Enter the text:");
	scanf("%[^\n]s",str);
	printf("Enter pattern:");
	scanf("%s",ptr);
	res=hors(ptr,str);
	if (res==-1)
		printf("Not found");
	else
		printf("Pattern found at position %d",res+1);
}
