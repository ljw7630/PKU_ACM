#include <iostream>
using namespace std;

int n;
int arr[100001];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d",&n)!=EOF)
	{
		for(int i=0;i<n;++i)
		{
			scanf("%d",&arr[i]);
		}
		int c=0;
		int jill=arr[0],jack=arr[1];
		arr[n]=INT_MAX;
		int indexl=1,indexk=2;
		bool flagk=true;
		bool flagl=true;
		while(true)
		{
			while(arr[indexl]-jill<=10)
			{
				indexl++;
			}
			if(arr[indexl-1]==jill)
			{
				flagl=false;
			}
			else
			{
				if(indexk!=indexl)
				{
					jill=arr[indexl-1];
					c++;
					flagl=true;
				}
				else if(jill!=arr[indexl-2])
				{
					jill=arr[indexl-2];
					c++;
					flagl=true;
				}
				else
				{
					flagl=false;
				}
			}
			if(indexl==n)
				break;
			while(arr[indexk]-jack<=10)
			{
				indexk++;
			}
			if(arr[indexk-1]==jack)
			{
				flagk=false;
			}
			else
			{
				if(indexk!=indexl)
				{
					jack=arr[indexk-1];
					c++;
					flagk=true;
				}
				else if(jack!=arr[indexk-2])
				{
					jack=arr[indexk-2];
					c++;
					flagk=true;
				}
				else
				{
					flagk=false;
				}
			}
			if(indexk==n)
				break;
			if(indexl>indexk)
			{
				int t=indexl;
				indexl=indexk;
				indexk=t;
				t=jack;
				jack=jill;
				jill=t;
			}
			if(!flagl&&!flagk)
				break;
		}
		if(!flagl&&!flagk)
			printf("-1\n");
		else
			printf("%d\n",c);
	}
	return 0;
}