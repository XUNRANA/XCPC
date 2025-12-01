#include<cstdio>
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#define RI register int
#define CI const int&
using namespace std;
const int N=200005;
int t,n,m,a[N],b[N],x[N],y[N],z[N],tx[N],ty[N],tz[N];
vector <int> vec[N]; multiset <int> s[N];
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    for (cin>>t;t;--t)
    {
        cin>>n>>m;
        for (RI i=1;i<=n;++i) s[i].clear(),vec[i].clear();
        for (RI i=1;i<=m;++i)
        {
            cin>>a[i]>>b[i]>>x[i]>>y[i]>>z[i];
            tx[i]=x[i]; ty[i]=y[i]; tz[i]=z[i];
            vec[a[i]].push_back(i); vec[b[i]].push_back(i);
            if (x[i]<=y[i])
            {
                int dlt=min(y[i]-x[i],z[i]); x[i]+=dlt; z[i]-=dlt;
                if (z[i]>0) x[i]+=z[i]/2+(z[i]%2),y[i]+=z[i]/2;
                s[a[i]].insert(x[i]); s[b[i]].insert(y[i]);
            } else
            {
                int dlt=min(x[i]-y[i],z[i]); y[i]+=dlt; z[i]-=dlt;
                if (z[i]>0) x[i]+=z[i]/2+(z[i]%2),y[i]+=z[i]/2;
                s[a[i]].insert(x[i]); s[b[i]].insert(y[i]);
            }
        }
        multiset <int> rst;
        for (RI i=1;i<=n;++i) rst.insert(*s[i].rbegin());
        vector <int> ans;
        for (RI i=1;i<=n;++i)
        {
            vector <int> tmp;
            for (auto id:vec[i]) tmp.push_back(a[id]),tmp.push_back(b[id]);
            sort(tmp.begin(),tmp.end());
            tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
            for (auto p:tmp) rst.erase(rst.find(*s[p].rbegin()));
            for (auto id:vec[i])
            {
                s[a[id]].erase(s[a[id]].find(x[id]));
                s[b[id]].erase(s[b[id]].find(y[id]));
            }
            for (auto id:vec[i])
            {
                if (a[id]==i)
                {
                    int nx=tx[id]+tz[id],ny=ty[id];
                    s[a[id]].insert(nx); s[b[id]].insert(ny);
                } else
                {
                    int nx=tx[id],ny=ty[id]+tz[id];
                    s[a[id]].insert(nx); s[b[id]].insert(ny);
                }
            }
            for (auto p:tmp) rst.insert(*s[p].rbegin());
            auto mx=rst.end(); --mx;
            auto smx=mx; --smx;
            if (*mx==*s[i].rbegin()&&*mx!=*smx) ans.push_back(i);
            for (auto p:tmp) rst.erase(rst.find(*s[p].rbegin()));
            for (auto id:vec[i])
            {
                if (a[id]==i)
                {
                    int nx=tx[id]+tz[id],ny=ty[id];
                    s[a[id]].erase(s[a[id]].find(nx));
                    s[b[id]].erase(s[b[id]].find(ny));
                } else
                {
                    int nx=tx[id],ny=ty[id]+tz[id];
                    s[a[id]].erase(s[a[id]].find(nx));
                    s[b[id]].erase(s[b[id]].find(ny));
                }
            }
            for (auto id:vec[i])
            {
                s[a[id]].insert(x[id]);
                s[b[id]].insert(y[id]);
            }
            for (auto p:tmp) rst.insert(*s[p].rbegin());
        }
        printf("%d\n",(int)ans.size());
        for (auto x:ans) printf("%d ",x); putchar('\n');
    }
    return 0;
}

