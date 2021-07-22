// Divide integers without using operatirs


int divide(int A, int B) {
    long long int n=A,m=B;
    int sign=0;
    sign = (n<0 || m<0) ? 1 : 0;
    if(n<0 && m<0)
        sign=0;
    n=abs(n), m=abs(m);
    long long int ans=0,t=0;
    for(int i=31;i>=0;i--)
    {
        if(t+(m<<i)<=n)
        {
            t+=(m<<i);
            ans+=(1ll<<i);
            
        }
    }
    if(sign) 
        ans=-ans;
    
    if (ans>INT_MAX || ans<INT_MIN)
        return INT_MAX;
    return ans;
}
