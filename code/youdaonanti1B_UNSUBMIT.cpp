#include <iostream>
#include <set>
#include <string>
using namespace std;

class triesnode
{
public:
	int n;
	struct triesnode *str[26];
};

class triesnode *root;
string inputDic;
string findWord;
string output[8];
set<string>mySet;

void myInsert(string c)
{
	triesnode *p=root,*newnode;
	for(int i=0;c[i]!='\0';++i)
	{
		if(p->str[c[i]-'a']!='\0')
		{
			p->n++;
			p=p->str[c[i]-'a'];
		}
		else
		{
			p->n=1;
			newnode = new triesnode;
			for(int i=0;i<26;++i)
				newnode->str[i]='\0';
			p->str[c[i]-'a']=newnode;
			p=newnode;
		}
	}
}

void dfs(triesnode *tmp,int &index,int len)
{
	int oldIndex=index;
	int i;
	for(i=0;i<26;++i)
	{
		if(tmp->str[i]!='\0')
		{
			output[index].push_back(i+'a');
			if(mySet.find(output[index])!=mySet.end()&&tmp->n!=1)
			{
				index++;
				output[index]=output[index-1];
			}
			dfs(tmp->str[i],index,len+1);
			if(index-oldIndex==tmp->n)
				return;
		}
	}
	if(i==26)
	{
		output[index].push_back('\0');
		index++;
	}
}

void myFind()
{
	triesnode *p=root,*parent;
	int i;
	for(i=0;findWord[i]!='\0';++i)
	{
		if(p->str[findWord[i]-'a']!='\0')
		{
			parent=p;
			p=p->str[findWord[i]-'a'];
		}
		else
		{
			cout << findWord << endl;
			return;
		}
	}
	int k=p->n<8?p->n:8;
	for(i=0;i<k;++i)
	{
		output[i]=findWord;
	}
	int index=0;
	triesnode *tempnode=p;
	for(int i=0;i<26;++i)
	{
		if(p->str[i]!='\0')
		{
			tempnode=p;
			dfs(tempnode,index,output[index].size());
		}
	}
	if(parent->n!=1&&p->n==1)
	{
		cout << findWord;
		for(i=0;i<index;++i)
		{
			cout << " " <<  output[i];
		}
	}
	else
	{
		cout << output[0];
		for(i=1;i<index;++i)
		{
			cout << " " << output[i];
		}
	}
	cout << endl;
}

int main()
{
    freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	int numDic,numFind;
	int ccount;
	cin >> numDic;
	ccount=numDic;
	root = new triesnode;
	root->n=0;
	for(int i=0;i<26;++i)
	{
		root->str[i]='\0';
	}
	int index=0;
	while(ccount--)
	{
		cin >> inputDic;
		if(mySet.find(inputDic)==mySet.end())
		{
			mySet.insert(inputDic);
			myInsert(inputDic);
		}
	}
	cin >> numFind;
	while(numFind--)
	{
		cin >> findWord;
		myFind();
	}
	system("pause");
	return 0;
}