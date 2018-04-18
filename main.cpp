#include <iostream>
#define ERROR -1;
typedef char elem_type;
struct binary_node{
    elem_type data;
    binary_node* left;
    binary_node* right;
};
//default preorder create
int create_tree(binary_node* b){
    char c;
    setbuf(stdin,NULL);
    scanf("%c",&c);
    if (c == '#'){
        b = NULL;
    }else{
        b = (binary_node *) malloc(sizeof(binary_node));
        if (b == NULL)
            return ERROR;
        b->data = c;
        create_tree(b->left);
        create_tree(b->right);
    }
};
//preorder traversal
void preorder(binary_node* b){
    if(b){
        printf("data = %c,",b->data);
        preorder(b->left);
        preorder(b->right);
    }
}
int main() {
    binary_node* b = NULL;
    create_tree(b);
    preorder(b);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}