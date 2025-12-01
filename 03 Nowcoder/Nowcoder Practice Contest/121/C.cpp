#include <bits/stdc++.h>
using namespace std;
int t,n,p,a[200010],l,r,sl,sr;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>p;
        for(int i=1;i<=n;i++) cin>>a[i];
        l=r=p;
        if(a[p]==9)
        {
            sl=sr=1;
            while((r+1<=n&&a[r+1]+sr>=10)||(l-1>=1&&a[l-1]+sl>=10))
            {
                if(r+1<=n&&a[r+1]+sr>=10) 
                {
                    sl++;
                    sr=(a[r+1]+sr)-10+1;
                    r++;
                }
                if(l-1>=1&&a[l-1]+sl>=10) 
                {
                    sr++;
                    sl=(a[l-1]+sl)-10+1;
                    l--;
                }
            }
        }
        if(r<n) sr=0;
        if(l>1) sl=0;
        cout<<sl<<" "<<sr<<"\n";
    }
}