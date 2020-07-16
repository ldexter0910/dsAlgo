#include<bits/stdc++.h>
using namespace std;

#define MAX 100000

template <typename T>
class Stack {
    private:
        int top;
    public:
        T arr[MAX];

    Stack() : top (-1) {}
    T peek();
    T pop();
    bool push(T x);
    bool isEmpty();
    int size();
};

template <typename T>
bool Stack<T>::isEmpty() {
    if(this->top == -1)
        return true;
    return false;
}

template <typename T>
int Stack<T>::size() {
    return ((this->top)+1);
}

template <typename T>
bool Stack<T>::push(T x) {
    if(this->top == MAX-1) {
        cout<<"Stack Overflow\n";
        return false;
    }
    this->top++;
    this->arr[this->top] = x;
    return true;
}

template <typename T>
T Stack<T>::peek() {
    if(this->isEmpty()) {
        cout<<"Stack is empty\n";
        return 0;
    }
    return this->arr[this->top];
}

template <typename T>
T Stack<T>::pop() {
    if(this->isEmpty()) {
        cout<<"Stack is empty\n";
        return 0;
    }
    return this->arr[this->top--];
}

int main() {
    Stack<char> st;
    if(st.isEmpty()) {
        cout<<"Empty\n";
    }
    st.push('a');
    st.push('b');
    cout<<st.pop()<<"\n";
    cout<<st.peek()<<"\n";
    st.push('c');
    cout<<st.size()<<"\n";
    cout<<st.peek()<<"\n";
    cout<<st.pop()<<"\n";
    cout<<st.pop()<<"\n";
    cout<<st.pop()<<"\n";

    return 0;
}