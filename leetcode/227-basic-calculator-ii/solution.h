#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct Token {
    long number;
    char op;
    bool isNumber;
};

class Solution {
   public:
    vector<Token> parseInput(string s) {
        vector<Token> tokens;
        int index = 0;
        while (index < s.size()) {
            char ch = s[index];
            long num = 0;
            if (isDigit(ch)) {
                while (index < s.size() && isDigit(s[index])) {
                    num = num * 10 + s[index] - '0';
                    index++;
                }
                tokens.push_back(Token{
                    .number = num,
                    .op = 0,
                    .isNumber = true,
                });
            } else {
                if (ch != ' ') {
                    tokens.push_back(Token{
                        .number = -1,
                        .op = ch,
                        .isNumber = false,
                    });
                }
                index++;
            }
        }
        return tokens;
    }

    vector<Token> convertToPostfix(const vector<Token>& tokens) {
        vector<Token> output;
        stack<Token> ops;
        for (const auto token : tokens) {
            if (token.isNumber) {
                output.push_back(token);
            } else {
                while (!ops.empty() && isHigherPrecedence(ops.top().op, token.op)) {
                    output.push_back(ops.top());
                    ops.pop();
                }
                ops.push(token);
            }
        }
        while (!ops.empty()) {
            output.push_back(ops.top());
            ops.pop();
        }
        return output;
    }

    int calculate(string s) {
        auto tokens = convertToPostfix(parseInput(s));
        stack<long> st;
        for (const auto token : tokens) {
            if (token.isNumber) {
                st.push(token.number);
            } else {
                int num1 = st.top();
                st.pop();
                int num2 = st.top();
                st.pop();
                long result = 0;
                switch (token.op) {
                    case '+':
                        result = num2 + num1;
                        break;
                    case '-':
                        result = num2 - num1;
                        break;
                    case '*':
                        result = num2 * num1;
                        break;
                    case '/':
                        result = num2 / num1;
                        break;
                }
                st.push(result);
            }
        }

        return (int)st.top();
    }

    bool isDigit(char ch) { return ch >= '0' && ch <= '9'; }
    bool isHigherPrecedence(char op1, char op2) {
        bool res = (op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-');
        printf("%c higher than %c ? %s\n", op1, op2, (res ? "true" : "false"));
        return res;
    }
};

int main() {
    Solution s;
    cout << "Result = " << s.calculate("1-1+1");
    return 0;
}