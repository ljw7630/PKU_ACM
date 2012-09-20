#include <iostream>
using namespace std;
int p,a[150001],s[150001][2][2];
int max(int a,int b)
{
	return a>b?a:b;
}
int main()
{
	int i;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	
	while(scanf("%d",&p)!=EOF)
	{
		for(i=0;i<p;i++)
			scanf("%d",&a[i]);
		memset(s,0,sizeof(s));
		for(i=1;i<=p;i++)
		{
			s[i][0][0]=max(s[i-1][1][0],s[i-1][0][1])-a[i-1];
			s[i][0][1]=max(s[i-1][0][1],s[i-1][1][0]);
			s[i][1][0]=max(s[i-1][1][1],s[i-1][0][0])+a[i-1];
			s[i][1][1]=max(s[i-1][1][1],s[i-1][0][0]);
		}
		printf("%d\n",max(max(s[p][0][0],s[p][0][1]),max(s[p][1][0],s[p][1][1])));
	}
	return 0;
}
