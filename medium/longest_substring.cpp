// Problem: Longest Substring Without Repeating Characters
// Difficulty: Medium
// Approach: Sliding Window + HashMap - O(n) time, O(n) space
// Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> map;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            if (map.count(s[right]) && map[s[right]] >= left) {
                left = map[s[right]] + 1;
            }
            map[s[right]] = right;
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
