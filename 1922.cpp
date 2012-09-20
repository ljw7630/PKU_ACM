#include <iostream>
using namespace std;
int n,v,t;
double maxi,temp;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		maxi=50000;
		while(n--)
		{
			scanf("%d%d",&v,&t);
			if(t>=0)
			{
				temp=((double)(4500*3.6)/v)+t;
				if(temp<maxi)
					maxi=temp;
			}
		}
		if(maxi-(int)maxi>0.0)
			maxi++;
		printf("%.0lf\n",maxi);
	}
	return 0;
}