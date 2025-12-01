#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 988444333
int n;
string s,t;

bool ck(string s,string t)
{
	int res=0;
	for(int i=0;i<s.size();i++) if(s[i]==t[i]) res++;
	return res>=(s.size()+1)/2;
}

void solve()
{
	cin>>n;
	cin>>t;
	
	int ans=0;
	while(n--)
	{
		cin>>s;
		if(ck(s,t)) ans++;
	}
	if(ans) 
	{
		cout<<ans<<"\n";
		cout<<"Make persistent efforts.\n";
	}
	else
	{
		cout<<"0\n";
		cout<<"Good job!\n";
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
