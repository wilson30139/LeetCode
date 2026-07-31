class Solution {
public:
    long long ConvertStrToInt (string numStr) {
        long long num = 0;
        bool isNegativeNum = false;
        for (int i = 0; i < numStr.length(); i++) {
            if (numStr[i] == '-')
                isNegativeNum = true;
            else {
                num = num * 10;
                num = num + numStr[i] - '0';
            }
        }
        if (isNegativeNum)
            num = num * (-1);
        return num;
    }

    string ConvertStrToInt (long long num) {
        string numStr = "";
        bool isNegativeNum = false;
        if (num < 0) {
            isNegativeNum = true;
            num = num * (-1);
        }
        while (num != 0) {
            numStr = to_string(num % 10) + numStr;
            num = num / 10;
        }
        if (isNegativeNum)
            numStr = "-" + numStr;
        return numStr;
    }

    long long evalRPN(vector<string>& tokens) {
        stack<string> st;
        long long num, num2;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                num2 = ConvertStrToInt(st.top());
                st.pop();

                num = ConvertStrToInt(st.top());
                st.pop();

                st.push(ConvertStrToInt(num + num2));
            } else if (tokens[i] == "-") {
                num2 = ConvertStrToInt(st.top());
                st.pop();

                num = ConvertStrToInt(st.top());
                st.pop();

                st.push(ConvertStrToInt(num - num2));
            } else if (tokens[i] == "*") {
                num2 = ConvertStrToInt(st.top());
                st.pop();

                num = ConvertStrToInt(st.top());
                st.pop();

                st.push(ConvertStrToInt(num * num2));
            } else if (tokens[i] == "/") {
                num2 = ConvertStrToInt(st.top());
                st.pop();

                num = ConvertStrToInt(st.top());
                st.pop();

                st.push(ConvertStrToInt(num / num2));
            }
            else
                st.push(tokens[i]);
        }
        return ConvertStrToInt(st.top());
    }
};