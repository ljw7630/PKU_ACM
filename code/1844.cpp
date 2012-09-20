#include <iostream>
using namespace std;

const int maxi=200000;
int main()
{
	int s;
	while(scanf("%d",&s)!=EOF)
	{
		int temp,i;
		for(i=1;i<maxi;++i)
		{
			temp=(1+i)*i/2;
			if(temp>=s)
			{
				temp-=s;
				if(temp%2==0)
					break;
			}
		}
		printf("%d\n",i);
	}
	return 0;
}