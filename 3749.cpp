#include <iostream>
#include <string>
using namespace std;
char s[501];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,len;
	while(gets(s)&&strcmp(s,"ENDOFINPUT")!=0)
	{
		if(strcmp(s,"START")==0)
			continue;
		if(strcmp(s,"END")==0)
			continue;
		len=strlen(s);
		for(i=0;i<len;i++)
		{
			if(s[i]>='A'&&s[i]<='Z')
			{
				if(s[i]>='F')
					s[i]-=5;
				else
					s[i]+=21;
			}
		}
		printf("%s\n",s);
	}
	return 0;
}