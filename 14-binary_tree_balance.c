#include <stdlib.h>
#include "binary_trees.h"

/**
 * binary_tree_balance - measure the balance factor of the binary tree
 * @tree: pointer to the next node
 * Return: return the balanced tree
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	if (tree->left)
		left_h = 1 + binary_tree_balance(tree->left);

	if (tree->right)
		right_h = 1 + binary_tree_balance(tree->right);

	return ((int)left_h - (int)right_h);
}
