#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100010],p[100010];
string s;
int d[100010];
int vt[100010];
void solve() 
{
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    p[n-1]=1;
    for(int i=n-2;i>=0;i--) p[i]=p[i+1]*a[i+1];    
    cin>>s;
    priority_queue<array<int,2>,vector<array<int,2>>,greater<array<int,2>>>q;
    if(s[0]=='1'||s.back()=='1')
    {
        cout<<"-1\n";
        return ;
    }
    for(int i=0;i<s.size();i++) d[i]=1e9,vt[i]=0;
    q.push({0,0});
    d[0]=0;
    while(!q.empty())
    {
        int u=q.top()[1];
        q.pop();
        if(vt[u]) continue;
        vt[u]=1;
        int tu=u;
        for(int i=n-1;i>=0;i--)
        {
            int val=u%a[i];
            if(val)
            {

                if(s[tu-p[i]]!='1'&&d[tu-p[i]]>d[tu]+1)
                {
                    d[tu-p[i]]=d[tu]+1;
                    q.push({d[tu-p[i]],tu-p[i]});
                }
            }
            if(val<a[i]-1)
            {
                if(s[tu+p[i]]!='1'&&d[tu+p[i]]>d[tu]+1)
                {
                    d[tu+p[i]]=d[tu]+1;
                    q.push({d[tu+p[i]],tu+p[i]});
                }
            }
            u/=a[i];
        }
    }
    if(d[s.size()-1]==1e9) d[s.size()-1]=-1;
    cout<<d[s.size()-1]<<"\n";
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