#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n;
int main()
{
  // 请在此输入您的代码
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin>>n;
  for(ll i=1;i;i++)
  {
    if(i*i < n && n <(i+1)*(i+1))
    {
      ll a =i;
      ll b =i+1;
      ll c =n-a*a;
      if(n<=a*b)
      cout<<(a*(a-1)*2+c*2-1)*2;
      else
      cout<<(a*(a-1)*2+c*2-2)*2;
      break;
    }
    else if(n==i*i)
    {
      cout<<i*(i-1)*4;
      break;
    }
  } 

  return 0;
}
