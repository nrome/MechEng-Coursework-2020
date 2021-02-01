//  --------------------
//  C - Traverse doubly-linked list
//  --------------------

#include <stdio.h>
#include <stdlib.h>
#include "traversal.h"

    /*  ---------------- 1 head node is 12 bytes ----------------
        [  head 100  ]     [   head 200    ]     [   head 300   ]
        [ 0 | 1 | 200] <-> [ 100 | 2 | 300 ] <-> [ 200 | 3 | 400]
        --------------------  Node template  --------------------
        --------  [ prv address | data | nxt address ]  ---------  */

    void PrintDLLForward(ListNode* head) { 

        // for (struct ListNode* ptr = head; ptr->next != head + 1; ptr = ptr->next) {
        //     printf("%d\n", ptr->data);
        // }

        //  Start from beginning/position head
        struct ListNode* ptr = head;
            
        //  Print pos 0
        printf("%d \n", ptr->data);
        
        //  Navigate to the end of the list
        while(ptr->next != head) { 
            //  Iterate next items       
            ptr = ptr->next;
            printf("%d \n", ptr->data);
        }

    }

    void PrintDLLReverse(ListNode* head) {

        // for (struct ListNode* ptr = head; ptr->prev != head + 1; ptr = ptr->prev) {
        //     printf("%d\n", ptr->data);
        // }

        //  Start from beginning/position head
        struct ListNode* ptr = head;

        //  Print pos 0
        printf("%d\n", ptr->data);

        //  Navigate to the start of the list
        while (ptr->prev != head) {
            //  Iterate prev items 
            ptr = ptr->prev;
            printf("%d \n", ptr->data);
        }

    }


