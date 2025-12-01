#include <bits/stdc++.h>
using namespace std;
#define int long long

#define P 1000000007
int c[6];
string t="PATest";
void solve()
{
    string s;
    cin>>s;
    int cnt=0;
    for(auto i:s) for(int j=0;j<6;j++) 
    if(i==t[j]) 
    {
        c[j]++;
        cnt++;
    }
    
    while(cnt)
    {
        for(int j=0;j<6;j++)
        {
            if(c[j]) 
            {
                cout<<t[j];
                c[j]--;
                cnt--;
            }
        }
    }
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
