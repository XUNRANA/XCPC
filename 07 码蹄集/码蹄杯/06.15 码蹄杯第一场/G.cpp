#include <bits/stdc++.h>
using namespace std;
int n;

void solve()
{
    cin>>n;
    vector<array<int,2>>a;
    for(int i=1;i<=n;i++)
    {
        int op,x,y;
        cin>>op;
        if(op==1) 
        {
            cin>>x;
            // [0,n-1]
            a.push_back({x+1,n});
        }
        else if(op==2)
        {
            cin>>x;
            a.push_back({1,x+1});
        }
        else 
        {
            cin>>x>>y;
            a.push_back({x+1,y+1});
        }
    }
    sort(a.begin(),a.end());
    priority_queue<int,vector<int>,greater<int>>q;

    int now=1;
    int i=0;
    while(1)
    {
        while(i<n&&a[i][0]<=now)
        {
            q.push(a[i][1]);
            i++;
        }
        if(q.empty()&&now!=n+1)
        {
            cout<<"N\n";
            return ;
        }

        if(!q.empty())
        {
            if(q.top()>=now) 
            {
                now++;
                q.pop();
            }
            else
            {
                cout<<"N\n";
                return ;
            }
        }
        
        if(now==n+1)
        {
            cout<<"Y\n";
            return ;
        }
    }
    cout<<"Y\n";

}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}