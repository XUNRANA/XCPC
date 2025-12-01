#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	string s;
	cin>>s;
	int n;
	cin>>n;
	while(n--)
	{
		int a,b;
		string c,d;
		cin>>a>>b>>c>>d;
		string t=s.substr(a-1,b-a+1);
		s=s.substr(0,a-1)+s.substr(b);
		if(s.find(c+d)!=s.npos)
		{
			int p=s.find(c+d);
			s=s.substr(0,p+c.size())+t+s.substr(p+c.size());
		}
		else s+=t;
	}
	cout<<s<<"\n";
	
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

