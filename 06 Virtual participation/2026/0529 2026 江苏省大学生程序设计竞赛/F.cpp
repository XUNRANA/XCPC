#include <bits/stdc++.h>
using namespace std;

int n;
int mp[100010];
void solve()
{
    cin>>n;
    int mx=0;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        mx=max(mx,x);
        if(x<=n) mp[x]++;
    }    

    if(!mp[0])
    {
        cout<<"1\n";
        return ;
    }

    for(int x=0;x<=n;x++) 
    if(!mp[x])//[0,,x-1]
    {
        if(mx!=x-1)
        {
            cout<<x+1<<"\n";
            return ;
        }

        int ans=1;
        while(1)
        {
            int f=0;
            for(int i=0;i<x;i++)
            {
                if(mp[i])
                {
                    mp[i]--;
                    ans++;
                }
                else 
                {
                    f=1;
                    break;
                }
            }
            if(f) break;
        }
        cout<<ans<<"\n";
        return ;
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