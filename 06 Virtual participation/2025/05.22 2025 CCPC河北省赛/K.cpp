#include <bits/stdc++.h>
using namespace std;
// #define int long long
int a[200010];
void solve()
{
    int n,m;
    cin>>n>>m;
    deque<int>dq;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        dq.push_back(i);
    }   
    string s;
    cin>>s;
    int f=1;
    for(auto i:s)
    {
        if(f)//顺时针
        {
            if(i=='C')
            {
                int j=dq.front();
                dq.pop_front();
                a[j]--;
                if(a[j]) dq.push_back(j);
            }
            else if(i=='S')
            {
                int j=dq.front();
                dq.pop_front();
                a[j]--;
                if(a[j]) dq.push_back(j);

                j=dq.front();
                dq.pop_front();
                if(a[j]) dq.push_back(j);
            }
            else if(i=='R')
            {
                int j=dq.front();
                a[j]--;

                if(a[j]==0) dq.pop_front();
                f^=1;
            }
            else if(i=='D')
            {
                int j=dq.front();
                dq.pop_front();
                a[j]--;
                if(a[j]) dq.push_back(j);

                j=dq.front();
                dq.pop_front();
                a[j]+=2;
                if(a[j]) dq.push_back(j);
            }
        }
        else
        {
            if(i=='C')
            {
                int j=dq.back();
                dq.pop_back();
                a[j]--;
                if(a[j]) dq.push_front(j);
            }
            else if(i=='S')
            {
                int j=dq.back();
                dq.pop_back();
                a[j]--;
                if(a[j]) dq.push_front(j);

                j=dq.back();
                dq.pop_back();
                if(a[j]) dq.push_front(j);
            }
            else if(i=='R')
            {
                int j=dq.back();
                a[j]--;
                f^=1;
                if(a[j]==0) dq.pop_back();
            }
            else if(i=='D')
            {
                int j=dq.back();
                dq.pop_back();
                a[j]--;
                if(a[j]) dq.push_front(j);

                j=dq.back();
                dq.pop_back();
                a[j]+=2;
                if(a[j]) dq.push_front(j);
            }
        }   
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<"\n";
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
