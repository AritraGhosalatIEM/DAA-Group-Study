#include <stdio.h>
#include <stdlib.h>

struct bstnode
{
    int data;
    struct bstnode* left;
    struct bstnode* right;
};

struct bstnode* root = NULL;  // global pointer to the root

struct bstnode* newnode(int x)
{
    struct bstnode* temp = (struct bstnode*)malloc(sizeof(struct bstnode));
    temp->data = x;
    temp->left = temp->right = NULL;

    return temp;  // You should return temp, not newnode
}

struct bstnode* insert(struct bstnode* root, int data)
{
    if (root == NULL)  // base case
        return newnode(data);  // Return the new node

    if (data <= root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}

int search(struct bstnode* root, int data)
{
    if (root == NULL)
        return 0;
    if (data == root->data)  // Use '==' for comparison
        return 1;
    if (data <= root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

void preorder_traversal(struct bstnode* node)
{
    if (node == NULL)
        return;
    printf("%d\t", node->data);
    preorder_traversal(node->left);
    preorder_traversal(node->right);
}

void postorder_traversal(struct bstnode* node)
{
    if (node == NULL)
        return;
    postorder_traversal(node->left);
    postorder_traversal(node->right);    
    printf("%d\t", node->data);
}

void inorder_traversal(struct bstnode* node)
{
    if (node == NULL)
        return;
    inorder_traversal(node->left);
    printf("%d\t", node->data);
    inorder_traversal(node->right);
}

struct bstnode* deleteNode(struct bstnode* root, int k)
{
    // Base case
    if (root == NULL)
        return root;
 
    // Recursive calls for ancestors of
    // node to be deleted
    if (root->data > k) {
        root->left = deleteNode(root->left, k);
        return root;
    }
    else if (root->data < k) {
        root->right = deleteNode(root->right, k);
        return root;
    }
 
    // We reach here when root is the node
    // to be deleted.
 
    // If one of the children is empty
    if (root->left == NULL) {
        struct bstnode* temp = root->right;
        free(root);
        return temp;
    }
    else if (root->right == NULL) {
        struct bstnode* temp = root->left;
        free(root);
        return temp;
    }
 
    // If both children exist
    else {
 
        struct bstnode* successorParent = root;
 
        // Find successor
        struct bstnode* succ = root->right;
        while (succ->left != NULL) {
            successorParent = succ;
            succ = succ->left;
        }
 
        // Delete successor.  Since successor
        // is always left child of its parent
        // we can safely make successor's right
        // right child as left of its parent.
        // If there is no succ, then assign
        // succ->right to succParent->right
        if (successorParent != root)
            successorParent->left = succ->right;
        else
            successorParent->right = succ->right;
 
        // Copy Successor Data to root
        root->data = succ->data;
 
        // Delete Successor and return root
        free(succ);
        return root;
    }
}

void max(struct bstnode* start)
{
	if(start->right==NULL)
	 printf("MAX=%d\n",start->data);
	else
	 max(start->right);	
}

void min(struct bstnode* start)
{
	if(start->left==NULL)
	 printf("MIN=%d\n",start->data);
	else
	 max(start->left);	
}



int main()
{
    // INSERTION INTO BST
    int i,n;
    printf("Enter the number of insertions-\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    	int ele;
    	printf("Enter data\n");
    	scanf("%d",&ele);
    	root=insert(root,ele);
    	
	}
    
    //TRAVERSAL
  printf("\nAfter insertion-\n");
    printf("\nPREORDER-\n");\
    preorder_traversal(root);

    printf("\nPOSTORDER-\n");
    postorder_traversal(root);*/

    printf("\nINORDER-\n");
    inorder_traversal(root);
    
    //MAX AND MIN
    max(root);
    min(root);
    
    
     printf("\n\nSEARCHING-\n");
    
    printf("Enter element to be searched");
    scanf("%d",&n);
    
   //SEARCH
    if(search(root,n)==1)
     printf("\nelement found\n");
    else
     printf("\nelement not found");
 
 
    //DELETION FROM BST
     printf("Enter the number of deletions-\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
    	int ele;
    	printf("\nEnter data\n");
    	scanf("%d",&ele);
    	root=deleteNode(root,ele);
    	
	}
     
	 //TRAVERSAL    
    printf("\nAfter deletion-\n");
    printf("\nPREORDER-\n");\
    preorder_traversal(root);

    printf("\nPOSTORDER-\n");
    postorder_traversal(root);

    printf("\nINORDER-\n");
    inorder_traversal(root);*/

    return 0;
}//main()
