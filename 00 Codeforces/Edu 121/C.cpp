#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k[110],h[110],f[110];
int cal(int f,int s,int l)
{
    return (f+s)*l/2;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>k[i];
    for(int i=1;i<=n;i++) cin>>h[i];
    f[n]=h[n];//至少需要的法术值
    for(int i=n-1;i>=1;i--) f[i]=max(h[i],f[i+1]-(k[i+1]-k[i]));
    int ans=cal(1,f[1],f[1]);
    int p=f[1];
    for(int i=1;i<=n-1;i++)
    {
        int kk=k[i+1]-k[i];
        if(f[i+1]<=kk) 
        {
            ans+=cal(1,f[i+1],f[i+1]);
            p=f[i+1];
        }
        else 
        {
            ans+=cal(p+1,p+kk,kk);
            p+=kk;
        }
    }
    cout<<ans<<"\n";
} 

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}