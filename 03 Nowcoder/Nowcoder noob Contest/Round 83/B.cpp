#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    int n,m,x,a[110],b[110];
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    sort(a+1,a+1+n,cmp);
    sort(b+1,b+1+m,cmp);
    int c=0,s=0,j=1;
    for(int i=1;i<=m;i++)
    {
        if(b[i]+s>=x)
        {
            cout<<++c;
            return 0;
        }
        else
        {
            if(j<=n) 
            {
                s+=b[i]*a[j++],c+=2;
                if(s>=x)
                {
                    cout<<c;
                    return 0;
                }
            }
            else s+=b[i],c++;
        }
    }
    if(s<x) cout<<-1;
    else cout<<c;
}