#include <iostream>
#include <string>
using namespace std;

string post;
int n;

void cal(string &a,string &b)
{
	string t1,t2;
	if(b.length()==1)
		post+=b;
	else
	{
		int k=a.find(b.substr(0,1));
		if(k>0)
		{
			t1=a.substr(0,k);
			t2=b.substr(1,k);
			cal(t1,t2);
		}
		if(k<a.length()-1)
		{
			t1=a.substr(k+1,a.length()-k-1);
			t2=b.substr(k+1,b.length()-k-1);
			cal(t1,t2);
		}
		post+=a[k];
	}
}

int main()
{
	string pre,in;
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	while(cin >> pre >> in)
	{
		post.clear();
		cal(in,pre);
		cout << post << endl;
	}
	return 0;
}