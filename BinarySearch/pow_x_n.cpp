//https://leetcode.com/problems/powx-n/
/*
O(log n) binary search technique:

pow(2, 10) = pow(pow(2, 2), 5)
           = pow(4, 5)
           = 4*pow(4,4)
           =4*pow(4^2, 2)
           =4*pow(16, 2)

2 recursive cases to consider come down to:
       if(n % 2 == 0) => pow(x*x, n/2)            
       else => x*pow(x, n-1)

*/
class Solution {
public:
    
    double helper(double x, long n){
        cout << "x: " << x << " , n: " << n << endl;
        if(n == 0){return 1;}
        if(n == 1){return x;}
        if(n == 2){return x * x;}
        if(n % 2 == 0){
            return helper(x*x, n/2);
        } else{
            return x*helper(x, n-1);
        }
    }
    
    double myPow(double x, int n) {
        long _n = n;
        if(n < 0){
            _n *= -1;
            return 1 / helper(x, _n);
        }
        return helper(x, _n);
    }
};
