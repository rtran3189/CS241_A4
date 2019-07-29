/*	Name: Richard Tran
 * 	Date: July 11, 2019
 * 	Class: CS241L SUM 2019
 *
 *	This file is responsible for parsing user input from stdin and 
 *	executing the proper commands based on the input.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "help.h"
#include "ll.h"

#define ASSIGNMENT_NUM 4
#define BUFFER_SIZE 100
void parse () 
{
	struct ListNode* head = NULL;
	char line[BUFFER_SIZE];

	char delim[2] = " ";
	char *token;

	printf("Command: ");
	/* Something to consider: When reading a from a file, fgets reads up
	to the \n line terminator (which it includes). In Windows, a line read
	ends up in \r\n.
	In Unix, a line read ends up in just \n.
	So under Windows (the machine I'm coding on) fgets will be 1 byte longer.
	*/
	while (fgets(line, BUFFER_SIZE, stdin) != NULL)
	{	
		/* Takes off the new line character at the end and replaces it
			with null terminator. */
		if ((line[0] != '\0') && (line[strlen(line) -1] == '\n'))
		{
            line[strlen(line) -1] = '\0';
        }

        /* I left this in so that the user can see the command when feeding
        	a text file into the program. (aka when using ./main < input.txt 
        */
		printf("Echoing line: %s\n", line);
		
		token = strtok(line, delim);
		
		/* Add command */
		if (!strcmp(token, "Add") || !strcmp(token, "add"))
		{
			/* Iterates through all the arguments following the Add command. */
			while ((token = strtok(NULL, delim)))
			{
				head = insertBeginning(head, token);
			}
		}
		/* Author command */
		else if (!strcmp(token, "Author") || !strcmp(token, "author"))
		{
			printName(ASSIGNMENT_NUM);
		}
		/* Clear command */
		else if (!strcmp(token, "Clear") || !strcmp(token, "clear"))
		{
			freeList(head);
			head = NULL;
			printf("Clear Executed Successfully.\n");
		}
		/* Delete command. Deletes by word. */
		else if (!strcmp(token, "Delete") || !strcmp(token, "delete"))
		{
			int result = 0;
			token = strtok(NULL, delim);
			/* Iterates through all the arguments following the Delete command. */
			while (token != NULL)
			{
				result = removeItem(&head, token);
				token = strtok(NULL, delim);
			}
			if (result)
			{
				printf("Delete Executed Successfully.\n");
			}
			else
			{
				printf("Delete failed at a certain point.\n");
			}
		}
		/* IDelete command. Deletes by index. */
		else if (!strcmp(token, "IDelete") || !strcmp(token, "idelete"))
		{	
			int result = 0;
			int deleteCount = 0;
			token = strtok(NULL, delim);
			/* Iterates through all the arguments following the IDelete command. */
			while (token != NULL)
			{
				int deletedIndex = atoi(token);
				/* Use this to get around the fact that the indexes shift each removal.
				   Now the user can delete using the index each element had that in the
				   beginning instead of the "new" indexes the elements get after one removal. */
				result = removeItemByIndex(&head, deletedIndex - deleteCount);
				token = strtok(NULL, delim);
				deleteCount++;
			}
			if (result)
			{
				printf("IDelete Executed Successfully.\n");
			}
			else
			{
				printf("IDelete failed at a certain point.\n");
			}
		}
		/* Exit command. Frees the list memory and exits the program.*/
		else if (!strcmp(token, "Exit") || !strcmp(token, "exit"))
		{
			printf("Exiting program...\n");
			freeList(head);
			exit(1);
		}
		/* GetIndex command. Gets item index given the word. */
		else if (!strcmp(token, "GetIndex") || !strcmp(token, "getindex"))
		{
			token = strtok(NULL, delim);
			printf("Index of %s is: %d\n", token, getIndex(head, token));
		}
		/* Help command. Prints the help text. */
		else if (!strcmp(token, "Help") || !strcmp(token, "help"))
		{
			printHelp();
		}
		/* IsEmpty command. Outputs if the list is empty or not. */
		else if (!strcmp(token, "IsEmpty") || !strcmp(token, "isempty"))
		{
			if (listLength(head))
			{
				printf("FALSE\n");
			}
			else
			{
				printf("TRUE\n");
			}
		}
		/* Print command. Prints item details given the word or words. */
		else if (!strcmp(token, "Print") || !strcmp(token, "print"))
		{
			token = strtok(NULL, delim);
			/* Iterates through all the arguments following the Print command. */
			while (token != NULL)
			{
				printItemByWord(head, token);
				token = strtok(NULL, delim);
			}
			printf("\n");
		}
		/* IPrint command. Prints item details given an index or indexes.*/
		else if (!strcmp(token, "IPrint") || !strcmp(token, "iprint"))
		{
			token = strtok(NULL, delim);
			/* Iterates through all the arguments following the IPrint command. */
			while (token != NULL)
			{
				printItemByIndex(head, atoi(token));
				token = strtok(NULL, delim);
			}
			printf("\n");
		}
		/* PrintAll command. A new command that prints all items in the linked list. */
		else if (!strcmp(token, "PrintAll") || !strcmp(token, "printall"))
		{
			printf("Printing linked list: ");
			printList(head);
		}
		/* Size command. Prints out the length of the linked list. */
		else if (!strcmp(token, "Size") || !strcmp(token, "size"))
		{
			printf("List length: %d\n", listLength(head));
		}
		/* Sort command. Performs a merge sort on the linked list to sort
		   the nodes alphabetically based on the word. */
		else if (!strcmp(token, "Sort") || !strcmp(token, "sort"))
		{
			mergeSortList(&head);
		}
		/* If no matched command, outputs invalid command. */
		else
		{
			printf("Invalid command. Please type \"Help\" or \"help\" to view available commands.\n");
		}

		if (listLength(head) > 0)
		{
			printf("\nCurrent list: ");
			printList(head);
			printf("\n");
		}
		else
		{
			printf("List is currently empty. \n\n");
		}
		
		printf("Command: ");
	}
}