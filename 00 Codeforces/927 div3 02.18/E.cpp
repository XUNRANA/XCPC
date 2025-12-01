#include <bits/stdc++.h>
using namespace std;
int n,a[1000010];
string s;
void solve()
{
	cin>>n>>s;
	for(int i=0;i<=n+10;i++) a[i]=0;
	for(int i=0;i<s.size();i++)
	{
		a[1]+=s[i]-'0';
		a[n-i+1]-=s[i]-'0';
	}
	for(int i=1;i<=n+1;i++) a[i]+=a[i-1];	
	for(int i=1;i<=n;i++) a[i+1]+=a[i]/10,a[i]%=10;
	int i=n+1;
	while(a[i]==0) i--;
	while(i>=1) cout<<a[i--];
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
