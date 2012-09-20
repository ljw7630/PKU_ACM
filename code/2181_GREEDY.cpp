#include <iostream>
using namespace std;
int p,a,sum,maxi,mini;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&p)!=EOF)
	{
		int i=1;
		sum=0;
		maxi=0;
		mini=0;
		scanf("%d",&a);
		maxi=a;
		while(i<p)
		{
			while(scanf("%d",&a),a>=maxi&&i<p)
			{
				maxi=a;i++;
			}
			sum+=(maxi-mini);
			if(i>=p)
				break;
			mini=a;
			while(scanf("%d",&a),a<=mini&&i<p)
			{
				mini=a;i++;
			}
			maxi=a;
		}
		printf("%d\n",sum);
	}
	return 0;
}