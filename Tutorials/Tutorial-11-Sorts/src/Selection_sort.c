// L5_SELSORT 
// Simple selection sort

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



int findbiggest (int *pd, int min, int max)
// Fuction finds biggest value in array pd, between locations (indexes)
// min and max.  Returns index where biggest value found.
{
	int		i;
	int		bigndx, bigvalue;

	if (verbose)	{
		printf (
			"Search for biggest value between min (%d) and max (%d) index\n",
			min, max);
		}


	// Start by assuming biggest value is in first place
	bigndx = min;
	bigvalue = pd[min];

	// Now check all other places
	for (i=min+1; i<=max; i++)
		// This value bigger than the one we know about?
		if (pd[i] > bigvalue)	{
			// Data at i bigger than biggest so far. Record index where to
			// find biggest, and record the biggest value.
			bigndx = i;
			bigvalue = pd[i];
			}
	// Checked everywhere
	return bigndx;
}//findbiggest()


int		callcounter = 0;

int selsortR (int *pd, int min, int max)
// This version of selection sort is done recursively.
{
	int		bigplace;
	int		temp;
	callcounter++;
	if (min >= max)	return swaps;
	bigplace = findbiggest (pd, min, max);
	swap (pd, bigplace, max);
	if (verbose)	{
		printf ("Call #%d:      ", callcounter);
		printarray (NULL, pd, min, max, 10);
		}
	selsortR (pd, min, max-1);
	return swaps;
}//selsortR()


int selsortI (int *pd, int min, int max)
// This version of selection sort is done iteratively.
{
	int		i;

	i = max;
	while (i > min)	{
		// Find biggest value between index i and index max
		int ndx;
		ndx = findbiggest (pd, min, i);
		// Swap biggest value into biggest index
		if (verbose)	{
			printf ("Putting value %d into last array position (%d)\n",
				pd [ndx], i);
			}
		swap (pd, ndx, i);
		// Last one - index i - is now correct
		i--;
		}
	return swaps;
} //selsortI()
