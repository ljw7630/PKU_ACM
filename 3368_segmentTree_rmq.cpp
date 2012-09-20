#include <iostream>
#include <cmath>
using namespace std;

int n,q,c;
int pow2[20],maxi[18][100005];

struct LINE
{
	int start;
	int end;
	int value;
}line[100005];

void st()
{
	// maxi[i,j]是[i,2^j]区间的最大值
	memset(maxi,0,sizeof(maxi));
	int k=log((double)n)/log(2.0);
	for(int i=1;i<=n;++i)
		maxi[0][i]=line[i].value;
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j+pow2[i-1]<=n;++j)
		{
			maxi[i][j]=max(maxi[i-1][j],maxi[i-1][j+pow2[i-1]]);
		}
	}
}

int find(int k)
{
	int s=1,e=n;
	while(s<=e)
	{
		int mid=(s+e)/2;
		if(line[mid].start>k)
			e=mid-1;
		else if(line[mid].end<k)
			s=mid+1;
		else
			return mid;
	}
	return s;
}

int rmq(int i,int j)
{
	int res=1;
	int a=find(i),b=find(j);
	int aa=a+1,bb=b-1;
	if(bb>=aa)
	{
		int k=log((double)(bb-aa+1))/log(2.0);
		res=max(maxi[k][aa],maxi[k][bb-pow2[k]+1]);
	}
	if(b>a)
	{
		res=max(res,line[a].end-i+1);
		res=max(res,j-line[b].start+1);
	}
	else
		res=max(res,j-i+1);
	return res;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	for(int i=0;i<18;++i)
		pow2[i]=1<<i;
	while(scanf("%d",&n)!=EOF&&n)
	{
		int num,start,last;
		scanf("%d",&q);
		scanf("%d",&num);
		last=num;
		int count=1;
		c=0;
		start=1;
		for(int i=2;i<=n;++i)
		{
			scanf("%d",&num);
			if(last==num)
			{
				++count;
			}
			else
			{
				line[++c].value=count;
				line[c].start=start;
				line[c].end=i-1;
				start=i;
				last=num;
				count=1;
			}
		}
		line[++c].value=count;
		line[c].start=start;
		line[c].end=n;
		n=c;
		st();
		while(q--)
		{
			int i,j;
			scanf("%d%d",&i,&j);
			printf("%d\n",rmq(i,j));
		}
	}
	return 0;
}


