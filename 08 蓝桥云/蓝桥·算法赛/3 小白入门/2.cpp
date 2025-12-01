#include <bits/stdc++.h>
using namespace std;
int n,c0,c1,ansl,ansr;
int main()
{
  string s;
  cin>>n>>s;
  for(int i=0;i<n;i++)
  {
    if(s[i]=='0') c0++;
    else ansl+=c0;
  }
  for(int i=0;i<n;i++)
  {
    if(s[i]=='1') c1++;
    else ansr+=c1;
  }
  cout<<min(ansr,ansl);
}
