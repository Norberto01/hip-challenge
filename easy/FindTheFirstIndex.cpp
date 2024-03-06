#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
    public:
        int strStrA(string haystack, string needle) {
            if (needle == haystack){
                return 0;
            } else if (needle.size() > haystack.size()){
                return -1;
            }

            int left = 0;
            int right = needle.size();
            int vh = 0;
            int rv = -1;
            int hz = haystack.size();
            while(left < right){
                try{
                    int hl = left + vh;
                    bool nh = needle.at(left) == haystack.at(hl);
                    if(nh){
                        if (rv == -1){
                            rv = left + vh;
                        }
                    } else {
                        vh ++;
                        left = 0;
                        rv = -1;
                        continue;
                    }
                }catch (const std::out_of_range& oor) {
                    return rv;
                }
                if(needle.size() > (haystack.size() - vh)){
                    return -1;
                }
                hz --;
                left ++;
            }
            return rv;
        }
        int strStr(string haystack, string needle){
            int haystackSize = haystack.size();
            int needleSize = needle.size();

            if (needleSize == 0){
                return 0;
            } else if(haystackSize < needleSize){
                return - 1;
            }

            for(int i = 0; i <= haystackSize - needleSize; ++i){
                int y = 0;
                int z = i;

                while(y < needleSize && haystack[z] == needle[y]){
                    ++ z;
                    ++ y;
                }

                if (y == needleSize){
                    return i;
                }
            }

            return -1;

        }
};