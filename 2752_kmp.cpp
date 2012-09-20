#include <iostream>
using namespace std;

char str[400005];
int pi[400005];
int res[400005];
int len;

void prefix()
{
	pi[0]=-1;
	int k=-1;

	for(int i=1;i<len;++i)
	{
		while(k!=-1&&str[k+1]!=str[i])
			k=pi[k];
		if(str[k+1]==str[i])
			k++;
		pi[i]=k;
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%s",&str)!=EOF)
	{
		len=strlen(str);
		prefix();
		int index=0;
		int j=len-1;
		while(j!=-1)
		{
			res[index++]=j+1;
			j=pi[j];
		}
		for(int i=index-1;i>-1;--i)
			printf("%d ",res[i]);
		printf("\n");
	}
}