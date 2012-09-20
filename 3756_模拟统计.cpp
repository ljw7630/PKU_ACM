#include <iostream>
using namespace std;

int n,t,index,temppos;
int chess[105]; // 0 normal,1 stop,2 backward,3 forward
int step[105];

void valid()
{
	while(temppos<0||temppos>n)
	{
		if(temppos<0)
			temppos=-temppos;
		else if(temppos>n)
			temppos=(2*n)-temppos;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	const int maxn=205;
	double map[maxn+3][105];
	while(scanf("%d",&n)!=EOF)
	{
		memset(chess,0,sizeof(chess));
		scanf("%d",&t); // forward
		for(int i=0;i<t;++i)
		{
			scanf("%d",&index);
			chess[index]=3;
			scanf("%d",&step[index]);
		}
		scanf("%d",&t); // backward
		for(int i=0;i<t;++i)
		{
			scanf("%d",&index);
			chess[index]=2;
			scanf("%d",&step[index]);
		}
		scanf("%d",&t); // stop
		for(int i=0;i<t;++i)
		{
			scanf("%d",&index);
			chess[index]=1;
		}
		for(int i=0;i<=maxn;++i)
			for(int j=0;j<=n;++j)
				map[i][j]=0.0;
		map[0][0]=1;
		double prob=(1.0/6.0);
		for(int round=0;round<=maxn;++round)
		{
			for(int pos=0;pos<n;++pos)
			{
				if(map[round][pos]>0)
				{
					for(int i=1;i<=6;++i)
					{
						temppos=pos+i;
						valid();
						if(chess[temppos]==0)
						{
							map[round+1][temppos]+=map[round][pos]*prob;
						}
						else if(chess[temppos]==1) // stop
						{
							map[round+2][temppos]+=map[round][pos]*prob;
						}
						else if(chess[temppos]==2) // backward
						{
							temppos-=step[temppos];
							valid();
							map[round+1][temppos]+=map[round][pos]*prob;
						}
						else
						{
							temppos+=step[temppos];
							valid();
							map[round+1][temppos]+=map[round][pos]*prob;
						}
					}
				}
			}
		}
		double res=0.0;
		for(int i=0;i<=maxn;++i)
		{
			res+=map[i][n]*i;
		}
		if(res>0)
			printf("%.2lf\n",res);
		else
			printf("Impossible\n");
	}
	return 0;
}