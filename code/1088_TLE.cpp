#include <iostream>
using namespace std;
int best[101][101],matrix[101][101];
int r,c;
class points
{
public:
	int x,y;
}minplace,maxplace;
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	int i,j,k,minimal,maximal;
	minimal=10000;
	maximal=0;
	scanf("%d%d",&r,&c);
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&matrix[i][j]);
			if(minimal>matrix[i][j])
			{
				minimal=matrix[i][j];
				minplace.x=i;
				minplace.y=j;
			}
			if(maximal<matrix[i][j])
			{
				maximal=matrix[i][j];
				maxplace.x=i;
				maxplace.y=j;
			}
		}
	}
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			best[i][j]=1;
	for(k=0;k<r*c;k++)
	{
		for(i=0;i<r;i++)
		{
			for(j=0;j<c;j++)
			{
				if(matrix[i+1][j]>matrix[i][j]&&i!=r-1)
				{
					if(best[i+1][j]<best[i][j]+1)
						best[i+1][j]=best[i][j]+1;
				}
				else if(matrix[i+1][j]<matrix[i][j]&&i!=r-1)
				{
					if(best[i+1][j]+1>best[i][j])
						best[i][j]=best[i+1][j]+1;
				}
				if(matrix[i][j+1]>matrix[i][j]&&j!=c-1)
				{
					if(best[i][j+1]<best[i][j]+1)
						best[i][j+1]=best[i][j]+1;
				}
				else if(matrix[i][j+1]<matrix[i][j]&&j!=c-1)
				{
					if(best[i][j+1]+1>best[i][j])
						best[i][j]=best[i][j+1]+1;
				}
				if(matrix[i-1][j]>matrix[i][j]&&i!=0)
				{
					if(best[i-1][j]<best[i][j]+1)
						best[i-1][j]=best[i][j]+1;
				}
				else if(matrix[i-1][j]<matrix[i][j]&&i!=0)
				{
					if(best[i-1][j]+1>best[i][j])
						best[i][j]=best[i-1][j]+1;
				}
				if(matrix[i][j+1]>matrix[i][j]&&j!=0)
				{
					if(best[i][j+1]<best[i][j]+1)
						best[i][j+1]=best[i][j]+1;
				}
				else if(matrix[i][j+1]<matrix[i][j]&&j!=0)
				{
					if(best[i][j+1]+1>best[i][j])
						best[i][j]=best[i][j+1]+1;
				}
			}
		}
	}
	maximal=0;
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
		{
			if(maximal<best[i][j])
			{
				maximal=best[i][j];
			}
		}
	printf("%d\n",maximal);
	return 0;
}