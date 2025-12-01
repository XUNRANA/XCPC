#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int m,x,y;
    cin>>m>>x>>y;
    for(int i=99;i>=10;i--)//甲
    {
        int j=i/10+i%10*10;//乙
        // if(j%y==0)
        {
            double k=j/y;
            if(abs(i-j)*y%j==0&&abs(i-j)*y/j==x)
            {
                // cout<<i<<" "<<j<<" "<<k<<"\n";
                cout<<i;
                if(i>m) cout<<" Cong";
                else if(i==m) cout<<" Ping";
                else cout<<" Gai";

                if(j>m) cout<<" Cong";
                else if(j==m) cout<<" Ping";
                else cout<<" Gai";

                if(j>y*m) cout<<" Cong";
                else if(j==y*m) cout<<" Ping";
                else cout<<" Gai";
                return ;
            }
        }
    }
    cout<<"No Solution\n";
}

signed main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
