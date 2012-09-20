#include <iostream>
using namespace std;
int arr[3002];
bool visit[3002];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,i;
	while(scanf("%d",&n)!=EOF)
	{
		memset(visit,false,sizeof(visit));
		for(i=0;i<n;++i)
		{
			scanf("%d",&arr[i]);
			if(i!=0)
				visit[abs(arr[i]-arr[i-1])]=true;
		}
		for(i=1;i<n;++i)
		{
			if(!visit[i])
				break;
		}
		if(i!=n)
			printf("Not jolly\n");
		else
			printf("Jolly\n");
	}
	return 0;
}