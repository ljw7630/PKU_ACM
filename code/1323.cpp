#include <iostream>
using namespace std;
int m,n,t,win,MAX,count=1;
bool arr[1002];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(1)
	{
		scanf("%d%d",&m,&n);
		if(m==0||n==0)
			return 0;
		MAX=0;win=0;
		memset(arr,0,sizeof(arr));
		for(int i=0;i<n;i++)
		{
			scanf("%d",&t);
			arr[t]=true;
		}
		for(int i=n*m;i>0;i--)
		{
			if(arr[i])
				win++;
			else
				win--;
			if(win>MAX)
				MAX=win;
		}
		printf("Case %d: %d\n",count++,MAX);
	}
	return 0;
}