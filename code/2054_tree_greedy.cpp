//这道题就是要求 Sigma( i * Ci ) (i = 1 .. n) 的值最小，{ Ci } 是节点费用的一个排列，同时要满足父节点要出现在子节点前面。如果没有父节点出现在子节点前面这个限制，那么答案很明显。当{ Ci }按降序排列的时候，Sigma的值是最小的。当有这个限制的时候情况也是类似的。考虑某一个可行解，就是{ Ci }的某一个排列。找到其中的最大值，比如为Ck，它有一个父节点比如Cp。显然Cp要出现在Ck之前。更进一步，Cp就应该出现在Ck的前一个位置。只有这样才有可能Sigma的值最小。不然我们可以将Ck位置向前移动，得到一个更小的Sigma值，并且不破坏上面的约束。既然Cp就出现在Ck的前一个位置，那么它们其实就是连在一起的，可以最为一个整体来看。这样问题的规模就有n减小到n-1。然后重复这一过程，直到所有的位置都确定下来。
//
//算法流程：
//
//1.        令所有节点S值均为1，每个节点生成序列中仅有一个元素，即为它本身。
//
//2.        若树中只剩一个结点，则输出这个这个结点的生成序列。
//
//3.        取出Ci/Si值最大的非根结点Max。
//
//4.        将Max和其父亲合并，新合并出的结点Union的各个参数为：Cunion=CMax+CPa(max)，SUnion=SMax+SPa(Max)，同时Union的生成序列为Pa(Max)的生成序列与Max的生成序列连接而成。
//
//5.        重复2~4步。
//
//注意：其实这题可以不用记录结点先后的序列，设置一个全局变量res,在预处理时，res=所有节点的C的和，然后每合并两个节点（编号为pos,其父节点为编号为f），那么 res+=c[pos]*time[f],最后输出res即可，至于为什么能这样子，自己可以动脑筋思考一下          


#include <iostream>
using namespace std;

int n,r,maxi,res;
struct NODE
{
	int c;
	int time;
	int parent;
	double weight;  // 用c/time greedy
}node[1005];

int findmaxweight()
{
	int p=0;
	double maxi=0.0;
	for(int i=1;i<=n;++i)
	{
		if(node[i].weight>maxi&&i!=r)
		{
			maxi=node[i].weight;
			p=i;
		}
	}
	return p;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int fa,son,pos;
	while(scanf("%d%d",&n,&r)!=EOF&&n&&r)
	{
		res=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&node[i].c);
			node[i].time=1;
			node[i].weight=node[i].c;
			res+=node[i].c;
		}
		node[r].parent=-1;
		for(int i=1;i<n;++i)
		{
			scanf("%d%d",&fa,&son);
			node[son].parent=fa;
		}
		int count=n;
		while(count>1)
		{
			pos=findmaxweight();
			fa=node[pos].parent;
			res+=node[pos].c*node[fa].time;
			for(int i=1;i<=n;++i)
			{
				if(node[i].parent==pos)
					node[i].parent=fa;
			}
			node[pos].weight=0;
			node[fa].time+=node[pos].time;
			node[fa].c+=node[pos].c;
			node[fa].weight=(double)node[fa].c/node[fa].time;
			count--;
		}
		printf("%d\n",res);
	}
	return 0;
}