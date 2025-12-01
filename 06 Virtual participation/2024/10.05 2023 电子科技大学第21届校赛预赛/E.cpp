#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k;
int a[100010],b[100010];
map<int,int>mp;
/*
 5 4
 1 6
 2 1
 1 9
 2 2
 2 10
*/
void work(int a,int b)
{
	if(b>k)
	{
		if(b%k==0)
		{
			mp[a]+=(b/k-1)*(2*k)+k;
		}
		else
		{
			mp[a]+=b/k*(2*k)+b%k;
		}
	}
	else mp[a]+=b;
	
}
void solve()
{
	cin>>n>>k;
	int a,b,a1,b1;
	cin>>a>>b;
	for(int i=1;i<n;i++) 
	{
		cin>>a1>>b1;
		if(a1!=a)
		{
			work(a,b);
			a=a1;
			b=b1;
		}
		else b+=b1;
	}
	work(a,b);
	cout<<mp.size()<<"\n";
	for(auto i:mp) cout<<i.first<<" "<<i.second<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
/*
6
2 0 5 9 22 30
*/
