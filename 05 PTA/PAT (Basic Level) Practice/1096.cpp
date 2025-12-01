#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n;
    cin>>n;
    set<int>st;
    for(int i=1;i*i<=n;i++)
    if(n%i==0)
    {
        st.insert(i);
        st.insert(n/i);
    }
    vector<int>a;
    for(auto i:st) a.push_back(i);

    for(int i=0;i<a.size();i++)
    for(int j=i+1;j<a.size();j++)
    for(int k=j+1;k<a.size();k++)
    for(int l=k+1;l<a.size();l++)
    if((a[i]+a[j]+a[k]+a[l])%n==0) 
    {
        // cout<<a[i]<<" "<<a[j]<<" "<<a[k]<<" "<<a[l]<<"\n";
        cout<<"Yes\n";
        return ;
    }
    cout<<"No\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
