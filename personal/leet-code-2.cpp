class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int newNum1 = 0;
        int newNum2 = 0;
        int totalNum = 0;
        int count = 0;
        int finalList[100];
        int times;

        for(int i = l1.size(); i != 0; i--) {
            times = pow(10, i);
            newNum1 += l1[i] * times;
        }

        for(int i = l2.size(); i != 0; i--) {
            times = pow(10, i);
            newNum2 += l2[i] * times;
        }

        totalNum = newNum1 + newNum2;

        while(totalNum != 0) {
            finalList[count] = totalNum % 10
        }
        
    }
};