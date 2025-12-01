#include <bits/stdc++.h>
using namespace std;
long long n,q,k,s,ans,a[100010],b[100010];
int main()
{
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    while(q--)
    {
        cin>>k;
        s=0;
        ans=1e18;
        priority_queue<long long,vector<long long>,less<long long>>q;//降序
        for(int i=1;i<=n;i++)
        {
            s+=a[i];
            s+=b[i];
            q.push(b[i]);
            while(q.size()>k) 
            {
                s-=q.top();
                q.pop();
            }
            if(q.size()==k) ans=min(ans,s);
        }
        cout<<ans<<"\n";
    }
}