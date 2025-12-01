#include <bits/stdc++.h>
using namespace std;
#define int long long


int a[200010];
int b[200010];
void solve() 
{
    int n;
    cin>>n;
    multiset<int>sx,sy;
    for(int i=1;i<=n;i++) 
    {
        int x,y;
        cin>>x>>y;
        a[i]=x;
        b[i]=y;
        sx.insert(x);
        sy.insert(y);
    }

    if(n<=2)
    {
        cout<<n<<"\n";
        return ;
    }

    int ans=1e18;
    for(int i=1;i<=n;i++) 
    {
        int x=a[i];
        int y=b[i];
        sx.erase(sx.find(x));
        sy.erase(sy.find(y));

        int l1=(*sx.rbegin())-(*sx.begin())+1;
        int l2=(*sy.rbegin())-(*sy.begin())+1;
        int s=l1*l2;

        if(s>=n) ans=min(ans,s);
        else ans=min({ans,(l1+1)*l2,(l2+1)*l1});


        sx.insert(x);
        sy.insert(y);
    }
    cout<<ans<<"\n";
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--)
    solve();
}