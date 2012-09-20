#include <iostream>
#include <algorithm>
using namespace std;
int a[100002],n;
char t[5];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int c=0;
	while(scanf("%d",&n)!=EOF)
	{
		while(n--)
		{
			scanf("%d",&a[c++]);
		}
		sort(a,a+c);
		scanf("%s",t);
		int len;
		scanf("%d",&len);
		int index;
		for(int i=0;i<len;++i)
		{
			scanf("%d",&index);
			printf("%d\n",a[index-1]);
		}
	}
	return 0;
}