#include <bits/stdc++.h>
using namespace std;
string ma[20];
string mb[20];
string mc[20];
void solve()
{
    int n,d;
    double e;
    cin>>n>>e>>d;
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++)
    {
        int k;
        double x;
        cin>>k;
        int cnt=0;
        for(int j=1;j<=k;j++) 
        {
            cin>>x;
            if(x<e) cnt++;
        }
        if(cnt>k/2) 
        {
            if(k>d) ans2++;
            else ans1++;
        }   
    }
    printf("%.1f%% %.1f%%",100.0*ans1/n,100.0*ans2/n);
    // cout<<ans1<<" "<<ans2<<"\n";
}

int main() 
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	// cin>>T;
	while(T--) solve(); 
}
