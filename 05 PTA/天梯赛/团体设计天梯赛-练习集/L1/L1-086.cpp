#include <bits/stdc++.h>
using namespace std;
#define int long long
string f(string a)
{
	string s;
	for(int i=1;i<a.size();i++)
	{
		if(a[i]%2==a[i-1]%2)
		{
			s+=max(a[i],a[i-1]);
		}
	}
	return s;
}
void solve()
{
	string a,b;
	cin>>a>>b;
	string ra=f(a);
	string rb=f(b);
	if(ra==rb) cout<<ra<<"\n";
	else
	{
		cout<<ra<<"\n"<<rb<<"\n";
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

