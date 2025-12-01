#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];



    vector<int>b;
    for(int i=1;i<=n;i++) if(a[i]) b.push_back(i);
    if(b.size()==0)
    {
        for(int i=1;i<=n;i++) cout<<i<<" \n"[i==n];
    }
    else if(b.size()==1)
    {
        for(int i=1;i<=n;i++) 
        if(!a[i])
        {
            if((i&1)==(b[0]&1)) cout<<a[b[0]]<<" ";
            else cout<<a[b[0]]+1<<" ";
        }
        else cout<<a[i]<<" ";
        cout<<"\n";
    }
    else
    {
        for(int i=1;i<b.size();i++)
        {
            int len=b[i]-b[i-1];
            int l=max(a[b[i-1]]-len,1ll);
            int r=a[b[i-1]]+len;
            if((a[b[i]]%2!=r%2)||a[b[i]]>r||a[b[i]]<l)
            {
                cout<<"-1\n";
                return ;
            }
            int j=b[i-1]+1;
            while(j<b[i])
            {
                if(a[j-1]<a[b[i]]) a[j]=a[j-1]+1;                
                else a[j]=a[j-1]-1;
                j++;
            }
        }
        if(a[1]==0)
        {
            for(int i=1;i<=n;i++) 
            if(a[i])
            {
                for(int j=i-1;j>=1;j--) a[j]=a[j+1]+1;
                break;
            }
        }
        if(a[n]==0)
        {
            for(int i=n;i>=1;i--) 
            if(a[i])
            {
                for(int j=i+1;j<=n;j++) a[j]=a[j-1]+1;
                break;
            }
        }
        for(int i=1;i<=n;i++) cout<<a[i]<<" \n"[i==n];
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
