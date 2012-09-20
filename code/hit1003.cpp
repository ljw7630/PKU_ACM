#include <iostream>
#include <algorithm>
using namespace std;

int n,m;

class farm
{
public:
	int p;
	int a;
}farmer[5005];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		scanf("%d",&m);
		for(int i=0;i<m;++i)
		{
			scanf("%d%d",&farmer[i].p,&farmer[i].a);
		}
		farm t;
		for(int i=0;i<m;++i)
		{
			for(int j=0;j<i;++j)
			{
				if(farmer[j].p>farmer[i].p)
				{
					t.a=farmer[i].a;t.p=farmer[i].p;
					farmer[i].a=farmer[j].a;farmer[i].p=farmer[j].p;
					farmer[j].a=t.a;farmer[j].p=t.p;
				}
			}
		}
		int res=0;
		int c=0;
		while(n>0)
		{
			if(n-farmer[c].a<0)
			{
				break;
			}
			else
			{
				n-=farmer[c].a;
				res+=farmer[c].a*farmer[c].p;
				c++;
			}
		}
		res+=n*farmer[c].p;
		printf("%d\n",res);
	}
	return 0;
}