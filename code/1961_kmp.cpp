#include <iostream>
using namespace std;

const int MAX=1000005;
char str[MAX];
int pi[MAX];
int n,len;

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
	int c=0;
	while(scanf("%d",&n)!=EOF&&n)
	{
		scanf("%s",str);
		len=strlen(str);
		prefix();
		printf("Test case #%d\n",++c);
		for(int i=1;i<len;++i)
		{
			int count=0;
			if((i+1)%(i+1-(pi[i]+1))==0&&pi[i]!=-1)
				count=(i+1)/(i+1-(pi[i]+1));
			if(count)
				printf("%d %d\n",i+1,count);
		}
		printf("\n");
	}
	return 0;
}