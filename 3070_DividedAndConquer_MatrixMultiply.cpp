#include <iostream>
using namespace std;
const int mod=10000;
int a[2][2]=
{
	1,1,
	1,0
};

void calmatrix(int c[2][2],int n)
{
	if(n==1)
	{
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				c[i][j]=a[i][j];
		return;
	}
	int t[2][2];
	calmatrix(t,n/2);
	for(int i=0;i<2;++i)
	{
		for(int j=0;j<2;++j)
		{
			c[i][j]=0;
			for(int k=0;k<2;++k)
			{
				c[i][j]=(c[i][j]+t[i][k]*t[k][j])%mod;
			}
		}
	}
	if(n&1)
	{
		for(int i=0;i<2;++i)
			for(int j=0;j<2;++j)
				t[i][j]=c[i][j];
		for(int i=0;i<2;++i)
		{
			for(int j=0;j<2;++j)
			{
				c[i][j]=0;
				for(int k=0;k<2;++k)
				{
					c[i][j]=(c[i][j]+t[i][k]*a[k][j])%mod;
				}
			}
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	while(scanf("%d",&n)!=EOF)
	{
		if(n==-1)
			break;
		else if(n==0)
			printf("0\n");
		else if(n==1||n==2)
			printf("1\n");
		else
		{
			int c[2][2]={0};
			calmatrix(c,n);
			printf("%d\n",c[0][1]%mod);
		}
	}
	return 0;
}