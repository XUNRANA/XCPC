#include <bits/stdc++.h>
using namespace std;
#define int long long
multiset<int>l,r;
void bal()
{
    while(l.size()>r.size()+1)
    {
        r.insert(*l.rbegin());
        l.erase(--l.end());
    }

    while(r.size()&&l.size()&&(*l.rbegin())>(*r.begin()))
    {
        int x=*l.rbegin();
        int y=*r.begin();
        l.erase(--l.end());
        r.erase(r.begin());
        l.insert(y);
        r.insert(x);
    }
}

void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) 
    {
        int x;
        cin>>x;
        l.insert(x);
        bal();
        if(i%2==0) cout<<((*l.rbegin())+(*r.begin()))/2<<" ";
        else cout<<(*l.rbegin())<<" ";
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
