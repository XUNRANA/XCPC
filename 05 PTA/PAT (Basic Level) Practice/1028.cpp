#include <bits/stdc++.h>
using namespace std;
#define int long long

string d1="1814/09/06";
string d2="2014/09/06";
void solve()
{
    int n;
    cin>>n;
    vector<pair<string,string>>a;
    while(n--)
    {
        string s,d;
        cin>>s>>d;
        if(d<d1||d>d2) continue;
        // cout<<s<<" "<<d<<"\n";
        a.push_back({d,s});
    }
    sort(a.begin(),a.end());
    cout<<a.size();
    if(a.size()) cout<<" "<<a[0].second<<" "<<a[a.size()-1].second<<"\n";

}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

