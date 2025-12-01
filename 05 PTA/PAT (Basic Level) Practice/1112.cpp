#include <bits/stdc++.h>
using namespace std;
int n,t;
void solve()
{
    cin>>n>>t;
    int l=-1,r=-1;
    int mx=1;
    for(int i=0;i<n;i++) 
    {
        int x;
        cin>>x;
        mx=max(mx,x);
        if(x>t)
        {
            if(l!=-1) 
            {
                if(i==r+1) r=i;
                else
                {
                    cout<<"["<<l<<", "<<r<<"]"<<"\n";
                    l=r=i;
                }
            }
            else 
            {
                l=r=i;
            }
        }
    }
    if(l!=-1) cout<<"["<<l<<", "<<r<<"]"<<"\n";
    else cout<<mx<<"\n"; 
} 

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
