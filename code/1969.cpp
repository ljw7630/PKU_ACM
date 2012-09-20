#include <iostream>
using namespace std;
int n,k;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		printf("TERM %d IS ",n);
		k=0;
		while(n>0)
		{
			k++;
			n-=k;
		}
		if(k%2==0)
			printf("%d/%d\n",k+n,1-n);
		else
			printf("%d/%d\n",1-n,k+n);
	}
	return 0;
}