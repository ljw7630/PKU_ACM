#include <math.h>
#include <stdio.h>
#include <string.h>

int n;
int map[27][27], c[27];
char adj[27][30];

void get_graph()
{
	int i, j;

	for(i = 0; i < n; i++)
	{
		c[adj[i][0]-'A'] = i;
	}
	for(i = 0; i < n; i++)
	{
		for(j = 2; adj[i][j]!='\0'; j++)
		{
			map[i][c[adj[i][j]-'A']] = 1;
		}
	}
}

int fit(int v,int num)
{
	int i, j;

	for(i = 0; i < num; i++)
	{
		c[v] = i;
		for(j = 0; j < n; j++)
		{
			if(map[v][j]&&c[j]==c[v])
				goto con;
		}
		if(v==n-1||fit(v+1,num))
			return 1;
con:
		;
	}
	return 0;
}

int main()
{
	int i;
	int max, mid, min;

	while(scanf("%d",&n)==1,n)
	{
		memset(map,0,sizeof(map));
		for(i = 0; i < n; i++)
		{
			scanf("%s",adj[i]);
		}
		get_graph();
		min = 1;max = n;
		while(min<max)
		{
			memset(c,-1,sizeof(c));
			mid = (max+min)/2;
			if(fit(0,mid))
				max = mid;
			else
				min = mid+(min==mid);
		}
		printf("%d channel",min);
		if(min!=1)
			putchar('s');
		puts(" needed.");
	}
	return 1;
}
