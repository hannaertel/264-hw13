#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "tree.h"



TreeNode * helperTree(Scanner * s)
{

	//define tree node constants to be used later
	TreeNode * node;
        TreeNode * left;
        TreeNode * right;

 	Token newToken = nextToken(s);
        if(newToken.type == T_VAL) //checks if number
        {
                node = buildTreeNode(newToken);
                return node;
        }

	else if(newToken.type == T_LPAREN) //begin recursion if it is a left parentheses
        {
                left = helperTree(s);
		Token op = nextToken(s); //token for operator
		right = helperTree(s);
		Token rightSide = nextToken(s);

		if(rightSide.type == T_RPAREN)
		{
			TreeNode * opNode = buildTreeNode(op);
			opNode -> left = left;
			opNode -> right = right;
			return opNode;
		}

	}

	else
	{
		exit(1);
	}

	return(0);

}


#ifndef BUILDTREE_OFF
TreeNode * buildExpressionTree(Scanner * s) 
{
	if(s -> buf == NULL)
	{
		exit(1);
	}

	TreeNode * endTree = helperTree(s);
	Token newToken = nextToken(s);
	
	if(newToken.type != T_EOF)
	{
		exit(1);
	}

	return endTree;

}
#endif

#ifndef POSTFIX_OFF
void makePostFix(TreeNode * t, FILE * fptr) 
{
	if(t -> t.type == T_VAL)
	{
		fprintf(fptr, "%f ", t -> t.value);
		return;
	}	


	//visit left then right
	makePostFix(t -> left, fptr);
	makePostFix(t -> right, fptr);

	fprintf(fptr, "%c ", t -> t.type);

}
#endif
