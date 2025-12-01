#include <bits/stdc++.h>
using namespace std;
long long n,a[1010],ans;
string s;
void solve()
{
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>s;
	for(int i=0;i<n;i++) if(s[i]=='F') ans+=max(5ll,a[i]/100);
	else ans+=a[i];
	cout<<ans<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

