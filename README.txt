Name: Richard Tran
Assignment: 4
Course: CS241L Summer 2019
Date: July 11 2019

USEFUL INFO : - The program, ran with and without input.txt, as well as lltest does NOT produce any valgrind errors or memory leaks on my machine (WITHOUT USING SORT!). Hopefully it stays that way for you too! :) I used the command: valgrind --leak-check=full ./main
              - The input file input.txt does not include the Sort command because it leaks memory. I did not include it so that you can see the rest of the program is nicely cleaned up in terms of memory allocation and freeing.
     	      - The lltest.c file contains a #define DEBUG flag. Change this flag from 0 to 1 and recompile if you want to see a verbose explanation of each test. 
              - input.txt is a text file that executes each of the required commands multiple times (except Sort) so you don't have to do it manually. Use if you want!
              - The "Echoing Line:" output is left in so that the user can see the command when feeding a text file into the program. (aka when using ./main < input.txt).  I thought this was helpful so I left it in. It may seem unncessary when manually inputting commands since it just echos but when using a .txt file it helps to know what command it is executing per line.

Directory: Top
Compile Command: make main       OR    gcc -Wall -ansi -pedantic -g -o main main.c ll.c help.c parse.c
Run Command without input.txt: ./main
Run Command with input.txt: ./main < input.txt
Running Test: make lltest && ./lltest        OR gcc -Wall -ansi -pedantic -g -o lltest lltest.c ll.c help.c && ./lltest
Bugs:
	- Sort does not work properly and leaks memory. The program does NOT leak memory if you DO NOT use sort! Hope that counts for something.
	- Hitting the return key as the command with no other input will seg fault the program.

How to use:
-----------INSTRUCTIONS-----------
The program will take a command from its interface input as the program is running.
The program will print:
	Command:
when it is ready for the next command. To enter the command just
type one of the following commands:

         Add <followed by list of words to add>
                 Adds all items into the linked list.
                 Example: Add one two three

         Author
                 Prints author information.

         Clear
                 Removes all elements of the linked list

         Delete <followed by list of words to delete>
                 Deletes the specified items from the linked list.
                 Example: Delete one two three

         IDelete <followed by list of indexes to delete>
                 Deletes the specified indexes from the linked list.
                 Example: IDelete 0 4 2

         Exit
                 Exits the program.

         GetIndex <followed by a word>
                 Gets the index of the word. Returns "Index not Found" if index not found.
                 Example: GetIndex TestOne

         Help
                 Prints this help information.

         IsEmpty
                 Returns TRUE if there is no value in the linked list. Otherwise FALSE is returned.

         Print <followed by word or list of words to print>
                 Prints words in order listed from input in the following format:
                 <index>:<word>

         PrintAll
                 Prints all words in the linked list in the following format:
                 <index>:<word>

         IPrint <followed by index or list of indexes to print>
                 Prints the words of the items associated with the specified indexes.
                 Example: IPrint 4 2 9

         Size
                 Returns the size of the linked list. Returns 0 if empty.

         Sort
                 Performs a merge sort on the linked list sorted by aplhabetic word order.
--------------------------------------

SAMPLE INPUT AND OUTPUTS:
Current list: 0:five  1:four  2:three  3:two  4:one

Command: Print two four five
Echoing line: Print two four five
3:two 1:four 0:five

Current list: 0:five  1:four  2:three  3:two  4:one

Command: IPrint 1 3 4
Echoing line: IPrint 1 3 4
1:four 3:two 4:one

Current list: 0:five  1:four  2:three  3:two  4:one

Command: Size
Echoing line: Size
List length: 5

Current list: 0:five  1:four  2:three  3:two  4:one

Command: Delete two three four
Echoing line: Delete two three four
Delete Executed Successfully.

Current list: 0:five  1:one

Command: Add twelve thirteen fourteen fifteen
Echoing line: Add twelve thirteen fourteen fifteen

Current list: 0:fifteen  1:fourteen  2:thirteen  3:twelve  4:five  5:one

Command: IDelete 2 3 5
Echoing line: IDelete 2 3 5
IDelete Executed Successfully.

Current list: 0:fifteen  1:fourteen  2:five

Command: GetIndex fourteen
Echoing line: GetIndex fourteen
Index of fourteen is: 1

Current list: 0:fifteen  1:fourteen  2:five

Command: Size
Echoing line: Size
List length: 3

Current list: 0:fifteen  1:fourteen  2:five

Command: Print one thirteen fourteen
Echoing line: Print one thirteen fourteen
1:fourteen

Current list: 0:fifteen  1:fourteen  2:five

Command: IsEmpty
Echoing line: IsEmpty
FALSE

Current list: 0:fifteen  1:fourteen  2:five

Command: Clear
Echoing line: Clear
Clear Executed Successfully.
List is currently empty.

Command: Echoing line: Exit
Exiting program...













valgrind --leak-check=full ./lltest
==2899== Memcheck, a memory error detector
==2899== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==2899== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
==2899== Command: ./lltest
==2899==
==2899== error calling PR_SET_PTRACER, vgdb might block
OK - Empty List
OK - Insert List
OK - Remove from List
OK - Remove Multiple Items from List
OK - Remove Item by Index
OK? - Print List: 0:TestOne  1:TestTwo  2:TestThree  3:TestFour
OK - Get Index
OK - Get Index After Removal
OK? - Print Item by Index: 2:TestThree
OK - Clear Linked List
==2899==
==2899== HEAP SUMMARY:
==2899==     in use at exit: 0 bytes in 0 blocks
==2899==   total heap usage: 59 allocs, 59 frees, 5,251 bytes allocated
==2899==
==2899== All heap blocks were freed -- no leaks are possible
==2899==
==2899== For counts of detected and suppressed errors, rerun with: -v
==2899== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)



valgrind --leak-check=full ./main < input.txt
==2914==
==2914== HEAP SUMMARY:
==2914==     in use at exit: 0 bytes in 0 blocks
==2914==   total heap usage: 20 allocs, 20 frees, 8,528 bytes allocated
==2914==
==2914== All heap blocks were freed -- no leaks are possible
==2914==
==2914== For counts of detected and suppressed errors, rerun with: -v
==2914== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)