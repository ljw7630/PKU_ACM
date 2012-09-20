#include <iostream>
#include <algorithm>
using namespace std;

int n,c,a[100002];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&c)!=EOF)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int mini=a[0],maxi=(a[n-1]-a[0])/(c-1),mid;
		int count;
		while(mini<maxi)
		{
			mid=(maxi+mini)/2;
			count=0;
			int j;
			for(int i=0;i<n;++i)
			{
				j=i;
				while(j<n&&a[j]<a[i]+mid)
					j++;
				if(j!=n)
					count++;
				if(count>c)
					break;
				i=j-1;
			}
			++count;
			if(count<c)
				maxi=mid;
			else
			{
				if(mini==mid)
					break;
				mini=mid;
			}
		}
		printf("%d\n",mini);
	}
	return 0;
}