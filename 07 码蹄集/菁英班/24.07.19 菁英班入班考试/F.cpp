#include <bits/stdc++.h>
using namespace std;

void solve()
{
    string s;
    int c1=0;
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        if(i&1)
        {
            if(s[i]=='A') c1++;
        }
        else
        {
            if(s[i]=='B') c1++;
        }
    }
    cout<<min(c1,(int)s.size()-c1)<<"\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}

