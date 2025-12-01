#include <bits/stdc++.h>
using namespace std;
int n,ans;
string b,w;
void solve()
{
    cin>>n>>b>>w;
    for(int i=0;i<n;i++)
    {
        if(b[i]=='Y') ans+=2;
        if(w[i]=='Y') ans+=1;
        if(w[i]=='Y'&&b[i]!='Y') ans++;
    }
    cout<<ans;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

