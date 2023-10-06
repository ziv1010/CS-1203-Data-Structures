#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

struct node{
    int key;
    struct node *left, *right;
};

struct stack{
    int sp;
    struct node* arr[SIZE];
};

typedef struct stack STACK;

void initStack(STACK *s){
    s->sp = -1;
}

int isStackEmpty(STACK *s){
    return (s->sp == -1);
}

int isStackFull(STACK *s){
    return (s->sp == SIZE-1);
}

void push(STACK *s, struct node* elm){
    if (isStackFull(s)){
        printf("Stack overflow\n");
        return;
    }
    s->arr[++(s->sp)] = elm;
}

struct node* pop(STACK *s){
    if (isStackEmpty(s)){
        printf("Stack underflow\n");
        return NULL;
    }
    return(s->arr[(s->sp)--]);
}

struct node * createNode(int k){
    struct node *temp;

    temp = (struct node *) malloc(sizeof(struct node));
    temp->key = k;
    temp->left = temp->right = NULL;
    return temp;
}

void displayNode(struct node *temp){
    if (temp == NULL)
        printf("Node does not exist\n");
    else
        printf("%x %d\n", (unsigned int) temp, temp->key);
}

struct node * search(struct node * anode, int k){
    struct node *temp, *parent;

    if (anode == NULL) return NULL;

    temp = anode;
    while (temp != NULL){
        if (temp->key == k){
            return temp;
        }

        if (k < temp->key){
            temp = temp->left;
        }
        else{
            temp = temp->right;
        }
    }
    return NULL;
}

struct node * insert(struct node * anode, int k){
    struct node *temp, *parent;
    int direction;

    if (anode == NULL){
        anode = createNode(k);
        return anode;
    }

    temp = anode;
    while (temp != NULL){
        if (temp->key == k){
            printf("node with value %d exists\n", k);
            return temp;
        }

        if (k < temp->key){
            parent = temp;
            temp = temp->left;
            direction = 0;
        }
        else{
            parent = temp;
            temp = temp->right;
            direction = 1;
        }
    }
    temp = createNode(k);
    if (direction == 0)
        parent->left = temp;
    else
        parent->right = temp;

    return temp;
}

struct node * delete (struct node * anode, int k){

    struct node *temp, *parent, *intemp, *inparent;
    int direction, flag = 0, val;
     
    if (anode == NULL){ 
	printf("Tree empty\n");
        return NULL;
    }
   
    parent = NULL; 
    temp = anode;

    while (temp != NULL){
	if (temp->key == k){
           flag = 1;
	   break;
        }
    	if (k < temp->key){
	    parent = temp;
            temp = temp->left;
            direction = 0;
        }
        else{
	    parent = temp;
	    temp = temp->right;
            direction = 1;
        }
    }

    if (flag == 0){
	printf("Node not found\n");
        return NULL;
    }

    if ((temp->left == NULL) && (temp->right == NULL)){
        if (direction == 0) parent->left = NULL;
        else parent->right = NULL;
        return temp;
    }

    if ((temp->left != NULL) && (temp->right == NULL)){
	if (parent == NULL){
		anode = temp->left;
		return temp;
        }
        if (direction == 0) parent->left = temp->left;
        else parent->right = temp->left;
        return temp;
    }

    if ((temp->left == NULL) && (temp->right != NULL)){
	if (parent == NULL){
		anode = temp->right;
		return temp;
        }
        if (direction == 0) parent->left = temp->right;
        else parent->right = temp->right;
        return temp;
    }

    if ((temp->left != NULL) && (temp->right != NULL)){
        inparent = temp;	
        intemp = temp->right;
        printf("%d %d\n", inparent->key, intemp->key);

    	while(intemp->left != NULL){ 
	   inparent = intemp;
           intemp = intemp->left;
        }
        printf("%d %d\n", inparent->key, intemp->key);

	val = temp->key;
	temp->key = intemp->key;
        intemp->key = val;

        printf("%d %d\n", temp->key, intemp->key);

	if ((intemp->right == NULL))
		inparent->left = NULL;
	else
        	inparent->left = intemp->right;

	return intemp;
    }

    return NULL;
}

// Define a function to perform an inorder traversal of a binary tree
// We use stack to replace the recursion
void inorder(struct node * anode){
    // If the current node is NULL (empty tree or leaf node), return
    if (anode == NULL)
        return;

    // Initialize a stack to help with the traversal
    STACK st;
    initStack(&st); 

    struct node* curr = anode; // Start traversal from the root node

    while (curr != NULL || !isStackEmpty(&st)){ // Continue until all nodes are processed
        while (curr != NULL){
            // Push the current node onto the stack and move to its left child
            push(&st, curr); // to push a node onto the stack
            curr = curr->left;
        }

        // When we reach a NULL left child or after processing left subtrees,
        // pop a node from the stack, print its value, and move to its right child
        curr = pop(&st); 
        printf("%d ", curr->key); 
        curr = curr->right; // Move to the right for further traversal
    }
}


void preorder(struct node * anode){
    if (anode != NULL) {
        printf("%d ", anode->key);
        preorder(anode->left);
        preorder(anode->right);
    }
}

void postorder(struct node * anode){
    if (anode != NULL) {
        postorder(anode->left);
        postorder(anode->right);
        printf("%d ", anode->key);
    }
}

void displayTree(struct node* root, int space)
{
    int i;

    if (root == NULL) return;
 
    space += 10;
 
    // Process right child first
    displayTree(root->right, space);
 
    // Print current node after space count
    printf("\n");
    for (i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);
 
    // Process left child
    displayTree(root->left, space);
}

void freeTree(struct node * anode){
    if (anode != NULL) {
        freeTree(anode->left);
        freeTree(anode->right);
        free(anode);
    }
}

int main()
{
    struct node * root = NULL, *temp;
    int elm, menu;

    while(1){
      printf("\n0. exit, 1. initialize, 2. search, 3. insert, 4. delete,\n ");
      printf("5. inorder, 6. preorder, 7. postorder, 8. free tree, 9. display. Input Choice: ");
          scanf("%d", &menu);

          switch(menu){
           case 0: exit(0);

           case 1: root = NULL;
                   break;

           case 2: printf("Give element to search: ");
                   scanf("%d", &elm);
		   temp = search(root, elm);
		   displayNode(temp);
                   break;

           case 3: printf("Give element to insert: ");
                   scanf("%d", &elm);
		   if (root == NULL)
		   	temp = root = insert(root, elm);
		   else
		   	temp = insert(root, elm);
		   displayNode(temp);
                   break;

           case 4: printf("Give element to delete: ");
                   scanf("%d", &elm);
		   if (root == NULL)
                      printf("Tree empty\n");
		   else if ((root->key == elm) && (root->left == NULL) && (root->right == NULL)){
		      temp = root;
                      root = NULL;
		   }
		   else if ((root->key == elm) && (root->left != NULL) && (root->right == NULL)){
			temp = root;
			root = root->left;
		   }
		   else if ((root->key == elm) && (root->left == NULL) && (root->right != NULL)){
			temp = root;
			root = root->right;
		   }
		   else
		   	temp = delete(root, elm);

		   displayNode(temp);
                   break;

           case 5: inorder(root);
		   printf("\n");
                   break;

           case 6: preorder(root);
                   printf("\n");
                   break;

           case 7: postorder(root);
                   printf("\n");
                   break;

           case 8: freeTree(root);
                   root = NULL;
                   break;

           case 9: if (root == NULL) printf("Tree empty\n");
		   displayTree(root, 0);
                   break;

           default: printf("Wrong choice\n");
         }
        }

    return 0;
}
