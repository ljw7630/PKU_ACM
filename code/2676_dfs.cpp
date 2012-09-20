#include <iostream>
using namespace std;

bool flag;
int map[9][9];

bool validate(int i,int j)
{
	for(int t=0;t<9;++t)
	{
		if(t!=i)
		{
			if(map[t][j]==map[i][j])
				return false;
		}
		if(t!=j)
		{
			if(map[i][t]==map[i][j])
				return false;
		}
	}
	int s1=i/3;
	int s2=j/3;
	for(int m=0;m<3;++m)
	{
		for(int n=0;n<3;++n)
		{
			if(s1*3+m!=i&&s2*3+n!=j)
			{
				if(map[s1*3+m][s2*3+n]==map[i][j])
					return false;
			}
		}
	}
	return true;
}

void dfs(int i,int j)
{
	if(i==-1)
	{
		flag=true;
		return;
	}
	if(map[i][j]==0)
	{
		for(int k=1;k<=9;++k)
		{
			map[i][j]=k;
			if(validate(i,j))
			{
				if(j==0)
					dfs(i-1,8);
				else 
					dfs(i,j-1);
				if(flag)
					return;
			}
			map[i][j]=0;
		}
	}
	else
	{
		if(j==0)
			dfs(i-1,8);
		else 
			dfs(i,j-1);
	}
		
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	char str[10];
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<9;++i)
		{
			scanf("%s",str);
			for(int j=0;str[j];++j)
				map[i][j]=str[j]-'0';
		}  
		flag=false;
		dfs(8,8);
		for(int i=0;i<9;++i)
		{
			for(int j=0;j<9;++j)
				printf("%d",map[i][j]);
			printf("\n");
		}
	}
	return 0;
}