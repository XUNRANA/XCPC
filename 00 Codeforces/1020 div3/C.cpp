#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[200010],b[200010];
void solve()
{
    cin>>n>>k;
    int mi=1e9;
    int mx=0;
    for(int i=1;i<=n;i++) cin>>a[i],mi=min(mi,a[i]),mx=max(mx,a[i]);
    for(int i=1;i<=n;i++) cin>>b[i];
    set<int>st;
    for(int i=1;i<=n;i++) if(b[i]!=-1) st.insert(a[i]+b[i]);
    if(st.size()>1) cout<<"0\n";
    else if(st.size()==1) 
    {
        int res=*st.begin();
        if(res-mi>k) cout<<"0\n";
        else if(res-mx<0) cout<<"0\n";
        else cout<<"1\n";
    }
    else if(st.size()==0)
    {
        int l=mx-mi;
        int r=k;
        cout<<r-l+1<<"\n";    
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
