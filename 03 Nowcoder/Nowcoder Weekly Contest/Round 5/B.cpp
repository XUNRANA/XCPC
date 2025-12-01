#include <bits/stdc++.h>
using namespace std;
int n,k,c,a[100010];
void solve()
{
    cin>>n>>k;
    c=n-k+1;
    for(int i=1,j=1;i<=k;i++,j+=2,c++) a[j]=c;
    c=1;
    for(int i=1;i<=n;i++) if(!a[i]) cout<<c++<<" ";
    else cout<<a[i]<<" ";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
