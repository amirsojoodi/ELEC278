// L5_BCKTSORT.C 
// Simple implementation of bucket sort

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



// Each Bucket is implemented as linked list of nodes. Node has actual data
// and pointer to next node.
struct listnode  {    // nodes in linked list
    int				data;
    struct listnode	*next;
};
typedef struct listnode	ListNode;


ListNode *newlistnode (int value)
// Create new listnode, initializing it with value.
{
	ListNode   *p = malloc (sizeof (ListNode));
	p->data = value;
	p->next = NULL;
	return p;
}//newlistnode()


// Bucket array is array of node lists.
    
struct intlist	{
	int         count;		// how many items in this bucket
	ListNode    *list;		// pointer to linked list of actual data
};
typedef struct intlist IntList;


IntList *newIntListArray (int size)
// Create initialized array of IntLists. This is essentially the set of buckets.
// Parameter size indicates how big an array of lists to create.
{
	IntList *pil = malloc (size * sizeof(IntList));
	int		i;
	for (i=0; i<size; i++)	{
		pil[i].count = 0;
		pil[i].list = NULL;
		}
	return pil;
}//newIntListArray()


void insertIntoList (IntList *pl, int value)
// Given pointer to IntList and value, create node and insert in
// correct place in list. That is, we're doing an insertion sort into list.
{
	ListNode *pnode = newlistnode (value);
	ListNode *current;

	// Where does new node go? If list currently empty or value
	// less than value in first node, new node goes to front
	if (pl->list == NULL || pl->list->data > value)	{
		// new node goes to front
		pnode->next = pl->list;
		pl->list = pnode;
		pl->count++;
		return;
		}
	// Gotta insert somewhere in list. Start by pointing to
	// first in list, which we know is less than value
	current = pl->list;
	while (current->next != NULL)	{
		if (current->next->data > value)	{
			// Node goes after current, before next
			pnode->next = current->next;
			current->next = pnode;
			pl->count++;
			return;
			}
		current = current->next;
		}
	// exit loop only if new node belongs at end
	current->next = pnode;
	pl->count++;
	return;
}//InsertIntoList()


int deletefromlist (IntList *pl, int *value)
// Remove next item from list, storing value in place pointed to
{
	ListNode	*ptmp;
	if (pl->list == NULL)	return 0;
	ptmp = pl->list;
	pl->list = ptmp->next;
	*value = ptmp->data;
	free (ptmp);
	return 1;
}//deletefromlist()


void printlist (IntList *pl)
{
	if (pl->list == NULL)	printf ("--NO ENTRIES--");
	else	{
		ListNode	*ptemp;
		ptemp = pl->list;
		while (ptemp != NULL)	{
			printf (" %3d", ptemp->data);
			ptemp = ptemp->next;
			}
		}
	putchar ('\n');
}


int numbers [] = {34, 99,  27, 204, 435, 927, 525, 601,  87,  12,
				   3, 66, 108,  57, 366, 278, 436,  61, 542, 269 };
int	count = 20;

int bucket (int num)
{
	return (num * count)/1000;
}//bucket()


void printarray (int *a, int count)
{
	int i;
	for (i=0; i<count; i++)	printf (" %3d", a[i]);
	putchar ('\n');
}

int main (void)
{
	int		i, k, bk, dt;
	IntList	*Buckets;
	printf ("Bucket sort\n");
	printarray (numbers, count);
	Buckets = newIntListArray (20);
	// go through array, put all data in right bucket
	for (i=0; i<count; i++)	{
		dt = numbers [i];		// get data value
		bk = bucket (dt);		// figure out bucket
		printf ("Data value %d into bucket %d\n", dt, bk);
		insertIntoList (&Buckets[bk], dt);
		}
	// Now show buckets
	for (i=0; i<count; i++)	{
		printf ("%2d (%2d): ", i, Buckets[i].count);
		printlist (&Buckets[i]);
		}

	// Put all numbers back
	k = 0;				// place to put number
	// Go through all buckets
	for (i=0; i<count; i++)	{
		while (deletefromlist (&Buckets[i], &dt))	{
			numbers [k++] = dt;
			}
		}
	// Show final list
	printf ("Final sorted array:\n");
	printarray (numbers, count);
	printf ("\nHit any character to exit:"); fflush (stdout);
	getchar ();
	return 0;
}
		
		

		




	
