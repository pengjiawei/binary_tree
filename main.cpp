#include <iostream>
#include <stack>
#include <queue>

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
void preorder_no_recursive(binary_node* b){
    std::stack<binary_node*> stack1;
    binary_node* tmp = b;
    while(!stack1.empty() || tmp != NULL){
        while(tmp != NULL){
            //向左搜寻
            printf("%c,",tmp->data);
            stack1.push(tmp);
            tmp = tmp->left;
        }
        if (!stack1.empty()){
            //搜寻右边
            tmp = stack1.top();
            stack1.pop();
            tmp = tmp->right;
        }
    }
}
//和递归先序遍历是一样的
void DFS_Recursive(binary_node* b){
    printf("%c,",b->data);
    if (b == NULL)
        return;
    if(b->left != NULL)
        DFS_Recursive(b->left);
    if(b->right != NULL)
        DFS_Recursive(b->right);
}
//广度优先，层次遍历
void BFS(binary_node* b){
    std::queue<binary_node*> queue;
    queue.push(b);
    binary_node* tmp = (binary_node *) malloc(sizeof(binary_node));
    while(!queue.empty()){
        //按层次出队
        tmp = queue.front();
        printf("%c,",tmp->data);

        //把节点的左孩子和右孩子按顺序入队
        if(tmp->left != NULL)
            queue.push(tmp->left);
        if (tmp->right != NULL)
            queue.push(tmp->right);
        queue.pop();
    }
}
int main() {
    //abd##e##cf##g##
    //传递指针的引用，创建二叉树这里也可以改成函数参数返回，直观上写法会比现在这样简单
    setbuf(stdin,NULL);
    binary_node* b = NULL;
    create_tree(&b);

    printf("pre order\n");
    preorder(b);
    printf("\n");

    printf("preorder no recursive\n");
    preorder_no_recursive(b);
    printf("\n");

    printf("DFS\n");
    DFS_Recursive(b);
    printf("\n");

    printf("BFS\n");
    BFS(b);
    printf("\n");
    return 0;
}