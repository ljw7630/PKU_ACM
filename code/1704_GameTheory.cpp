// Staircase Nim
// 偶数编号堆中棋子个数不影响局面状态
// 因为a将棋子从偶数堆移到奇数堆,他对
// 手总是可以将相同数目棋子从此奇数堆移到编号更小的偶数堆
// 所以,Staricase Nim中从奇数编号堆移动棋子相当于Nim中将
// 棋子从堆中拿走
// Nim: 堆中石子异或大于零先手胜,否则后手胜

#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int a[10005];
	int p[10005];
	int t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int k=0;
		if(n%2)
		{
			p[k++]=a[0]-1;
			for(int i=1;i<n-1;i+=2)
			{
				p[k++]=a[i+1]-a[i]-1;
			}
		}
		else
		{
			for(int i=0;i<n-1;i+=2)
			{
				p[k++]=a[i+1]-a[i]-1;
			}		
		}
		int s=p[0];
		int tk=1;
		while(tk<k)
		{
			s=s^p[tk];
			tk++;
		}
		if(s)
			printf("Georgia will win\n");
		else
			printf("Bob will win\n");
	}
	return 0;
}