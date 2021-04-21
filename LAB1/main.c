#include <stdlib.h>
#include <stdio.h>
#include "list.h"
#include "stacks.h"
#include "queue.h"
#include "test.h"


int main() {
    //------------------------------ Use this to create and insert a list for exercise 2. ---------------------------//

    List* L1 = createLinkedList();
    List* L2 = createLinkedList(); 

    insertIntoL1Test(L1);
    insertIntoL2Test(L2);

    //------------------------------ Testing if the isEmpty function works ---------------------------//
    
    //isEmptyTest(L1);

    //------------------------------Testing if the insert function works ---------------------------//
    
    //insertTest(L1, 5);

   //------------------------------Testing if the search function works ---------------------------//
    
    //searchTest(L1, 5);

   //------------------------------Testing if the delete function works ---------------------------//
   
    //deleteTest(L1, 5);

    //------------------------------Testing if the maximum & minimum function for List 1 ---------------------------//
    
    //maximumAndMinTest(L1, 10, 5);
    //maximumAndMinTest(L2, 9, 1);

    // ------------------------------Testing if the successor & predecessor function for List 1 & List 2 works ---------------------------//
    
    //successorPredecessorTest(L1, 5, 7, 3);
    //successorPredecessorTest(L2, 9, -1, 6);

  // ------------------------------Testing what the key is of the predecessor in L2 of the maximum of L1  ---------------------------//
    
    //predecessorOfMaximumTest(L1, L2, 9);
    //predecessorOfMaximumTest(L2, L1, 8);

    // ------------------------------Testing the stack ny using bogus personal number  ---------------------------//

    //pushPopStackTest();

     // ------------------------------Testing the queue ny using bogus personal number  ---------------------------//
  
    //enqueueDequeueQueue();

    //Stack* S1 = createStack();
    //push(S1, 2);
    //isStackEmptyTest(S1);

    //Stack* S2 = createStack();
    //testQueueWithStack(S1, S2, 5,2,7);
    //dequeue2(S2);
    //free(S2);
     free(S1);
     freeList(L1);
     free(L1);
     freeList(L2);
     free(L2);
     
}

