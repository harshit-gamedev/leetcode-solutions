class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0;
        
        while (a > 0 || b > 0 || c > 0) {
            int a_bit = a & 1;  // last bit of a
            int b_bit = b & 1;  // last bit of b
            int c_bit = c & 1;  // last bit of c
            
            if (c_bit == 0) {
                // c wants 0, so any 1 in a or b must be flipped
                flips += a_bit + b_bit;
            } else {
                // c wants 1, so if both a and b are 0, we need 1 flip
                if (a_bit == 0 && b_bit == 0) flips += 1;
            }
            
            // right shift to check next bit
            a >>= 1;
            b >>= 1;
            c >>= 1;
        }
        
        return flips;
    }
};
