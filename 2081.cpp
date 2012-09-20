#include <iostream>
using namespace std;
int k,a[500001];
bool flag[10000001];
int main()
{
	freopen("in.txt","r",stdin);	
	freopen("out.txt","w",stdout);
	int i;
	a[0]=0;
	flag[0]=true;
	for(i=1;i<=500000;i++)
	{
		if(a[i-1]-i>0&&flag[a[i-1]-i]==false)
			a[i]=a[i-1]-i;
		else
			a[i]=a[i-1]+i;
		flag[a[i]]=true;
	}
	while(scanf("%d",&k)&&k!=-1)
	{
		printf("%d\n",a[k]);
	}
	return 0;
}