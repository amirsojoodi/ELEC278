// L5_BUBBLESORT.C
// Implement simple bubblesort.

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

int bubbleup(int *a, int min, int max)
// Bubble largest element to high-index end of array.
// Returns number of swaps done.
{
  int swaps = 0;
  int i;
  if (a == NULL)
    return -1;
  if (max <= min)
    return 0;
  if (verbose)
    printf("Start another bubble up\n");
  for (i = min; i < max; i++) {
    if (a[i] > a[i + 1]) {
      // out of order - swap required
      swap(a, i, i + 1);
      swaps++;
    }
  }
  return swaps;
} // bubbleup()

int bubblesort(int *a, int min, int max) {
  int i;
  int rslt, totalswaps = 0;

  // Every time through loop, one more data item is placed correctly.
  for (i = max; i > 0; i--) {
    rslt = bubbleup(a, 0, max);
    totalswaps = totalswaps + rslt;
    if (verbose)
      printf("Swaps done: %d\n", rslt);
    // printarray ("After another bubble :", a, min, max, 10);
    // if no swaps were done, we're finished
    if (rslt == 0)
      break;
  }
  return totalswaps;
} // bubblesort()
