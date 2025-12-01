#include <bits/stdc++.h>
using namespace std;
#define int long long


void solve()
{
    string a,b;
    // cin>>a>>b;
    getline(cin,a);
    // cin.ignore();
    getline(cin,b);
    set<char>st;
    for(auto i:a)
    {
        if(i=='+')
        {
            for(char ch='A';ch<='Z';ch++) st.insert(ch);
        }
        else 
        {
            st.insert(i);
            st.insert(tolower(i));
        }
    }
    for(auto i:b)
    if(!st.count(i)) cout<<i;
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}

