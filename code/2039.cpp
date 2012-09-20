#include <iostream>
using namespace std;
char c[202];
int column;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,len,temp;
	int flag;
	while(scanf("%d",&column)!=EOF&&column!=0)
	{
		scanf("%s",&c);
		len=strlen(c);
		temp=column;
		for(i=0;i<column;i++)
		{
			j=i;
			flag=2;
			while(j<len)
			{
				printf("%c",c[j]);
				if(flag==2)
				{
					j+=temp*flag-1;
					flag=0;
				}
				else
				{
					j+=(column-temp)*2+1;
					flag=2;
				}
			}
			temp--;
		}
		printf("\n");
	}
	return 0;
}