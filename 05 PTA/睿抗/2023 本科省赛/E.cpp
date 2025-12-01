#include <bits/stdc++.h>
using namespace std;


int a[100010];
int b[100010];
int p[100010];
int r[100010];
void solve()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++) 
    {
        if(a[p[i]]&&!b[p[i]]) r[i]=1;
        else if(!a[p[i]]&&!b[p[i]]) r[i]=2;
        else if(a[p[i]]&&b[p[i]]) r[i]=2;
        else if(!a[p[i]]&&b[p[i]]) r[i]=4;
    }
    vector<int>v;
    for(int i=1;i<=n;i++)
    {
        auto it=upper_bound(v.begin(),v.end(),r[i]);
        if(it==v.end()) v.push_back(r[i]);
        else *it=r[i];
    }
    cout<<n-v.size()<<"\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
