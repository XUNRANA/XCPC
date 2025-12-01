#include <bits/stdc++.h>
using namespace std;
#define int long long


int nxt[100010];
int da[100010];
void solve()
{
    int head,n,k;
    cin>>head>>n>>k;
    for(int i=1;i<=n;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        da[a]=b;
        nxt[a]=c;
    }
    vector<pair<int,int>>a;
    while(head!=-1)
    {
        a.push_back({da[head],head});
        head=nxt[head];
    }
    for(int i=0;i<a.size();i+=k)
    {
        if(i+k-1<a.size())
        {
            for(int i1=i,j1=i+k-1;i1<j1;i1++,j1--)
            {
                swap(a[i1],a[j1]);
            }
        }
    }
    for(int i=0;i<a.size();i++) 
    {
        if(i+1<a.size()) printf("%05d %d %05d\n",a[i].second,a[i].first,a[i+1].second);
        else printf("%05d %d -1\n",a[i].second,a[i].first);
    }
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

