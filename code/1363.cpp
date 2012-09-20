#include <iostream>
using namespace std;
int num,order[1002];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&num)!=EOF&&num!=0)
	{
		while(scanf("%d",&order[0])&&order[0]!=0)
		{
			bool flag=true;
			for(int i=1;i<num;i++)
			{
				scanf("%d",&order[i]);
			}
			for(int i=0;i<num;i++)
			{
				int temp=order[i+1];
				for(int j=i+2;j<num;j++)
				{
					if(order[j]<order[i])
					{
						if(order[j]<=temp)
							temp=order[j];
						else
						{
							flag=false;
							break;
						}
					}
				}
			}
			if(flag==1)
				printf("Yes\n");
			else
				printf("No\n");
		}
		printf("\n");
	}
	return 0;
}