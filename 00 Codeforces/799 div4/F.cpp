#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,x;
int cnt[10];
void solve() 
{
    cin>>n;
    for(int i=0;i<10;i++) cnt[i]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        cnt[x%10]++;
    }
    vector<int>a;
    for(int i=0;i<10;i++) 
    {
        int t=min(3ll,cnt[i]);
        while(t--) a.push_back(i);
    }
    for(int i=0;i<a.size();i++)
    {
        for(int j=i+1;j<a.size();j++)
        {
            for(int k=j+1;k<a.size();k++)
            {
                if((a[i]+a[j]+a[k])%10==3)
                {
                    cout<<"YES\n";
                    return ;
                }
            }
        }
    }
    cout<<"NO\n";
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