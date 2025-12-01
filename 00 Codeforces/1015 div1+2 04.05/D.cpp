#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    int mx=max(k,n/(m+1));    
    for(int i=0;i<n;i++) cout<<i%mx<<" \n"[i==n-1];
}
int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}
