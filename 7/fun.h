#include "head.h"
Status InitBiTree(BiTree &T) {
    if (T == NULL) 
    return ERROR; 
    T = NULL;
    return OK;
}

void DestroyBiTree(BiTree &T)
{
    if (T != nullptr) {
        DestroyBiTree(T->lchild); 
        DestroyBiTree(T->rchild); 
        delete T; 
        T = nullptr; 
    }
}

Status CreateBiTree(BiTree &T, Tdatatype *definition, int &index){
  Tdatatype val = definition[index++];
  if (val == -1) { 
    T = nullptr;//空节点或者停止
  } else {
    T =new BiTNode;
    if (!T) {
      return ERROR; 
    }
    T->data = val;
    CreateBiTree(T->lchild, definition, index); 
    CreateBiTree(T->rchild, definition, index); 
  }
  return OK; 
}

bool BiTreeEmpty(BiTree T){
    if(T==NULL){
        return true;
    }else{
        return false;
    }
}

int BiTreeDepth(BiTree T){
    if(T==NULL){
        return 0;
    }else{
        int right=BiTreeDepth(T->rchild);
        int left=BiTreeDepth(T->lchild);
        return (right>left?right:left)+1;
    }
}

BiTree Parent(BiTree T, Tdatatype e) {
  if (T == NULL || T->data == e) {
    return NULL; 
  }
  
  
  if ((T->lchild != NULL && T->lchild->data == e) || 
      (T->rchild != NULL && T->rchild->data == e)) {
    return T;
  }


  BiTNode* leftResult = Parent(T->lchild, e);
  if (leftResult != NULL) { 
    return leftResult;
  }

  BiTNode* rightResult = Parent(T->rchild, e);
  if (rightResult != NULL) { 
    return rightResult;
  }

  return NULL;
}

BiTree LeftChild(BiTree T, Tdatatype e) {
    
    if (T == NULL) {
        return NULL; 
    }

    if (T->data == e) {
        if (T->lchild != NULL) {
            return T->lchild;
        } else {
            return NULL; 
        }
    }

    BiTNode* leftResult = LeftChild(T->lchild, e);
    if (leftResult != NULL) {
        return leftResult; 
    }

    BiTNode* rightResult = LeftChild(T->rchild, e);
    if (rightResult != NULL) {
        return rightResult; 
    }

    return NULL; 
}

BiTree RightChild(BiTree T, Tdatatype e) {
    
    if (T == NULL) {
        return NULL; 
    }

    if (T->data == e) {
        if (T->rchild != NULL) {
            return T->rchild;
        } else {
            return NULL; 
        }
    }

    BiTree leftResult = RightChild(T->lchild, e);
    if (leftResult != NULL) {
        return leftResult; 
    }

    BiTree rightResult = RightChild(T->rchild, e);
    if (rightResult != NULL) {
        return rightResult; 
    }

    return NULL; 
}

BiTree LeftSibling(BiTree T, Tdatatype e) {
    BiTree pNode = Parent(T, e); 
    if (pNode == NULL) {
        return NULL; 
    }

    if (pNode->rchild != NULL && pNode->rchild->data == e && pNode->lchild != NULL) {
        return pNode->lchild; 
    }
    return NULL; 
    
}

BiTree RightSibling(BiTree T, Tdatatype e) {
    BiTree pNode = Parent(T, e); 
    if (pNode == NULL) {
        return NULL; 
    }

    if (pNode->lchild != NULL && pNode->lchild->data == e && pNode->rchild != NULL) {
        return pNode->rchild; 
    }
    return NULL; 
}


// #define LEFT 0
// #define RIGHT 1

Status InsertChild(BiTNode* p, int LR, BiTree c) {
    if (!p || !c) {
        return ERROR; 
    }

    BiTree* childPtr = (LR == 0) ? &(p->lchild) : &(p->rchild);
    if (*childPtr) {
        BiTNode* rmost = c;
        while (rmost->rchild) {
            rmost = rmost->rchild;
        }
        // 将p原本的子树设置为c的最右侧节点的右子树
        rmost->rchild = *childPtr;
    }

    // 将c设置为p的相应子树
    if (LR == 0){
        p->lchild = c;
    }else{
        p->rchild = c;
    }

    return OK;
}


Status DeleteChild(BiTNode* p, int LR) {
    if (p == nullptr) {
        return ERROR; // p不能为空
    }

    if (LR == 0) {
        DestroyBiTree(p->lchild); // 删除左子树
    } else if (LR == 1) {
        DestroyBiTree(p->rchild); // 删除右子树
    } else {
        return ERROR; // LR必须为0或1
    }

    return OK;
}

void PreOrderTraverse(BiTree T) {
    if (T != NULL) {
        printf("%d ", T->data);     
        PreOrderTraverse(T->lchild); 
        PreOrderTraverse(T->rchild); 
    }
}

Status Traverse(BiTree T) {
    if (T == NULL) {
        return ERROR;
    }
    PreOrderTraverse(T); 
    printf("\n");
    return OK;
}
