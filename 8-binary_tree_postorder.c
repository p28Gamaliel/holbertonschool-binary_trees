#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_postorder - traverse the tree from left,
 *						to right to the last node
 * @tree: tree that will be traversed
 * @func: is a pointer to a function to call for each node
 */

void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	if (tree == NULL || func == NULL)
		return;

	binary_tree_postorder(tree->left, func);
	binary_tree_postorder(tree->right, func);
	func(tree->n);
}
