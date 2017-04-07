class Solution {
public:
    bool isPowerOfFour(int num) {
       if (num == 1)
            return true;
        else if (num <= 0 || (num & 1))
            return false;
        else {
            while ((num & 0x03) == 0) {
                num >>= 2;
                if (num == 1) {
                    return true;
                }
            }
            return false;
        }
    } 
};