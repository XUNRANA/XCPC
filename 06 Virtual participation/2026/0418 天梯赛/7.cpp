#include <bits/stdc++.h>
using namespace std;
int n,a[1010];
void solve()
{
    cin>>n;
    int s=0;
    int mx=0;
    int mi=1e6;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i]; 
        s+=a[i];
        mx=max(mx,a[i]);
        mi=min(mi,a[i]);
    }
    cout<<mx<<" "<<mi<<" "<<s/n<<"\n";
    vector<int>ans;
    for(int i=1;i<=n;i++)
    {
        if(a[i]*n>2*s) ans.push_back(i);
    }
    if(ans.size())
    {
        for(int i=0;i<ans.size();i++) cout<<ans[i]<<" \n"[i==ans.size()-1];
    }
    else cout<<"Normal\n";

}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    // cin>>T;
    while(T--) solve();
}