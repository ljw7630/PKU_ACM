#include <iostream>
using namespace std;
int num,bit,all[46],t;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&num);
	t=num;
	all[1]=2;
	all[2]=3;
	for(int i=3;i<46;i++)
	{
		all[i]=all[i-1]+all[i-2];
	}
	while(num--)
	{
		scanf("%d",&bit);
		printf("Scenario #%d:\n",t-num);
		printf("%d\n\n",all[bit]);
	}
	return 0;
}