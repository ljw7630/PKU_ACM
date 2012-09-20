#include <iostream>
using namespace std;
int n;
int oldone[100002];

bool solve()
{
	for(int i=1;i<=n;++i)
	{
		if(oldone[oldone[i]]!=i)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i;
	while(scanf("%d\n",&n)!=EOF&&n)
	{
		for(i=1;i<=n;++i)
		{
			scanf("%d",&oldone[i]);
		}
		if(solve())
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
	}
	return 0;
}