#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,q,l,r,a[3][100010];
string s;
void solve()
{
	cin>>n>>q>>s;
	s=" "+s;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<3;j++) a[j][i]=a[j][i-1];
        if(s[i]=='r') a[0][i]++;
        if(s[i]=='e') a[1][i]++;
        if(s[i]=='d') a[2][i]++;
    }
	while(q--)
 	{
		cin>>l>>r;
        if((r-l+1)<3)
        {
            cout<<"0\n";
            continue;
        }
		if((r-l+1)%3==0) 
        {
            int l0=(r-l+1)/3,l1=l0,l2=l0,l3=l0;
            cout<<l1-(a[0][l+l1-1]-a[0][l-1])+l2-(a[1][l+l1-1+l2]-a[1][l+l1-1])+l3-(a[2][l+l1-1+l2+l3]-a[2][l+l1-1+l2])<<"\n";
        }
		else if((r-l+1)%3==1)
        {
            
            int l0=(r-l+1)/3,l1=l0,l2=l0,l3=l0,ans=1e9;
            l1++;
            ans=min(ans,l1-(a[0][l+l1-1]-a[0][l-1])+l2-(a[1][l+l1-1+l2]-a[1][l+l1-1])+l3-(a[2][l+l1-1+l2+l3]-a[2][l+l1-1+l2]));
            l1--;
            l2++;
            ans=min(ans,l1-(a[0][l+l1-1]-a[0][l-1])+l2-(a[1][l+l1-1+l2]-a[1][l+l1-1])+l3-(a[2][l+l1-1+l2+l3]-a[2][l+l1-1+l2]));
            l2--;
            l3++;
            ans=min(ans,l1-(a[0][l+l1-1]-a[0][l-1])+l2-(a[1][l+l1-1+l2]-a[1][l+l1-1])+l3-(a[2][l+l1-1+l2+l3]-a[2][l+l1-1+l2]));
            l3--;
            cout<<ans<<"\n";
        }
		else 
        {
            int l0=(r-l+1)/3,l1=l0,l2=l0,l3=l0,ans=1e9;
            l1++;
            l2++;
            ans=min(ans,l1-(a[0][l+l1-1]-a[0][l-1])+l2-(a[1][l+l1-1+l2]-a[1][l+l1-1])+l3-(a[2][l+l1-1+l2+l3]-a[2][l+l1-1+l2]));
            l1--;
            l2--;
            
            l1++;
            l3++;
            ans=min(ans,l1-(a[0][l+l1-1]-a[0][l-1])+l2-(a[1][l+l1-1+l2]-a[1][l+l1-1])+l3-(a[2][l+l1-1+l2+l3]-a[2][l+l1-1+l2]));
            l1--;
            l3--;
            
            l2++;
            l3++;
            ans=min(ans,l1-(a[0][l+l1-1]-a[0][l-1])+l2-(a[1][l+l1-1+l2]-a[1][l+l1-1])+l3-(a[2][l+l1-1+l2+l3]-a[2][l+l1-1+l2]));
            l2--;
            l3--;
            cout<<ans<<"\n";
        }
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int T=1;
	//cin>>T;
	while(T--) solve();
}
