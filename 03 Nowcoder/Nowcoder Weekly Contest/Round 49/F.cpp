#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef unsigned long long ULL;
const int N=5e5+10,P=131;
int n,a[N];
ULL p[N], h[N];
ULL find(int l, int r)
{
    return h[r]-h[l-1]*p[r-l+1];
}
void solve()
{
    cin>>n;
    p[0]=1;
    for(int i=0;i<n;i++) 
    {
        cin>>a[i];
        p[i+1]=p[i]*P;
        h[i+1]=h[i]*P+a[i];
    }
    for(int k=1;k<=n;k++) 
    if(find(1,n-2*k)+find(2*k+1,n)==2*find(k+1,n-k)) 
    {
        cout<<k<<"\n";
        return ;
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
