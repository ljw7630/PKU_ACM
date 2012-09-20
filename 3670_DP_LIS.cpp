#include <iostream>
using namespace std;

int cow[30005];
int m[30005];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,len,res1,res2;
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
			scanf("%d",&cow[i]);
		res1=0;
		len=-1;
		for(int i=0;i<n;++i)
		{	
			int left=0;
			int right=len;
			while(left<=right)
			{
				int mid=(left+right)/2;
				if(m[mid]<=cow[i])
					left=mid+1;
				else
					right=mid-1;
			}
			m[left]=cow[i];
			if(left>len)
				len++;
			if(res1<len)
				res1=len;
		}
		res2=0;
		len=-1;
		for(int i=0;i<n;++i)
		{
			int left=0;
			int right=len;
			while(left<=right)
			{
				int mid=(left+right)/2;
				if(m[mid]>=cow[i])
					left=mid+1;
				else
					right=mid-1;
			}
			m[left]=cow[i];
			if(left>len)
				len++;
			if(res2<len)
				res2=len;
		}
		printf("%d\n",min(n-res1-1,n-res2-1));
	}
	return 0;
}
