#include <bits/stdc++.h>
using namespace std;
int c[200010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) c[i]=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        if(x>n) continue;
        c[x]++;
    }
    for(int i=n;i>=1;i--) for(int j=i+i;j<=n;j+=i) c[j]+=c[i];
    int ans=0;
    for(int i=1;i<=n;i++) ans=max(ans,c[i]);
    cout<<ans<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
