// L5_INSTSORT 
//
// INSERTION SORT - simple version using integers

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

int insertionsort (int *a, int min, int max)
// Work through array of numbers, placing each one in the correct place. Note
// that insertion sort differs from bubblesort in that with insertion sort, one
// value is moved to its relative place. In bubble sort, the largest value is
// found as the checking keeps choosing the larger of two values to keep
// moving.
{
	int		i, j;
	int		rslt = -1;

	// Check for errors
	if (a == NULL || (min > max))	{
		error ("insertionsort() called with invalid parameters");
	} else	{
		// initialize swaps so we know how many exchanges take place
		swaps = 0;

		// Outer for loop works through values from min to max. Effectively,
		// we start by making the data in position relative 0 a sorted array containing
		// one element, then adding the rest of the array, one by one, to the
		// sorted part
		for (i = min; i <=max; i++) {
			// Now, i indicates which new element in the array is going to be
			// inserted into its correct position. At the end of each loop, one
			// more value is moved, and all of the bottom is ordered.
			for (j = i; j > min && (a[j - 1] > a[j]); j--) {
				swap(a, j, j - 1);
				}//endfor
			}//endfor
		rslt = swaps;
		}//endif
	return rslt;
}//insertionsort()
