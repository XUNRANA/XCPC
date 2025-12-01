#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[110];
int b[110];
bool ck(int x,int y)
{
    for(int i=1;i<=n;i++) b[i]=1;
    b[x]=b[y]=0;//x 和 y是狼人
    

    // for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    // cout<<"\n";

    int cnt=0,c=0;
    for(int i=1;i<=n;i++)
    {
        int z=abs(a[i]);
        if(b[z]&&a[i]<0) 
        {
            cnt++;
            // cout<<i<<" "<<a[i]<<"\n";
            if(!b[i]) c++;
        }

        if(!b[z]&&a[i]>0) 
        {
            cnt++;
            // cout<<i<<" "<<a[i]<<"\n";
            if(!b[i]) c++;
        }
    }
    // cout<<x<<" "<<y<<"!!!\n";
    // cout<<cnt<<" "<<c<<"??\n";
    return cnt==2&&c==1;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    // cout<<ck(1,4)<<"\n";
    for(int i=1;i<=n;i++) 
    {
        for(int j=i+1;j<=n;j++)
        {
            if(ck(i,j)) 
            {
                cout<<i<<" "<<j<<"\n";
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
