#include "binary_trees.h"


/**
 * depth - measures the depth of a node in a binary tree
 * @node: pointer to the node to measure the depth
 *
 * Return: depth of the tree or 0
 */
int depth(const binary_tree_t *node)
{
	int d;

	d = 0;
	while (node != NULL)
	{
		d++;
		node = node->left;
	}
	return (d);
}

/**
 * is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * @d: depth of the tree
 * @level: current level
 *
 * Return: 1 if perfect, 0 otherwise
 */
int is_perfect(const binary_tree_t *tree, int d, int level)
{
	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (d == level);

	if (tree->left == NULL || tree->right == NULL)
		return (1);

	return (is_perfect(tree->left, d, level + 1)
            && is_perfect(tree->right, d, level + 1));
}

/**
 * binary_tree_is_perfect - checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	int dep;

	dep = depth(tree);

	return ((dep == (tree->n - 1)) ? 1 : 0);
}
