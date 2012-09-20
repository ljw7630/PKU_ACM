#include <iostream>
using namespace std;
char web[130][100];
char action[10];
int pointto,count;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	strcpy(web[0],"http://www.acm.org/");
	pointto=0,count=1;
	while(true)
	{
		scanf("%s",&action);
		if(action[0]=='Q')
			break;
		else if(action[0]=='V')
		{
			scanf("%s",&web[++pointto]);
			count=pointto+1;
			printf("%s\n",&web[pointto]);
		}
		else if(action[0]=='B')
		{
			if(pointto!=0)
				printf("%s\n",&web[--pointto]);
			else
				printf("Ignored\n");
		}
		else if(action[0]=='F')
		{
			if(count>pointto+1)
				printf("%s\n",&web[++pointto]);
			else
				printf("Ignored\n");
		}
	}
	return 0;
}