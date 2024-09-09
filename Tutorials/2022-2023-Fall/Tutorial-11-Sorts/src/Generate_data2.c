// MAKEDATA2.C
// Code to create the data files used for ELEC278 Lab 5.

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


#define DATASIZE 1000
char *fnames[3] = {"ASCENDINGSMALL.TXT", "DESCENDINGSMALL.TXT",
                   "RANDOMSMALL.TXT"};

int main(int argc, char *argv[]) {
  FILE *fp; // used to create all three files
  int k;
  int arraysize = -1;        // will be set to required data size
  unsigned int seed = 27901; // just grabbed this number out of the air
  unsigned int rn;           // used for computed random number

  // Check if user specified a size for the data files
  if (argc == 2) {
    // Assume they did because there is an argument on command line
    arraysize = atoi(argv[1]);
  }
  // Now either we got legitimate size, or we got nothing (or an incorrect
  // size).
  if (arraysize < 1)
    arraysize = DATASIZE; // use default
  printf("MAKEDATA2: Building files with %d data items\n", arraysize);

#if 0
	// **** This version is used to generate a RANDOM file with small random
	// **** to work with RADIX sort		
	// Build the file with ascending data first
	fp = fopen (fnames[0], "w");
	if (fp == NULL)	{
		fprintf (stderr, "ERROR: Cannot create %s\n", fnames[0]);
		return -1;
		}
	for (k=1; k<=arraysize; k++)	{
		fprintf (fp, "%d\n", k);
		}
	fprintf (fp, "%d\n", -1);
	fclose (fp);

	// Build the file with descending data next
	fp = fopen (fnames[1], "w");
	if (fp == NULL)	{
		fprintf (stderr, "ERROR: Cannot create %s\n", fnames[1]);
		return -1;
		}
	for (k=arraysize; k>=1; k--)	{
		fprintf (fp, "%d\n", k);
		}
	fprintf (fp, "%d\n", -1);
	fclose (fp);
#endif

  // Finally, build the file with random data. This version only generates
  // random numbers between 0 and 32767.
  srand(seed);
  fp = fopen(fnames[2], "w");
  if (fp == NULL) {
    fprintf(stderr, "ERROR: Cannot create %s\n", fnames[2]);
    return -1;
  }
  for (k = 1; k <= arraysize; k++) {
    rn = rand();
    fprintf(fp, "%d\n", rn);
  }
  fprintf(fp, "%d\n", -1);
  fclose(fp);

  printf("Data files created for Lab 5\n");
  return 0;
} // main()
