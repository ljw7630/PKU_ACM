#include <iostream>
const int NUM=100005;
int n,m,mini,maxi;
struct segmentTree
{
	int l,r,depth;
}node[1<<20];
int mergetree[20][NUM],a[NUM];

void MergeSort(int index,int l,int r,int depth)
{
	node[index].depth=depth,node[index].l=l,node[index].r=r;
	if(l+1==r)
	{
		mergetree[depth][l]=a[l];
	}
	else
	{
		int mid=(l+r)>>1;
		MergeSort(index<<1,l,mid,depth+1);
		MergeSort((index<<1)+1,mid,r,depth+1);
		int p1=l,p2=mid;
		while(l<r)
		{
			if(p1==mid)
				mergetree[depth][l++]=mergetree[depth+1][p2++];
			else if(p2==r)
				mergetree[depth][l++]=mergetree[depth+1][p1++];
			else
			{
				if(mergetree[depth+1][p1]<mergetree[depth+1][p2])
					mergetree[depth][l++]=mergetree[depth+1][p1++];
				else
					mergetree[depth][l++]=mergetree[depth+1][p2++];
			}
		}
	}
}

void Initial()
{
	mini=0x7fffffff;
	maxi=-0x7fffffff;
	for(int i=0;i<n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]>maxi)
			maxi=a[i];
		if(a[i]<mini)
			mini=a[i];
	}
	MergeSort(1,0,n,0);  // index, l, r, depth
}

int Rank(int index,int l,int r,int x)
{
	if(r<node[index].l|| l>node[index].r)
		return 0;
	if(l<node[index].l)
		l=node[index].l;
	if(r>node[index].r)
		r=node[index].r;
	if(l==node[index].l&&r==node[index].r)
	{
		r--;
		int depth=node[index].depth;
		if(x<=mergetree[depth][l])
			return 0;
		if(x>mergetree[depth][r])
			return r-l+1;
		while(l+1<r)
		{
			int mid=(l+r)>>1;
			if(mergetree[depth][mid]<x)
				l=mid;
			else
				r=mid;
		}
		return l-node[index].l+1;
	}
	return Rank(index<<1,l,r,x)+Rank((index<<1)+1,l,r,x);
}

int Query(int i,int j,int k)
{
	int l=mini,r=maxi+1;
	while(l+1<r)
	{
		int mid=(l+r)>>1;
		if(Rank(1,i,j,mid)+1>k)
			r=mid;
		else
			l=mid;
	}
	return l;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k;
	scanf("%d%d",&n,&m);
	Initial();
	while(m--)
	{
		scanf("%d%d%d",&i,&j,&k);
		printf("%d\n",Query(i-1,j,k));
	}
	return 0;
}