#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n;
    cin>>n;
    string s[2*n+1];
    for(int i=1,t=n;i<=n;i++)
    {
        int t1=t,t2=4*n-2*t,t3=t;
        while(t1--) s[i]+='.';
        while(t2--) s[i]+='*';
        while(t3--) s[i]+='.';
        t--;
    }
    for(int i=n+1;i<=2*n;i++)
    {
        int t1=n,t2=2*n,t3=n;
        while(t1--) s[i]+='*';
        while(t2--) s[i]+='.';
        while(t3--) s[i]+='*';
    }
    for(int i=1;i<2*n+1;i++) cout<<s[i]<<"\n";
    for(int i=2*n;i>=1;i--) cout<<s[i]<<"\n";
	
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

