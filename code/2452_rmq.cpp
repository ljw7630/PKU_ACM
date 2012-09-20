//找出以下标i为最小值的范围，找到这个范围以后，
//只需找到其中最大值所在的位置，就找到以i为起点
//对应的最长区间了

#include <iostream>
using namespace std;

const int maxn=50005;
int n;
int a[maxn];
int maxi[maxn][16];
int mini[maxn][16];
int lg2[maxn];


void rmq()
{
	for(int i=1;i<=n;++i)
	{
		maxi[i][0]=i;
		mini[i][0]=i;
	}
	for(int j=1;(1<<j)<=n;++j)
	{
		for(int i=1;i+(1<<j)-1<=n;++i)
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
}

int getmin(int l,int r)
{
	int t=lg2[r-l+1];
	int j=r-(1<<t)+1;
	if(a[mini[l][t]]<a[mini[j][t]])
		return a[mini[l][t]];
	else
		return a[mini[j][t]];
}

int find(int index)
{
	int l=index,r=n,mid;
	while(l+1<r)
	{
		mid=(l+r)>>1;
		if(getmin(index,mid)==a[index])
			l=mid;
		else
			r=mid-1;
	}
	if(getmin(index,r)==a[index])
		return r;
	else
		return l;
}

void calculate()
{
	int maxpos=0;
	int res=0;
	for(int i=1;i<=n;++i)
	{
		int len=find(i);
		int t=lg2[len-i+1];
		int j=len-(1<<t)+1;
		if(a[maxi[i][t]]>a[maxi[j][t]])
			maxpos=maxi[i][t];
		else
			maxpos=maxi[j][t];
		if(maxpos-i>res)
			res=maxpos-i;
	}
	if(res>=1)
		printf("%d\n",res);
	else
		printf("-1\n");
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	lg2[1]=0;
	for(int i=2;i<maxn;++i)
	{
		if((1<<(lg2[i-1]+1))==i)
			lg2[i]=lg2[i-1]+1;
		else
			lg2[i]=lg2[i-1];
	}
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		rmq();
		calculate();
	}
	return 0;
}