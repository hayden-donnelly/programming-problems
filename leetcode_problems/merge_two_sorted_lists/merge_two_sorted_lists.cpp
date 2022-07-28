class Solution 
{
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {   
        ListNode* mergedList = nullptr;
        ListNode* mergedListStart = nullptr;

        if(list1 != nullptr && list2 != nullptr)
        {
            if(list1->val < list2->val)
            {
                mergedList = list1;
                list1 = list1->next;
            }
            else
            {
                mergedList = list2;
                list2 = list2->next;
            }

            mergedListStart = mergedList;

            while(list1 != nullptr && list2 != nullptr)
            {
                if(list1->val < list2->val)
                {
                    mergedList->next = list1;
                    mergedList = mergedList->next;
                    list1 = list1->next;
                }
                else
                {
                    mergedList->next = list2;
                    mergedList = mergedList->next;
                    list2 = list2->next;
                }
            }

            if(list1 == nullptr)
            {
                mergedList->next = list2;
            }
            else
            {
                mergedList->next = list1;
            }

            return mergedListStart;
        }
        else if(list1 == nullptr)
        {
            return list2;
        }
        else
        {
            return list1;
        }
    }
};