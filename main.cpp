#include <iostream>
#define ERROR -1;
typedef char elem_type;
struct binary_node{
    char data;
    binary_node* left;
    binary_node* right;
};
//default preorder create
int create_tree(binary_node** b){
    char c;
    scanf("%c",&c);
    if (c == '#'){
        *b = NULL;
    }else{
        //这里注意，如果传入进来的是*b 那么走到这里重新分配内存空间之后就不是在操作实参了。
        *b =  (binary_node*)malloc(sizeof(binary_node));
        if (b == NULL)
            return ERROR;
        (*b)->data = c;
        create_tree(&(*b)->left);
        create_tree(&(*b)->right);
    }
};
//preorder traversal
void preorder(binary_node* b){
    if(b != NULL){
        printf("%c,",b->data);
        preorder(b->left);
        preorder(b->right);
    }
}
int main() {
    //传递指针的引用
    setbuf(stdin,NULL);
    binary_node* b = NULL;
    create_tree(&b);
    printf("pre order\n");
    preorder(b);
    printf("\n");
    std::cout << "Hello, World!" << std::endl;
    return 0;
}