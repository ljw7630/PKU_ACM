#include <iostream>
using namespace std;
int t,m,n,k;
int f[11][11];//apple, plate;
int cal(int m,int n)
{
	for(int i=0;i<=m;i++)
		f[i][1]=1;
	for(int i=0;i<=n;i++)
		f[0][i]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=2;j<=n;j++)
		{
			f[i][j]=f[i][j-1];
			if(i>=j)
				f[i][j]+=f[i-j][j];
		}
	}
	return f[m][n];
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&m,&n);
		printf("%d\n",cal(m,n));
	}
	return 0;
}