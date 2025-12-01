#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,t;
    cin>>n;
    int mx=0,cnt=0;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        if(t>mx)
        {
            mx=t;
            cnt=1;
        }
        else if(t==mx) cnt++;
    }
    cout<<n-cnt;

}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

