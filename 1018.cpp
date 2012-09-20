#include <iostream>
using namespace std;
int b[100][100],p[100][100],t,n,m[100],findmin,findmax;
double result;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,l,sumprice,pmin;
	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d",&n);
		findmin=32767,findmax=0;
		for(j=0;j<n;j++)
		{
			scanf("%d",&m[j]);
			for(k=0;k<m[j];k++)
			{
				scanf("%d",&b[j][k]);
				scanf("%d",&p[j][k]);
				if(findmin>b[j][k])
					findmin=b[j][k];
				if(findmax<b[j][k])
					findmax=b[j][k];
			}
		}
		result=0;
		for(j=findmin;j<=findmax;j++)
		{
			sumprice=0;
			for(k=0;k<n;k++)
			{
				pmin=32767;
				for(l=0;l<m[k];l++)
					if(b[k][l]>=j&&p[k][l]<pmin)
					{
						pmin=p[k][l];
					}
				sumprice+=pmin;
			}
			if( (double)j/(double)sumprice>result )
				result=(double)j/(double)sumprice;
		}
		printf("%.3lf\n",result);

	}
	return 0;
}