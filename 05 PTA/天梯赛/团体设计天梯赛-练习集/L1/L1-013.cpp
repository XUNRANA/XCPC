#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n;
	cin>>n;
	int s=0;
	int f=1;
	for(int i=1;i<=n;i++) f*=i,s+=f;
	cout<<s<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

