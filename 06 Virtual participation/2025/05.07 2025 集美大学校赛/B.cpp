#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,h,a[100010];
bool cmp(int x,int y)
{
    return x>y;
}
void solve() 
{
    cin>>n>>h;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>a[i]>>x;
        a[i]-=x;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(h+a[i]>0) h+=a[i];
        else 
        {
            cout<<i-1<<"\n";
            return ;
        }
    }
    cout<<n<<"\n";
}


signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}