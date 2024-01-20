#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> rv;
        for (int i = 1; i <= n; i++){
            if (i % 3 == 0 && i % 5 == 0){
                rv.push_back("FizzBuzz");
            } else if (i % 3 == 0) {
                rv.push_back("Fizz");
            } else if (i % 5 == 0) {
                rv.push_back("Buzz");
            } else {
                rv.push_back(to_string(i));
            }
        }
        return rv;
    }
};