
#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[100010];
void solve()
{
    int n;
    string s;
    cin>>n>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==2) cout<<"Alice\n";
    else 
    {
        if(s=="Alice")
        {
            vector<int>b;
            for(int i=1;i<=n;i++) if(i!=a[i]) b.push_back(i);
            swap(a[b[0]],a[b[1]]);
            int f=0;
            for(int i=1;i<=n;i++) if(i!=a[i]) f=1;
            if(!f) cout<<"Alice\n";
            else cout<<"Bob\n";
        }
        else
        {
            if(n==3)
            {
                if(a[1]==2&&a[2]==3&&a[3]==1) cout<<"Alice\n";
                else if(a[1]==3&&a[2]==1&&a[3]==2) cout<<"Alice\n";
                else cout<<"Bob\n";
            }
            else cout<<"Bob\n";
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