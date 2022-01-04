#include <stack>
#include <vector>
#include <string>

using namespace std;

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2);
};

class RegularExpression
{
public:
    bool isMatch(string s, string p);
};

class ValidParentheses
{
public:
    bool isValid(string s);
};

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class MergeKSortedLists
{
public:
    ListNode *merge(vector<ListNode *> &lists);

private:
    void insertNewListToProcess(vector<ListNode *> &processList, ListNode *list);
};
