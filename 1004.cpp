#include <iostream>
using namespace std;
double perMon, sum, count;

int main()
{
	//freopen("in.txt","r",stdin);
	//freopen("out.txt","w",stdout);
	
	count = 0;
	while(scanf("%lf",&perMon)!=EOF)
	{
		if(count==11)
		{
			count=0;
			printf("$%.2lf",(sum+perMon)/12);
			sum=0;
		}
		else
		{
			count++;
			sum+=perMon;
		}
	}
	return 0;
}