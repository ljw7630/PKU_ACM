#include <iostream>
using namespace std;

int n,map[355][355];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<=i;++j)
			{
				scanf("%d",&map[i][j]);
			}
		}
		for(int i=n-1;i>0;--i)
		{
			for(int j=0;j<i;++j)
			{
				map[i-1][j]+=max(map[i][j],map[i][j+1]);
			}
		}
		printf("%d",map[0][0]);
	}
	return 0;
}