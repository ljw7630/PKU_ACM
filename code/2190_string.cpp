#include <iostream>
using namespace std;

char pre[11];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int mark,sum,i;
	while(scanf("%s",&pre)!=EOF)
	{
		sum=0;
		for(i=0;i<10;++i)
		{
			if(pre[i]=='?')
			{
				mark=i;
			}
			else if(pre[i]!='X')
			{
				sum+=(pre[i]-'0')*(10-i);
			}
			else
			{
				sum+=10*(10-i);
			}
		}
		int n=0;
		if(mark==9)
			n=10;
		else
			n=9;
		char res;
		for(i=0;i<=n;++i)
		{
			sum+=i*(10-mark);
			if(sum%11==0)
			{
				if(mark==9&&i==10)
				{
					res='X';
				}
				else
				{
					res='0'+i;
				}
				break;
			}
			sum-=i*(10-mark);
		}
		if(i>n)
			printf("-1\n");
		else
			printf("%c\n",res);
	}
	return 0;
}