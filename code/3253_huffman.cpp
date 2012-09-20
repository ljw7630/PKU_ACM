#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	priority_queue<__int64,vector<__int64>,greater<__int64>> pq;
	scanf("%d",&n);
	__int64 temp;
	__int64 sum=0;
	for(int i=0;i<n;++i)
	{
		scanf("%I64d",&temp);
		pq.push(temp);
	}
	__int64 t1,t2;
	while(pq.size()!=1)
	{
		t1=pq.top();
		pq.pop();
		t2=pq.top();
		pq.pop();
		t1+=t2;
		sum+=t1;
		pq.push(t1);
	}
	printf("%I64d\n",sum);
	pq.pop();
}
