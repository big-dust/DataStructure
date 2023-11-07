#include <iostream>
using namespace std;
// 链表节点
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
    Node* front;  // 队首
    Node* rear;   // 队尾
    int size;     // 队列大小

public:
    // 构造函数，初始化队列为空
    Queue() : front(nullptr), rear(nullptr), size(0) {}

    // 入队
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
    }
    
    // 出队，并记录e
    void dequeue(int* e) {
        if (!isEmpty()){
            *e = front->data;
            Node * tmp = front;
            front = front->next;
            size--;
            delete tmp;
        }
    }

    // 出队，不记录e
    void dequeue() {
        if (!isEmpty()){
            Node * tmp = front;
            front = front->next;
            size--;
            delete tmp;
        }
    }


    // 获取队首元素
    bool getFront(int* e) {
        if (isEmpty()){
            return false;
        }
        *e = front->data;
        return true;
    }

    // 检查队列是否为空
    bool isEmpty() {
        return size == 0;
    }

    // 获取队列大小
    int getSize() {
        return size;
    }

    // 清空队列
    void clear() {
        while(!isEmpty()){
            dequeue();
        }
    }

    // 显示队列元素
    void display() {
        Node *current = front;
        while(current!=nullptr){
            cout<<current->data<<" ";
            current = current->next;
        }
        cout<<endl;
    }

    // 销毁队列
    ~Queue() {
        clear();
    }
};

//输入元素
void inputQueue(Queue &q){
    cout<<"input elem:"<<endl;
    int num ,temp;
    cin>>num;
    while(num--){
        cin >>temp;
        q.enqueue(temp);
    }
}

int main() {
    Queue queue;

    // 入队
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);

    // 显示队列元素
    queue.display();
    // inputQueue(queue);
    // 获取队首元素
    int front ;
    bool ok = queue.getFront(&front);
    if (ok) {
        cout << "Front element: " << front << endl;
    }else{
        cout << "empty queue" << endl;
    }
    // 出队
    queue.dequeue();
    queue.display();

    // 检查队列是否为空
    cout << "Is the queue empty? " << (queue.isEmpty() ? "Yes" : "No") << endl;

    // 获取队列大小
    cout << "Queue size: " << queue.getSize() << endl;

    // 清空队列
    queue.clear();
    queue.display();

    return 0;
}
