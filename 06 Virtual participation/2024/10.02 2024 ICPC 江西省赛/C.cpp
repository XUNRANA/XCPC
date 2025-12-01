#include <bits/stdc++.h>
using namespace std;
int n,s,s1,a[100010];
void solve()
{
	cin>>n>>s;
	s1=0;
	for(int i=1;i<=n;i++) cin>>a[i],s1+=a[i];
	if(s1==s) cout<<n<<"\n";
	else cout<<n-1<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
