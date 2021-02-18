#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack {
    public:
        Stack(int s);
        bool IsFull();
        bool IsEmpty();
        void push(const T& val);
        void pop();
        void print();
    private:
        int size;
        int top;
        T* stack;
};

template <typename T>
Stack<T>::Stack(int s): size(s), top(-1), stack(new T[size]) {};

template<typename T>
bool Stack<T>::IsFull(){
    if (top == size - 1)
        return true;
    else 
        return false;
}

template<typename T>
bool Stack<T>::IsEmpty(){
    if (top == -1)
        return true;
    else 
        return false;
}

template<typename T>
void Stack<T>::push(const T& val){
    if (IsFull()){
        cout << "The stack is full." << endl;
        return;
    }
    else 
        stack[++top] = val;
}

template<typename T>
void Stack<T>::pop(){
    if (IsEmpty()){
        cout << "The stack is empty." << endl;
        return;
    }
    else 
        top--;
}

template<typename T>
void Stack<T>::print(){
    if (IsEmpty())
        cout << "Nothing in the stack." << endl;
    else 
        for (int i = 0; i <= top; i++)
            cout << stack[i] << " ";
}

int main(){
    int size;
    cin >> size;
    Stack<int> stack(size);
    int n, s, val;
    cin >> n;
    while (n--){
        cin >> s;
        switch(s) {
            case 1:
                if (stack.IsFull())
                    cout << "The stack is full." << endl;
                else 
                    cout << "The stack is not full." << endl;
                break;
            case 2:
                if (stack.IsEmpty())
                    cout << "The stack is empty." << endl;
                else 
                    cout << "The stack is not empty." << endl;
                break;
            case 3:
                cin >> val;
                stack.push(val);
                break;
            case 4:
                stack.pop();
                break;
            case 5:
                stack.print();
                break;
        }
    }
    cout << endl;
    stack.print();
    return 0;
}