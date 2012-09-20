#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char>value;
stack<char>sign;

char conjunction(char t1,char t2)
{
	if(t1=='V'||t2=='V')
		return 'V';
	else
		return 'F';
}

char ampersand(char t1,char t2)
{
	if(t1=='V'&&t2=='V')
		return 'V';
	else
		return 'F';
}

char reverse(char t)
{
	if(t=='V')
		return 'F';
	else
		return 'V';
}

char cal()
{
	char s=sign.top();sign.pop();
	char t,t1,t2;
	switch(s)
	{
	case '!':
		t1=value.top();
		value.pop();
		t=reverse(t1);
		break;
	case '&':
		t1=value.top();value.pop();
		t2=value.top();value.pop();
		t=ampersand(t1,t2);
		break;
	case '|':
		t1=value.top();value.pop();
		t2=value.top();value.pop();
		t=conjunction(t1,t2);
		break;
	}
	return t;
}

bool eval(char str[])
{
	for(int i=0;str[i];++i)
	{
		if(str[i]==' ')
			continue;
		else if(str[i]=='V'||str[i]=='F')
		{
			value.push(str[i]);
		}
		else if(str[i]=='('||str[i]=='!')
			sign.push(str[i]);
		else if(str[i]=='&')
		{
			while(!sign.empty()&&sign.top()=='!')
			{
				sign.pop();
				char t1=value.top();
				value.pop();
				char t=reverse(t1);
				value.push(t);
			}
			sign.push(str[i]);
		}
		else if(str[i]=='|')
		{
			char k;
			while(!sign.empty()&&((k=sign.top())=='&'||k=='!'))
			{
				sign.pop();
				if(k=='&')
				{
					char t1=value.top();value.pop();
					char t2=value.top();value.pop();
					char t3=ampersand(t1,t2);
					value.push(t3);
				}
				else
				{
					char t1=value.top();
					value.pop();
					char t=reverse(t1);
					value.push(t);					
				}
			}
			sign.push(str[i]);
		}
		else if(str[i]==')')
		{
			while(!sign.empty()&&sign.top()!='(')
			{
				char t=cal();
				value.push(t);
			}
			sign.pop();
		}
	}
	while(!sign.empty())
	{
		char t=cal();
		value.push(t);
	}
	return value.top()=='V'?true:false;
}

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char str[202];
	int c=0;
	while(gets(str)!=NULL)
	{
		while(!value.empty())
			value.pop();
		while(!sign.empty())
			sign.pop();
		bool res=eval(str);
		printf("Expression %d: ",++c);
		printf("%c\n",res==true?'V':'F');
	}
	return 0;
}