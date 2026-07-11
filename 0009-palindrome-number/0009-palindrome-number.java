class Solution {
    public boolean isPalindrome(int x) {
        int res = 0;
        int copy= x;
        while(x>0){
            int l= x% 10;
            res = res*10 +l;
            x = x/10;
        }
        if (res== copy){
            return true;
        }
        else return false;
    }
}