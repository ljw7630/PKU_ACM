#include <iostream>
using namespace std;

int t,len,n,c,sum;
int cake[12];
int map[42];  // 记录每列填了几行 // 好想法!
bool flag;

void dfs(int a)
{
	int j,pos,col;
	bool in_loop_flag;
	if(a==n)
	{
		flag=true;
		exit;
	}
	for(j=0,pos=42;j<len;++j)
		if(pos>map[j])
		{
			pos=map[j];
			col=j;
		}
	for(int i=10;i>0;--i)
	{
		if(cake[i]>0&&pos+i<=len&&col+i<=len)  //精髓
		{
			for(j=col,in_loop_flag=true;j<col+i;++j) //精髓
			{
				if(map[j]>pos)
				{
					in_loop_flag=false;
					break;
				}
			}
			if(in_loop_flag)
			{
				for(j=col;j<col+i;++j)
					map[j]+=i;
				--cake[i];
				dfs(a+1);
				++cake[i];
				for(j=col;j<col+i;++j)
					map[j]-=i;
			}
		}
	}
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(cake,0,sizeof(cake));
		sum=0;
		for(int i=0;i<42;++i)
			map[i]=0;
		scanf("%d%d",&len,&n);
		for(int i=0;i<n;++i)
		{
			scanf("%d",&c);
			cake[c]++;
			sum+=c*c;
		}
		if(sum!=len*len)
			flag=false;
		else
		{
			flag=false;
			dfs(0);
		}
		if(flag)
			printf("KHOOOOB!\n");
		else
			printf("HUTUTU!\n");
	}
	return 0;
}