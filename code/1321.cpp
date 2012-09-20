#include <iostream>
using namespace std;
int n,k,count;
bool row[9],col[9];
char chess[9][9];

void backtrack(int w,int a,int b)
{
	int i,j;
	if(w>k)
	{
		count++;
		return;
	}
	else
	{
		for(i=a;i<n;i++)
		{
			for(j=b;j<n;j++)
			{
				if(chess[i][j]=='#'&&row[i]==false&&col[j]==false)
				{
					chess[i][j]='.';
					row[i]=true;
					col[j]=true;
					backtrack(w+1,i,j);
					chess[i][j]='#';
					row[i]=false;
					col[j]=false;
				}
			}
			b=0;
		}
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j;
	while(scanf("%d%d",&n,&k)!=EOF&&(n!=-1||k!=-1))
	{
		memset(row,false,sizeof(row));
		memset(col,false,sizeof(col));
		count=0;
		for(i=0;i<n;i++)
		{
			scanf("%s",chess[i]);
		}
		backtrack(1,0,0);
		printf("%d\n",count);
	}
	return 0;
}