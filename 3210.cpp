//题目说的是必须要翻k次。
//如果n是偶数，分成两个奇数（即，正的奇数个，反的奇数个）那么必要翻奇数次
//           分成两个偶数，必要翻偶数次。故无解
//如果n是奇数，只能分成一奇一偶，显然翻n-1次就行了（n-1为偶数，我们只翻偶数那种的） 

#include <iostream>
using namespace std;
int n;
int main()
{
	while(scanf("%d",&n)!=EOF&&n)
	{
		if(n&1)
			printf("%d\n",n-1);
		else
			printf("No Solution!\n");
	}
	return 0;
}