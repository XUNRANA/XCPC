#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,m;
	cin>>n>>m;
	string s;
	for(int i=1;i<=n;i++)
	{
		if(m>=9) s+='9',m-=9;
		else if(m) s+='0'+m,m-=m;
		else s+='0';
	}
	cout<<s<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
} 
