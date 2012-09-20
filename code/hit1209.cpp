#include <iostream>
using namespace std;
int n;
int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	scanf("%d",&n);
	while(n--)
	{
		int t;
		scanf("%d",&t);
		if(t<=5)
		{
			printf("%d\n",t);
			continue;
		}
		else
		{
			int count=0;
			while(t>5)
			{
				t-=4;
				t--;
				count+=4;
			}
			count+=t;
			printf("%d\n",count);
		}
	}
	system("pause");
	return 0;
}