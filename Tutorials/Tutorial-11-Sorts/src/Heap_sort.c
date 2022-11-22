

#define	LEFT(n)		(2*n +1)		// formula for index of left child of n
#define	RITE(n)		(2*n +2)		// formula for index of right child of n

void heapify(int *a, int size, int i)
// Treating i as index of root, make adjustments so that all components of
// complete tree below i form a heap
{
	int	left, right, root;

	// determine indexes for left and right subtrees of whatever node given
	root = i;
	left = LEFT(root);
	right = RITE(root);

	// Now look at relationship between nodes. In a maxheap, the parent is
	// supposed to be largest value of parent-value, left-value, right-value.
	// For any arbitrary node, there are no children, a left child or both left
	// and right children.
	if (left >= size)	{
		// left index greater than size of array. So no left child. Cannot be
		// a right child, so root is largest. Done.
		return;
		}
	// We have left child, do we have right child?
	if (right < size)	{
		// yes we do, so we have to figure out which child is bigger
		if (a[right] > a[left])	{
			// right child bigger than the left - see if it is also bigger
			// than the root
			if (a[right] > a[root])	{
				// Bigger than root, so need to swap root and right child
				// values.
				swap (a, right, root);
				// This may mess up the right subtree, so fix it up
				heapify (a, size, right);
				// and that is it.
				return;
				}//endif right bigger than root
			}//endif right bigger than left
		}//endif there is a right

	// We got here either because there was no right child, or the right child
	// is less than the left child.
	// So all we have to do is see if the left value and the parent value need
	// to be swapped.
	if (a[left] > a[root])	{
		// Bigger than root, so need to swap root and left child values.
		swap (a, left, root);
		// This may mess up the right subtree, so fix it up
		heapify (a, size, left);
		// and that is it.
		return;
		}//endif left bigger than root

	// We go here because the root was bigger than the left and if it exists,
	// the right. That's actually what we want, so we are done.
	return;
}// heapify() 


 
long int heapsort(int *a, int size)
// Perform heapsort on array a. This is done by turning array into a heap,
// then repeatedly removing the front value (the largest) and putting it in
// the last location, then heapifying the reduced size array. 
{
	int		k;

	swaps = 0;
	// Starting with first non-leaf, heapify every tree working our way to
	// the top. 
	for (k = size / 2 - 1; k >= 0; k--) 
		heapify(a, size, k);
	// The whole array is a heap. So, we know the biggest value is in a[0],
	// and we want it in a[size-1] (biggest value in biggest index). So
	// we just put the biggest where it is supposed to be, and put the
	// value that was there at the root of the tree. This breaks the heap,
	// so we re-heapify the array - less the last item that we have put
	// where we want.

	for (k = size - 1; k >= 0; k--) { 
		// Move current root to end 
		swap(a, 0, k); 
		// and fix up heap. Note that size keeps going down by one.
		heapify(a, k, 0); 
		}//endfor
	return swaps;
}//heapsort() 
