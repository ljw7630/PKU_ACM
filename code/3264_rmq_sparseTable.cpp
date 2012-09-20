#include <iostream>
#include <cmath>
using namespace std;

int a[50005];
int maxi[50005][20];
int mini[50005][20];

int log2(int x)
{
	int y=(int)(log((double)x)/log(2.0));
	return y;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,q;
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		memset(maxi,0,sizeof(maxi));
		memset(mini,0,sizeof(mini));
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;++i)
		{
			maxi[i][0]=i;
			mini[i][0]=i;
		}
		for(int j=1;(1<<j)<=n;++j)
		{
			for(int i=0;i+(1<<j)-1<n;++i)
			{
				if(a[maxi[i][j-1]]>a[maxi[i+(1<<(j-1))][j-1]])
					maxi[i][j]=maxi[i][j-1];
				else
					maxi[i][j]=maxi[i+(1<<(j-1))][j-1];
				if(a[mini[i][j-1]]<a[mini[i+(1<<(j-1))][j-1]])
					mini[i][j]=mini[i][j-1];
				else
					mini[i][j]=mini[i+(1<<(j-1))][j-1];
			}
		}
		int t1,t2;
		for(int i=0;i<q;++i)
		{
			scanf("%d%d",&t1,&t2);
			t1--,t2--;
			if(t1>t2)
				swap(t1,t2);
			int k=log2(t2-t1+1);
			int m1=max(a[maxi[t1][k]],a[maxi[t2-(1<<k)+1][k]]);
			int m2=min(a[mini[t1][k]],a[mini[t2-(1<<k)+1][k]]);
			printf("%d\n",m1-m2);
		}
	}
	return 0;
}