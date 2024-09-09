// UTILITYCODE.C
//
// This code is intended to be used for educational
// purposes only.
//
//
// Code useful for all sort routines.
//
// READ THIS WARNING BEFORE USING!
//
// Warning! This module is expected to be included in your code, not separately
//          linked. This is not good programming, IMHO, but is done this way to
//          make it a little easier for students in ELEC278.
//
//			This code uses stdio. It is expected that the #include
// of
// stdio.h
//			has been done before this code is included.
//
//			This code uses stderr for warnings and errors, and it
// uses
// stdout
//			for expected output.
//
//          This code expects two GLOBAL variables to be declared BEFORE the
//          include directive that includes this code:
//          verbose - set to a non-zero value if messages showing action are
//                    required
//          swaps - keeps track of how many swaps done. Calling code must
//                  set swaps to 0 before starting.
//
// Limitation: This code expects that the array values will be integers. (It
//			would be an exercise to see how easy it might be to
// change
// this
//			code to deal with floats, doubles, long ints, unsigned
// ints,
// chars
//			or unsigned chars. It would be slightly harder to change
// this code
//			to work with arbitrary structures of data.
//
//  List of functions:

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

#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// "Global" variables
int verbose = 0;
long unsigned int swaps = 0; // may be lots of swaps

int array_sorted(char *msg, int *a, int min, int max, int ascending);
void error(char *msg);
void printarray(char *msg, int *a, int min, int max, int numperline);
void swapcontents(int *pa, int *pb);
void swap(int *a, int g, int h);

int array_sorted(char *msg, int *a, int min, int max, int ascending)
// Check if portion of array (parameter a) from index min to index max
// inclusive is sorted. Parameter ascending determines whether check is for
// ascending order, meaning lower value is in lower index, or descending
// order, meaning lower value is in higher index.
// If msg is not NULL, prints string pointed to by msg on stdout.
{
  int correct = 0; // either error or unsorted to begin

  // Check first for dumbness
  if (a != NULL) {
    int i;
    if (msg != NULL)
      printf("%s\n", msg);
    for (i = min; i < max; i++) {
      // data in higher index position should be equal or higher value
      // when array is sorted in ascending order, and should be equal
      // or lower value when array is sorted in descending order.
      // (Note use of C's conditional evaluation.) Variable correct
      // will be true if order OK, and false if order wrong.
      if ((ascending && (a[i] > a[i + 1])) ||
          (!ascending && (a[i] < a[i + 1]))) {
        // found two out of order - therefore it is unsorted
        if (verbose) {
          printf("Sort check failed at position %d\n", i);
          printf("a[%d] = %d, a[%d] = %d\n", i, a[i], i + 1, a[i + 1]);
        }
        return 0;
      }
    } // endfor
    // Get to this point only because we did not detect an out of order
    correct = 1;
  } else {
    fprintf(stderr, "Call to array_sorted() with no array to check\n");
  } // endif a valid
  return correct;
} // array_sorted()

void error(char *msg)
// Errors are reported to both stderr and stdout.
{
  if (msg == NULL)
    msg = "Default error message";
  fprintf(stderr, "ERROR: %s\n", msg);
  fprintf(stdout, "ERROR: %s\n", msg);
} // error()

void printarray(char *msg, int *a, int min, int max, int numperline)
// Print contents of array a from position min to position max. If msg is not
// NULL, prints msg on stdout before printing array. Parameter numperline -
// if not 0 - indicates how many numbers to print per line.
{
  // Check first for dumbness
  if ((a != NULL) && (numperline > 0)) {
    int i, num2print;
    if (msg != NULL)
      printf("%s\n", msg);
    // Compute total number of data items to print
    num2print = 1 + max - min;
    for (i = 0; i < num2print; i++) {
      // See if we have to finish current line and start next line.
      if (i && ((i % numperline) == 0))
        putchar('\n');
      // Print number - remember counter goes from 0 but items to
      // print start at min.
      printf(" %4d", a[i + min]);
    }
    // Close off last line
    putchar('\n');
  } else {
    fprintf(stderr, "Error in printarray() parameters\n");
  }
} // printarray()

void swapcontents(int *pa, int *pb)
// Swap values at locations pa and pb - two pointers to integers
{
  int t = *pa;
  *pa = *pb;
  *pb = t;
} // swapcontents()

void swap(int *a, int g, int h)
// Swap values at locations g and h in array a.
// If global verbose is set, reports that swap takes place.
// Global counter swaps is incremented by 1.  User needs to remember to
// reset swaps before starting code that swap count is required.
{
  int t = a[g]; // temporary to hold one value being swapped
  if (verbose)
    printf("Swap elements at %d (%d) and %d (%d)\n", g, a[g], h, a[h]);
  a[g] = a[h];
  a[h] = t;
  swaps++;
} // swap()

int read_int_file(char *fname, int **parray)
// Function reads file containing positive integer values and stores data in
// order in an array.  The data is terminated by a negative value.
// Function uses malloc() to get enough memory for the array, and returns
// the size of the array in integers (not bytes). The pointer to the array
// is returned in the place pointed to by parray.
// If parray is NULL, function reads file and determines how many integers are
// in the file, but does not create an array and store the values.
{
  FILE *fp;
  int *pa; // pointer to array
  int count;
  int rslt;
  int data;

  fp = fopen(fname, "r");
  if (fp == NULL) {
    fprintf(stderr, "ERROR: Cannot open %s\n", fname);
    return -1;
  }

  // Step 1. Read through array just counting how many numbers there are
  count = 0;
  while (fscanf(fp, "%d", &data) == 1) {
    if (data == -1)
      break;
    count++;
  }
  // report if asked
  if (verbose) {
    printf("File %-15s contains %d data items\n", fname, count);
  }

  // Step 2. If caller provided a parray pointer then we reread the file
  // storing data as we go.
  if (parray != NULL) {
    int k;
    rewind(fp); // back to beginning of file
    // gat an array big enough to store all the data
    pa = (int *)malloc(count * sizeof(int));
    if (pa == NULL) {
      fprintf(stderr, "ERROR: Cannot allocate space for array\n");
      fclose(fp);
      return -1;
    }
    // Got an array - fill it
    for (k = 0; k < count; k++) {
      if (fscanf(fp, "%d", pa + k) != 1) {
        fprintf(stderr, "ERROR: Problem reading item %d from file\n", k);
        fclose(fp);
        return -1;
      }
    } // endfor
  }   // endif parray non-NULL

  // All data read. Close file and provide pointer
  fclose(fp);
  *parray = pa;
  return count;
} // read_int_file()

#endif