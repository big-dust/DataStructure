#include "../include/head.h"

class LinkedStack {
private:
    Node* top; // 栈顶指针
    int size;  // 栈的大小
public:
    // 初始化
    LinkedStack() : top(nullptr) , size(0) {}

    // 入栈操作
    void Push(int data) {
        Node * temp = new Node(data);
        temp->next = top;
        top = temp;
        size++;
    }

    // 出栈操作,不存e
    void Pop() {
        if (!IsEmpty()) {
            Node* temp = top;
            top = top->next;
            delete temp;
            size--;
        }
    }

    // 出栈操作，保存e 
    void Pop(int * e) {
        if (!IsEmpty()) {
            Node* temp = top;
            *e = top->data;
            top = top->next;
            delete temp;
            size--;
        }
    }

    // 获取栈顶元素
    int Top() {
        if (!IsEmpty()) {
            return top->data;
        }
        return -1; //表示栈为空
    }

    // 判断栈是否为空
    bool IsEmpty() {
        return top == nullptr;
    }

    // 获取栈的大小
    int Size() {
        return size;
    }

    // 清空栈
    void Clear() {
        while (!IsEmpty()) {
            Pop();
        }
    }

    // 打印栈的元素
    void Print() {
        Node * current = top;
        cout<<"stack (top to bottom): ";
        while(current != nullptr){
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }

    // 销毁栈
    void Destroy() {
        Clear();
        top = nullptr;
        size = 0;
    }

    ~LinkedStack() {
        Destroy();
    }
};



int main() {
    LinkedStack stack;

    stack.Push(1);
    stack.Push(2);
    stack.Push(3);
    stack.Push(4);
    
    stack.Print();

    cout << "Top element: " << stack.Top() << endl;

    stack.Pop();
    stack.Print();

    stack.Clear();
    stack.Print();

    return 0;
}
