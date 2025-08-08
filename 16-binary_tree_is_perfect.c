#include "binary_trees.h"

/**
 * depth - Measures depth of a node from the root
 * @tree: Pointer to the node
 *
 * Return: Depth of the node
 */
int depth(const binary_tree_t *tree)
{
	return (tree && tree->parent ? 1 + depth(tree->parent) : 0);
}

/**
 * is_perfect_rec - Recursive check for perfect tree
 * @tree: Pointer to the root node
 * @leaf_depth: Depth where leaves should be
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect_rec(const binary_tree_t *tree, int leaf_depth)
{
	if (!tree)
		return (1);

	if (!tree->left && !tree->right)
		return (depth(tree) == leaf_depth);

	if (!tree->left || !tree->right)
		return (0);

	return (is_perfect_rec(tree->left, leaf_depth) &&
			is_perfect_rec(tree->right, leaf_depth));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree
 *
 * Return: 1 if the tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
const binary_tree_t *leaf;

	if (!tree)
		return (0);

	leaf = tree;
	while (leaf->left)
		leaf = leaf->left;

	return (is_perfect_rec(tree, depth(leaf)));
}
