#include "../include/algorithm.hpp"

using namespace std;

ListNode *MergeKSortedLists::merge(vector<ListNode *> &lists)
{
    vector<ListNode *> processList;

    // Initial process list to track current node of all the list in ascent order
    for (vector<ListNode *>::iterator iter = lists.begin(); iter != lists.end(); iter++)
    {
        if (*iter != nullptr)
        {
            insertNewListToProcess(processList, *iter);
        }
    }

    ListNode *result = nullptr, **currentResult = &result;

    // Continue process if there are some lists have items
    while (processList.size() != 0)
    {
        // First item in the process list has the smallest value among all the lists
        ListNode *smallestValNode = *processList.begin();

        // Clone from current node and append it to result list
        *currentResult = new ListNode(smallestValNode->val);
        currentResult = &((*currentResult)->next);

        // Remove the list which has the smallest value
        processList.erase(processList.begin());

        // If this list has more items, inert it to the process list
        if (smallestValNode->next != nullptr)
        {
            insertNewListToProcess(processList, smallestValNode->next);
        }
    }

    return result;
}

/*
 * Compare current node value of the list and insert it to the process list
 * Process list constains the node value in ascent order
 * It means the first item has the smallest value
 */
void MergeKSortedLists::insertNewListToProcess(vector<ListNode *> &processList, ListNode *list)
{
    vector<ListNode *>::iterator iter = processList.begin();

    for (; iter != processList.end(); iter++)
    {
        if (list->val < (*iter)->val)
        {
            break;
        }
    }

    processList.insert(iter, list);
}