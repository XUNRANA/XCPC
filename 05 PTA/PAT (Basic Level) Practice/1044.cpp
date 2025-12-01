#include <bits/stdc++.h>
using namespace std;
#define int long long
#define P 1000000007

string a[]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string b[]={"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string,string>mp;
void init()
{
    for(int i=0;i<13;i++)
    {
        string ans=a[i];
        // cout<<i<<" "<<ans<<"\n";
        mp[ans]=to_string(i);
        mp[to_string(i)]=ans;
    }
    for(int i=13;i<169;i++)
    {
        int j=i/13;
        int k=i%13;
        string ans=b[j-1];
        if(k) ans+=" "+a[k];
        // cout<<i<<" "<<ans<<"\n";
        mp[ans]=to_string(i);
        mp[to_string(i)]=ans;
    }
}
void solve()
{

    int n;
    cin>>n;
    cin.ignore();
    string s;
    while(n--)
    {
        getline(cin,s);
        // cout<<s<<"\n";
        cout<<mp[s]<<"\n";
    }
}

signed main() 
{
    init();
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
