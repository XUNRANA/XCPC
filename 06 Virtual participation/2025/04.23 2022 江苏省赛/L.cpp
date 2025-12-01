#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() 
{
    int n;
    string s;
    cin>>s;
    n=s.size();
    s=" "+s;
    vector<pair<int,int>>p;
    for(int i=1;i<=n;i++)
    {
        if(s[i]!='B') continue;
        int t=0;
        while(i-t-1>=1&&i+t+1<=n&&s[i-t-1]=='A'&&s[i+t+1]=='C') t++;
        if(t) p.push_back({i&1,t});
    }
    int res=0;
    int cnt=0;//删除了多少个B
    for(auto i:p)
    {
        int odd=i.first;
        int num=i.second;
        if(!cnt)
        {
            if(odd) 
            {
                res++;
                cnt++;//只能删除B
            }
            else 
            {
                if(num==1) res++;//删AC
                else res+=2,cnt++;//删AC 删B
            }
        }
        else 
        {
            //删除的次数取决于之前删了多少个B
            res+=min(num,(odd==0)+cnt+1);
            cnt++;
            //B的次数
        }
    }
    cout<<res<<"\n";
}

signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
    return 0;
}