#include <bits/stdc++.h>
using namespace std;
void solve()
{
    int n;
    cin>>n;
    if(n<=4) cout<<"-1\n";
    else 
    {
        if(n==5) cout<<"1 3 5 4 2\n";
        else 
        {
            vector<int>a,b;
            for(int i=6;i<=n;i++) 
            if(i&1) a.push_back(i);
            else b.push_back(i);

            for(auto i:a) cout<<i<<" ";
            cout<<"1 3 5 4 2 ";
            for(auto i:b) cout<<i<<" ";
            cout<<"\n";
        }
    }
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve();
}
