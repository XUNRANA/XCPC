class Solution {
public:
    #define ll long long
    #define P 1000000007
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param a int整型vector 
     * @param x int整型 
     * @return int整型
     */
    int getSubarrayNum(vector<int>& a, int x) {
        ll n=a.size(),s2=0,s5=0,ans=0;
        vector<ll>c2(n,0),c5(n,0);
        for(int i=0;i<n;i++)
        {
            int t=a[i];
            while(t%2==0) t/=2,c2[i]++;
            while(t%5==0) t/=5,c5[i]++;
        }
        for(int i=0,j=0;j<n;j++)
        {
            s2+=c2[j];
            s5+=c5[j];
            while(s2>=x&&s5>=x)
            {
                s2-=c2[i];
                s5-=c5[i];
                i++;
                ans+=n-j;
                ans%=P;
            }
        }
        return ans;
    }
};
