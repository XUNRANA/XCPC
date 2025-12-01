#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,ans[100010];
void solve()
{
    cin>>n>>k;
    int j=1;
    for(int i=1;i<=n;i++) ans[i]=0;
    for(int i=k;i<=n;i+=k)
    {
        ans[i]=j++;
    }
    for(int i=1;i<=n;i++) 
    if(ans[i]) cout<<ans[i]<<" ";
    else cout<<(j++)<<" ";
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

