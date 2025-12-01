#include <bits/stdc++.h>
using namespace std;
#define P 1000000007
#define int long long
int n,a[100010],b[100010],sa=1,sb=1;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) 
    {
        cin>>b[i];
        if(b[i]>a[i]) swap(a[i],b[i]);
    }

    for(int i=2;i<=n;i++) a[i]=a[i]*a[i-1]%P;
    for(int i=2;i<=n;i++) b[i]=b[i]*b[i-1]%P;
    cout<<(a[n]+b[n])%P<<"\n";
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

