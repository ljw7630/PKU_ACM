// 找环,最后swap数等于数字种数-环数


#include <iostream>
using namespace std;

int t,n,arr[10005],count;
bool isIn[10005];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		count=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&arr[i]);
			isIn[i]=false;
		}
		for(int i=1;i<=n;++i)
		{
			if(!isIn[i])
			{
				++count;
				int c=i;
				while(!isIn[c])
				{
					isIn[c]=true;
					c=arr[c];
				}
			}
		}
		printf("%d\n",n-count);
	}
	return 0;
}