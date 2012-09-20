#include <iostream>
using namespace std;
long l,m;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	long t1,t2;
	while(scanf("%ld%ld",&l,&m)!=EOF && l)
	{
		++l;
		for(int i=0;i<m;++i)
		{
			scanf("%ld%ld",&t1,&t2);
			l=l-(t2-t1+1);
		}
		printf("%ld\n",l);
	}
	return 0;
}