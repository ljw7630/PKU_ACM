#include <iostream>
#include <algorithm>
using namespace std;
int n,a[10001];
void change(int p,int d)
{
	int temp;
	if(d<0)
		return;
	if(a[d]==0)
	{
		a[d]=p;
		return;
	}
	if(p>a[d])
	{
		temp=a[d];
		a[d]=p;
	}
	else
		temp=p;
	change(temp,d-1);
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int p,d,max,sum;
	while(scanf("%d",&n)!=EOF)
	{
		max=0;
		sum=0;
		memset(a,0,sizeof(a));
		while(n--)
		{
			scanf("%d%d",&p,&d);
			change(p,d);
			if(d>max)
				max=d;
		}
		for(int i=1;i<=max;i++)
		{
			sum+=a[i];
		}
		printf("%d\n",sum);
	}
	return 0;
}