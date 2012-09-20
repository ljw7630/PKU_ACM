#include <iostream>
#include <algorithm>
using namespace std;
int n,k;
__int64 res;
const int maxn=40005;
int hashtable[2*maxn];
struct PT
{
	int left;
	int right;
	__int64 add;
	bool friend operator <(const PT &a,const PT &b)
	{
		return a.add<b.add;
	}
}p[maxn];

struct TREE
{
	int x;
	int y;
	int mid;
	__int64 count;
}tree[8*maxn];

int FIND(int x)
{
	int l=0,r=k-1,mid;
	while(l<=r)
	{
		mid=(l+r)>>1;
		if(hashtable[mid]==x)
			return mid;
		else if(x>hashtable[mid])
			l=mid+1;
		else
			r=mid-1;
	}
	return 0;
}

void create(int x,int y,int index)
{
	tree[index].x=x;
	tree[index].y=y;
	tree[index].count=0;
	if(x+1==y)
		return;
	int mid=(x+y)>>1;
	tree[index].mid=mid;
	create(x,mid,index*2);
	create(mid,y,index*2+1);
}

void insert(int x,int y,__int64 c,int index)
{
	if(x==tree[index].x&&y==tree[index].y)
	{
		tree[index].count=c;
		return;
	}
	if(tree[index].count)
	{
		tree[index*2].count=tree[index*2+1].count=tree[index].count;
		tree[index].count=0;
	}
	int mid=tree[index].mid;
	if(x>=mid)
	{
		insert(x,y,c,index*2+1);
	}
	else if(y<=mid)
	{
		insert(x,y,c,index*2);
	}
	else
	{
		insert(x,mid,c,index*2);
		insert(mid,y,c,index*2+1);
	}
}

__int64 query(int index)
{
	if(tree[index].count!=0||tree[index].y-tree[index].x==1)
	{
		return (hashtable[tree[index].y]-hashtable[tree[index].x])*tree[index].count;
	}
	return query(index*2)+query(index*2+1);
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		k=0;
		for(int i=0;i<n;++i)
		{
			scanf("%d%d%I64d",&p[i].left,&p[i].right,&p[i].add);
			hashtable[k++]=p[i].left;
			hashtable[k++]=p[i].right;
		}
		sort(hashtable,hashtable+k);
		sort(p,p+n);
		create(0,k-1,1);
		for(int i=0;i<n;++i)
		{
			insert(FIND(p[i].left),FIND(p[i].right),p[i].add,1);
		}
		res=query(1);
		printf("%I64d\n",res);
	}
	return 0;
}