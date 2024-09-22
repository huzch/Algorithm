#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped)
    {
        vector<int> st;
        int i = 0, j = 0, n = pushed.size();

        while (i < n)
        {
            st.push_back(pushed[i++]);
            while (st.size() && st.back() == popped[j])
            {
                st.pop_back();
                ++j;
            }
        }
        return st.size() == 0;
    }
};

int main()
{
    vector<int> pushed = { 1,2,3,4,5 };
    vector<int> popped = { 4,3,5,1,2 };
    bool ret = Solution().validateStackSequences(pushed, popped);
    return 0;
}

//class Solution
//{
//public:
//    string decodeString(string s)
//    {
//        string ret;
//        vector<int> nums;
//        int i = 0, n = s.size();
//        while (i < n)
//        {
//            char ch = s[i];
//            if (isdigit(ch))
//            {
//                long x = 0;
//                while (isdigit(s[i]))
//                {
//                    x = x * 10 + s[i] - '0';
//                    ++i;
//                }
//                nums.push_back(x);
//            }
//            else
//            {
//                if (ch == ']')
//                {
//                    int j = ret.size() - 1;
//                    for (; j >= 0; --j)
//                    {
//                        if (ret[j] == '[') break;
//                    }
//                    string tmp = ret.substr(j + 1);
//                    ret.erase(j);
//                    int k = nums.back();
//                    nums.pop_back();
//                    while (k--) ret += tmp;
//                }
//                else ret += ch;// [ ºÍ ×Ö·û
//                ++i;
//            }
//        }
//        return ret;
//    }
//};
//
//int main()
//{
//    string s = "100[leetcode]";
//    string ret = Solution().decodeString(s);
//    return 0;
//}

//class Solution
//{
//public:
//    int calculate(string s)
//    {
//        unordered_map<char, int> hash = { {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2} };
//        vector<int> nums;
//        vector<char> ops;
//        int i = 0, n = s.size();
//        while (i < n)
//        {
//            char ch = s[i];
//            if (ch == ' ') ++i;
//            else if (ch == '(')
//            {
//                ops.push_back(ch);
//                if (!isdigit(s[i + 1])) nums.push_back(0);
//                ++i;
//            }
//            else if (ch == ')')
//            {
//                while (ops.size())
//                {
//                    char op = ops.back();
//                    ops.pop_back();
//                    if (op == '(') break;
//                    else calc(nums, op);
//                }
//                ++i;
//            }
//            else if (isdigit(ch))
//            {
//                long x = 0;
//                while (isdigit(s[i]))
//                {
//                    x = x * 10 + s[i] - '0';
//                    ++i;
//                }
//                nums.push_back(x);
//            }
//            else
//            {
//                if (nums.size() == 0) nums.push_back(0);
//
//                while (ops.size())
//                {
//                    char op = ops.back();
//                    if (op == '(') break;
//                    if (hash[op] >= hash[ch])
//                    {
//                        calc(nums, op);
//                        ops.pop_back();
//                    }
//                    else break;
//                }
//                ops.push_back(ch);
//                ++i;
//            }
//        }
//
//        while (ops.size())
//        {
//            char op = ops.back();
//            ops.pop_back();
//            calc(nums, op);
//        }
//        return nums.back();
//    }
//
//    void calc(vector<int>& nums, char op)
//    {
//        if (nums.size() < 2) return;
//        int b = nums.back(); nums.pop_back();
//        int a = nums.back(); nums.pop_back();
//        int ret = 0;
//        if (op == '+') ret = a + b;
//        else if (op == '-') ret = a - b;
//        else if (op == '*') ret = a * b;
//        else if (op == '/') ret = a / b;
//        nums.push_back(ret);
//    }
//};
//
//int main()
//{
//    //int ret = Solution().calculate("1-(     -2)");
//    //int ret = Solution().calculate("(7)-(0)+(4)");
//    /*int ret = Solution().calculate("3+2*2");*/
//    int ret = Solution().calculate("(3+18/6)*2");
//    cout << ret << endl;
//    return 0;
//}