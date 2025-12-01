#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

int is(int x,int a)
{
    string ans="";
    while(x)
    {
        ans=char('0'+x%a)+ans;
        x/=a;
    }
    // 11
    // 22
    string r=ans;
    reverse(r.begin(),r.end());
    return r==ans;
}

// 1 000000 000000
int ck(int x)
{
    string r=to_string(x);
    string rt=r;
    reverse(rt.begin(),rt.end());
    return rt==r;
}

void solve()
{
    int a,n;
    cin>>a>>n;
    int ans=0;
    //<10
    for(int i=1;i<=min(n,9ull);i++) 
    if(ck(i)&&is(i,a)) 
    {
        // cout<<i<<"!!\n";
        ans+=i;
    }
    // 1
    // 11
    // 101
    // 111
    // 1001

    //>10
    for(int i=1;i<=1e6;i++) 
    {
        string s=to_string(i);
        
        string rs=s;
        reverse(rs.begin(),rs.end());
        
        string t=s+rs;

        if(stoll(t)<=n&&ck(stoll(t))&&is(stoll(t),a)) 
        {
            // cout<<t<<"!\n";
            ans+=stoll(t);
        }
        if(s.size()>1)
        {
            rs=s.substr(0,s.size()-1);
            reverse(rs.begin(),rs.end());
            t=s+rs;
            if(stoll(t)<=n&&ck(stoll(t))&&is(stoll(t),a)) 
            {
                // cout<<t<<"?\n";
                ans+=stoll(t);
            }
        }
    }
    cout<<ans<<"\n";
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve();
}