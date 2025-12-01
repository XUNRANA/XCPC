#include <bits/stdc++.h>
using namespace std;
#define int long long
#define N 200010
int n,m,a[N],b[N],pa[N],pb[N];
int f[2*N];
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) cin>>b[i];
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	for(int i=1;i<=n/2;i++) pa[i]=a[n-i+1]-a[i];
	for(int i=1;i<=m/2;i++) pb[i]=b[m-i+1]-b[i];
	int k=0;
    for(int i=0;i<=n/2&&i<=m;i++) k=max(k,i+min(n-2*i,(m-i)/2));
    cout<<k<<"\n";
    int i=1,j=1,s=0;
    while(k--)
    {
        if(2*(i-1)+(j-1)==n) s+=pb[j++]-pa[--i];
        else if(2*(j-1)+(i-1)==m) s+=pa[i++]-pb[--j];
        
        if(n-2*(i-1)-(j-1)>=2&&(m-2*(j-1)-(i-1)<2||pa[i]>pb[j])) s+=pa[i++];
        else s+=pb[j++];
        cout<<s<<" ";
    }
    cout<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
