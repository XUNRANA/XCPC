

#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll P=1e9+7;
const ll inv2=5e8+4;
void solve()
{
	int n;
	string s;
	cin>>n>>s;
	ll ans=0;
	for(int i=n-1;i>0;i--) ans=(ans+(s[i]=='1'))*inv2%P;
	cout<<(n-1+ans)%P<<"\n";

}
  

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

