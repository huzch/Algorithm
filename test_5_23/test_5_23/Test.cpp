#define _CRT_SECURE_NO_WARNINGS 1

//最长公共前缀
class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.size() == 0) return "";

        string tmp = strs[0];
        for (int i = 1; i < strs.size(); i++)
        {
            int cur = 0;
            while (cur < tmp.size() && cur < strs[i].size() && tmp[cur] == strs[i][cur])
            {
                cur++;
            }
            tmp.resize(cur);
        }
        return tmp;
    }
};

//最长回文子串
class Solution
{
public:
    string longestPalindrome(string s)
    {
        int pos = 0, len = 0;
        for (int i = 0; i < s.size(); i++)
        {
            int left1 = i, right1 = i;//奇数个
            while (left1 >= 0 && right1 < s.size() && s[left1] == s[right1])
            {
                left1--;
                right1++;
            }
            if (right1 - left1 - 1 > len)
            {
                pos = left1 + 1;
                len = right1 - left1 - 1;
            }

            int left2 = i, right2 = i + 1;//偶数个
            while (left2 >= 0 && right2 < s.size() && s[left2] == s[right2])
            {
                left2--;
                right2++;
            }
            if (right2 - left2 - 1 > len)
            {
                pos = left2 + 1;
                len = right2 - left2 - 1;
            }
        }
        return s.substr(pos, len);
    }
};

//二进制求和
class Solution
{
public:
    string addBinary(string a, string b)
    {
        string s;
        int cur1 = a.size() - 1, cur2 = b.size() - 1, carry = 0;
        while (cur1 >= 0 || cur2 >= 0 || carry)
        {
            int n1 = cur1 >= 0 ? a[cur1--] - '0' : 0;
            int n2 = cur2 >= 0 ? b[cur2--] - '0' : 0;
            int n = n1 + n2 + carry;

            s += n % 2 + '0';
            carry = n / 2;
        }

        reverse(s.begin(), s.end());
        return s;
    }
};

//字符串相乘
class Solution
{
public:
    string multiply(string n1, string n2)
    {
        //无进位相乘
        int m = n1.size(), n = n2.size();
        vector<int> tmp(m + n - 1);
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                tmp[i + j] += (n1[i] - '0') * (n2[j] - '0');
            }
        }
        //处理进位
        string s;
        int cur = m + n - 2, carry = 0;
        while (cur >= 0 || carry)
        {
            if (cur >= 0) carry += tmp[cur--];
            s += carry % 10 + '0';
            carry /= 10;
        }
        //去除前导零
        while (s.size() > 1 && s.back() == '0') s.pop_back();
        //逆序
        reverse(s.begin(), s.end());
        return s;
    }
};
