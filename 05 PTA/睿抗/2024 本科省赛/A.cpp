#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n,w,s=0,s1=0;
    cin>>n>>w;
    while(n--)
    {
        int x;
        cin>>x;
        if(x>=35)
        {
            if(w!=4) s++;
            else s1++;
        }
        w++;
        if(w==8) w-=7;
    }
    cout<<s<<" "<<s1<<"\n";
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--) solve();
}
