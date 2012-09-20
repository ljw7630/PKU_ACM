#include <iostream>
#include <algorithm>
using namespace std;

class SCORE
{
public:
	double score;
	int credit;
};

SCORE optional[101];

class myCmp
{
public:
	bool operator()(const SCORE &a,const SCORE &b)
	{
		if(a.score>b.score)
			return true;
		else if(a.score==b.score)
			return a.credit>b.credit;
		else
			return false;
	}
};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n,m,c,tempc,i;
	double a,tempa;
	cin >> t;
	while(t--)
	{
		a=0;
		c=0;
		cin >> n >> m;
		for(i=0;i<n;++i)
		{
			cin >> tempa >> tempc;
			a+=tempa*tempc;
			c+=tempc;
		}
		for(i=0;i<m;++i)
			cin >> optional[i].score >> optional[i].credit;
		sort(optional,optional+m,myCmp());
		double sumScore=0;
		int sumCredit=0;
		bool flag=false;
		for(i=0;optional[i].score>=90;++i)
		{
			sumScore+=optional[i].score*optional[i].credit;
			sumCredit+=optional[i].credit;
			if((a+sumScore)/(c+sumCredit)>=90.00)
			{
				flag=true;
				break;
			}
		}
		if(flag)
			cout << i+1 << endl;
		else
			cout << "Impossible" << endl ;
	}
	return 0;
}