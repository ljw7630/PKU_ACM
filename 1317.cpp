#include <iostream>
using namespace std;
int key;
char c[72],p[72];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int len,i;
	while(scanf("%d",&key)!=EOF&&key!=0)
	{
		scanf("%s",&c);
		len=strlen(c);
		for(i=0;i<len;i++)
		{
			if(c[i]=='_')
				c[i]=0;
			else if(c[i]=='.')
				c[i]=27;
			else if(c[i]>='a'&&c[i]<='z')
				c[i]=c[i]-'a'+1;
		}	
		for(i=0;i<len;i++)
			p[(key*i)%len]=(c[i]+i)%28;
		for(i=0;i<len;i++)
		{
			if(p[i]==0)
				p[i]='_';
			else if(p[i]>=1&&p[i]<=26)
				p[i]+='a'-1;
			else if(p[i]==27)
				p[i]='.';
		}
		p[i]='\0';
		printf("%s\n",p);
	}
	return 0;
}