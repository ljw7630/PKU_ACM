#include <iostream>
#include <algorithm>
using namespace std;

int p[102];

class road
{
public:
	int b;
	int e;
	int d;

	bool friend operator <(class road &a,class road &b)
	{
		return a.d<b.d;
	}
}a[10002];

int parent(int k)
{
	while(p[k]!=k)
		k=p[k];
	return k;
}

void merge(int x,int y)
{
	while(x!=p[x])
	{
		p[x]=p[y];
		x=p[x];
	}
	p[x]=p[y];
	return;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,i,j,temp,count,q;
	while(scanf("%d",&n)!=EOF)
	{
		count=0;
		for(i=0;i<n;++i)
		{
			for(j=0;j<n;++j)
			{
				scanf("%d",&temp);
				if(j>i)
				{
					a[count].b=i;
					a[count].e=j;
					a[count].d=temp;
					count++;
				}
			}
		}
		for(i=0;i<n;++i)
		{
			p[i]=i;
		}

		scanf("%d",&q);
		int x,y,p1,p2;
		for(i=0;i<q;++i)
		{
			scanf("%d%d",&x,&y);
			p1=parent(x-1);
			p2=parent(y-1);
			if(p1!=p2)
			{
				merge(p1,p2);
			}
		}

		int sum=0;
		sort(a,a+count);
		
		for(i=0;i<count;++i)
		{
			p1=parent(a[i].b);
			p2=parent(a[i].e);

			if(p1!=p2)
			{
				sum+=a[i].d;
				merge(p1,p2);
			}
		}
		printf("%d\n",sum);
	}

	return 0;
}