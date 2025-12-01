#include <bits/stdc++.h>
using namespace std;
long long n,s,s1,a[500010],b[500010],c[500010];
void solve()
{
	s=s1=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],s1+=a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) b[i]=b[i-1]+a[i];
	

	for(int i=1;i<n;i++) s+=b[i];
	if(s<s1-a[1]) cout<<"YES\n";
	else cout<<"NO\n";
}
int main()
{
	int t;
	cin>>t;
	while(t--) solve();
}
