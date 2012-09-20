#include <iostream>
using namespace std;
int num,len,wid,tile,each[101][4];
char map[40001][40001];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k;
	bool outsideflag,overlapflag,uncoverflag;
	scanf("%d",&num);
	while(num--)
	{
		scanf("%d%d%d",&len,&wid,&tile);
		outsideflag=false;
		overlapflag=false;
		uncoverflag=false;
		for(i=0;i<len;i++)
			for(j=0;j<wid;j++)
				map[i][j]=0;
		for(i=0;i<tile;i++)
			for(j=0;j<4;j++)
				scanf("%d",&each[i][j]);
		for(i=0;i<tile;i++)
		{
			for(j=each[i][0];j<each[i][2];j++)
			{
				for(k=each[i][1];k<each[i][3];k++)
				{
					if(j>len||k>wid)
						outsideflag=true;
					if(j<0||k<0)
					{
						outsideflag=true;
						continue;
					}
					map[j][k]++;
				}
			}
		}
		for(i=0;i<len;i++)
		{
			for(j=0;j<wid;j++)
			{
				if(map[i][j]==0)
				{
					uncoverflag=true;
				}
				if(map[i][j]>1)
				{
					overlapflag=true;
				}
			}
		}
		if(overlapflag==true)
			printf("NONDISJOINT\n");
		else if(outsideflag==true)
			printf("NONCONTAINED\n");
		else if(uncoverflag==true)
			printf("NONCOVERING\n");
		else
			printf("OK\n");
	}
	return 0;
}