//��Ŀ˵���Ǳ���Ҫ��k�Ρ�
//���n��ż�����ֳ�����������������������������������������ô��Ҫ��������
//           �ֳ�����ż������Ҫ��ż���Ρ����޽�
//���n��������ֻ�ֳܷ�һ��һż����Ȼ��n-1�ξ����ˣ�n-1Ϊż��������ֻ��ż�����ֵģ� 

#include <iostream>
using namespace std;
int n;
int main()
{
	while(scanf("%d",&n)!=EOF&&n)
	{
		if(n&1)
			printf("%d\n",n-1);
		else
			printf("No Solution!\n");
	}
	return 0;
}