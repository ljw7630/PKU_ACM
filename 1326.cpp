#include <iostream>
using namespace std;
char s1[101],s2[101];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char _class;
	int _money,sum=0;
	bool flag=false;
	while(1)
	{
		while(1)
		{
			scanf("%s",&s1);
			if(strcmp(s1,"#")==0)
			{
				flag=true;
				break;
			}
			if(strcmp(s1,"0")==0)
			{
				printf("%d\n",sum);
				sum=0;
				continue;
			}
			scanf("%s %d %c",&s2,&_money,&_class);
			if(_class=='F')
				sum+=2*_money;
			else if(_class=='B')
				sum+=_money+(_money+1)/2;
			else if(_money<500)
				sum+=500;
			else
				sum+=_money;
		}
		if(flag)
			break;
	}
	return 0;
}