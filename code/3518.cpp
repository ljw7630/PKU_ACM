#include <iostream>
using namespace std;
const int n=1299710;
int p[100002];
bool a[n];

void create()
{
	memset(a,false,sizeof(a));
	for(int i=2;i<n;++i)
	{
		if(a[i]==true)
			continue;
		for(int j=2;i*j<n;++j)
		{
			a[i*j]=true;
		}
	}
	int c=0;
	for(int i=2;i<n;++i)
	{
		if(a[i]==false)
			p[c++]=i;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int temp;
	create();
	while(scanf("%d",&temp)!=EOF&&temp)
	{
		for(int i=0;i<100002;++i)
		{
			if(p[i]==temp)
			{
				printf("0\n");
				break;
			}
			if(p[i]>temp)
			{
				printf("%d\n",p[i]-p[i-1]);
				break;
			}
		}
	}
	return 0;
}