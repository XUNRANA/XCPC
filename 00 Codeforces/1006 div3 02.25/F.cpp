#include <bits/stdc++.h>
using namespace std;
void solve()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++) cout<<(((n-1)&i)==i? k:0)<<" \n"[i==n-1];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int T=1;
    cin>>T;
    while(T--) solve();
}
