#include <iostream>
using namespace std;
int t;
char s[25];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		printf("%c%c/%c%c/%c%c%c%c-",s[5],s[6],s[8],s[9],s[0],s[1],s[2],s[3]);
		if(s[11]=='0'&&s[12]=='0')
		{
			printf("12:%c%c:%c%cam",s[14],s[15],s[17],s[18]);
		}
		else if(s[11]=='1'&&s[12]=='2')
		{
			printf("12:%c%c:%c%cpm",s[14],s[15],s[17],s[18]);
		}
		else
		{
			if(s[11]>='1')
			{
				if(s[12]=='1'||s[12]=='0')
				{
					printf("%c%c:%c%c:%c%cam",s[11],s[12],s[14],s[15],s[17],s[18]);
				}
				else
				{
					printf("%c%c:%c%c:%c%cpm",s[11]-1,s[12]-2,s[14],s[15],s[17],s[18]);
				}
			}
			else
				printf("%c%c:%c%c:%c%cam",s[11],s[12],s[14],s[15],s[17],s[18]);
		}
		
		printf("\n");
	}
	return 0;
}