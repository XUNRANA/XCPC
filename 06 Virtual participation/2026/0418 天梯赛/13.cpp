#include <bits/stdc++.h>
using namespace std;

int vt[100000];//患者i是否已经看完病
int r[100000];//时间i是哪位患者预约的
int arr[100000];//患者i的到达时间

int a[10010];
int b[10010];
int c[10010];
int d[10010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        r[b[i]]=c[i];
        arr[c[i]]=a[i];
    }
    

    int j=1;
    vector<array<int,2>>ans;
    priority_queue<int,vector<int>,greater<int>>q1,q2;

    for(int i=1;i<=n;i++)
    {
        // cout<<j<<" "<<i<<"!!!!!!!\n";
        while(j<=n&&a[j]<=i)
        {
            if(d[j]>=80) q1.push(b[j]);
            else q2.push(b[j]);
            j++;
        }

        if(!vt[r[i]]&&arr[r[i]]<=i) 
        {
            vt[r[i]]=1;
            ans.push_back({i,r[i]});
        }
        else
        {
            while(!q1.empty()&&vt[r[q1.top()]]) q1.pop();
            while(!q2.empty()&&vt[r[q2.top()]]) q2.pop();
            if(!q1.empty())
            {
                vt[r[q1.top()]]=1;
                ans.push_back({i,r[q1.top()]});
                q1.pop();
            }else if(!q2.empty())
            {
                vt[r[q2.top()]]=1;
                ans.push_back({i,r[q2.top()]});
                q2.pop();
            }
        }
    }
    while(!q1.empty()&&vt[r[q1.top()]]) q1.pop();
    while(!q2.empty()&&vt[r[q2.top()]]) q2.pop();
    int idx=n+1;
    while(!q1.empty()) 
    {
        if(vt[r[q1.top()]]) 
        {
            q1.pop();
            continue;
        }
        vt[r[q1.top()]]=1;
        ans.push_back({idx++,r[q1.top()]});
        q1.pop();
    }
    while(!q2.empty()) 
    {
        if(vt[r[q2.top()]]) 
        {
            q2.pop();
            continue;
        }
        vt[r[q2.top()]]=1;
        ans.push_back({idx++,r[q2.top()]});
        q2.pop();
    }
    for(auto i:ans) printf("%d %05d\n",i[0],i[1]);


 
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}