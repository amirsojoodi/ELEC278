// SHELLSORT 
//
// Example of Shellsort implementation.
// Written in a hurry - use at your own risk.
// Your discoveries of errors and, even better, your corrections are
// welcome.
//
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



int ShellSort (int *pa, int min, int max)
// Acknowledgement to Donald Shell, who invented the Shell sort.
// Implement shellsort. Sorts contents of integer array pa, starting at index
// min and extending to index max.
// Returns number of swaps performed while doing full sort
{
	int		gap;	// distance between data items
	int		len;	// length of array being sorted
	int		i;		// for-loop counter

	// initialize swaps so we get an accurate count
	swaps = 0;
	// compute length of array being sorted
	len = max + 1 - min;
	// Begin with gap half size array, then reduce gap by half each pass
	for (gap = len/2; gap > 0; gap = gap >> 1) {
		// For array elements at gap+0, gap+1, etc, do insertion sort
		for (i = gap+min; i < len; i++) { 
			int temp = pa[i];			// save item this gap 
			int j;
			if (verbose)	{
				printf ("Gap size = %d  Contents of pa[i] = %d\n", gap, temp);
				}	 
			// Use insertion sort to move item up to place it should be
			for (j = i; j >= gap && pa[j - gap] > temp; j -= gap) 
				swap (pa, j, j - gap); 
			// put temp (the original pa[i]) in its correct location 
			pa[j] = temp; 
			} // end insertion sort for this gap width
		} // end all gaps
	return swaps; 
}// Shellsort()
