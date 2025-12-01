#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    priority_queue<array<int,3>,vector<array<int,3>>,greater<array<int,3>>>q0,q1;
    for(int i=0;i*i<=n*100;i++)
    {
        for(int j=0;j*j<=n*100;j++)
        {
            q0.push({3*i+3*j+2,3*i+1,3*j+1});
            q1.push({3*i+3*j+3,3*i+1,3*j+2});
            q1.push({3*i+3*j+3,3*i+2,3*j+1});
            q1.push({3*i+3*j+4+2,3*i+2,3*j+2});
        }
    }
    for(int i=1;i<=n;i++)
    {
        int f,x,y;
        cin>>f;
        if(!f)
        {
            x=get<1>(q0.top());
            y=get<2>(q0.top());
            q0.pop();
        }
        else
        {
            if(!q0.empty()&&q0.top()<q1.top())
            {
                x=get<1>(q0.top());
                y=get<2>(q0.top());
                q0.pop();
            }
            else
            {
                x=get<1>(q1.top());
                y=get<2>(q1.top());
                q1.pop();
            }
        }
        cout<<x<<" "<<y<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
