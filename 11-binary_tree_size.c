#include "binary_trees.h"

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: size of the tree or 0
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size;
	size_t left_size;
	size_t right_size;

	if (tree == NULL)
		return (0);

	left_size = 0;
	right_size = 0;

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	size = 1 + left_size + right_size;

	return (size);

}
