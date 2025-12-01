#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,a[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    if(n==1)
    {
        cout<<"0\n";
        return ;
    }

    int x1=a[1];
    int x2=a[n];
    vector<int>ans;
    while(x1!=x2)
    {
        if((x1&1)&&!(x2&1)) 
        {
            x1=(x1+1)/2;
            x2=(x2+1)/2;
            ans.push_back(1);
        }
        else
        {
            x1/=2;
            x2/=2;
            ans.push_back(0);
        }
    }
    
    cout<<ans.size()<<"\n";
    if(ans.size()<=n)
    {
        for(auto i:ans) cout<<i<<" ";
        cout<<"\n";
    }
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
    return 0;
}