#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    cin>>s;
    vector<int>c(10);
    for(auto i:s) c[i-'0']++;
    for(int i=1;i<10;i++)
    if(c[i])
    {
        cout<<i;
        c[i]--;
        break;
    }
    
    for(int i=0;i<10;i++)
    while(c[i]--) cout<<i;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

