//看了论文,还是不是很明白

#include <iostream>
using namespace std;

int n;
int l[3005];
int f[3005];
int t[3005];
bool used[3005];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		int count=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&l[i]);
			if(l[i])
				count++;
			used[i]=false;
		}
		for(int i=0;i<n-count;++i)
			f[i]=0;
		for(int i=n-count;i<n;++i)
			f[i]=1;
		int j=0;
		for(int i=0;i<n;++i)
		{
			j=0;
			while(f[i]!=l[j]||(used[j]==true))
				j++;
			used[j]=true;
			t[i]=j;
		}
		j=0;
		for(int i=0;i<n;++i)
		{
			j=t[j];
			printf("%d ",l[j]);
		}
		printf("\n");
	}
}