#include <iostream>
using namespace std;
int t,n;
int a[22];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		int mini=INT_MAX,maxi=INT_MIN;
		for(int i=0;i<n;++i)
		{
			scanf("%d",&a[i]);
			if(a[i]<mini)
				mini=a[i];
			if(a[i]>maxi)
				maxi=a[i];
		}
		printf("%d\n",(maxi-mini)<<1);
	}
	return 0;	
}