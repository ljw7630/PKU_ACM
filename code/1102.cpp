#include <iostream>
using namespace std;
bool digit[7][10]=
{
	{1,0,1,1,0,1,1,1,1,1},
    {1,0,0,0,1,1,1,0,1,1},
	{1,1,1,1,1,0,0,1,1,1},
	{0,0,1,1,1,1,1,0,1,1},
	{1,0,1,0,0,0,1,0,1,0},
	{1,1,0,1,1,1,1,1,1,1},
	{1,0,1,1,0,1,1,0,1,1}
};
int s,len;
char str1[10];
int str2[10];

void print_h(int line)
{
	int i,j;

	for(i=0;i<len;i++)
	{
		printf(" ");
		for(j=0;j<s;j++)
		{
			if(digit[line][str2[i]]==1)
				printf("-");
			else
				printf(" ");
		}
		printf("  ");
	}
}

void print_v(int line)
{
	int i,j;
	for(i=0;i<len;i++)
	{
		if(digit[line][str2[i]]==1)
			printf("|");
		else
			printf(" ");
		for(j=0;j<s;j++)
			printf(" ");
		if(digit[line+1][str2[i]]==1)
			printf("|");
		else
			printf(" ");
		printf(" ");
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j;
	while(scanf("%d%s",&s,&str1)!=EOF&&s!=0)
	{
		len=strlen(str1);
		for(i=0;i<len;i++)
			str2[i]=str1[i]-'0';
		print_h(0);printf("\n");
		for(j=0;j<s;j++)
		{
			print_v(1);
			printf("\n");
		}
		print_h(3);printf("\n");
		for(j=0;j<s;j++)
		{
			print_v(4);printf("\n");
		}
		print_h(6);printf("\n");
		printf("\n");
	}
	return 0;
}