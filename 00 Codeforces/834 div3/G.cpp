#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[200010];
int b[200010];
int vt[200010];
void solve1()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) vt[i]=0;
    for(int i=1;i<=n/2;i++) 
    {
        cin>>b[i];
        vt[b[i]]=i;
    }
    priority_queue<int>s;
    for(int i=n;i>=1;i--)
    {
        if(vt[i]) s.push(vt[i]);
        else if(s.empty()) 
        {
            cout<<"-1\n";
            return ;
        }
        else 
        {
            a[s.top()]=i;
            s.pop();
        }
    }
    for(int i=1;i<=n/2;i++) cout<<a[i]<<" "<<b[i]<<" ";
    cout<<"\n";
}
void solve()
{
    int n;
    cin>>n;
    set<int>st;
    for(int i=1;i<=n;i++) st.insert(i); 
    int f=0;
    for(int i=1;i<=n/2;i++) 
    {
        int x;
        cin>>x;
        a[i]=x;
        if(st.count(x)) st.erase(x);
        else f=1;
    }
    if(f) 
    {
        cout<<"-1\n";
        return ;
    }
    else
    {
        // 8 7 2 3
        // 1 4 5 6
        for(int i=n/2;i>=1;i--)
        {
            auto it=st.upper_bound(a[i]);
            if(it==st.begin())
            {
                cout<<"-1\n";
                return ;
            }
            else 
            {
                it--;
                b[i]=*it;
                st.erase(it);
            }
        }
        for(int i=1;i<=n/2;i++) cout<<b[i]<<" "<<a[i]<<" ";
        cout<<"\n";
    }
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve1();
    return 0;
}


