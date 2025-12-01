#include <bits/stdc++.h>
using namespace std;




int cnt[1000010];
void solve()
{
    int n,q;
    cin>>n>>q;
    set<int>st;
    for(int i=1;i<=n;i++) 
    {
        st.insert(i);
        cnt[i]=1;
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        int ans=0;
        for(auto i:st) 
        if(i<=x) ans+=cnt[i];
        else break;

        while(*st.begin()<=x) st.erase(st.begin());
        cnt[y]+=ans;
        cout<<ans<<"\n";
    }
} 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
