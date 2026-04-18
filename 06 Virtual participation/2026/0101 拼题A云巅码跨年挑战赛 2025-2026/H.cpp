#include <bits/stdc++.h>
using namespace std;
int c[100010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    stack<int>a;
    stack<int>b;

    int mx=0,j=0;
    for(int i=1;i<=n;i++)
    {
        int x;
        x=c[i];
        while(!a.empty()&&x>a.top()) a.pop();
        a.push(x);
        if(a.size()>mx) 
        {
            mx=a.size();
            j=i;
        }
    }
  
    for(int i=1;i<=j;i++)
    {
        int x;
        x=c[i];
        while(!b.empty()&&x>b.top()) b.pop();
        b.push(x);
    }

    int f=0;
    cout<<b.size()<<"\n";
    while(!b.empty())
    {
        if(f) cout<<" "; 
        cout<<b.top();
        b.pop();
        f=1;
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