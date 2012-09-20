#include <iostream>
using namespace std;
int n,k;
bool cow[100001];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,ans,a;
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		memset(cow,false,sizeof(cow));
		ans=1;t=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a);
			if(cow[a]==false)
			{
				cow[a]=true;
				t++;
			}
			if(t==k)
			{
				for(int j=1;j<=k;j++)
					cow[j]=false;
				t=0;
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}