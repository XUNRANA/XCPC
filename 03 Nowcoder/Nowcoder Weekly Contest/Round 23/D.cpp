#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define N 1010
#define int long long
int da[10010],db[10010],t,n,p,ans;
string s;
void solve()
{
	cin>>n>>p>>s;
	vector<int>a,b;
	for(int i=0;i<n;i++) 
	{
		cin>>t;
		if(s[i]=='B') a.push_back(t);
		else b.push_back(t);
	}
	
	da[0]=1;
	for(int i=0;i<a.size();i++)
	{
		for(int j=p;j>=a[i];j--) 
		{
			da[j]=(da[j]+da[j-a[i]])%P;
		}
	}
	
	db[0]=1;
	for(int i=0;i<b.size();i++)
	{
		for(int j=p;j>=b[i];j--) 
		{
			db[j]=(db[j]+db[j-b[i]])%P;
		}
	}
	
	for(int i=1;i<p;i++) 
	{
		ans+=da[i]*db[p-i]%P;
		ans%=P;
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

