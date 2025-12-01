#include <bits/stdc++.h>
using namespace std;
int n,m,x,k,a[1000010],s[1000010];
void solve()
{
	cin>>k;
	for(int i=0;i<k;i++) cin>>a[i];
	for(int i=k;i<=100;i++) a[i]=a[i-k];
	cin>>n>>m>>x;
	s[0]=a[0]%m;
	for(int i=1;i<=100;i++) s[i]=(s[i-1]+a[i])%m;
	for(int i=0;i<=100;i++) cout<<a[i]<<" ";
	cout<<"\n";
	
	cout<<x<<" ";
	for(int i=0;i<=100;i++) cout<<(s[i]+x)%m<<" ";
	cout<<"\n";

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
