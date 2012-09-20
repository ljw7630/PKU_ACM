#include <iostream>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	long long a,b,c;
	while(scanf("%lld%lld%lld",&a,&b,&c)!=EOF)
		printf("%lld\n",a+b+c);
	return 0;
}