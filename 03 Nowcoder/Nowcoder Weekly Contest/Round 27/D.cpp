class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param n int整型 
     * @param m int整型 
     * @param x int整型 
     * @return int整型
     */
    #define ll long long
    #define P 1000000007
    ll ksm(ll a,ll b)
    {
        int res=1;
        while(b)
        {
            if(b&1) res=res*a%P;
            a=a*a%P;
            b>>=1;
        }
        return res;
    }
    int numsOfGoodMatrix(int n,int m,int x) {
        return ksm(x,m+n-1)*ksm(x/2,1ll*(n-1)*(m-1))%P;
    }
};
