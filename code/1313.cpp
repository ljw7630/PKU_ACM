#include <iostream>
using namespace std;
int n;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,j,k,sheet;
	while(scanf("%d",&n)!=EOF&&n!=0)
	{
		printf("Printing order for %d pages:\n",n);
		i=1;
		j=n/4;
		if(n%4!=0)
			j++;
		sheet=j;j=j*4;
		for(k=1;k<=sheet;k++)
		{
			printf("Sheet %d, front: ",k);
			if(j>n)
				printf("Blank");
			else
				printf("%d",j);
			printf(", %d\n",i);
			j--;i++;
			if(i>n) break;
			printf("Sheet %d, back : ",k);
			printf("%d, ",i);
			if(j>n)
				printf("Blank\n");
			else 
				printf("%d\n",j);
			j--;i++;
		}
	}
	return 0;
}