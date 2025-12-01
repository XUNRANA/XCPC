#include <bits/stdc++.h>
using namespace std;
int n;
void solve()
{
    cin>>n;
    if(n%4==0) cout<<"Bong\n";
    else cout<<"Bing\n";
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int t1=1;
	cin>>t1;
	while(t1--) solve(); 
}