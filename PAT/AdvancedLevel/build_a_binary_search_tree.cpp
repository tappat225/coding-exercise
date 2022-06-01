/**
 * Title: N_AZ1010 Build A Binary Search Tree
 * 
 * 
 * Link: https://www.nowcoder.com/pat/5/problem/4323
 * 
 * State: Unsolved.
*/
#include<iostream>
using namespace std;

struct BTNode{
    int data;
    BTNode *lchild,*rchild;
};

BTNode* newnode(int v){
    BTNode* node = new BTNode;
    node->data=v;
    node->lchild = NULL;
    node->rchild = NULL;
    return node;
}

int main(){
    BTNode *BST=NULL;
    
}