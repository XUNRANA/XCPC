#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[300010];
int b[300010];
void solve()
{
    cin>>n>>m;
    int s=0;
    for(int i=1;i<=n;i++) cin>>a[i],a[i]%=m,s+=a[i];
    for(int i=1;i<=n;i++) cin>>b[i],b[i]%=m,s+=b[i];
    sort(a+1,a+1+n);

    multiset<int>st;
    for(int i=1;i<=n;i++) st.insert(b[i]);
    for(int i=n;i>=1;i--)
    {
        int x=m-a[i];
        auto it=st.lower_bound(x);
        if(it==st.end()) break;
        else 
        {
            s-=m;
            st.erase(it);
        }
    }
    cout<<s<<"\n";

}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

