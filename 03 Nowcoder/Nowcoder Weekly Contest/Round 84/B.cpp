#include <bits/stdc++.h>
using namespace std;
int n,a[110];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	if(a[1]!=a[n]) cout<<2<<" "<<a[n]-a[1]<<"\n";
	else cout<<"1 0\n";
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve(); 
}

