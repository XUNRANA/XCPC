#include <bits/stdc++.h>
using namespace std;
#define int long long

int m,n,s;
void solve()
{
    cin>>m>>n>>s;
    set<string>st;
    int f=0;
    for(int i=1;i<=m;i++)
    {
        string t;
        cin>>t;
        if(i>=s)
        {
            if(f%n==0)
            {
                if(st.count(t)) f--;
                else
                {
                    cout<<t<<"\n";
                    st.insert(t);
                    f=0;
                }
            }
            f++;
        }
    }
    if(!st.size()) cout<<"Keep going...\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
