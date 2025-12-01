#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve()
{
    int n,k,n1,b,t,n2;
    cin>>n>>k;
    while(k--)
    {
        cin>>n1>>b>>t>>n2;
        b^=1;
        if(t>n) cout<<"Not enough tokens.  Total = "<<n<<".\n";
        else 
        {
            if(b)
            {
                if(n1>n2) 
                {
                    n+=t;
                    cout<<"Win "<<t<<"!  Total = "<<n<<".\n";
                }
                else 
                {
                    n-=t;
                    cout<<"Lose "<<t<<".  Total = "<<n<<".\n";
                }
            }
            else
            {
                if(n1<n2) 
                {
                    n+=t;
                    cout<<"Win "<<t<<"!  Total = "<<n<<".\n";
                }
                else 
                {
                    n-=t;
                    cout<<"Lose "<<t<<".  Total = "<<n<<".\n";
                }
            }
        }
        if(!n) 
        {
            cout<<"Game Over.\n";
            return ;
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
