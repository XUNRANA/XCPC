#include <bits/stdc++.h>
using namespace std;//质数的筛选 
void prime(int n) //Eratosthenes
{
	vector<int>v(n); 
	for(int i=2;i<=n;i++)
	{
		if(v[i]==1) continue;
		cout<<i<<endl;
		for(int j=i;j<=n/i;j++) v[i*j]=1;
	}
}
#define MAX_N 100000000
int v[MAX_N];
int primenum[MAX_N];
void primes(int n)
{
	memset(v,0,sizeof(v));
	int m=0;//质数数量
	for(int i=2;i<=n;i++)
	{
		if(v[i]==0)
		{
			v[i]=i;//代表是质数 
			primenum[m++]=i;
		}
		for(int j=0;j<m;j++)
		{
			//i有比primenum[j]更小的质因子 或超出n的范围 停止循环 
			if(primenum[j]>v[i]||primenum[j]>n/i) break;
			//primenum[j]是primenum[j]*i的最小质因子 
			v[i*primenum[j]]=primenum[j];
		}
	}
	for(int i=0;i<m;i++) cout<<primenum[i]<<endl; 
	cout<<m<<endl;
}
int main()
{
	int n;
	cin>>n;
	primes(n);
}
