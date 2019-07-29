#ifndef LL_H
#define LL_H

/* Creates a linked list node containing the word. */
struct ListNode* createNode(char* word);

/* Inserts a node at the beginning of the list. */
struct ListNode* insertBeginning(struct ListNode*, char* word);

/*  Removes the item from the linked list given the word. If the word
    matches any node in the linked list, it removes it and re-links the
    previous node and the current's next node. Returns 1 if successful.
    Otherwise returns 0. */
int removeItem(struct ListNode** headRef, char* word);

/*  Removes the item from the linked list given the index. If the index
    matches any node in the linked list, it removes it and re-links the
    previous node and the current's next node. Returns 1 if successful.
    Otherwise returns 0. */
int removeItemByIndex(struct ListNode** headRef, int index);

/* Compares two words. Since the null terminator of one is striped,
  the length is kept track and each character is compared.
  Returns 1 if match, otherwise returns 0. */
int compareString (char* word1, int len, char* word2);

/* Return the length of the list by counting each node in
  the linked list. */
int listLength(struct ListNode* head);

/* Returns the index of a node that contains the specified word. */
int getIndex(struct ListNode* head, char* word);

/* Prints out the index and word contents of a node given an index.
  Returns 1 if the index was found. Otherwise returns 0. */
int printItemByIndex(struct ListNode* head, int index);

/* Prints out the index and word contents of a node given a word. */
void printItemByWord(struct ListNode* head, char* word);

/* Prints all items in the linked list by index and word. */
void printList(struct ListNode* head);

/* Frees all memory used by the list */
void freeList(struct ListNode* head);

/* Updates all indexes in the linked list. Used after adding
  and deleting nodes. */
void updateListIndexes(struct ListNode** headRef);

void mergeSortList(struct ListNode** headRef);
#endif
