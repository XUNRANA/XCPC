#include<bits/stdc++.h>
#define For(i,j,k) for(int i=(j);i<=(k);++i)
#define ForDown(i,j,k) for(int i=(j);i>=(k);--i)
#define Debug(fmt, args...) fprintf(stderr,"(func %s, line #%d): " fmt,__func__,__LINE__,##args),fflush(stderr)
#define debug(fmt, args...) fprintf(stderr,fmt,##args),fflush(stderr)
#define within :
#define LJY main
using namespace std;
typedef long long ll;
const int N=2e5+5;
inline int read(){
  char ch=getchar();int x=0,f=1;
  while(ch<'0'||ch>'9'){if(ch=='-') f=-1;ch=getchar();}
  while(ch>='0'&&ch<='9')
    x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
  return x*f;
}
int Mx[1024][1024];
int n,a[N],f[N];
signed LJY(){
  n=read();For(i,1,n) a[i]=read()^a[i-1];
  ll ans=0;
  memset(Mx,-0x3f,sizeof(Mx));
  For(i,1,n){
    For(j,0,1023) Mx[a[i-1]^j][a[i-1]]=max(Mx[a[i-1]^j][a[i-1]],f[i-1]-(a[i-1]^j)*(i-1));
    For(j,0,1023) f[i]=max(f[i],Mx[a[i]^j][j]+(a[i]^j)*i);
    ans+=f[i];
  }printf("%lld\n",ans);
  return 0;
}
