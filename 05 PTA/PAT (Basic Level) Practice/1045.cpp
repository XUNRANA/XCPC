#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007
int a[100010];
int mi[100010];
int mx[100010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1)
    {
        cout<<"1\n"<<a[1];
        return ;
    }
    mx[1]=a[1];
    for(int i=2;i<=n;i++) mx[i]=max(mx[i-1],a[i]);
    mi[n]=a[n];
    for(int i=n-1;i>=1;i--) mi[i]=min(mi[i+1],a[i]);
    set<int>st;
    if(a[1]<mi[2]) st.insert(a[1]);
    if(a[n]>mx[n-1]) st.insert(a[n]);
    for(int i=2;i<=n-1;i++) if(a[i]>mx[i-1]&&a[i]<mi[i+1]) st.insert(a[i]);
    int f=0;
    cout<<st.size()<<"\n";
    for(auto i:st) 
    {
        if(f) cout<<" ";
        cout<<i;
        f=1;
    }
    cout<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
