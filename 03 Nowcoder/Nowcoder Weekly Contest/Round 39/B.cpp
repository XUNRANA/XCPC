#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,k,a[100010],s,cnt;
void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i],s+=a[i];
    sort(a+1,a+1+n);
    s%=k;
    if(s==0) 
    {
        cout<<"0\n";
        return ;
    }
    for(int i=n;i>=1;i--)
    {
    	s-=a[i];
    	cnt++;
    	if(s<=0)
    	{
    		cout<<cnt<<"\n";
    		return ;
		}
	}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
