//for each c[i] and y[i], there is 1<=j<=i, let sum_of_money[i]=min(c[j]+(i-j)*s)*y[i];
//so from 1 to n, just record the minimum (c[j]-j*s), and for each new enter i, compare
//(c[j]-j*s) with c[i]

#include <iostream>
using namespace std;

int n,s;
__int64 money;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&n,&s)!=EOF)
	{
		money=0;
		int i=0,j=0,c,y,mini=INT_MAX;
		n--;
		scanf("%d%d",&c,&y);
		mini=c*y;
		money+=mini;
		i++;
		while(n--)
		{
			scanf("%d%d",&c,&y);
			if((mini+i*s)>c)
			{
				j=i;
				mini=(c-i*s);
			}
			money+=(mini+i*s)*y;
			i++;
		}
		printf("%I64d\n",money);
	}
	return 0;
}