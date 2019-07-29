/*  Name: Richard Tran
 *  Date: July 11, 2019
 *  Class: CS241L SUM 2019
 *
 *  This file includes all linked list functions for parse.c
 *  as well as some helper functions relating to functionality of
 *  the linked list.
 */

#include <stdio.h>
#include <stdlib.h>
#include "ll.h"
#include <string.h>

/* The elements that make up a node. Word, length of the word, the node's
  index, and pointers to the next and previous nodes beside it. */
struct ListNode
{
  char* word;
  int wordLength;
  int index;
  struct ListNode* next;
  struct ListNode* prev;
};

/* Creates a linked list node containing the word. */
struct ListNode* createNode(char* word)
{
  /* Memory allocation */
  struct ListNode* node = malloc(sizeof(struct ListNode));
  char * newWord = malloc(sizeof(char) * strlen(word));
  
  memcpy(newWord, word, sizeof(char)*strlen(word));
  node->wordLength = strlen(word);
  node->word = newWord;
  node->next = NULL;
  return node;
}

/* Inserts a node at the beginning of the list. */
struct ListNode* insertBeginning(struct ListNode* head, char* word)
{
  struct ListNode* newNode = createNode(word);
  newNode->next = head;
  head = newNode;
  updateListIndexes(&head);
  return newNode;
}

/*  Removes the item from the linked list given the word. If the word
    matches any node in the linked list, it removes it and re-links the
    previous node and the current's next node. Returns 1 if successful.
    Otherwise returns 0. */
int removeItem(struct ListNode** headRef, char* word)
{
  struct ListNode* previous;
  struct ListNode* current;

  previous = *headRef;
  if(previous->next)
  {
    current = previous->next; 
  }
  else
  {
    if(previous->word == word)
    {
      free(previous->word);
      free(previous);
      return 1;
    }
    return 0;
  }
  /* While loop that checks all nodes of the linked list.*/
  while (current)
  {
    /*Checks if the word matches the node's word. This is a custom function
      that iterates through each character since there is no null terminator. */
    if(compareString(current->word, current->wordLength, word))
    {
      struct ListNode* newNext = current->next;
      previous->next = newNext;
      free(current->word);
      free(current);
      updateListIndexes(headRef);
      return 1;
    }
    previous = current;
    current = current->next;
  }
  return 0;
}

/*  Removes the item from the linked list given the index. If the index
    matches any node in the linked list, it removes it and re-links the
    previous node and the current's next node. Returns 1 if successful.
    Otherwise returns 0. */
int removeItemByIndex(struct ListNode** headRef, int index)
{
  struct ListNode* previous;
  struct ListNode* current;

  previous = *headRef;

  if(previous->next)
  {
    current = previous->next; 
  }
  else
  {
    if(previous->index == index)
    {
      free(previous->word);
      free(previous);
      return 1;
    }
    return 0;
  }

  /* While loop that checks all first node of the linked list.*/
  while (current)
  {
    if(current->index == index)
    {
      struct ListNode* newNext = current->next;
      previous->next = newNext;
      free(current->word);
      free(current);
      updateListIndexes(headRef);
      return 1;
    }
    previous = current;
    current = current->next;
  }
  return 0;
}

/* Compares two words. Since the null terminator of one is striped,
  the length is kept track and each character is compared.
  Returns 1 if match, otherwise returns 0. */
int compareString (char* word1, int len, char* word2)
{
  int count;
  for (count = 0; count < len; count++)
  {
    if (word1[count] != word2[count])
    {
      return 0;
    }
  }
  return 1;
}

/* Return the length of the list by counting each node in
  the linked list. */
int listLength(struct ListNode* head)
{
  struct ListNode* current = head;
  int count = 0;
  
  while (current != NULL)
  {
    count++;
    current = current->next;
  }

  return count; 
}

/* Returns the index of a node that contains the specified word. */
int getIndex(struct ListNode* head, char* word)
{
  struct ListNode* current = head;
  while (current != NULL)
  {
    /* Uses a custom function that compares the words. */
    if (compareString(current->word, current->wordLength, word))
    {
      return current->index;
    }
    current = current->next;
  }
  return -1;
}

/* Prints out the index and word contents of a node given an index.
  Returns 1 if the index was found. Otherwise returns 0. */
int printItemByIndex(struct ListNode* head, int index)
{
  int counter = 0;
  struct ListNode* current = head;
  while (current != NULL)
  {
    if (current->index == index)
    {
      printf("%d:", current->index);
      while (counter < current->wordLength)
      {
        printf("%c", current->word[counter]);
        counter++;
      }
      printf(" ");
      return 1;
    }
    current = current->next;
  }
    return 0;
}

/* Prints out the index and word contents of a node given a word. */
void printItemByWord(struct ListNode* head, char* word)
{
  struct ListNode* current = head;

  while (current)
  {
    if(compareString(current->word, current->wordLength, word))
    {
      printItemByIndex(head, current->index);
    }
    current = current->next;
  }
}

/* Prints all items in the linked list by index and word. */
void printList(struct ListNode* head)
{
  int counter;
  struct ListNode* current = head;
  while (current)
  {
    counter = 0;
    printf("%d:", current->index);
    while (counter < current->wordLength)
    {
      printf("%c", current->word[counter]);
      counter++;
    }
    printf("  ");
    if (current->next)  {
      current = current->next;
    } else {
      current = NULL;
    }
  }
  printf("\n");
}

/* Frees all memory used by the list */
void freeList(struct ListNode* head)
{
  struct ListNode* tmp;

  while (head)
  {
    tmp = head;
    head = head->next;
    free(tmp->word);
    free(tmp);
  }
}

/* Updates all indexes in the linked list. Used after adding
  and deleting nodes. */
void updateListIndexes(struct ListNode** headRef)
{
  struct ListNode* current = *headRef;
  int i = 0;
  /* Loops through all nodes and assigns them the correct index. */
  while (current)
  {
    current->index = i;
    current = current->next;
    i++;
  }
}

/* This splits a linked list provided the list, start, and stop positions. */
void subList(struct ListNode* src, struct ListNode** start, struct ListNode** stop)
{
  struct ListNode* doubleIncrement;
  struct ListNode* singleIncrement;
  singleIncrement = src;
  doubleIncrement = src->next;

  /* Advance 'doubleIncrement' two nodes forward, 'singleIncrement' advances one node. */
  while (doubleIncrement != NULL)
  {
    doubleIncrement = doubleIncrement->next;
    if (doubleIncrement != NULL)
    {
      singleIncrement = singleIncrement->next;
      doubleIncrement = doubleIncrement->next;
    }
  }

  *start = src;
  *stop = singleIncrement->next;
  singleIncrement->next = NULL;
}

/* Merges two 'sub lists' together, sorting along the way. This is recursive. */
struct ListNode* mergeTogether(struct ListNode* left, struct ListNode* right, int charPosition)
{
  struct ListNode* result = NULL;
  int charPos = charPosition;
  /* Base case. If the left or right sides run out, return the other. */
  if (left == NULL)
  {
    return (right);
  }
  else if (right == NULL)
  {
    return (left);
  }

  /* Recursive merge starts here, comparing the words of each side.
     If the characters match, shift the comparison index up. */
  if (left->word[charPos] == right->word[charPos])
  {
    mergeTogether(left->next, right->next, charPos++);
  }
  else if (left->word[charPos] <= right->word[charPos])
  {
    result = left;
    result->next = mergeTogether(left->next, right, 0);
  }
  else
  {
    result = right;
    result->next = mergeTogether(left, right->next, 0);
  }
  return (result);
}

/* Recursive that continuously splits the lists in half until there is only one in each sublist. 
   Then performs mergeTogether which sorts the nodes back together.*/
void mergeSortList(struct ListNode** headRef)
{
  struct ListNode* head = *headRef;
  struct ListNode* leftSide;
  struct ListNode* rightSide;

  /* Base case, checks if the length of the list is 0 or 1. */
  if (((listLength(head) == 0) || (listLength(head)) == 1))
  {
    return;
  }

  subList(head, &leftSide, &rightSide);

  mergeSortList(&leftSide);
  mergeSortList(&rightSide);

  /* Merge two lists back together */
  *headRef = mergeTogether(leftSide, rightSide, 0);
}

