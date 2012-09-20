#include <iostream>
using namespace std;

int l[500005];
int r[500005];
int a[500005],n;

__int64 merge_inversions(int p,int q,int last)
{
	int n1=q-p+1;
	int n2=last-q;
	for(int i=1;i<=n1;++i)
		l[i]=a[p+i-1];
	for(int i=1;i<=n2;++i)
		r[i]=a[q+i];
	l[n1+1]=INT_MAX;
	r[n2+1]=INT_MAX;
	bool counted=false;
	__int64 inversions=0;
	int i=1;
	int j=1;
	for(int k=p;k<=last;++k)
	{
		if(counted==false&&r[j]<l[i])
		{
			inversions+=n1-i+1;
			counted=true;
		}
		if(l[i]<r[j])
		{
			a[k]=l[i];
			i++;
		}
		else
		{
			a[k]=r[j];
			j++;
			counted=false;
		}
	}
	return inversions;
}

__int64 count_inversions(int p,int r)
{
	__int64 inversions=0;
	if(p<r)
	{
		int q=(p+r)/2;
		inversions+=count_inversions(p,q);
		inversions+=count_inversions(q+1,r);
		inversions+=merge_inversions(p,q,r);
	}
	return inversions;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		__int64 c=count_inversions(1,n);
		printf("%I64d\n",c);
	}
	return 0;
}