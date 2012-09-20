#include <iostream>
using namespace std;

char origin[1000002];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k;
	while(scanf("%s",origin)!=EOF&&origin[0]!='.')
	{
		int len=strlen(origin);
		for(i=1;i<len;i++)
		{
			if(len%i==0)
			{
				for(j=0;j<i;++j)
				{
					for(k=j+i;k<len;k+=i)
					{
						if(origin[j]!=origin[k])
							break;
					}
					if(k<len)   // do not match
						break;
				}
				if(j==i)   // all are match
					break;
			}
		}
		printf("%d\n",len/i);
	}
	return 0;
}