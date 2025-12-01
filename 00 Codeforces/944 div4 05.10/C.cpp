#include <bits/stdc++.h>
using namespace std;
int a,b,c,d;
void solve()
{
	cin>>a>>b>>c>>d;
	if(a>b) swap(a,b);
	if(c>d) swap(c,d);
	if(c<a)
	{
		swap(a,c);
		swap(b,d);
	}
	if(c<=b&&d>=b) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
