#include <iostream>
using namespace std;
long long n,t,s;
int main()
{
  cin>>n;
  while(n--)
  {
    cin>>t;
    s+=abs(t);
  }
  cout<<s;
}
