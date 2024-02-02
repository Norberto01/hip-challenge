#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;


class Solution{
    public:
        vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
            int left = 0;
            int right = mat.size() - 1;
            int soldier = 1;
            map<int, int> rv;

            sort(mat.begin(), mat.end());

            while (left <= right) {
                int mid = left + (right - left) / 2;
                vector<int> vr = mat.at(left);
                int curr = count(vr.begin(), vr.end(), soldier);
                rv[mid] = curr;

                cout << endl;
                left ++;
            }

            return rv;
        }
};
int main() {
    // Example usage
    Solution solution;

    vector<vector<int>> edgesB = {
        {1,1,0,0,0}, 
        {1,1,1,1,0}, 
        {1,0,0,0,0}, 
        {1,1,0,0,0}, 
        {1,1,1,1,1}
    };
    int target = 3;
    vector<int> rvs = solution.kWeakestRows(edgesB, target);
    cout << endl << "RV: ----> {";
    for (int i: rvs) {
        cout << i << ", ";
    }
    cout << "}";
    cout << endl << "------------------------------------------------------------------------" << endl;
}