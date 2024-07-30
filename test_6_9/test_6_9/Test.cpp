#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;

//����������||
class Solution
{
public:
    int calculate(string s)
    {
        vector<long long> v;
        char op = '+';
        int i = 0, n = s.size();
        while (i < n)
        {
            if (s[i] == ' ') ++i;//����ո�
            else if (s[i] >= '0' && s[i] <= '9')//��������
            {
                long long x = 0;
                while (s[i] >= '0' && s[i] <= '9')
                {
                    x = x * 10 + s[i] - '0';
                    ++i;
                }

                if (op == '+') v.push_back(x);
                else if (op == '-') v.push_back(-x);
                else if (op == '*') v.back() *= x;
                else if (op == '/') v.back() /= x;
            }
            else op = s[i++];//���������
        }

        long long ret = 0;
        for (auto x : v) ret += x;
        return ret;
    }
};

//class Solution
//{
//public:
//    int calculate(string s)
//    {
//        char op = '+';
//        stack<long long> st;
//        for (int i = 0; i < s.size();)
//        {
//            char ch = s[i];
//            if (ch == '+' || ch == '-' || ch == '*' || ch == '/')//���������
//            {
//                op = ch;
//                ++i;
//            }
//            else if (ch == ' ') ++i;//����ո�
//            else//��������
//            {
//                long long x = 0;
//                while (s[i] >= '0' && s[i] <= '9')
//                {
//                    x = x * 10 + s[i] - '0';
//                    ++i;
//                }
//
//                if (op == '+') st.push(x);
//                else if (op == '-') st.push(-x);
//                else if (op == '*')
//                {
//                    long long y = st.top();
//                    st.pop();
//                    st.push(y * x);
//                }
//                else if (op == '/')
//                {
//                    long long y = st.top();
//                    st.pop();
//                    st.push(y / x);
//                }
//            }
//        }
//
//        long long ret = 0;
//        while (!st.empty())
//        {
//            ret += st.top();
//            st.pop();
//        }
//        return ret;
//    }
//};

int main()
{
    string s = "3+2*2";
    cout << Solution().calculate(s) << endl;
    return 0;
}

////�ȽϺ��˸���ַ���
//class Solution
//{
//public:
//    bool backspaceCompare(string s, string t)
//    {
//        string ret1, ret2;
//        for (auto ch : s)
//        {
//            if (ret1.size() && ch == '#') ret1.pop_back();
//            else if (ch != '#') ret1 += ch;
//        }
//
//        for (auto ch : t)
//        {
//            if (ret2.size() && ch == '#') ret2.pop_back();
//            else if (ch != '#') ret2 += ch;
//        }
//
//        return ret1 == ret2;
//    }
//};
//
////ɾ���ַ����е����������ظ���
//class Solution
//{
//public:
//    string removeDuplicates(string s)
//    {
//        string ret;
//        for (auto ch : s)
//        {
//            if (ret.size() != 0 && ret.back() == ch) ret.pop_back();
//            else ret += ch;
//        }
//        return ret;
//    }
//};
//
//class Solution
//{
//public:
//    string removeDuplicates(string s)
//    {
//        stack<char> st;
//        for (auto ch : s)
//        {
//            if (!st.empty() && ch == st.top()) st.pop();
//            else st.push(ch);
//        }
//
//        string ret;
//        while (!st.empty())
//        {
//            ret += st.top();
//            st.pop();
//        }
//        reverse(ret.begin(), ret.end());
//
//        return ret;
//    }
//};