#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char s[25],c[105];
string t;
int len;

bool valid()
{
	int tlen=strlen(c)/2;
	for(int i=0;i<tlen;++i)
		if(find(s,s+len,c[i*2])>find(s,s+len,c[i*2+1]))
			return false;
	return true;
}

int main()
{
	int j;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(getline(cin,t))
	{
		len=t.size();
		j=0;
		for(int i=0;i<len;i++)
		{
			if(t[i]<='z'&&t[i]>='a')
			{
				s[j]=t[i];
				j++;
			}
		}
		s[j]='\0';
		getline(cin,t);
		len=t.size();
		j=0;
		for(int i=0;i<len;i++)
		{
			if(t[i]<='z'&&t[i]>='a')
			{
				c[j]=t[i];
				j++;
			}
		}
		c[j]='\0';
		len=strlen(s);
		sort(s,s+len);
		if(valid())
			printf("%s\n",s);
		while(next_permutation(s,s+len))
		{
			if(valid())
			{
				printf("%s\n",s);
			}
		}
		printf("\n");
	}
	return 0;
}