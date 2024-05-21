#define _CRT_SECURE_NO_WARNINGS 1

//两数相加
class Solution
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
    {
        auto Guard = new ListNode(-1), cur = Guard;
        auto cur1 = l1, cur2 = l2;
        int carry = 0;
        while (cur1 || cur2 || carry)
        {
            int n1 = cur1 ? cur1->val : 0;
            int n2 = cur2 ? cur2->val : 0;
            int n = n1 + n2 + carry;
            carry = n / 10;

            auto node = new ListNode(n % 10);
            cur->next = node;

            cur = cur->next;
            if (cur1) cur1 = cur1->next;
            if (cur2) cur2 = cur2->next;
        }

        return Guard->next;
    }
};

//两两交换链表节点
class Solution
{
public:
    ListNode* swapPairs(ListNode* head)
    {
        if (!head || !head->next) return head;//处理边界

        auto Guard = new ListNode(-1), prev = Guard;//虚拟节点
        auto cur = head, next = cur->next;
        while (cur && next)
        {
            //交换节点
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
            //更新节点
            prev = prev->next->next;
            cur = prev->next;
            if (cur) next = cur->next;
        }

        cur = Guard->next;
        delete Guard;
        return cur;
    }
};

//重排链表
class Solution
{
public:
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = nullptr, * cur = head;
        while (cur)
        {
            auto next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    void reorderList(ListNode* head)
    {
        if (!head->next || !head->next->next) return;//处理边界
        //分解链表
        auto slow = head, fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        auto head1 = head, head2 = slow->next;
        slow->next = nullptr;
        //逆置链表
        head2 = reverse(head2);
        //合并链表
        auto Guard = new ListNode(-1), cur = Guard;
        auto cur1 = head1, cur2 = head2;
        int k = 0;
        while (cur1 || cur2)
        {
            if (k % 2 == 0)
            {
                cur->next = cur1;
                cur1 = cur1->next;
            }
            else
            {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
            k++;
        }
        delete Guard;
    }
};

//合并k个升序链表
//方法一：分支归并
class Solution
{
public:
    ListNode* mergeSort(vector<ListNode*>& lists, int begin, int end)
    {
        if (begin == end) return lists[begin];

        int mid = begin + (end - begin) / 2;
        auto cur1 = mergeSort(lists, begin, mid);
        auto cur2 = mergeSort(lists, mid + 1, end);

        auto Guard = new ListNode(-1), cur = Guard;
        while (cur1 && cur2)
        {
            if (cur1->val < cur2->val)
            {
                cur->next = cur1;
                cur1 = cur1->next;
            }
            else
            {
                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
        }

        if (cur1) cur->next = cur1;
        if (cur2) cur->next = cur2;

        cur = Guard->next;
        delete Guard;
        return cur;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.size() == 0) return nullptr;
        return mergeSort(lists, 0, lists.size() - 1);
    }
};
//方法二：优先级队列：建小堆
class Solution
{
    struct cmp
    {
        bool operator()(const ListNode* l1, const ListNode* l2)
        {
            return l1->val > l2->val;
        }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        priority_queue<ListNode*, deque<ListNode*>, cmp> pq;//建小堆

        for (auto x : lists) if (x) pq.push(x);//所有链表头结点入堆

        auto Guard = new ListNode(-1), head = Guard;
        while (!pq.empty())
        {
            //弹出堆顶指针，并压入下一指针
            auto cur = pq.top();
            pq.pop();
            if (cur->next) pq.push(cur->next);
            //链接节点
            head->next = cur;
            head = head->next;
        }

        head = Guard->next;
        delete Guard;
        return head;
    }
};

//k个一组翻转链表
class Solution
{
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        int size = 0;
        auto tail = head;
        while (tail)
        {
            ++size;
            tail = tail->next;
        }

        int n = size / k;//求出需要逆序多少组
        auto Guard = new ListNode(-1);//虚拟节点
        Guard->next = head;
        auto Prev = Guard, Cur = head;
        while (n--)
        {
            //逆置k个节点
            auto prev = Prev, cur = Cur;
            for (int i = 0; i < k; i++)
            {
                auto next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            //链接前后链表
            Cur->next = cur;
            Prev->next = prev;
            //更新节点
            Prev = Cur;
            Cur = cur;
        }

        Cur = Guard->next;
        delete Guard;
        return Cur;
    }
};