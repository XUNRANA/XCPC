#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define int long long
const ull P=10000000000000000+1029;
void solve()
{
	int n,q;
	cin>>n>>q;
	vector<ull>a(n),p(64);
	for(auto &i:a) cin>>i;
	for(auto &i:p) i=-1;//每一位都是1111111111111111111111111111111111111111111111111111111111111111
	for(auto &i:a)
	{
		for(int j=0;j<64;j++)
		if(i>>j&1) p[j]=p[j]&i;//包含这一位的最小值
	}
	ull ans=0;
	for(int i=1;i<=q;i++)
	{
		ull x;
		cin>>x;
		ull tmp=-1;//二进制全是1
		ull cur=0;
		for(int j=63;j>=0;j--)
		{
			if(x>>j&1) cur|=p[j];//必须包含这一位
			else tmp=min(tmp,cur|p[j]);//可以包含或不包含
		}
		tmp=min(tmp,cur);//取最小
		ans=ans^(tmp%P);
	}
	cout<<ans<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

