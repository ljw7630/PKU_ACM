#include <iostream>
using namespace std;
bool res[100002];
int count[100002][2]; 
// count[i][0] means last coin is which kind
// count[i][1] means used how many count[i][0] kind coins
//count[i][0]��ʾ����۸�i�����һöӲ�ҵ�����
//count[i][1]��ʾ����۸�i�����һöӲ�����˶��ٸ�

//���Ĵ���
//int pre=j-a[i];
//if(!res[j]&&res[pre]&&!(count[pre][0]==i&&count[pre][1]==c[i]))
//{
//	ans++;
//	res[j]=true;
//	count[j][0]=i;
//	count[j][1]=count[pre][0]==i?count[pre][1]+1:1;
//}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m;
	int a[102],c[102];
	while(scanf("%d%d",&n,&m)!=EOF&&n)
	{
		memset(res,false,sizeof(res));
		memset(count,0,sizeof(count));
		for(int i=1;i<=n;++i)
			scanf("%d",&a[i]);
		for(int i=1;i<=n;++i)
			scanf("%d",&c[i]);
		res[0]=true;
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=a[i];j<=m;++j)
			{
				int pre=j-a[i];
				if(!res[j]&&res[pre]&&!(count[pre][0]==i&&count[pre][1]==c[i]))
				{
					ans++;
					res[j]=true;
					count[j][0]=i;
					count[j][1]=count[pre][0]==i?count[pre][1]+1:1;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}