class Solution {
public:
    int reverse(int x) {
        if (!x|| x==INT_MIN) return 0;
        if (x < 0) return -1 * reverse(-x);
        while (!(x % 10)) 
            x /= 10;
        long long  ans=0;
        while (x) 
            ans = ans * 10 + x % 10, x /= 10;
        return (ans>INT_MAX ||ans<INT_MIN)?0:ans;
    }
};
