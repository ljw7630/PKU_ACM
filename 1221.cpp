#include <iostream>
using namespace std;
int n;
__int64 s[301][301];
int main()
{
	int i,j;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	for(i=1;i<=300;i++)
		for(j=i;j>=0;j--)
			s[i][j]=1;
	for(i=0;i<=300;i++)
		s[0][i]=1;
	for(i=2;i<=300;i++)
		for(j=i/2;j>=1;j--)
			s[i][j]=s[i-2*j][j]+s[i][j+1];

	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		printf("%d %I64d\n",n,s[n][1]);
	}
	return 0;
}