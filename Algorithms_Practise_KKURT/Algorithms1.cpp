//BST Operations

InOrderWalk(x) 
{ // x is a pointer to a node in the tree
	if (x != NULL) {
		InOrderWalk(left[x]); // walk into left subtree
		print key[x]; // visit the current node
		InOrderWalk(right[x]); // walk into right subtree
	}
}

BST_Search(x, k) 
{
	if (x == NULL)
		return NULL; // to denote that k is not found
	if (k == key[x])
		return x; // i.e. return the pointer to the node with key k
	if (k < key[x]) // k cannot be in the right subtree
		return BST_Search(left[x], k);
	else // k cannot be in the left subtree
		return BST_Search(right[x], k);
}

BST_Search_Iterative(x, k) 
{
	while (x != NULL and k != key[x]) {
		if (k < key[x]) // k cannot be in the right subtree
			x = left[x]; // continue using the left subtree
		else // k cannot be in the left subtree
			x = right[x]; // continue using the right subtree
	}
	return x;
}

BST_Minimum(x) 
{
	while (left[x] != NULL) // if there exists a left child, its key is
		x = left[x]; // smaller or equal to the current node
	return x;
}

BST_Maximum(x) 
{
	while (right[x] != NULL) // if there exists a right child, its key is
		x = right[x]; // greater or equal to the current node
	return x;
}

BST_Successor(x) 
{
	if (right[x] != NULL) // simple case
		return (BST_Minimum(right[x]));
	// find the closest ancestor of x
	// for which x is in the left subtree
	y = parent[x]; t = x;
	while (y != NULL and t = right[y]) {
		t = y;
		y = parent[t];
	}
	return y;
}

BST_Insert(T, x) { // T: the tree, x: a new node to be inserted
	if (root[T] == NULL)
		root[T] = x; // inserting into empty BST
	else {
		y = root[T]; // y follows a path to find the correct place for x
		z = NULL; // z will simply follow y (value of y in previous iteration)
		while (y != NULL) { // as long as we can go deeper in the BST
			z = y; // make y follow z, and go into the correct subtree
			y = (key[x] < key[y]) ? left[y] : right[y];
		}
		parent[x] = z; // z keeps the correct parent for x
		if (key[x] < key[z]) // decide whether x will be a left or right child
			left[z] = x;
		else
			right[z] = x;
	}
}

SortUsingBST(A) 
{ // A: the array of numbers to be sorted
	root[T] = NULL; // create an empty BST
	for (i = 1; i <= length[A]; i++) { // for each number
		newNode = create a new node with key A[i];
		BST_Insert(T, newNode); // insert the key (number) into BST
	}
	InOrderWalk(root[T]); // will output the keys in sorted order
}
