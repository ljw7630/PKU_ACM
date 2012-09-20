#include <iostream>
using namespace std;
const int mid=100001;
int n,a[200002];
bool visit[200002];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<200002;++i)
			a[i]=INT_MIN;
		memset(visit,false,sizeof(visit));
		a[mid]=0;visit[mid]=true;
		int s,f,l=0,r=0;
		for(int j=0;j<n;++j)
		{
			scanf("%d%d",&s,&f);
			if(s<0&&f<0)
				continue;
			if(s<0)
			{
				for(int i=l;i<=r;++i)
				{
					if(visit[i+mid])
					{
						a[i+mid+s]=max(a[i+mid+s],a[i+mid]+f);
						visit[i+mid+s]=true;
					}
				}
				l+=s;
			}
			else
			{
				for(int i=r;i>=l;--i)
				{
					if(visit[i+mid])
					{
						a[i+mid+s]=max(a[i+mid+s],a[i+mid]+f);
						visit[i+mid+s]=true;
					}	
				}
				r+=s;
			}
		}
		int ans=-1;
		for(int i=0;i<=r;++i)
		{
			if(a[i+mid]>=0)
			{
				ans=max(ans,i+a[i+mid]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}