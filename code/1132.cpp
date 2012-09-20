#include <iostream>
using namespace std;
int t,x,y;
char c,bitmap[33][33];
int main()
{
	int i;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		printf("Bitmap #%d\n",i);
		memset(bitmap,'.',sizeof(bitmap));
		scanf("%d%d",&x,&y);
		while(scanf("%c",&c)!=EOF&&c!='.')
		{
			if(c=='E')
				bitmap[y-1][x]='X',x++;
			else if(c=='N')
				bitmap[y][x]='X',y++;
			else if(c=='W')
				bitmap[y][x-1]='X',x--;
			else if(c=='S')
				bitmap[y-1][x-1]='X',y--;
		}
		for(int j=31;j>=0;j--)
		{
			for(int k=31;k>=0;k--)
				printf("%c",bitmap[j][31-k]);
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}