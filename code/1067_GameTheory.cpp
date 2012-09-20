//其一：
//按位异或及其在求解游戏策略问题中的应用，李学武（原载:《计算机科学》 2001.10）
//请自己google
//
//其二：
//好玩的数学系列《幻方及其他》19.4，NIM的另一种变形。
//
//这里给出第二种解法
//本游戏的安全组合序列如下（后手胜），先手可以通过构造这些安全状态达到胜利。
//(1, 2)
//(3, 5)
//(4, 7)
//(6, 10)
//(8, 13)
//(9, 15)
//(11, 18)
//(12, 20)
//……
//
//考察序列，可发现如下性质
//1. 1，2，3，4……每个正整数都正好出现且只出现1次
//2. 序列中每对正整数之差，次序为1，2，3，4……
//3. 一般表达式为（[a·r], [b·r]），其中，a=(sqrt(5)+1)/2，b=(sqrt(5)+3)/2=(sqrt(5)+1)/2+1=a+1
//4. a与b恰为黄金分割X=(sqrt(5)-1)/2=0.618和 1/X同1之和。即a=1+X，b=1+1/X。
//

#include <iostream>
#include <math.h>
using namespace std;
int a,b,k,temp;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(scanf("%d%d",&a,&b)==2)
	{
		if(a>b)
		{
			temp=a;
			a=b;
			b=temp;
		}
		k=b-a;
		temp=floor((double)k*(1+sqrt(5.0))/2);
		if(temp==a)
			printf("0\n");
		else
			printf("1\n");
	}
	return 0;
}