#include <iostream>
using namespace std;
char s[101];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(gets(s)&&s[0]!='#')
	{
		int len=strlen(s);
		for(int i=0;i<len;++i)
		{
			switch(s[i])
			{
			case ' ':
				printf("%%20");
				break;
			case '!':
				printf("%%21");
				break;
			case '$':
				printf("%%24");
				break;
			case '%':
				printf("%%25");
				break;
			case '(':
				printf("%%28");
				break;
			case ')':
				printf("%%29");
				break;
			case '*':
				printf("%%2a");
				break;
			default:
				printf("%c",s[i]);
			}
		}
		printf("\n");
	}
	return 0;
}