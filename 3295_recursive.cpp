#include <iostream>
#include <string>
using namespace std;
int p,q,r,s,t,index;
string str;
int tautology()
{
	index++;
	switch(str[index])
	{
	case 'p':
		return p;
	case 'q':
		return q;
	case 'r':
		return r;
	case 's':
		return s;
	case 't':
		return t;
	case 'K':
		return tautology()&tautology();
	case 'A':
		return tautology()|tautology();
	case 'N':
		return !tautology();
	case 'C':
		return (!tautology())|tautology();
	case 'E':
		return tautology()==tautology();
	}
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin>>str)
	{
		int res=1;
		if(str=="0")
			break;
		for(p=0;p<2&&(res==1);++p)
		{
			for(q=0;q<2&&(res==1);++q)
			{
				for(r=0;r<2&&(res==1);++r)
				{
					for(s=0;s<2&&(res==1);++s)
					{
						for(t=0;t<2&&(res==1);++t)
						{
							index=-1;
							res=tautology();
						}
					}
				}
			}
		}
		if(res==1)
			cout << "tautology" << endl;
		else
			cout << "not" << endl;
	}
	return 0;
}