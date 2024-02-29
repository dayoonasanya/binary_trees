#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"
/**
 * check_max - goes through a binary tree cheking ropt as max value
 * @tree: pointer to the root
 * Return: 1 if all nodes are max, 0 in other cases
 **/
int check_max(const binary_tree_t *tree)
{
	int tmp1 = 1, tmp2 = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		tmp1 = check_max(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		tmp2 = check_max(tree->right);
	}
	return (tmp1 && tmp2);
}
/**
 * binary_tree_is_heap - checks if a binary tree is heap
 * @tree: pointer to the node
 * Return: 1 in case BTS /  0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int tmp;

	if (!tree)
		return (0);

	tmp = binary_tree_is_complete(tree);
	if (!tmp)
		return (0);
	return (check_max(tree));
}
