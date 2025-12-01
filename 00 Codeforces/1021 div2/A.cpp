#include <bits/stdc++.h>
using namespace std;
void solve()
{
    string s;
    cin>>s;
    vector<int>cnt(10,0);
    for(auto i:s) cnt[i-'0']++;
    for(int i=1;i<=10;i++)
    {
        int l=10-i;
        for(int j=l;j<=9;j++) 
        if(cnt[j])
        {
            cout<<j;
            cnt[j]--;
            break;
        }
    }
    cout<<"\n";
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
