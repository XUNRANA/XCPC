#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];
int b[200010];
void solve() 
{
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        while(a[i]%2==0) a[i]/=2;
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        while(b[i]%2==0) b[i]/=2;
    }
    sort(b+1,b+1+n);
    priority_queue<int>q;
    for(int i=1;i<=n;i++) q.push(b[i]);
    int j=n;
    while(!q.empty())
    {
        int x=q.top();
        q.pop();
        if(x==a[j])
        {
            j--;
        }
        else if(x>a[j])
        {
            q.push(x/2);
        }
        else 
        {
            cout<<"NO\n";
            return ;
        }
    }
    cout<<"YES\n";
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