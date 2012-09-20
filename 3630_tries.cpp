// TLE faint

//#include <iostream>
//#include <algorithm>
//#include <string>
//using namespace std;
//
//struct triesnode
//{
//	int n;
//	bool haveson;
//	struct triesnode *num[10];
//};
//
//struct triesnode *root;
//bool flag;
//string str[10002];
//
//
//void insert(string s)
//{
//	struct triesnode *p=root,* newnode;
//	for(int i=0;s[i]!='\0';++i)
//	{
//		if(p->num[s[i]-'0']!=NULL)
//		{
//			p=p->num[s[i]-'0'];
//			p->n++;
//		}
//		else
//		{
//			if(p->haveson==true)
//			{
//				newnode = new triesnode;
//				for(int j=0;j<10;++j)
//					newnode->num[j]=NULL;
//				p->num[s[i]-'0']=newnode;
//				p=newnode;
//				if(s[i+1]!='\0')	
//					p->haveson=true;
//				else
//					p->haveson=false;
//				p->n=1;
//			}
//			else
//			{
//				flag=false;
//				return;
//			}
//		}
//	}
//}
//
//int main()
//{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
//	int t,n;
//	scanf("%d",&t);
//	while(t--)
//	{
//		root = new triesnode;
//		root->n=0;
//		root->haveson=true;
//		scanf("%d",&n);
//		for(int i=0;i<10;++i)
//			root->num[i]=NULL;
//		flag=true;
//		for(int i=0;i<n;++i)
//		{
//			cin >> str[i];
//		}
//		sort(str,str+n);
//		for(int i=0;i<n;++i)
//		{
//			insert(str[i]);
//			if(!flag)
//				break;
//		}
//		if(flag)
//			printf("YES\n");
//		else
//			printf("NO\n");
//		delete root;
//	}
//	return 0;
//}


#include <iostream>
using namespace std;

bool flag;
int nodenum;

struct triesnode
{
	bool isExist;
	triesnode *branch[10];
}node[100005];

class Tries
{
private:
	triesnode root;
public:
	Tries()
	{
		root=node[0];
	}
	void insert(char s[])
	{
		triesnode *p=&root;
		int i=0;
		int len=strlen(s);
		while(s[i])
		{
			if(i==len-1&&p->branch[s[i]-'0']!=NULL)
			{
				flag=false;
				return;
			}
			if(p->branch[s[i]-'0']==NULL)
			{
				p->branch[s[i]-'0']=&node[nodenum];
				node[nodenum].isExist=false;
				for(int j=0;j<10;++j)
				{
					node[nodenum].branch[j]=NULL;
				}
				nodenum++;
			}
			if(p->branch[s[i]-'0']->isExist==true)
			{
				flag=false;
				return;
			}
			p=p->branch[s[i]-'0'];
			i++;
		}
		p->isExist=true;
		return;
	}
};

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t,n;
	char str[11];
	scanf("%d",&t);
	while(t--)
	{
		nodenum=1;
		Tries t;
		flag=true;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			scanf("%s",&str);
			if(flag)
				t.insert(str);
		}
		if(flag)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}