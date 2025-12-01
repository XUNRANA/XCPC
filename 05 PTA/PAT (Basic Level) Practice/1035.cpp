#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
int a[110],b[110],c[110];
int fx(int x)
{
    int len=1<<x;
    for(int i=1;i<=n;i++)
    {
        sort(a+i,min(a+i+len,a+1+n));
        i+=len-1;
    }
    for(int i=1;i<=n;i++) if(a[i]!=c[i]) return 0;
    return 1;
}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i],c[i]=b[i];
    int f=1;
    for(int i=1;i<=n;i++) 
    {
        if(b[i]>b[i+1])
        {
            for(int j=i+1;j<=n;j++) if(b[j]!=a[j]) f=0;
            sort(b+1,b+1+i+1);
            break;
        }
    }

    if(f)
    {
        cout<<"Insertion Sort\n";
        for(int i=1;i<=n;i++) cout<<b[i]<<" \n"[i==n];
    }
    else
    {
        cout<<"Merge Sort\n";
        int len=1;
        while(1) 
        {
            if(fx(len))
            {
                fx(len+1);
                break;
            }
            else len++;
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

