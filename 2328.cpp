#include <iostream>
using namespace std;
int num;
char s1[5],s2[5];
int check[11];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j;
	bool flag;
	for(i=0;i<11;i++)
	{
		check[i]=-1;
	}
	while(scanf("%d",&num)!=EOF&&num!=0)
	{
		scanf("%s%s",&s1,&s2);
		if(strcmp(s2,"high")==0)
		{
			for(j=num;j<11;j++)
			{
				check[j]=0;
			}
			continue;
		}
		if(strcmp(s2,"low")==0)
		{
			for(j=num;j>0;j--)
			{
				check[j]=0;
			}
			continue;
		}
		if(strcmp(s1,"right")==0)
		{
			if(check[num]==-1)
			{
				flag=true;
			}
			else
			{
				flag=false;
			}
			if(!flag)
			{
				printf("Stan is dishonest\n");
			}
			else
			{
				printf("Stan may be honest\n");
			}
			for(i=0;i<11;i++)
			{
				check[i]=-1;
			}
		}
	}
	return 0;
}