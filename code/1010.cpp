#include <iostream>
using namespace std;
int stamp[100],use[100],best[5];
int t,total,bestmax,bestnum,maxvalue,type;
bool tie;

bool compare()
{
	int counttype=0,findmax=0,findnum=0;
	for(int i=1;i<=stamp[0];++i)
	{
		if(use[i]!=0)
		{
			counttype++,findnum+=use[i];
			if(stamp[i]>findmax)
				findmax=stamp[i];
		}
	}
	if(counttype>type)
	{
		type=counttype;
		bestmax=findmax;
		bestnum=findnum;
		tie=false;
		return true;
	}
	else if(counttype==type)
	{
		if(findnum<bestnum)
		{
			bestmax=findmax;
			bestnum=findnum;
			tie=false;
			return true;
		}
		else if(findnum==bestnum)
		{
			if(findmax>bestmax)
			{
				bestmax=findmax;
				tie=false;
				return true;
			}
			else if(findmax==bestmax)
			{
				tie=true;
				return false;
			}
		}
	}
	return false;
}

void copyresult()
{
	for(int i=0;i<5;++i)
		best[i]=0;
	int k=0;
	for(int i=1;i<=stamp[0];++i)
	{
		if(use[i]!=0)
		{
			for(int j=0;j<use[i];++j)
				best[k++]=stamp[i];
		}
	}
}

void search(int money,int now)
{
	for(int i=now;i<=stamp[0];++i)
	{
		if(money-stamp[i]>0&&total<4)
		{
			total++;
			money-=stamp[i];
			use[i]++;
			search(money,i);
			use[i]--;
			money+=stamp[i];
			total--;
		}
		else if(money-stamp[i]==0&&total<4) // 钱用光,比较最优值
		{
			use[i]++,total++;
			if(compare())
			{
				copyresult();
			}
			use[i]--,total--;
		}
	}
}

void out()
{
	cout << " (" << type << "):";
	int k=0;
	while(best[k]!=0)
		k++;
	if(tie)
		cout << " tie";
	else
		for(int i=0;i<k;++i)
			cout << " " << best[i];
	cout << endl;
}

bool prune()
{
	if(t<=4*maxvalue)
		return true;
	else
	{
		cout << " ---- none" << endl;
		return false;
	}
}

void initialize()
{
	maxvalue=0;
	for(int i=1;i<=stamp[0];++i)
	{
		use[i]=0;
		if(maxvalue<stamp[i])
			maxvalue=stamp[i];
	}
	total=0,tie=false,bestmax=0,bestnum=0,type=0;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin >> t)
	{
		memset(stamp,0,sizeof(stamp));
		stamp[0]=0,stamp[1]=t;
		while(t!=0)
		{
			stamp[0]++;
			stamp[stamp[0]]=t;
			cin >> t;
		}
		cin >> t;
		while(t!=0)
		{
			cout << t;
			initialize();
			if(prune())
			{
				search(t,1);
				if(type!=0)
					out();
				else
					cout << " ---- none" << endl;
			}
			cin >> t;
		}
	}
	return 0;
}