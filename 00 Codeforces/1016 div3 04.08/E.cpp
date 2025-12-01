#include <bits/stdc++.h>
using namespace std;
#define int long long

int n,k,a[200010];
bool ck(int x)
{
    set<int>st;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<x) st.insert(a[i]);
        if(st.size()==x) 
        {
            st.clear();
            cnt++;
        }
        if(cnt>=k) return 1; 
    }
    return 0;
}

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    int l=0,r=n/k;
    while(l<=r)
    {
        int m=l+r>>1;
        if(ck(m)) l=m+1;
        else r=m-1;
    }
    cout<<l-1<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

