#include <iostream>
#include <string>
using namespace std;

int t,n,score;
string tname;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&t,&n)!=EOF&&t)
	{
		long sum=0;
		for(int i=0;i<t;++i)
		{
			cin >> tname >> score;
			sum+=score;
		}
		printf("%ld\n",3*n-sum);
	}
	return 0;
}