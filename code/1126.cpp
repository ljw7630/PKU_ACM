#include <iostream>
#include <string.h>
using namespace std;
char s[260];

bool IsCorrect(char *s, int start, int end)
{
	if(end==start)
	{
		if(s[end]<='z'&&s[end]>='p')
			return true;
		else
			return false;
	}
	else if(s[start]=='N'&& IsCorrect(s,start+1,end))
	{
		return true;
	}
	else if( (s[start]>='C'&&s[start]<='E') || s[start]=='I' )
	{
		for(int i=1;i<end-start;i++)
		{
			if(IsCorrect(s,start+1,start+i)&&IsCorrect(s,start+i+1,end))
				return true;
		}
		return false;
	}
	else
	{
		return false;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int len;
	bool flag;
	while(scanf("%s",&s)!=EOF)
	{
		len=strlen(s);
		flag=IsCorrect(s,0,len-1);
		if(flag)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
}