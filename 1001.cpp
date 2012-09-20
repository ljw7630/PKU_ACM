#include <iostream>
using namespace std;
char origin[7];
int s3[155];
int s1[7],s2[155];
int n;
int getint(int s[])
{
	int i,j,p=0;
	for(i=0;i<6&&origin[i];++i)
	{
		if(origin[i]!='.')
			s3[p++]=origin[i]-'0';
	}
	for(j=0;j<5;++j)
	{
		s[j]=s3[4-j];
	}
	i=0;
	while((origin[i]!='.')&&origin[i])
		++i;
	return 5-i;
}

void mul(int s1[],int s2[])
{
	int inc;
	for(int i=0;i<5;++i)
		for(int j=0;j<155;++j)
			s3[i+j]+=s1[i]*s2[j];
	for(int i=inc=0;i<155;++i)
	{
		s2[i]=(inc+s3[i])%10;
		inc=(inc+s3[i])/10;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int point;
	while(scanf("%s%d",origin,&n)!=EOF)
	{
		int i;
		memset(s3,0,sizeof(s3));
		memset(s1,0,sizeof(s1));
		memset(s2,0,sizeof(s2));
		point=getint(s1);
		getint(s2);
		for(i=1;i<n;++i)
		{
			memset(s3,0,sizeof(s3));
			mul(s1,s2);
		}
		i=154;
		while((!s2[i])&&i)
		{
			--i;
		}
		int k=0;
		while((!s2[k])&&(k<155))
			++k;
		for(int m=i;m>=n*point;--m)
			printf("%d",s2[m]);
		if(point&&n*point>=k+1)
			printf(".");
		for(int m=n*point-1;m>=k;--m)
			printf("%d",s2[m]);
		printf("\n");
	}
	return 0;
}