#include <bits/stdc++.h>
using namespace std;
int ans[1000010];
void solve()
{
	int n,k;
	cin>>n>>k;
	if(2*k>n) 
	{
		cout<<"NO\n";
		return ;
	}
	cout<<"YES\n";
	int j=1;
	for(int i=2;i<=n;i+=2) ans[i]=j++;
	for(int i=1;i<=n;i+=2) ans[i]=j++;
	for(int i=1;i<=n;i++) cout<<ans[i]<<" ";
	cout<<"\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
