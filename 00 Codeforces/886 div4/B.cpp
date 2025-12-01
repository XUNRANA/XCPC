#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,a,b;
    cin>>n;
    int mx=0;
    int idx=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        if(a<=10&&b>mx) 
        {
            mx=b;
            idx=i;
        }
    }
    cout<<idx<<"\n";
    
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
} 
