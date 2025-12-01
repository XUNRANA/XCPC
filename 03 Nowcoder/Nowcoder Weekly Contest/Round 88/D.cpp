#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int x;
    cin>>x;
    if(x==1) cout<<"-1\n";
    else if(x%2==0) cout<<"1\n";
    else 
    {
        // cout<<x<<" "<<log2(x)<<"\n";
        // 11111
        for(int i=log2(x);i>=0;i--) if(!(x>>i&1))
        {
            cout<<(1<<i)<<"\n";
            return ;
        }
        cout<<"-1\n";
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
