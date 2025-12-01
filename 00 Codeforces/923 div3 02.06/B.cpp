#include <bits/stdc++.h>
using namespace std;
int a[200010];
void solve()
{
	int n,t1;
	cin>>n;
	for(int i=0;i<=n;i++) a[i]=0;
	while(n--)
	{
		cin>>t1;
		cout<<char('a'+a[t1]++);
	}
	cout<<"\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t;
    cin>>t;
    while(t--) solve();
}
