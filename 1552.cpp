#include <iostream>
using namespace std;

int value[20];
bool isin[200];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(true)
	{
		memset(isin,false,sizeof(isin));
		int c=0;
		while(scanf("%d",&value[c])&&value[c])
			c++;
		if(value[0]==-1)
			break;
		for(int i=0;i<c;++i)
			isin[value[i]]=true;
		int count=0;
		for(int i=0;i<c;++i)
		{
			if(isin[value[i]*2])
				count++;
		}
		printf("%d\n",count);
	}
	return 0;
}