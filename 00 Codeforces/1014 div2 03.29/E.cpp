#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int ksm(int a,int b)
{
    int res=1;
    while(b)
    {
        if(b&1) res=res*a%P;
        a=a*a%P;
        b>>=1;
    }
    return res;
}
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int cnt=0;//涂了的个数
    int ans=0;//涂黑的个数
    for(int i=1;i<=k;i++)
    {
        int x,y,c;
        cin>>x>>y>>c;
        if(x==1||x==n||y==1||y==m)
        {
            if(x==1&&y==1) continue;
            if(x==1&&y==m) continue;
            if(x==n&&y==1) continue;
            if(x==n&&y==m) continue;
            cnt++;
            ans+=c;
        }
    }
    if(cnt==(n-2+m-2)*2)
    {
        if(ans%2==0) cout<<ksm(2,n*m-k)<<"\n";
        else cout<<"0\n";
    }
    else cout<<ksm(2,n*m-k-1)<<"\n";
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
