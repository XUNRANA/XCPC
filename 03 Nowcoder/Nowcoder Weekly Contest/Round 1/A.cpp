#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,k;
    cin>>n>>k;
    if(k*3>n) cout<<"-1\n";
    else 
    {
        for(int i=1;i<=k;i++) cout<<"you";
        cout<<string(n-3*k,'y');
    }    
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
