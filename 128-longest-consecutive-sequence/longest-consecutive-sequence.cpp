class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> hashTable;
        int longestLength = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (hashTable.count(nums[i]))
                continue;
            else {
                int left = 0;
                if (hashTable.count(nums[i] - 1))
                    left = hashTable[nums[i] - 1];
                
                int right = 0;
                if (hashTable.count(nums[i] + 1))
                    right = hashTable[nums[i] + 1];

                int sum = left + right + 1;
                hashTable[nums[i]] = sum;
                hashTable[nums[i] - left] = sum;
                hashTable[nums[i] + right] = sum;

                if (longestLength < sum)
                    longestLength = sum;
            }
        }
        return longestLength;
    }
};