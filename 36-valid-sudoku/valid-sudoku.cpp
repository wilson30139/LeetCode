class Solution {
public:
    vector<bool> ResetNums () {
        vector<bool> nums;
        for (int i = 1; i <= 9; i++)
            nums.push_back(false);
        return nums;
    }

    bool IsMeetRuleOne (vector<vector<char>> board) {
        for (int row = 0; row < 9; row++) {
            vector<bool> nums = ResetNums();
            for (int col = 0; col < 9; col++) {
                if (board[row][col] != '.') {
                    if (nums[board[row][col] - '0' - 1])
                        return false;
                    else
                        nums[board[row][col] - '0' - 1] = true;
                }
            }
        }
        return true;
    }

    bool IsMeetRuleTwo (vector<vector<char>> board) {
        for (int col = 0; col < 9; col++) {
            vector<bool> nums = ResetNums();
            for (int row = 0; row < 9; row++) {
                if (board[row][col] != '.') {
                    if (nums[board[row][col] - '0' - 1])
                        return false;
                    else
                        nums[board[row][col] - '0' - 1] = true;
                }
            }
        }
        return true;
    }

    bool IsMeetRuleThree (vector<vector<char>> board) {
        for (int rowForSubBox = 0; rowForSubBox < 3; rowForSubBox++) {
            for (int colForSubBox = 0; colForSubBox < 3; colForSubBox++) {
                vector<bool> nums = ResetNums();
                for (int row = 0; row < 3; row++) {
                    for (int col = 0; col < 3; col++) {
                        if (board[rowForSubBox * 3 + row][colForSubBox * 3 + col] != '.') {
                            if (nums[board[rowForSubBox * 3 + row][colForSubBox * 3 + col] - '0' - 1])
                                return false;
                            else
                                nums[board[rowForSubBox * 3 + row][colForSubBox * 3 + col] - '0' - 1] = true;
                        }
                    }
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        if (!IsMeetRuleOne(board))
            return false;

        if (!IsMeetRuleTwo(board))
            return false;

        if (!IsMeetRuleThree(board))
            return false;

        return true;
    }
};