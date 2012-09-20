#include <iostream>
#include <algorithm>
using namespace std;
int n,m;
class arr
{
public:
	int num;
	int index;
	bool friend operator <(arr &a, arr &b)
	{
		return a.num<b.num;
	}
}a[100002];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int beg,last,k;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i].num);
			a[i].index=i+1;
		}
		sort(a,a+n);
		while(m--)
		{
			scanf("%d%d%d",&beg,&last,&k);
			int c=0;
			for(int i=0;i<n;++i)
			{
				if(a[i].index>=beg&&a[i].index<=last)
					c++;
				if(c==k)
				{
					printf("%d\n",a[i]);
					break;
				}
			}
		}
	}
	return 0;
}