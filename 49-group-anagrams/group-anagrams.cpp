class Solution {
public:
    static bool Compare (pair<string, string> a, pair<string, string> b) {
        return a.second < b.second;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.size() == 1) {
            vector<vector<string>> answers;
            vector<string> answer;
            answer.push_back(strs[0]);
            answers.push_back(answer);
            return answers;
        }

        vector<string> tempStrs = strs;
        for (int i = 0; i < tempStrs.size(); i++)
            sort(tempStrs[i].begin(), tempStrs[i].end());
        
        vector<pair<string, string>> strTempStrs;
        for (int i = 0; i < strs.size(); i++) {
            pair<string, string> strTempStr;
            strTempStr.first = strs[i];
            strTempStr.second = tempStrs[i];
            strTempStrs.push_back(strTempStr);
        }

        sort(strTempStrs.begin(), strTempStrs.end(), Compare);

        vector<vector<string>> answers;
        int start = 0;
        for (int i = 1; i < strTempStrs.size(); i++) {
            if (i == strTempStrs.size() - 1) {
                if (strTempStrs[i - 1].second == strTempStrs[i].second) {
                    vector<string> answer;
                    for (int j = start; j <= i; j++)
                        answer.push_back(strTempStrs[j].first);
                    answers.push_back(answer);
                } else {
                    vector<string> answer;
                    for (int j = start; j < i; j++)
                        answer.push_back(strTempStrs[j].first);
                    answers.push_back(answer);

                    vector<string> answer2;
                    answer2.push_back(strTempStrs[i].first);
                    answers.push_back(answer2);
                }
            } else {
                if (strTempStrs[i - 1].second != strTempStrs[i].second) {
                    vector<string> answer;
                    for (int j = start; j < i; j++)
                        answer.push_back(strTempStrs[j].first);
                    answers.push_back(answer);
                    start = i;
                }
            }
        }

        return answers;
    }
};