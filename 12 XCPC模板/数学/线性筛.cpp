bool f[100000001];
vector<int>p;
void init()//线性筛，时间复杂度O(n) 
{
	for(int i=2;i<=1e8;i++)
	{
		if(!f[i]) p.push_back(i);
		for(int j=0;j<p.size()&&p[j]*i<=1e8;j++)
		{
			f[p[j]*i]=1;
			if(i%p[j]==0) break;
		}
	}
}