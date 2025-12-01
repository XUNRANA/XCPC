#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 998244353
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
int inv(int x)
{
    return ksm(x,P-2);
}
void solve() 
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        if(i==1) cout<<"1 ";
        else if(i==m) cout<<"0 ";
        else
        {
            int res=(m-i)*inv(m-1)%P;
            cout<<ksm(res,n)<<" ";
        }
    }
    cout<<"\n";
    // cout<<ksm(1,3)*inv(ksm(4,3))%P<<"\n";
    // cout<<ksm(2,3)*inv(ksm(4,3))%P<<"\n";
    // cout<<ksm(3,3)*inv(ksm(4,3))%P<<"\n";
}

int32_t main() {
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}