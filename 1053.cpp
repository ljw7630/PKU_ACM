#include <iostream>
#include <string>
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	string s[100];
	int i,j,k,l,n,flag,num;
	n=0;
	do{
		getline(cin,s[n++]);
		if(s[n-1].size()<2)
		{
			n--;
			printf("CARDS: ");
			for(i=0;i<n;i++)
				cout << " " << s[i];
			printf("\nSETS:   ");
			for(i=0,num=0;i<n;i++)
			{
				for(j=i+1;j<n;j++)
				{
					for(k=j+1;k<n;k++)
					{
						for(l=0,flag=0;l<4;l++)
						{
							if((s[i][l]==s[j][l]&&s[j][l]==s[k][l])
								||(s[i][l]!=s[j][l]&&s[j][l]!=s[k][l]&&s[i][l]!=s[k][l]))
								flag++;
						}
						if(flag==4)
						{
							if(num==0)
							{
								cout << ++num << ".  " << s[i] << " " << s[j] << " " << s[k] << endl;
							}
							else
							{
								cout << "        " << ++num << ".  " << s[i] << " " << s[j] << " " << s[k] << endl;
							}
						}
					}
				}
			}
			if(num==0)
				printf("*** None Found ***\n");
			printf("\n");
			n=0;
		}
	}while(cin);
	return 0;
}