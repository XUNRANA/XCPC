#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int long long

int cnt[30];
void solve() 
{
    int n; 
    cin >> n;
    for(int i=0;i<30;i++) cnt[i]=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        cin>>x;
        for(int j=0;j<30;j++) if(x>>j&1) cnt[j]++;
    }
    while(1)
    {
        int f=0;
        for(int i=29;i>=0;i--)
        {
            if(i-1>=0&&cnt[i]>cnt[i-1])
            {
                int d=cnt[i]-cnt[i-1];
                int c=(d+2)/3;
                cnt[i]-=c;
                cnt[i-1]+=2*c;
                f=1;
                break;
            }
        }
        if(!f) break;
    }      
    cout<<cnt[0]<<"\n";
}


int32_t main() 
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}
