#include <bits/stdc++.h>
using namespace std;
int n,a[1000010],ans;
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
    ans=0;
    if(a[n]) ans++;
	for(int i=n-1;i>=1;i--) if(a[i]!=a[i+1]&&a[i]) ans++; 
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
