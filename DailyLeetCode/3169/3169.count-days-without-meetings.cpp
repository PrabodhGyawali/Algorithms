/*
 * @lc app=leetcode id=3169 lang=cpp
 *
 * [3169] Count Days Without Meetings
 */

#include <vector>
#include <thread>
#include <iostream>

using namespace std;
// @lc code=start
class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        vector<long int> visited(days + 1, 0);
        int count = 0;
        for (int i = 0; i < meetings.size(); i++) {
            int day = meetings[i][1];
            do {
                if (visited[day] == 0) {
                    visited[day] = 1;
                    count++;
                }
            } while (meetings[i][0] != day--);
        }
        return days - count;
    }
};
// @lc code=end

// int main() {
//     Solution solution;
//     vector<vector<int>> meetings = {
//         {5, 7}, {1, 3}, {9, 10}
//     };
//     int result = solution.countDays(10, meetings);
//     cout << "Days without meetings: " << result << endl;
//     return 0;
// }