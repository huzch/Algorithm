#define _CRT_SECURE_NO_WARNINGS 1

//两数之和
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hash;//<nums[i], i>
        for (int i = 0; i < nums.size(); i++)
        {
            int n = target - nums[i];
            if (hash.count(n)) return { hash[n], i };
            hash[nums[i]] = i;
        }
        return {};
    }
};

//判断字符重排
class Solution
{
public:
    bool CheckPermutation(string s1, string s2)
    {
        if (s1.size() != s2.size()) return false;//优化

        int hash[26] = { 0 };
        for (auto ch : s1) hash[ch - 'a']++;
        for (auto ch : s2)
        {
            hash[ch - 'a']--;
            if (hash[ch - 'a'] < 0) return false;//优化
        }

        return true;
    }
};

//存在重复元素
class Solution
{
public:
    bool containsDuplicate(vector<int>& nums)
    {
        unordered_set<int> hash;
        for (auto x : nums)
        {
            if (hash.count(x)) return true;
            hash.insert(x);
        }
        return false;
    }
};

//存在重复元素 ||
class Solution
{
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k)
    {
        unordered_map<int, int> hash;//<nums[i], i>
        for (int i = 0; i < nums.size(); i++)
        {
            int x = nums[i];
            if (hash.count(x) && i - hash[x] <= k) return true;
            hash[x] = i;
        }
        return false;
    }
};


//字母异位词分组
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        unordered_map<string, vector<string>> hash;
        for (auto& str : strs)
        {
            string s = str;
            sort(s.begin(), s.end());
            hash[s].push_back(str);
        }

        vector<vector<string>> ret;
        for (auto& kv : hash) ret.push_back(kv.second);
        return ret;
    }
};

