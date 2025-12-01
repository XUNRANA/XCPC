#include <bits/stdc++.h>
using namespace std;
#define int long long
map<pair<int,int>,int>cnt;
int fx(int l,int r,int k)
{
    if(l>r||k<0) return 0;
    if(cnt.count({r-l+1,k})) return cnt[{r-l+1,k}];
    int m=l+r>>1;
    int res=1;
    res+=fx(l,m-1,k-1);
    res+=fx(m+1,r,k);
    return cnt[{r-l+1,k}]=res;
}
void solve()
{
    int l,r,k;
    cin>>l>>r>>k;
    if(k>=60)
    {
        cout<<r-l+1<<"\n";
        return ;
    }
    cnt.clear();
    cout<<fx(l,r,k)<<"\n";
}


signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
