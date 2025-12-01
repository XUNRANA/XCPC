#include <bits/stdc++.h>
using namespace std;
int n,a[2010],b[2010],s[2010],s1[2010][2010];
bool ck(int x)//判断x能否为答案 
{
	for(int i=1;i<=n;i++) s[i]=s[i-1]+(a[i]>x);
	//比x大的看成1，小的看成0， 
	int cnt=0;
	for(int l=1;l<=n;l++)//s1[l,r]==1表示数组a区间[l,r]的中位数大于x 
	{
		for(int r=1;r<l;r++) s1[l][r]=0;
		for(int r=l;r<=n;r++)
		{
			//区间[l,r]的长度为r-l+1
			//区间大于x的个数为s[r]-s[l-1]
			//如果1的个数大于0的个数,s1[l][r]=1表示区间[l,r]的中位数b[l,r]大于x 
			int len=r-l+1;
			s1[l][r]=2*(s[r]-s[l-1])>len;//1的个数大于0的个数 
		}
	}
	
	for(int l=1;l<=n;l++)//计算二维前缀和 
	{
		for(int r=1;r<=n;r++)
		{
			s1[l][r]+=s1[l-1][r]+s1[l][r-1]-s1[l-1][r-1];
		}
	}
	
	int ans=0;
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)//遍历所有区间 
		{
			int len=(r-l+1)*(r-l+1+1)/2;
			//假设遍历[l,r]
			//计算二维区间[l,l]->[r,r]中1的个数，1的如果大于0的个数表示这个区间的C[l,r]大于x 
			ans+=2*(s1[r][r]-s1[r][l-1]-s1[l-1][r]+s1[l-1][l-1])>len;
		}
	}
	 
	return 2*ans>n*(n+1)/2;
}

void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[i]=a[i];
	}
	
	sort(b+1,b+n+1);
	int l=1,r=n;
	while(l<=r)
	{
		int m=l+r>>1;
		if(ck(b[m])) l=m+1;
		else r=m-1;
	}
	cout<<b[l]<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
