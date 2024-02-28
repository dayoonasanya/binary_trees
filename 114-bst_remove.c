#include "binary_trees.h"
/**
 * successor - get the next successor i mean the min node in the right subtree
 * @node: tree to check
 * Return: the min value of this tree
 */
int successor(bst_t *node)
{
	int left = 0;

	if (node == NULL)
	{
		return (0);
	}
	else
	{
		left = successor(node->left);
		if (left == 0)
		{
			return (node->n);
		}
		return (left);
	}
}
/**
 * two_children - function that gets the next successor using the min
 * value in the right subtree, and then replace the node value for
 * this successor
 * @the_root: node tat has two children
 * Return: the value found
 */
int two_children(bst_t *the_root)
{
	int new_value = 0;

	new_value = successor(the_root->right);
	the_root->n = new_value;
	return (new_value);
}
/**
 *remove_type - function that removes a node depending of its children
 *@the_root: node to remove
 *Return: 0 if it has no children or other value if it has
 */
int remove_type(bst_t *the_root)
{
	if (!the_root->left && !the_root->right)
	{
		if (the_root->parent->right == the_root)
			the_root->parent->right = NULL;
		else
			the_root->parent->left = NULL;
		free(the_root);
		return (0);
	}
	else if ((!the_root->left && the_root->right) || (!the_root->right && the_root->left))
	{
		if (!the_root->left)
		{
			if (the_root->parent->right == the_root)
				the_root->parent->right = the_root->right;
			else
				the_root->parent->left = the_root->right;
			the_root->right->parent = the_root->parent;
		}
		if (!the_root->right)
		{
			if (the_root->parent->right == the_root)
				the_root->parent->right = the_root->left;
			else
				the_root->parent->left = the_root->left;
			the_root->left->parent = the_root->parent;
		}
		free(the_root);
		return (0);
	}
	else
		return (two_children(the_root));
}
/**
 * bst_remove - remove a node from a BST tree
 * @the_root: the_root of the tree
 * @value: node with this value to remove
 * Return: the tree changed
 */
bst_t *bst_remove(bst_t *the_root, int value)
{
	int type = 0;

	if (the_root == NULL)
		return (NULL);
	if (value < the_root->n)
		bst_remove(the_root->left, value);
	else if (value > the_root->n)
		bst_remove(the_root->right, value);
	else if (value == the_root->n)
	{
		type = remove_type(the_root);
		if (type != 0)
			bst_remove(the_root->right, type);
	}
	else
		return (NULL);
	return (the_root);
}
