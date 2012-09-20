#include <iostream>
using namespace std;

int c[15005];

struct tree
{
public:
	int l;
	int r;
	int num;
}t[320000];

void create(int l,int r,int index)
{
	t[index].l=l;
	t[index].r=r;
	t[index].num=0;
	if(l==r)
		return;
	int mid=(l+r)/2;
	create(l,mid,index*2);
	create(mid+1,r,index*2+1);
}

void update(int l,int r,int index)
{
	if( t[index].l==l && t[index].r==r )
	{
		++t[index].num;
		return;
	}
	int mid = (t[index].l + t[index].r) / 2;
	if(r<=mid)
		update(l, r, index * 2);
	else if(l>mid)
		update(l, r, index * 2 + 1);
	else
	{
        update(l, mid, index * 2);
        update(mid + 1, r, index * 2 + 1);
	}
}

int search(int x,int index)
{
	if(t[index].l==t[index].r)
	{
		return t[index].num;
	}
	int mid=(t[index].l+t[index].r)/2;
	if(x<=mid)
		return search(x,index*2)+t[index].num;
	else
		return search(x,index*2+1)+t[index].num;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int x,y,temp,n;
	memset(c,0,sizeof(c));
	scanf("%d",&n);
	create(0,32000,1);
	for(int i=0;i<n;++i)
	{
		scanf("%d%d",&x,&y);
		temp=search(x,1);
		++c[temp];
		update(x,32000,1);
	}
	for(int i=0;i<n;++i)
		printf("%d\n",c[i]);
	return 0;
}

