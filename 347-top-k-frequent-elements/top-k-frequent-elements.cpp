class Solution {
public:
    static bool Compare (pair<int, int> a, pair<int, int> b) {
        return a.second > b.second;
    }

    vector<int> topKFrequent(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<pair<int, int>> numberFrequencyTable;
        for (int i = 0; i < nums.size(); i++) {
            if (i == 0) {
                pair<int, int> numberFrequencyEntry;
                numberFrequencyEntry.first = nums[i];
                numberFrequencyEntry.second = 1;
                numberFrequencyTable.push_back(numberFrequencyEntry);
            } else if (i > 0) {
                if (nums[i - 1] == nums[i])
                    numberFrequencyTable[numberFrequencyTable.size() - 1].second++;
                else {
                    pair<int, int> numberFrequencyEntry;
                    numberFrequencyEntry.first = nums[i];
                    numberFrequencyEntry.second = 1;
                    numberFrequencyTable.push_back(numberFrequencyEntry);
                }
            }
        }

        sort(numberFrequencyTable.begin(), numberFrequencyTable.end(), Compare);

        vector<int> answer;
        for (int i = 1; i <= k; i++)
            answer.push_back(numberFrequencyTable[i - 1].first);
        return answer;
    }
};