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

void inorder_no_recursive(binary_node* b){
    std::stack<binary_node*> stack1;
    binary_node* tmp = b;
    while(!stack1.empty() || tmp != NULL){
        while(tmp != NULL){
            //向左搜寻
            stack1.push(tmp);
            tmp = tmp->left;
        }
        if (!stack1.empty()){
            //回退一下，搜寻右边
            tmp = stack1.top();
            //每调转一下方向就打印一下当前值
            printf("%c,",tmp->data);
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
//ca#b##e#f##
void isBST(binary_node* b){
    binary_node* tmp = b;
    std::stack<binary_node*> stack1;
    std::vector<elem_type > vec_value;
    //每个元素都被压栈和出栈一次，时间复杂度O(n)
    while(!stack1.empty() || tmp != NULL){
        while(tmp != NULL){
            stack1.push(tmp);
            tmp = tmp->left;
        }
        if(!stack1.empty()){
            tmp = stack1.top();
            stack1.pop();
            vec_value.push_back(tmp->data);
            tmp = tmp->right;
        }
    }
    bool flag = true;
    printf("vec_value = ");
    //普通的for循环，时间复杂度也为O(n)
    for (auto iterator = vec_value.begin(); iterator != vec_value.end() - 1; ++iterator) {
        printf("%c,",*iterator);
        if(*iterator > *(iterator + 1))
            flag = false;
    }
    printf("%c\n",vec_value.back());
    printf("isBST = %d\n",flag);
}
void mirror(binary_node* b){
    if (b == NULL)
        return;
    if (b->left == NULL && b->right == NULL)
        return;
    binary_node* tmp = b->left;
    b->left = b->right;
    b->right = tmp;
    mirror(b->left);
    mirror(b->right);
}
void mirror_not_recursive(binary_node* b){
    std::queue<binary_node*> queue1;
    queue1.push(b);
    while(!queue1.empty()){
        binary_node* elem = queue1.front();
        queue1.pop();
        binary_node* tmp = elem->left;
        elem->left = elem->right;
        elem->right = tmp;
        if(elem->left != NULL)
            queue1.push(elem->left);
        if (elem->right != NULL)
            queue1.push(elem->right);
    }
}
void mirror_not_recursive_stack(binary_node* b){
    std::stack<binary_node*> stack1;
    stack1.push(b);
    while(!stack1.empty()){
        binary_node* elem = stack1.top();
        stack1.pop();
        binary_node* tmp = elem->left;
        elem->left = elem->right;
        elem->right = tmp;
        if(elem->left != NULL)
            stack1.push(elem->left);
        if (elem->right != NULL)
            stack1.push(elem->right);
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

    printf("inorder no recursive\n");
    inorder_no_recursive(b);
    printf("\n");

    printf("DFS\n");
    DFS_Recursive(b);
    printf("\n");

    printf("BFS\n");
    BFS(b);
    printf("\n");

    printf("isBST\n");
    isBST(b);
    printf("\n");

    printf("mirror b\n");
    mirror(b);
    inorder_no_recursive(b);
    printf("\n");

    printf("mirror not recursive b\n");
    mirror_not_recursive(b);
    inorder_no_recursive(b);
    printf("\n");

    printf("mirror not recursive stack b\n");
    mirror_not_recursive_stack(b);
    inorder_no_recursive(b);
    printf("\n");
    return 0;
}