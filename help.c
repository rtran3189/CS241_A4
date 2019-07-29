/*	Name: Richard Tran
 * 	Date: July 11, 2019
 * 	Class: CS241L SUM 2019
 *
 *	This file includes helper functions used for the assignment and
 *	for printing helpful feedback for the user.
 */

#include <stdio.h>
#include <limits.h>

/*
 * Prints a banner containing Name, Course, Date, and Assignment number
 * based on the specified format from class.
 */
void printName(int assignmentNum)
{
	printf("\n\n");
	printf("/**********************************************/\n");
	printf("/*Name: Richard Tran                          */\n");
	printf("/*Course: CS241L Summer 2019                  */\n");
	printf("/*Date: July 11, 2019                         */\n");
	printf("/*Assignment: %d                               */\n", assignmentNum);
	printf("/**********************************************/\n");
}

/*
 * Print information on how torun the program. 
 * This information may be the same information
 * you included in your readme file.
 */
void printHelp()
{
	printf("\n-----------------HELP-----------------\n");
	printf("The program will take a command from its interface input as the program is running.\n");
	printf("The program will print: \n");
	printf("\t Command: \n");
	printf("when it is ready for the next command. To enter the command just\n");
	printf("type one of the following commands: \n");
	printf("\n\t Add <followed by list of words to add> \n");
	printf("\t\t Adds all items into the linked list.\n");
	printf("\t\t Example: Add one two three\n");
	printf("\n\t Author \n");
	printf("\t\t Prints author information.\n");
	printf("\n\t Clear \n");
	printf("\t\t Removes all elements of the linked list\n");
	printf("\n\t Delete <followed by list of words to delete> \n");
	printf("\t\t Deletes the specified items from the linked list.\n");
	printf("\t\t Example: Delete one two three\n");
	printf("\n\t IDelete <followed by list of indexes to delete> \n");
	printf("\t\t Deletes the specified indexes from the linked list.\n");
	printf("\t\t Example: IDelete 0 4 2\n");
	printf("\n\t Exit \n");
	printf("\t\t Exits the program.\n");
	printf("\n\t GetIndex <followed by a word> \n");
	printf("\t\t Gets the index of the word. Returns \"Index not Found\" if index not found.\n");
	printf("\t\t Example: GetIndex TestOne\n");
	printf("\n\t Help \n");
	printf("\t\t Prints this help information.\n");
	printf("\n\t IsEmpty \n");
	printf("\t\t Returns TRUE if there is no value in the linked list. Otherwise FALSE is returned.\n");
	printf("\n\t Print <followed by word or list of words to print> \n");
	printf("\t\t Prints words in order listed from input in the following format: \n");
	printf("\t\t <index>:<word>\n");
	printf("\n\t PrintAll\n");
	printf("\t\t Prints all words in the linked list in the following format: \n");
	printf("\t\t <index>:<word>\n");
	printf("\n\t IPrint <followed by index or list of indexes to print> \n");
	printf("\t\t Prints the words of the items associated with the specified indexes.\n");
	printf("\t\t Example: IPrint 4 2 9\n");
	printf("\n\t Size \n");
	printf("\t\t Returns the size of the linked list. Returns 0 if empty.\n");
	printf("\n\t Sort \n");
	printf("\t\t Performs a merge sort on the linked list sorted by aplhabetic word order.\n");
	printf("--------------------------------------\n\n");

}	