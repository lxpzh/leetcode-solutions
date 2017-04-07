class Solution {
public:
    bool isUgly(int num) {
      while (num > 1)  {
            if ((num & 1) == 0) {
                num >>= 1;
            }
            else if (num % 5 == 0) {
                num = num / 5;
            }
            else if (num % 3 == 0) {
                num = num / 3;
            } else {
                return false;
            }
        };
    
        return num == 1 ? true : false;
    }
};