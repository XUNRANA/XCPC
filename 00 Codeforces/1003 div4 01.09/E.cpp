#include <bits/stdc++.h>
using namespace std;
#define int long long

string f0(int k)
{
	string res="";
	while(k--) res+='0';
	return res;
}
string f1(int k)
{
	string res="";
	while(k--) res+='1';
	return res;
}

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	if(max(n,m)<k||abs(n-m)>k) cout<<"-1\n";
	else
	{
		string ans="";
		if(n>m)
		{
			while(n||m)
			{
				if(n>=k) ans+=f0(k),n-=k;
				else if(n) ans+=f0(n),n-=n;
				if(m>=k) ans+=f1(k),m-=k;
				else if(m) ans+=f1(m),m-=m;
			}
		}
		else
		{
			while(n||m)
			{
				if(m>=k) ans+=f1(k),m-=k;
				else if(m) ans+=f1(m),m-=m;
				if(n>=k) ans+=f0(k),n-=k;
				else if(n) ans+=f0(n),n-=n;
			}
		}
		cout<<ans<<"\n";
	}

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
