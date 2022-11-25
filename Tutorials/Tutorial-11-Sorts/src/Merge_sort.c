// L5_MERGESORT 
//
// Implements simple mergesort algorithm.
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

void merge(int *a, int left, int mid, int right)
// Merges two subarrays of a[]. First subarray is a[left..mid]. Second
// subarray is a[mid+1..right]
{
    int i, j, k;
    int lenl = mid - left + 1;	// length of left part
    int lenr = right - mid;		// length of right part
	int *templeft, *tempright;

	if (verbose)
		printf ("Call merge: left %d, mid %d, right %d\n", left, mid, right);
	// get memory for two temporary arrays
	templeft = (int *)malloc (lenl * sizeof (int));
	tempright = (int *)malloc (lenr * sizeof (int));
	// copy given arrays into temporary arrays
	for (i=0; i<lenl; i++)	templeft[i] = a[left+i];
	for (i=0; i<lenr; i++)	tempright[i] = a[mid+1+i];
 
 	// Merge two sorted temporary arrays back into original array
    i = 0;					// Initial index of first subarray
    j = 0;					// Initial index of second subarray
    k = left;				// Initial index of merged subarray
    while (i < lenl && j < lenr) {
        if (templeft[i] <= tempright[j])
            a[k++] = templeft[i++];
        else
            a[k++] = tempright[j++];
		// Or for you one-liners:
		// a[k++] = (templeft[i]<=tempright[j])?templeft[i++]:tempright[j++];
		}//endwhile
 	// One of temporaries exhausted; copy remainder of other one
    while (i < lenl)	a[k++] = templeft[i++];
    while (j < lenr)	a[k++] = tempright[j++];
	free (templeft);
	free (tempright);
	if (verbose)	{
		printf ("End merge (L: %d  M: %d  R: %d)\n", left, mid, right);
		printarray (NULL, data, left, right, 1000);
		}
}//merge()
 

int mergesorta(int *a, int left, int right)
{
	int		mid;
	if (verbose)
		printf ("Call mergesort: left %d, right %d\n", left, right);
	// Check that half is not just a single item
    if (left < right)	{
		// Check first for tiny half that can be sorted trivially
		if (left+1 == right)	{
			if (verbose)
				printf ("--Two element segment - just reorder if required\n");
			// List has only two elements; there are only two possibilities,
			// they are in order or they are not.
			if (a[left] > a[right])	{
				// not ordered - swap them.
				swap (a, left, right);
				}
		} else	{
			// Anything more than 2 we consider non-trivial
			mid = (left+right)/2;
        	// Sort first and second halves.
        	mergesorta(a, left, mid);
        	mergesorta(a, mid+1, right);
 			// and merge results
        	merge(a, left, mid, right);
			// Note to students: Think about this code a bit. This is recursive
			// so we keep calling merge() on left halves before we ever call
			// merge() on a right half.  So, if you were to be asked to show
			// the changes to the contents of the array, you want to look at
			// the pictures in the course slides to see how progress is made
			// down the left side.
			}
    } else	{
		// Case where left == right - no work required
		if (verbose)
			printf ("  --Mergesort - no L:%d R:%d\n", left, right);
		}
	return 0;	// swaps irrelevant because of multiple array copies
}//mergesorta()


int mergesort(int *a, int left, int right)
// Since mergesort is recursive, we cannot have the initialization of swaps
// in the mergesort function. So, we name the real mergesort mergesorta (above)
// and add this mergesort whose only purpose is to initialize swaps prior to
// starting mergesort.
{
	swaps = 0;
	mergesorta (a, left, right);
	return swaps;
}//mergesort()

