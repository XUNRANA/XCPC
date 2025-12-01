#include <bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],c,mx;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n-1;i++) b[i]=abs(a[i]-a[i+1]);
    for(int i=1;i<n;i++)
    {
        if(b[i]<=1) c++;
        else c=0;
        mx=max(mx,c+1);
    }
    cout<<mx<<"\n";
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
