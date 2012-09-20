#include <iostream>
#include <map>
#include <queue>
#include <string>
using namespace std;

class NODE
{
public:
	int value;
	int weight;
	NODE *left;
	NODE *parent;
	NODE *right;
	NODE(int v,int w,NODE *p=NULL,NODE *l=NULL,NODE *r=NULL)
	{
		value=v;
		weight=w;
		parent=p;
		left=l;
		right=r;
	}
	int traversal(int height)
	{
		int sum=0;
		if(value!=-1)
			sum+=weight*height;
		if(left!=NULL)
			sum+=left->traversal(height+1);
		if(right!=NULL)
			sum+=right->traversal(height+1);
		return sum;
	}
};

class compare
{
public:
	bool operator()(NODE *lhs,NODE *rhs) const
	{
		return lhs->weight>rhs->weight;
	}
};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	map<char,int>themap;
	priority_queue<NODE *,vector<NODE *>,compare>thequeue;
	bool ch[300];
	string str;
	while(cin>>str&&str!="END")
	{
		memset(ch,0,sizeof(ch));
		for(int i=0;i<str.size();++i)
		{
			themap[str[i]]++;
			ch[str[i]-'A']=true;
		}
		for(int i=0;i<str.size();++i)
		{
			if(ch[str[i]-'A']==true)
			{
				NODE *newnode=new NODE(str[i],themap[str[i]]);
				thequeue.push(newnode);
				ch[str[i]-'A']=false;
			}
		}
		if(thequeue.size()==1)
		{
			printf("%d %d %.1lf\n",str.size()*8,str.size(),(double)str.size()*8/str.size());
			thequeue.pop();
		}
		else
		{
			while(thequeue.size()>1)
			{
				NODE *n1=thequeue.top(); thequeue.pop();
				NODE *n2=thequeue.top();thequeue.pop();
				NODE *res=new NODE(-1,n1->weight+n2->weight,NULL,n1,n2);
				n1->parent=n2->parent=res;
				thequeue.push(res);
			}
			NODE *root=thequeue.top(); thequeue.pop();
			int ans=root->traversal(0);
			printf("%d %d %.1lf\n",str.size()*8,ans,(double)str.size()*8/ans);
		}
		themap.clear();
	}
	return 0;
}