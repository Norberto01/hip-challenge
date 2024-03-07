class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        for (char &c : s) {
            c = std::tolower(c);
        }
        s.erase(remove_if(s.begin(), s.end(), not1(ptr_fun( (int(*)(int))isalnum))), s.end());

        if(s.size() == 2){
            return s.at(0) == s.at(1);
        } else if(s.size() == 1){
            return true;
        }
        int right = s.size() - 1;
        bool rv = true;
        while(left < right){
            if (s.at(left) == s.at(right)){
                left ++;
                right --;
            } else {
                rv = false;
                break;
            }
        }
        return rv;
    }
};