#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,a,b,s;
    cin>>n>>a>>b;
    cin>>s;
    vector<int>sta(n+1,0),c(n+1,0);
    vector<int>all(n+1,1e9);
    int res=0;
    while(s--)
    {
        int t;
        char p;
        string v;
        cin>>t>>p>>v;
        if(t<240)
        {
            int id=p-'A'+1;
            int st=(v=="ac");
            if(sta[id]) continue;
            else 
            {
                if(st) 
                {
                    res+=c[id]+t;
                    sta[id]=1;
                }
                else c[id]+=20;
            }
        }
        else
        {
            int id=p-'A'+1;
            all[id]=min(all[id],t+c[id]);
        }
    }
    vector<int>aa;
    int cnt=0;
    for(int i=1;i<=n;i++) 
    if(!sta[i]) 
    {
        if(all[i]!=1000000000) aa.push_back(all[i]);
    }
    else cnt++;

    sort(aa.begin(),aa.end());

    // cout<<cnt<<" "<<res<<"\n";
    int ans=0;
    for(auto i:aa) 
    {
        if(cnt>a||(cnt==a&&res<b))
        {
            cout<<ans<<"\n";
            return ;
        }
        res+=i;
        ans++;
        cnt++;
    }
    if(cnt>a||(cnt==a&&res<b))
    {
        cout<<ans<<"\n";
        return ;
    }
    else cout<<"-1\n";
}

int main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}