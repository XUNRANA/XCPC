#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int d,n;
    cin>>d>>n;
    string s="";
    s+=d+'0';
    // cout<<s<<"?\n";
    n--;
    while(n--)
    {
        vector<char>a;
        vector<int>b;
        for(auto i:s)
        {
            if(!a.size()||i!=a.back()) 
            {
                a.push_back(i);
                b.push_back(1);
            }
            else b.back()++;
        }
        string res="";
        for(int i=0;i<b.size();i++)
        {
            res+=a[i];
            res+=to_string(b[i]);
        }
        s=res;
        // cout<<s<<"?\n";
    }
    cout<<s<<"\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
