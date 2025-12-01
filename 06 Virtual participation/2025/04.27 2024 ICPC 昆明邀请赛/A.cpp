#include <bits/stdc++.h>
using namespace std;
#define int long long

struct node
{
    int s;
    vector<int>a;
    int sum;
    int cnt;
    int idx;
}a[400010];
bool cmp(node a1,node a2)
{
    return a1.s>a2.s;
}
bool cmpi(node a1,node a2)
{
    return a1.idx<a2.idx;
}
void solve() 
{
    int n,m,k,x;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        a[i].idx=i;
        cin>>a[i].s;
        a[i].cnt=a[i].sum=0;
        a[i].a.clear();
        for(int j=1;j<=m;j++)
        {
            cin>>x;
            a[i].a.push_back(x);
            if(x==-1) a[i].cnt++;
            else a[i].sum+=x;
        }
    }
    sort(a+1,a+1+n,cmp);
    map<int,int>mp;
    int mi=1e18;
    for(int i=1;i<=n;i++)
    {
        if(i==1) 
        {
            int sum=0;
            for(auto &j:a[i].a)
            {
                if(j==-1) j=k;
                sum+=j;
            }
            a[1].sum=sum;
            mp[a[i].s]=sum;
        }
        else
        {
            if(a[i].s==a[1].s)
            {
                int sum=0;
                for(auto &j:a[i].a)
                {
                    if(j==-1) j=k;
                    sum+=j;
                }
                a[i].sum=sum;
                mp[a[i].s]=min(mp[a[i].s],sum);
            }
            else 
            {
                if(a[i].s!=a[i-1].s)
                {
                    mi=min(mi,mp[a[i-1].s]);
                    if(a[i].sum>=mi)
                    {
                        cout<<"No\n";
                        return ;
                    }
                    int d=mi-a[i].sum-1;
                    int sum=0;
                    for(auto &j:a[i].a)
                    {
                        if(j==-1)
                        {
                            if(d>=k) 
                            {
                                j=k;
                                d-=k;
                            }
                            else 
                            {
                                j=d;
                                d=0;
                            }
                        }
                        sum+=j;
                    }
                    a[i].sum=sum;
                    mp[a[i].s]=sum;
                }
                else
                {
                    if(a[i].sum>=mi)
                    {
                        cout<<"No\n";
                        return ;
                    }
                    int d=mi-a[i].sum-1;
                    int sum=0;
                    for(auto &j:a[i].a)
                    {
                        if(j==-1)
                        {
                            if(d>=k) 
                            {
                                j=k;
                                d-=k;
                            }
                            else 
                            {
                                j=d;
                                d=0;
                            }
                        }
                        sum+=j;
                    }
                    a[i].sum=sum;
                    mp[a[i].s]=min(mp[a[i].s],sum);
                }
            }
        }
    }   
    sort(a+1,a+1+n,cmpi);
    cout<<"Yes\n";
    for(int i=1;i<=n;i++)
    {
        for(auto j:a[i].a) cout<<j<<" ";
        cout<<"\n";
    }
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