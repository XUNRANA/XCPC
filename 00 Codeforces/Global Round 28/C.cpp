#include <bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
    string s;
    cin>>s;
    int n=s.size();
    int c1=count(s.begin(),s.end(),'1');
    if(c1==n||c1==0) cout<<"1 1 1 "<<n<<"\n";
    else 
    {
        for(int i=0;i<s.size();i++)
        {
            if(i+1<s.size()&&s[i]=='1'&&s[i+1]=='0')
            {
                int c0=0,c1=0;
                for(int i1=i;i1>=0;i1--) 
                if(s[i1]=='1') c1++;
                else break;

                for(int i2=i+1;i2<n;i2++) 
                if(s[i2]=='0') c0++;
                else break;

                

                cout<<"1 "<<n<<" "<<i+2-min(c0,c1)<<" "<<n-min(c0,c1)<<"\n";
                return ;
            }
        }
        for(int i=0;i<s.size();i++)
        if(s[i]=='0')
        {
            cout<<"1 "<<n<<" "<<i+1<<" "<<i+1<<"\n";
            return ;
        }
    }
} 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T=1;
	cin>>T;
	while(T--) solve(); 
}

