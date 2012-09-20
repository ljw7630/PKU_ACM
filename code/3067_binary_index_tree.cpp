#include <iostream>
#include <algorithm>
using namespace std;

const int MAXIMUN=1000005;
__int64 tree[MAXIMUN];
int lowbit[MAXIMUN];

struct bridge
{
	int eastid;
	int westid;

	bool friend operator < (bridge &a,bridge &b)
	{
		if(a.westid>b.westid||((a.westid==b.westid)&&(a.eastid>b.eastid)))
			return true;
		else
			return false;
	}
}arr[MAXIMUN];

void update(int index)
{
	while(index<MAXIMUN)
	{
		tree[index]++;
		index+=lowbit[index];
	}
}

__int64 getcross(int index)
{
	__int64 s=0;
	while(index>0)
	{
		s+=tree[index];
		index-=lowbit[index];
	}
	return s;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,m,n,k;
	scanf("%d",&t);
	int c=0;
	for(int i=0;i<MAXIMUN;++i)
		lowbit[i]=i&(-i);
	while(t--)
	{
		memset(tree,0,sizeof(tree));
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<k;++i)
		{
			scanf("%d%d",&arr[i].eastid,&arr[i].westid);
		}
		sort(arr,arr+k);
		__int64 sum=0;
		for(int i=0;i<k;++i)
		{
			sum+=getcross(arr[i].eastid-1);
			update(arr[i].eastid);
		}
		printf("Test case %d: %I64d\n",++c,sum);
	}
	return 0;
}