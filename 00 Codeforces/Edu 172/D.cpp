#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node
{
    int i,l,r;
}a[200010];
int ans[200010];
bool cmpl(node a1,node a2)
{
    if(a1.l==a2.l) return a1.r>a2.r;
    return a1.l<a2.l;
}

bool cmpr(node a1,node a2)
{
    if(a1.r==a2.r) return a1.l<a2.l;
    return a1.r>a2.r;
}
void solve()
{
    int n,l,r;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].l>>a[i].r;
        a[i].i=i;
    }
    sort(a+1,a+1+n,cmpl);
    multiset<int>st;
    for(int i=1;i<=n;i++)
    {

        if(st.lower_bound(a[i].r)==st.end()) ans[a[i].i]=0;
        else ans[a[i].i]=*st.lower_bound(a[i].r)-a[i].r;
        // cout<<a[i].l<<" "<<a[i].r<<" "<<ans[a[i].i]<<"\n";
        st.insert(a[i].r);
    }
    sort(a+1,a+1+n,cmpr);
    st.clear();
    for(int i=1;i<=n;i++)
    {
        if(st.lower_bound(-a[i].l)==st.end()) ans[a[i].i]+=0;
        else ans[a[i].i]+=*st.lower_bound(-a[i].l)+a[i].l;
        // cout<<a[i].l<<" "<<a[i].r<<" "<<ans[a[i].i]<<"\n";
        st.insert(-a[i].l);

        if(i-1>=1&&a[i-1].l==a[i].l&&a[i-1].r==a[i].r) ans[a[i-1].i]=ans[a[i].i]=0;
    }

    
    for(int i=1;i<=n;i++) cout<<ans[i]<<"\n";
    

}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}