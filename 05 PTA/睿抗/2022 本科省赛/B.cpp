#include <bits/stdc++.h>
using namespace std;

int l[1010];
int last[1010];
void solve()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>l[i],last[i]=-1;
    while(m--)
    {
        int t,k,x;
        cin>>t;
        cin>>k;
        while(k--)
        {
            cin>>x;
            if(l[x]==-1) continue;

            if(last[x]==-1) last[x]=t;
            else
            {
                if(t-last[x]<l[x]) cout<<"Don't take "<<x<<" at "<<t<<"!\n";
                else last[x]=t;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}
