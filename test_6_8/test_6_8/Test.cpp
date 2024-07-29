#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<unordered_map>
#include<functional>
#include<algorithm>
using namespace std;

//逆波兰表达式
class Solution
{
public:
    int evalRPN(vector<string>& tokens)
    {
        unordered_map<string, function<int(int, int)>> cmdOP =
        {
            {"+", [](int x, int y) {return x + y; }},
            {"-", [](int x, int y) {return x - y; }},
            {"*", [](int x, int y) {return x * y; }},
            {"/", [](int x, int y) {return x / y; }}
        };

        stack<int> st;
        for (auto& s : tokens)
        {
            if (cmdOP.count(s))
            {
                int right = st.top();
                st.pop();
                int left = st.top();
                st.pop();

                st.push(cmdOP[s](left, right));
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};

//有效的括号
class Solution
{
public:
    bool isValid(string s)
    {
        int n = s.size();
        if (n % 2 != 0) return false;

        stack<char> st;
        for (auto ch : s)
        {
            if (ch == '(' || ch == '{' || ch == '[')
            {
                st.push(ch);
            }
            else if (!st.empty())
            {
                char left = st.top();
                st.pop();
                char right = ch;

                if ((left == '(' && right != ')')
                    || (left == '{' && right != '}')
                    || (left == '[' && right != ']'))
                {
                    return false;
                }
            }
            else return false;
        }

        return st.empty();
    }
};

//有效的数独
class Solution
{
    bool row[9][10];
    bool col[9][10];
    bool block[3][3][10];
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int m = board.size(), n = board[0].size();
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] != '.')
                {
                    int x = board[i][j] - '0';
                    if (!row[i][x] && !col[j][x] && !block[i / 3][j / 3][x])
                    {
                        row[i][x] = col[j][x] = block[i / 3][j / 3][x] = true;
                    }
                    else return false;
                }
            }
        }
        return true;
    }
};

//合并两个有序数组
class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int cur1 = m - 1, cur2 = n - 1, k = m + n - 1;
        while (cur1 >= 0 && cur2 >= 0)
        {
            if (nums1[cur1] > nums2[cur2])
            {
                nums1[k--] = nums1[cur1--];
            }
            else
            {
                nums1[k--] = nums2[cur2--];
            }
        }

        while (cur1 >= 0) nums1[k--] = nums1[cur1--];
        while (cur2 >= 0) nums1[k--] = nums2[cur2--];
    }
};

//N皇后
//vector<vector<vector<int>>> ret;
//vector<vector<int>> board;
//bool row[10];
//bool col[10];
//bool diag1[20];
//bool diag2[20];
//int n = 8;
//
//void dfs(int j)
//{
//    if (j == n)
//    {
//        ret.push_back(board);
//        return;
//    }
//
//    for (int i = 0; i < n; ++i)
//    {
//        if (!row[i] && !diag1[i - j + n] && !diag2[i + j])
//        {
//            board[i][j] = 1;
//            row[i] = diag1[i - j + n] = diag2[i + j] = true;
//            dfs(j + 1);
//            row[i] = diag1[i - j + n] = diag2[i + j] = false;
//            board[i][j] = 0;
//        }
//    }
//}
//
////void dfs(int i)
////{
////    if (i == n)
////    {
////        ret.push_back(board);
////        return;
////    }
////
////    for (int j = 0; j < n; ++j)
////    {
////        if (!col[j] && !diag1[i - j + n] && !diag2[i + j])
////        {
////            board[i][j] = 1;
////            col[j] = diag1[i - j + n] = diag2[i + j] = true;
////            dfs(i + 1);
////            col[j] = diag1[i - j + n] = diag2[i + j] = false;
////            board[i][j] = 0;
////        }
////    }
////}
//
//int main()
//{
//    board.resize(n, vector<int>(n, 0));
//    dfs(0);
//
//    for (auto& vv : ret)
//    {
//        for (auto& v : vv)
//        {
//            for (auto x : v)
//            {
//                cout << x << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
//    return 0;
//}

//vector<vector<int>> ret;
//vector<int> path;
//bool check[6];
//int n;
//
//void dfs(int pos)
//{
//    if (pos == n)
//    {
//        ret.push_back(path);
//        return;
//    }
//
//    for (int i = 0; i <= n; ++i)
//    {
//        if (!check[i])
//        {
//            path.push_back(i);
//            check[i] = true;
//            dfs(pos + 1);
//            check[i] = false;
//            path.pop_back();
//        }
//    }
//}
//
//int main()
//{
//    cin >> n;
//
//    dfs(0);
//
//    for (auto& v : ret)
//    {
//        for (auto x : v)
//        {
//            cout << x << " ";
//        }
//        cout << endl;
//    }
//    return 0;
//}

////插入排序
//void InsertSort(vector<int>& nums)
//{
//    int n = nums.size();
//    for (int i = 1; i < n; ++i)
//    {
//        int end = i - 1;
//        int tmp = nums[i];
//
//        while (end >= 0)
//        {
//            if (tmp < nums[end])
//            {
//                nums[end + 1] = nums[end];
//                --end;
//            }
//            else break;
//        }
//
//        nums[end + 1] = tmp;
//    }
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> nums[i];
//    }
//
//    InsertSort(nums);
//
//    for (auto x : nums)
//    {
//        cout << x << " ";
//    }
//    return 0;
//}
//
////希尔排序
//void ShellSort(vector<int>& nums)
//{
//    int n = nums.size(), gap = n;
//    while (gap > 1)
//    {
//        gap = gap / 3 + 1;
//
//        for (int i = gap; i < n; ++i)
//        {
//            int end = i - gap;
//            int tmp = nums[i];
//
//            while (end >= 0)
//            {
//                if (tmp < nums[end])
//                {
//                    nums[end + gap] = nums[end];
//                    end -= gap;
//                }
//                else break;
//            }
//
//            nums[end + gap] = tmp;
//        }
//    }
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> nums[i];
//    }
//
//    ShellSort(nums);
//
//    for (auto x : nums)
//    {
//        cout << x << " ";
//    }
//    return 0;
//}
//
////选择排序
//void SelectSort(vector<int>& nums)
//{
//    int n = nums.size();
//    for (int i = n - 1; i > 0; --i)
//    {
//        int pos = 0;
//        for (int j = 0; j <= i; ++j)
//        {
//            if (nums[pos] < nums[j])
//            {
//                pos = j;
//            }
//        }
//        swap(nums[pos], nums[i]);
//    }
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> nums[i];
//    }
//
//    SelectSort(nums);
//
//    for (auto x : nums)
//    {
//        cout << x << " ";
//    }
//    return 0;
//}
//
////堆排序
//void AdjustDown(vector<int>& nums, int parent, int n)
//{
//    int child = parent * 2 + 1;
//
//    while (child < n)
//    {
//        if (child + 1 < n && nums[child] < nums[child + 1])
//        {
//            ++child;
//        }
//
//        if (nums[parent] < nums[child])
//        {
//            swap(nums[parent], nums[child]);
//            parent = child;
//            child = parent * 2 + 1;
//        }
//        else break;
//    }
//}
//
//void HeapSort(vector<int>& nums)
//{
//    int n = nums.size();
//    for (int i = (n - 1 - 1) / 2; i >= 0; --i)
//    {
//        AdjustDown(nums, i, n);
//    }
//
//    int end = n - 1;
//    while (end >= 0)
//    {
//        swap(nums[0], nums[end]);
//        AdjustDown(nums, 0, end);
//        --end;
//    }
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> nums[i];
//    }
//
//    HeapSort(nums);
//
//    for (auto x : nums)
//    {
//        cout << x << " ";
//    }
//    return 0;
//}
//
////冒泡排序
//void BubbleSort(vector<int>& nums)
//{
//    int n = nums.size();
//    for (int i = n - 1; i > 0; --i)
//    {
//        bool exchange = false;
//        for (int j = 0; j < i; ++j)
//        {
//            if (nums[j] > nums[j + 1])
//            {
//                swap(nums[j], nums[j + 1]);
//                exchange = true;
//            }
//        }
//        if (!exchange) break;
//    }
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> nums[i];
//    }
//
//    BubbleSort(nums);
//
//    for (auto x : nums)
//    {
//        cout << x << " ";
//    }
//    return 0;
//}
//
////快速排序
//int GetKey(vector<int>& v, int begin, int end)
//{
//    int i = begin + rand() % (end - begin + 1);
//    return v[i];
//}
//
//void QuickSort(vector<int>& v, int begin, int end)
//{
//    if (begin >= end) return;
//
//    int key = GetKey(v, begin, end);
//
//    int left = begin, cur = begin, right = end;
//    while (cur <= right)
//    {
//        if (v[cur] < key) swap(v[left++], v[cur++]);
//        else if (v[cur] == key) ++cur;
//        else swap(v[right--], v[cur]);
//    }
//
//    QuickSort(v, begin, left - 1);
//    QuickSort(v, right + 1, end);
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    vector<int> v(n);
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> v[i];
//    }
//
//    srand(0);
//    QuickSort(v, 0, n - 1);
//
//    for (auto x : v)
//    {
//        cout << x;
//    }
//    return 0;
//}
//
////归并排序
//void MergeSort(vector<int>& nums, int begin, int end, vector<int>& tmp)
//{
//    if (begin >= end) return;
//
//    int mid = begin + (end - begin) / 2;
//    MergeSort(nums, begin, mid, tmp);
//    MergeSort(nums, mid + 1, end, tmp);
//
//    int cur1 = begin, cur2 = mid + 1, k = begin;
//    while (cur1 <= mid && cur2 <= end)
//    {
//        if (nums[cur1] < nums[cur2])
//        {
//            tmp[k++] = nums[cur1++];
//        }
//        else
//        {
//            tmp[k++] = nums[cur2++];
//        }
//    }
//
//    while (cur1 <= mid) tmp[k++] = nums[cur1++];
//    while (cur2 <= end) tmp[k++] = nums[cur2++];
//    for (int i = begin; i <= end; ++i) nums[i] = tmp[i];
//}
//
//int main()
//{
//    int n;
//    cin >> n;
//
//    vector<int> nums(n);
//    for (int i = 0; i < n; ++i)
//    {
//        cin >> nums[i];
//    }
//
//    vector<int> tmp(n);
//    MergeSort(nums, 0, n - 1, tmp);
//
//    for (auto x : nums)
//    {
//        cout << x << " ";
//    }
//    return 0;
//}