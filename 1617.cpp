#include <iostream>
#include <algorithm>
using namespace std;

char key[12],text[102],sortkey[12],result[102];
bool flag[12];

class myclass
{
public:
	int used,now;
	bool friend operator<(myclass &a,myclass &b)
	{
		return a.now<b.now;
	}
}m[12];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%s",key)!=EOF&&strcmp(key,"THEEND")!=0)
	{
		memset(flag,false,sizeof(flag));
		scanf("%s",text);
		int lenk,lent;
		lenk=strlen(key);
		lent=strlen(text);
		strcpy(sortkey,key);
		sort(sortkey,sortkey+lenk);
		for(int i=0;i<lenk;++i)
			m[i].used=i;
		for(int i=0;i<lenk;++i)
		{
			for(int j=0;j<lenk;++j)
			{
				if(key[j]==sortkey[i]&&!flag[j])
				{
					m[j].now=i;
					flag[j]=true;
					break;
				}
			}
		}
		sort(m,m+lenk);
		int c=0;
		for(int i=0;i<lenk;++i)
		{
			int w=m[i].used;
			while(w<lent)
			{
				result[w]=text[c++];
				w+=lenk;
			}
		}
		result[lent]='\0';
		printf("%s\n",result);
	}
	return 0;
}