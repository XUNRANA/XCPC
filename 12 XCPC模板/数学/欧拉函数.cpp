//欧拉函数是小于x的整数中与x互质的数的个数
//p[x]表示x的欧拉函数 

//O(nlogn)
for(int i=1;i<=n;i++) p[i]=i;
for(int i=2;i<=n;i++) 
{
	if(p[i]==i)//i是质数 
	for(int j=i;j<=n;j+=i) p[j]=p[j]*(i-1)/i;//筛i的倍数 
}



//O(n)
vector<int>pr;
void euler(int n)
{
	p[1]=1;
	for(int i=2;i<=n;i++)
	{
		if(!f[i])
		{
			pr.push_back(i);
			p[i]=i-1;
		}
		for(int j=0;j<pr.size()&&pr[j]*i<=n;j++)
		{
			f[pr[j]*i]=1;//筛质数
			if(i%pr[j]==0)
			{
				p[i*pr[j]]=p[i]*pr[j];
				break;
			} 
			else p[i*pr[j]]=p[i]*pr[j];
		}
	}
 } 