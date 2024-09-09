// RADXSORT.
// Simple implementation of radix sort - works only for integers.
//
// NOTICE
// This source code is used for teaching purposes in ELEC278,
// Queen's University, Kingston, Fall semester 2022.
// This code is provided without warranty of any kind.  It is the
// responsibility of the user to determine the correctness and the
// usefulness of this code. Under no circumstances shall the author
// or the University be held liable for any losses or damages caused
// by the use of this code.
// This code may be redistributed as long as this notice remains intact.
// END NOTICE
//
// All rights reserved.
// 
// See LICENCE.MD for restrictions on the use of this code.
//

/* --README--------------------------------------------------------------------
Source code used for teaching purposes in course:
ELEC278, Queen's University, Kingston, Fall semester 2022.
This code is provided without warranty of any kind. It is the responsibility
of the user to determine the correctness and the usefulness of this code for
any purpose.

All rights reserved. This code is intended for students registered in the
course and the semester listed above.

See LICENCE.MD for restrictions on the use of this code.
---------------------------------------------------------------------------- */

#include "Utilities.h"

//=============================================================================
// This part of code contains fundamental pieces for radix sort.




// Definitions of structures used to manage data

struct listnode  {				// nodes in linked list
    int				data;
    struct listnode	*next;
};
typedef struct listnode	ListNode;

ListNode *newlistnode (int value)
// Create new listnode, initializing it with value.
{
	ListNode   *p = (ListNode *)malloc (sizeof (ListNode));
	p->data = value;
	p->next = NULL;
	return p;
}//newlistnode()

// Array of "hoppers" where "cards" are placed. Each hopper has pointer
// to list of actual data values (see ListNode definition above), and 
// count indicating how many cards in the hopper. (References to cards
// and hoppers is meant to recall the IBM card sorter.)
// Note that we are keeping track of both front and end of list.

struct intlist	{
	int         count;
	ListNode    *frontlist;
	ListNode	*backlist;
};
typedef struct intlist IntList;


IntList *newIntListArray (int size)
// Create initialized array of IntLists
{
	IntList *pil = (IntList *)malloc (size * sizeof(IntList));
	if (pil != NULL)	{
		int		i;
		for (i=0; i<size; i++)	{
			pil[i].count = 0;
			pil[i].frontlist = NULL;
			pil[i].backlist = NULL;
			}
		}
	return pil;
}//newIntListArray()


void insertIntoList (IntList *pl, int value)
// Given pointer to IntList and value, create node and insert in correct place
// in list.
{
	ListNode *pnode = newlistnode (value);
	ListNode *current;

	// Where does new node go? If list empty, goes at beginning. (Duhh)
	// Otherwise, since ordering is supposed to be preserved, place at end.
	if (pl->frontlist == NULL)	{
		// empty list - first entry
		pnode->next = NULL;			// make sure list element points nowhere
		pl->frontlist = pnode;		// both list pointers point to first node
		pl->backlist = pnode;
		pl->count++;				// and update list count
	} else	{
		// Otherwise, since ordering must be preserved, place at end.
		current = pl->backlist;		// current end of list
		current->next = pnode;		// last one points to new node
		pl->backlist = pnode;		// and now it becomes the last node
		pl->count++;
		// Discussion: Could place every new one at the FRONT of the list, but
		// that would mean we would have to be pulling them out of the list
		// starting at the end. So, it's an even trade-off.
		}
	return;
}//insertIntoList()


int deletefromlist (IntList *pl, int *pvalue)
// Remove next item from list, storing value in place pointed to by pvalue.
// Returns 0 if there was nothing to delete - i.e. the list was empty - and
// 1 if a value was retrieved.
{
	ListNode	*ptmp;
	if (pl->frontlist == NULL)	return 0;
	// point to first list element.
	ptmp = pl->frontlist;
	// remove it from list by updating the start-of-list pointer with
	// pointer in first list element.  Reduce list count
	pl->frontlist = ptmp->next;
	pl->count--;
	// copy data from the list element to the place the caller wanted it
	*pvalue = ptmp->data;
	// and just like parents teach their children, clean up memory after
	// you have finished using it. (Well, mine might have said toys, not
	// memory.)
	free (ptmp);
	return 1;
}//deletefromlist()


void printlist (IntList *pl)
// Prints one of the lists.
{
	if (pl->frontlist == NULL)	printf ("--NO ENTRIES--");
	else	{
		ListNode	*ptemp;
		ptemp = pl->frontlist;
		while (ptemp != NULL)	{
			printf (" %3d", ptemp->data);
			ptemp = ptemp->next;
			}
		}
	putchar ('\n');
}//printlist()


// The following table holds powers of 10 - just so we don't have to
// calculate them each time using a language that didn't include an
// integer power operator. Note that this table goes up to 1 billion
// (US definition), so it is only suitable for 32-bit integers.
static int pwr10 []	=	{	1,
			  10,       100,       1000,
		   10000,    100000,    1000000,
		10000000, 100000000, 1000000000 };


int hopper (int num, int position)
// Return hopper number based on digit found in position in num.
// Note that position is 0 based, because we're all computer-types.
// Also note that this routine only works for numbers in the 0 to
// 9,999,999,999 range.
{
	// Programmer lament: This would be so much easier if we all worked
	// with base-16 numbers ...

	// Check required digit - if it is 0 digit, we have no work
	// required to isolate it.
	if (position != 0)	{
		// For all but lowest digit, we have to get digit into bottom
		// position. Basically, integer divide by appropriate power
		// of 10 to get desired digit in least significant digit position.
		num = num / pwr10 [position];
		}
	// So, desired digit is in bottom digit of number
	return num%10;
}//hopper()


int highestdigit (int num)
// Determine highest power of 10 present in num, using comparisons
// with entries in power-of-10 table.
{
	int		digits, i;

	for (digits = 9; digits > 0; digits--)	{
		if (num >= pwr10[digits])	return digits+1;
		}
	return 0;
}//highestdigit()


int largestnumber (int *a, int size)
// Determine largest number in set.
{
	int	biggest;
	int	i;

	biggest = a[0];
	for (i=1; i<size; i++)	if (a[i] > biggest)	biggest = a[i];
	return biggest;
}//largestnumber()
		


int radixsort (int *pdata, int count)
// Given an array containing count integers, return array with contents
// sorted in ascending order.
{
	int		rslt = -1;			// default value of return status
	// Mandatory idiot test
	if (pdata != NULL && count > 1)	{
		int		i, digit, maxdigits, maxval;
		IntList	*Hoppers = newIntListArray (10);
		// Always check if memory obtained
		if (Hoppers == NULL)	{
			fprintf (stderr, "ERROR: Failed to obtain memory for hoppers\n");
			return rslt;
			}
	
		//printf ("====Array before sorting:\n");
		//printarray (pdata, count);
		// Ready to go.  First check on numbers in data set, to see
		// how many passes through the set are required.
		maxval = pdata[0];
		for (i=1; i<count; i++)
			if (pdata[i] > maxval)	maxval = pdata[i];
		// biggest value in set is in pdata
		maxdigits = highestdigit (maxval);
		printf ("Largest value in array is %d, requiring %d passes\n",
			maxval, maxdigits);

		// For each of maxdigits, distribute among hoppers, gather up and
		// try again.
		for (digit=0; digit<maxdigits; digit++)	{
			int		k;								// temporary storage
			// go through array, put all data in correct hopper
			for (i=0; i<count; i++)	{
				int		dt = pdata [i];				// get data value
				int		hp = hopper (dt, digit);	// figure out hopper
				printf ("Data value %3d into hopper %d\n", dt, hp);
				insertIntoList (&Hoppers[hp], dt);
				}
			// Now show hoppers
			for (i=0; i<10; i++)	{
				printf ("%2d (%2d): ", i, Hoppers[i].count);
				printlist (&Hoppers[i]);
				}
			// Put all numbers back
			k = 0;				// location to place number
			// Go through all hoppers
			for (i=0; i<10; i++)	{
				int		dt;
				while (deletefromlist (&Hoppers[i], &dt))	{
					pdata [k++] = dt;
					}
				}
			printf ("After digit %d, array looks like:\n", digit);
			printarray (NULL, pdata, 0, count-1, 12);
			}
		printf ("====Array after sorting:\n");
		printarray (NULL, pdata, 0, count-1, 12);
		rslt = 0;
		}
	return rslt;
}//radixsort()
