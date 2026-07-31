class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> answer;
        for (int i = 0; i < nums.size(); i++)
            answer.push_back(1);
        
        int preAllNumProduct = 1;
        for (int i = 1; i < nums.size(); i++) {
            preAllNumProduct = preAllNumProduct * nums[i - 1];
            answer[i] = answer[i] * preAllNumProduct;
        }

        int postAllNumProduct = 1;
        for (int i = nums.size() - 2; i >= 0; i--) {
            postAllNumProduct = postAllNumProduct * nums[i + 1];
            answer[i] = answer[i] * postAllNumProduct;
        }

        return answer;        
    }
};