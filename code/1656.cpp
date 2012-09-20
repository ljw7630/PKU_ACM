#include <iostream>
using namespace std;
int n,x,y,l;
bool flag;
char c[8];
bool board[101][101];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		flag=0; // white
		memset(board,false,sizeof(board));
		while(n--)
		{
			scanf("%s %d %d %d",c,&x,&y,&l);
			if(c[0]=='T')
			{
				int count=0;
				for(int i=x;i<=x+l-1;++i)
				{
					for(int j=y;j<=y+l-1;++j)
					{
						if(board[i][j])
							count++;
					}
				}
				printf("%d\n",count);
				continue;
			}
			else if(c[0]=='B')
			{
				flag=1;
			}
			else
			{
				flag=0;
			}
			for(int i=x;i<=x+l-1;++i)
			{
				for(int j=y;j<=y+l-1;++j)
				{
					board[i][j]=flag;
				}
			}
		}
	}
	return 0;
}