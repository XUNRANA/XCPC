#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[310][310];
void solve()
{
    cin>>n;
    vector<int>b;
    for(int i=1;i<=n;i++) 
    {
        for(int j=1;j<=n;j++) cin>>a[i][j];
        for(int j=n-1;j>=1;j--) a[i][j]+=a[i][j+1];
        int f=0;
        for(int j=1;j<=n;j++) 
        if(a[i][j]==n-j+1) 
        {
            f=n-j+1;
            break;
        }
        b.push_back(f);
    }
    sort(b.begin(),b.end());
    int j=0;
    for(auto i:b)
    {
        if(i>=j) j++;
    }
    cout<<j<<"\n";
}
signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
