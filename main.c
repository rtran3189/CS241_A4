/*	Name: Richard Tran
 * 	Date: July 11, 2019
 * 	Class: CS241L SUM 2019
 *
 *	This is the main for the program. Calls parse from parse.c which executes
 *	the rest of the program.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "help.h"
#include "parse.h"

#define ASSIGNMENT_NUM 5

int main (int argc, char** argv)
{
	parse();

	return 0;
}