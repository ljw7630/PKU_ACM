#include <iostream>
using namespace std;
const int n=1000000;
bool a[n];
int main()
{
	int i,j;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	memset(a,true,sizeof(a));
	a[0]=a[1]=false;
	for(i=2;i<n;++i)
	{
		if(a[i]==false)
			continue;
		for(j=2;i*j<n;++j)
		{
			a[i*j]=false;
		}
	}
	int A,D,NUM;
	while(scanf("%d%d%d",&A,&D,&NUM)!=EOF&&(A||D||NUM))
	{
		int j=0;
		for(i=A;j<NUM;i+=D)
		{
			if(a[i])
				j++;
		}
		printf("%d\n",i-D);
	}
	return 0;
}