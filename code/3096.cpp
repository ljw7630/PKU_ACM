#include <iostream>
using namespace std;

char str[101];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%s",str)!=EOF&&str[0]!='*')
	{
		int len=strlen(str);
		bool flag=false;
		if(len==1||len==2)
		{
			printf("%s is surprising.\n",str);
			flag=true;
		}
		for(int i=1;i<len&&!flag;++i)
		{
			for(int j=0;j+i<len&&!flag;++j)
			{
				for(int k=j+1;k+i<len;++k)
				{
					if(str[j]==str[k]&&str[j+i]==str[k+i])
					{
						printf("%s is NOT surprising.\n",str);
						flag=true;
					}
				}
			}
		}
		if(!flag)
			printf("%s is surprising.\n",str);
	}
	return 0;
}