#include <iostream>
#include <algorithm>
using namespace std;
int n;
class interval
{
public:
	int s,e;
	bool friend operator <(interval a,interval b)
	{
		return a.s<b.s;
	}
}arr[50001];

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int i,start,end;
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
		scanf("%d%d",&arr[i].s,&arr[i].e);
	sort(arr,arr+n);
	start=arr[0].s;
	end=arr[0].e;
	for(i=1;i<n;i++)
	{
		if(end>=arr[i].s&&end<arr[i].e)
			end=arr[i].e;
		if(end<arr[i].s)
		{
			printf("%d %d\n",start,end);
			start=arr[i].s;
			end=arr[i].e;
		}
	}
	printf("%d %d\n",start,end);
	return 0;
}