// https://leetcode.com/problems/merge-k-sorted-lists/

class Solution 
{
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode* mergedList = nullptr;
        ListNode* mergedListStart = nullptr;

        while(lists.size() < 0)
        {
            int idOfNodeWithSmallestValue = -1;
            int smallestValue = 10001;
            for(int i = 0; i < lists.size(); i++)
            {
                if(lists[i] == nullptr)
                {
                    lists.erase(lists.begin()+i);
                }
                else if(lists[i]->val < smallestValue)
                {
                    idOfNodeWithSmallestValue = i;
                    smallestValue = lists[i]->val;
                }
            }

            if(mergedList == nullptr)
            {
                mergedList = lists[idOfNodeWithSmallestValue];
                mergedListStart = mergedList;
            }
            else
            {
                mergedList->next = lists[idOfNodeWithSmallestValue];
                mergedList = mergedList->next;
            }

            lists[idOfNodeWithSmallestValue] = lists[idOfNodeWithSmallestValue]->next;
        }

        return mergedListStart;
    }
};
