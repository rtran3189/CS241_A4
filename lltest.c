/*  Name: Richard Tran
 *  Date: July 11, 2019
 *  Class: CS241L SUM 2019
 *
 *  This file is the test file for the linked list. It contains
 *  test cases that tests the core functionality of ll.c. The
 *  DEBUG value can be changed in order to see a verbose output
 *  of all tests. Set the appropriate value and re-compile.
 */
#include <stdio.h>
#include <stdlib.h>
#include "ll.h"
#include "help.h"

#define ASSIGNMENT_NUM 4
/* Change this to 1 if you want to see debug print statements. */
#define DEBUG 0

/* This tests if the list can correctly indicate if it is empty. */
void testEmptyList()
{
  struct ListNode* head = NULL;

  if(DEBUG)
  {
    printf("\n---- Test Empty List ---- \n");
    printf("Printing empty list: ");
    printList(head);
  }
  
  if (listLength(head) == 0)
  {
    printf("OK - Empty List\n");
  }
  else
  {
    printf("FAIL - Empty List\n");
  }

  freeList(head);
}

/* This tests if items can be inserted into the list. */
void testInsertList()
{
  struct ListNode* head = NULL;
  head = insertBeginning(head, "Test One");

  if(DEBUG)
  {
    printf("\n---- Test Insert List ---- \n");
    printf("Inserted 'Test One' into list.\n");
    printf("Printing list: ");
    printList(head);
    printf("List Length: %d\n", listLength(head));
  }
  if ((listLength(head)) > 0)
  {
    printf("OK - Insert List\n");
  }
  else
  {
    printf("FAIL - Insert List\n");
  }
  freeList(head);
}

/* This tests if items can be removed from the list correctly. */
void testRemoveFromList()
{
  struct ListNode* head = NULL;
  head = insertBeginning(head, "TestFour");
  head = insertBeginning(head, "TestThree");
  head = insertBeginning(head, "TestTwo");
  head = insertBeginning(head, "TestOne");
  
  if(DEBUG)
  {
    printf("\n---- Test Remove from List ---- \n");
    printf("Printing list BEFORE removal: ");
    printList(head);
    printf("List Length: %d\n", listLength(head));

    printf("Removing item 'TestThree'\n");
    removeItem(&head, "TestThree");

    printf("Printing list AFTER removal: ");
    printList(head);
    printf("List Length: %d\n", listLength(head));
  }
  else
  {
    removeItem(&head, "TestThree");
  }

  if ((listLength(head)) == 3)
  {
    printf("OK - Remove from List\n");
  }
  else
  {
    printf("FAIL - Remove from List\n");
  }
  freeList(head);
}

/* This tests if multiple items can be removed from the list. */
void testRemoveMultipleFromList()
{
  struct ListNode* head = NULL;
  head = insertBeginning(head, "TestFour");
  head = insertBeginning(head, "TestThree");
  head = insertBeginning(head, "TestTwo");
  head = insertBeginning(head, "TestOne");
  
  if(DEBUG)
  {
    printf("\n---- Test Remove Multiple Items from List ---- \n");
    printf("Printing list BEFORE removal: ");
    printList(head);
    printf("List Length: %d\n", listLength(head));

    printf("Removing item 'TestFour'\n");
    removeItem(&head, "TestFour");
    printf("Removing item 'TestThree'\n");
    removeItem(&head, "TestThree");
    printf("Removing item 'TestTwo'\n");
    removeItem(&head, "TestTwo");

    printf("Printing list AFTER removal: ");
    printList(head);
    printf("List Length: %d\n", listLength(head));
  }
  else
  {
    removeItem(&head, "TestFour");
    removeItem(&head, "TestThree");
    removeItem(&head, "TestTwo");
  }

  if ((listLength(head)) == 1)
  {
    printf("OK - Remove Multiple Items from List\n");
  }
  else
  {
    printf("FAIL - Remove Multiple Items from List\n");
  }
  freeList(head);
}

/* This tests if printing the list can be done. This one requires
  visual inspection to determine if it is correct since there is no
  way to test if output is correct. */
void testPrintList()
{
  struct ListNode* head = NULL;

  head = insertBeginning(head, "TestFour");
  head = insertBeginning(head, "TestThree");
  head = insertBeginning(head, "TestTwo");
  head = insertBeginning(head, "TestOne");

  if(DEBUG)
  {
    printf("\n---- Test Print List ---- \n");
  }

  printf("OK? - Print List: ");
  printList(head);
  freeList(head);
}

/* This tests if the index of an item can be retrieved given the
  item's word. */
void testGetIndex()
{
  struct ListNode* head = NULL;
  head = insertBeginning(head, "TestOne");
  head = insertBeginning(head, "TestTwo");
  head = insertBeginning(head, "TestThree");

  if(DEBUG)
  {
    printf("\n---- Test Get Index ---- \n");
    printf("Printing list with indexes: ");
    printList(head);
    printf("Index of 'TestOne' is: %d\n", getIndex(head, "TestOne") );
  }

  if(getIndex(head, "TestOne") == 2)
  {
    printf("OK - Get Index\n");
  }
  else
  {
    printf("FAIL - Get Index\n");
  }
  freeList(head);
}

/* This tests if an item's index is updated after the removal of an item
   that was placed before it. */
void testGetIndexAfterRemoval()
{
  struct ListNode* head = NULL;
  head = insertBeginning(head, "Test One");
  head = insertBeginning(head, "Test Two");
  head = insertBeginning(head, "Test Three");

  if(DEBUG)
  {
    printf("\n---- Test Get Index After Removal ---- \n");
    printf("Printing list BEFORE removal: ");
    printList(head);
    printf("List Length: %d\n", listLength(head));

    printf("Removing item 'Test Two'\n");
    removeItem(&head, "Test Two");

    printf("Printing list AFTER removal: ");
    printList(head);
    printf("List Length: %d\n", listLength(head));
    printf("Index of item 'Test One': %d\n", getIndex(head, "Test One"));
  }
  else
  {
    removeItem(&head, "Test Two");
  }
  if(getIndex(head, "Test One") == 1)
  {
    printf("OK - Get Index After Removal\n");
  }
  else
  {
    printf("FAIL - Get Index After Removal\n");
  }
  freeList(head);
}

/* This tests if an item can be removed by its index instead of its word. */
void testRemoveByIndex()
{
  struct ListNode* head = NULL;
  head = insertBeginning(head, "TestFour");
  head = insertBeginning(head, "TestThree");
  head = insertBeginning(head, "TestTwo");
  head = insertBeginning(head, "TestOne");
  if(DEBUG)
  {
    printf("\n---- Test Remove Item by Index ---- \n");
    printf("Printing list BEFORE removal: ");
    printList(head);
    printf("List Length: %d\n", listLength(head));

    printf("Removing item at index 3\n");
    removeItemByIndex(&head, 3);
    printf("Removing item at index 2\n");
    removeItemByIndex(&head, 2);
    printf("Removing item at index 1\n");
    removeItemByIndex(&head, 1);

    printf("Printing list AFTER removal: ");
    printList(head);
    printf("List Length: %d\n", listLength(head));
  }
  else
  {
    removeItemByIndex(&head, 3);
    removeItemByIndex(&head, 2);
    removeItemByIndex(&head, 1);
  }

  if (listLength(head) == 1)
  {
    printf("OK - Remove Item by Index\n");
  }
  else
  {
    printf("FAIL - Remove Item by Index\n");
  }
  freeList(head);
}

/* This tests if an item's details can be printed given its index instead
   of its word. */
void testPrintItemByIndex()
{
  struct ListNode* head = NULL;
  head = insertBeginning(head, "TestThree");
  head = insertBeginning(head, "TestTwo");
  head = insertBeginning(head, "TestOne");
  if(DEBUG)
  {
    printf("\n---- Test Print Item by Index ---- \n");
    printf("Printing list: ");
    printList(head);
    printf("Printing item in index 2..\n");
  }
  printf("OK? - Print Item by Index: ");
  printItemByIndex(head, 2);
  printf("\n");
  freeList(head);
}

/* This tests if the linked list can be properly cleared of all items. */
void testClearLinkedList()
{
  struct ListNode* head = NULL;
  head = insertBeginning(head, "TestThree");
  head = insertBeginning(head, "TestTwo");
  head = insertBeginning(head, "TestOne");

  if (DEBUG)
  {
    printf("\n---- Test Remove Item by Index ---- \n");
    printf("Printing list BEFORE clearing linked list: ");
    printList(head);
    printf("List Length: %d\n", listLength(head));
    freeList(head);
    head = NULL;
    printf("Printing list AFTER clearing linked list: ");
    printList(head);
    printf("List Length: %d\n", listLength(head));
  }
  else
  {
    freeList(head);
    head = NULL;
  }

  if(listLength(head) == 0)
  {
    printf("OK - Clear Linked List\n");
  }
  else
  {
    printf("FAIL - Clear Linked List\n");
  }
}

/* Runs all tests */
int main(int argc, char** argv)
{
  testEmptyList();
  testInsertList();
  testRemoveFromList();
  testRemoveMultipleFromList();
  testRemoveByIndex();
  testPrintList();
  testGetIndex();
  testGetIndexAfterRemoval();
  testPrintItemByIndex();
  testClearLinkedList();

  return 0;
}
