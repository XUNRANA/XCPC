#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int l,n;
	cin>>l>>n;
	int s=1;
	for(int i=1;i<=l;i++) s=s*26;
	s-=n;
	string ans="";
	for(int i=1;i<=l;i++)
	{
		ans=char(s%26+'a')+ans;
		s/=26;
	}
	cout<<ans<<"\n";
	
} 
 
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

