#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010],s[200010];
int f(int x)
{
	int res=0;
	while(x) x=x/3,res++;
	return res;
}
void solve()
{
	int l,r;
	cin>>l>>r;
	cout<<s[r]-s[l-1]+a[l]<<"\n";
}
signed main()
{
	for(int i=1;i<=200000;i++) a[i]=f(i),s[i]=s[i-1]+a[i];
//	for(int i=1;i<10;i++) cout<<i<<" "<<a[i]<<"\n";
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

