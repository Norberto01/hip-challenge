class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() == 0){
            return true;
        }
        int left = 0;
        int right = t.size();
        bool rv = false;

        int sv = 0;
        int sl = s.size() - 1;
        int last_found = 0;
        while(left < right){
            if(sv > sl){
                break;
            }
            if (s.at(sv) == t.at(left)){
                rv = true;
                sv ++;
                last_found ++;
            } else {
                rv = false;
            }
            left ++;
        }

        if (last_found < s.size()){
            rv = false;
        }
        return rv;
    }
};