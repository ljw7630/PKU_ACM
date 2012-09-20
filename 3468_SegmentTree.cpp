//#include <iostream>
//using namespace std;
//
//int val[100005];
//int n,q;
//char command;
//
//struct TREE
//{
//	int l;
//	int r;
//	__int64 add;
//	__int64 sum;
//}tree[400005];
//
//__int64 create(int l,int r,int index)
//{
//	tree[index].l=l;
//	tree[index].r=r;
//	tree[index].add=0;
//	if(l==r)
//		return tree[index].sum=val[l];
//	int mid=(l+r)/2;
//	return tree[index].sum=create(l,mid,index*2)+create(mid+1,r,index*2+1);
//}
//
//void update(int l,int r,__int64 add,int index)
//{
//	if(l==tree[index].l&&r==tree[index].r)
//	{
//		tree[index].sum+=(tree[index].r-tree[index].l+1)*add;
//		tree[index].add+=add;
//		return;
//	}
//	if(tree[index].l==tree[index].r)
//		return;
//	if(tree[index].add)
//	{
//		tree[index*2].add+=tree[index].add;
//		tree[index*2+1].add+=tree[index].add;
//		tree[index*2].sum+=(tree[index*2].r-tree[index*2].l+1)*tree[index].add;
//		tree[index*2+1].sum+=(tree[index*2+1].r-tree[index*2+1].l+1)*tree[index].add;
//		tree[index].add=0;		
//	}
//	int mid=(tree[index].l+tree[index].r)/2;
//	if(l>mid)
//		update(l,r,add,index*2+1);
//	else if(r<=mid)
//		update(l,r,add,index*2);
//	else
//	{
//		update(l,mid,add,index*2);
//		update(mid+1,r,add,index*2+1);
//	}
//	tree[index].sum=tree[index*2].sum+tree[index*2+1].sum;
//}
//
//__int64 query(int l,int r,int index)
//{
//	if(tree[index].l==l&&tree[index].r==r)
//		return tree[index].sum;
//	if(tree[index].add)
//	{
//		tree[index*2].add+=tree[index].add;
//		tree[index*2+1].add+=tree[index].add;
//		tree[index*2].sum+=(tree[index*2].r-tree[index*2].l+1)*tree[index].add;
//		tree[index*2+1].sum+=(tree[index*2+1].r-tree[index*2+1].l+1)*tree[index].add;
//		tree[index].add=0;
//	}
//	int mid=(tree[index].l+tree[index].r)/2;
//	int t,tt;
//	if(r<=mid)
//	{
//		t=query(l,r,index*2);
//		return t;
//	}
//	else if(l>mid)
//	{
//		t=query(l,r,index*2+1);
//		return t;
//	}
//	else
//	{
//		t=query(l,mid,index*2);
//		tt=query(mid+1,r,index*2+1);
//		return t+tt;
//	}
//}
//
//int main()
//{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
//	int l,r;
//	__int64 add,res;
//	while(scanf("%d%d",&n,&q)!=EOF)
//	{
//		for(int i=1;i<=n;++i)
//			scanf("%d",&val[i]);
//		create(1,n,1);
//		while(q--)
//		{
//			cin >> command;
//			if(command=='Q')
//			{
//				scanf("%d%d",&l,&r);
//				res=query(l,r,1);
//				printf("%I64d\n",res);
//			}
//			else if(command=='C')
//			{
//				scanf("%d%d%I64d",&l,&r,&add);
//				update(l,r,add,1);
//			}
//		}
//	}
//	return 0;
//}

#include <iostream>
using namespace std;

__int64 res;
int val[100005];

struct TREE
{
	int l;
	int r;
	__int64 add;
	__int64 sum;
}tree[400005];

__int64 create(int l,int r,int index)
{
	tree[index].l=l;
	tree[index].r=r;
	tree[index].add=0;
	if(l==r)
		return tree[index].sum=val[l];
	int mid=(l+r)/2;
	return tree[index].sum=create(l,mid,index*2)+create(mid+1,r,index*2+1);
}

void query(int l,int r,int index,__int64 t)
{
	t+=tree[index].add;
	if(tree[index].l==l&&tree[index].r==r)
	{
		res+=tree[index].sum+t*(tree[index].r-tree[index].l+1);
		return;
	}
	int mid=(tree[index].l+tree[index].r)/2;
	if(l>mid)
		query(l,r,2*index+1,t);
	else if(r<=mid)
		query(l,r,2*index,t);
	else
	{
		query(l,mid,2*index,t);
		query(mid+1,r,2*index+1,t);
	}
	return;
}

void update(int l,int r,__int64 add,int index)
{
	if(tree[index].l==l&&tree[index].r==r)
	{
		tree[index].add+=add;
		return;
	}
	if(tree[index].l==tree[index].r)
		return;
	int mid=(tree[index].l+tree[index].r)/2;
	if(l>mid)
		update(l,r,add,2*index+1);
	else if(r<=mid)
		update(l,r,add,2*index);
	else
	{
		update(l,mid,add,index*2);
		update(mid+1,r,add,index*2+1);
	}
	tree[index].sum=tree[index*2].sum+(tree[2*index].r-tree[2*index].l+1)*tree[2*index].add+tree[index*2+1].sum+(tree[2*index+1].r-tree[2*index+1].l+1)*tree[2*index+1].add;
	return;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,q,l,r;
	__int64 add;
	char ch;
	while(scanf("%d%d",&n,&q)!=EOF)
	{
		for(int i=1;i<=n;++i)
			scanf("%d",&val[i]);
		create(1,n,1);
		while(q--)
		{
			cin >> ch;
			if(ch=='Q')
			{
				res=0;
				scanf("%d%d",&l,&r);
				query(l,r,1,0);
				printf("%I64d\n",res);
			}
			else if(ch=='C')
			{
				scanf("%d%d%I64d",&l,&r,&add);
				update(l,r,add,1);
			}
		}
	}
	return 0;
}