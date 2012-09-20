#include <iostream>
#include <algorithm>
using namespace std;
int n;
int cow[10001];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,mid;
	while(scanf("%d",&n)!=EOF)
	{
		for(i=0;i<n;i++)
			scanf("%d",&cow[i]);
		sort(cow,cow+n);
		printf("%d\n",cow[n/2]);
	}
	return 0;
}