#include <iostream>
using namespace std;
int v[102],num,res[102][102][2],ans[102];
char op[102];
int minf,maxf;

void maxmin(int i,int s,int j)
{
	int a,b,c,d,e[4],t,k;
	t=(i+s-1)%num+1;
	a=res[i][s][0];
	b=res[i][s][1];
	c=res[t][j-s][0];
	d=res[t][j-s][1];
	if(op[t]=='t')
	{
		minf=a+c;
		maxf=b+d;
	}
	else
	{
		e[0]=a*c;
		e[1]=a*d;
		e[2]=b*c;
		e[3]=b*d;
		minf=e[0];
		maxf=e[0];
		for(k=1;k<4;k++)
		{
			if(minf>e[k])minf=e[k];
			if(maxf<e[k])maxf=e[k];
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,s,k;
	while(scanf("%d",&num)!=EOF)
	{
		for(i=1;i<=num;i++)
		{
			scanf("%*c%c%*c%d",&op[i],&v[i]);
		}
		for(i=1;i<=num;i++)
			for(j=1;j<=num;j++)
			{
				res[i][j][0]=INT_MAX;
				res[i][j][1]=INT_MIN;
			}
		for(i=1;i<=num;i++)
		{
			res[i][1][0]=v[i];
			res[i][1][1]=v[i];
		}
		for(j=2;j<=num;j++)
		{
			for(i=1;i<=num;i++)
			{
				for(s=1;s<j;s++)
				{
					maxmin(i,s,j);
					if(res[i][j][0]>minf)
					{
						res[i][j][0]=minf;
					}
					if(res[i][j][1]<maxf)
					{
						res[i][j][1]=maxf;
					}
				}
			}
		}
		int temp=INT_MIN;
		k=1;
		for(i=1;i<=num;i++)
		{
			if(temp<res[i][num][1])
			{
				temp=res[i][num][1];
				k=1;
				ans[k++]=i;
			}
			else if(temp==res[i][num][1])
			{
				ans[k++]=i;
			}
		}
		printf("%d\n",temp);
		for(i=1;i<k;i++)
			printf("%d ",ans[i]);
		printf("\n");
	}
	return 0;
}