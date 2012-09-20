#include <iostream>
using namespace std;
int n,x[301]; // row i col x[i]
bool flag;
bool place(int k)
{
	for(int j=1;j<k;j++)
		if((abs(k-j)==abs(x[j]-x[k]))||(x[j]==x[k]))
			return false;
	return true;
}

void backtrack(int w)
{
	if(w>n)
	{
		flag=true;
		return;
	}
	else
	{
		for(int i=1;i<=n;i++)
		{
			x[w]=i;
			if(place(w))
				backtrack(w+1);
			if(flag)
				return;
		}
	}
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		memset(x,0,sizeof(x));
		backtrack(1);
		flag=false;
		for(int i=1;i<=n;i++)
		{
			printf("%d ",x[i]);
		}
	}
	return 0;
}