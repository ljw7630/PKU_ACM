1000 A+B Problem // ���ż�
    while(scanf("%d%d",&a,&b)!=EOF)
		printf("%d\n",a+b);
		
1002 487-3279 // ���� �ַ�������
	ûʲô��˵�ģ�����һ���ַ�����ת����Ҫ��ĸ�ʽ����һ����ά�Ĵ��ַ�����洢����
	//���� 
	qsort((void *)result, n,sizeof(result[0]),cmp);
	int cmp(const void *a,const void *b)
	{
		return ( strcmp((char*)a,(char*)b) );
	}
	
1003 Hangover // ˮ��
	ˮ��һ��
	for(i=2,sum=0;sum<len;i++)
		sum+=(1/i);
		
1004 Financial Management // ˮ��
	ˮ��һ��������ƽ��
	while(scanf("%lf",&perMon)!=EOF)
	{
		if(count==11)
		{
			count=0;
			printf("$%.2lf",(sum+perMon)/12);
			sum=0;
		}
		else
		{
			count++;
			sum+=perMon;
		}
	}
	
1005 I Think I Need a Houseboat // ��ѧˮ��
	ͦƯ���Ľⷨ
	����뾶��ƽ����Ȼ�����������뾶�ڵ��������100�ı�������ȥ��
	ceil(pi*x^2*y^2/100)
	
1006 Biorhythms // ���� �й���������
	discuss����˵���й�����������������һ�£�����
	scanf("%d%d%d%d",&p,&e,&i,&d);
	if(p==-1&&e==-1&&i==-1&&d==-1)
		break;
	count++;
	p%=23;
	e%=28;
	i%=33;
	c=(5544*p+14421*e+1288*i)%21252;

	if(c<=d)  // ����û�������������
		c+=(21252-d);
	else
		c-=d;
		
1007 DNA Sorting // �������,����,����
	������ԣ��뷨�ܼ򵥣�������д��

1008 Maya Calendar // ��ѧ����,ģ����
	����������ת��
	daysum=atoi(getday);
	daysum+=findmon*20;
	daysum+=getyear*365;
	printf("%d %s %d\n",daysum%13+1,tzolkin[daysum%20],daysum/260);
	
1012 Joseph  // �������
	// k������k�����ˣ�������һ������֮ǰ�ж��ٸ����˱�����
	for(i=0,j=0,changeLen=len;i<k;i++)
	{
		j=(j+n-1)%changeLen;  // ע��ϸ��
		if(people[j]<k)    // �÷���
			return true;
		for(t=j;t<changeLen-1;t++)
			people[t]=people[t+1];
		changeLen--;
	}
	
1013 Counterfeit Dollar // �õ��뷨
	// �ҼٱҲ�ָ������Ļ����ص�
	// ��ʼ��Ӳ��Ϊ0
	// �Ѿ�ƽ����һ���Ƚϴ��ֵ��ǲ�����Ѱ��
	// ���������ҳ�����ֵ��������Ӳ�Ҽ�Ϊ����
	
1014 Dividing // dp
	// ����dp[i]Ϊ��ֵi�Ŀɴ���
	// ������������sum����1�����Ϊ0��������,�˳�
	// ����,sum=sum/2,dp[0]=1
	for(i=0;i<6;i++)
	{
		for(j=sum;j>-1;j--)
		{
			if(dp[j]==0)
			{
				continue;
			}
			if(dp[j+i+1]==1) // ��֦ �����ظ���չ
			{				
				continue;
			}
			pos=j;
			for(k=0;k<num[i];k++)
			{
				pos+=(i+1);
				if(pos>sum)
					break;
				dp[pos]=1;
			}
		}
	}