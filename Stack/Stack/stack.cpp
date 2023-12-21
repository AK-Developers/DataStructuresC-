#include<iostream>
using namespace std;
int maxsize = 5, stack[5], top = -1;

int checkOverflow() {
	if (top == maxsize) {
		return 0;
	}
	else {
		return 1;
	}
}
int checkUnderflow() {
	if (top == -1) {
		return 0;
	}
	else {
		return 1;
	}
}
void printStack() {
	cout << "Updated Stack : " << endl;
	for (int i = 0; i <= top; i++) {
		cout << stack[i] << " ";
	}
}
void push() {
	if (checkOverflow()) {
		top++;
		cout << endl << "Enter the Value to be Inserted :";
		cin >> stack[top];
		printStack();
	}
	else {
		cout << "Stack is Full!!";
	}
}
void pop() {
	if (checkUnderflow()) {
		top--;
		printStack();
	}
	else {
		cout << "Stack is Empty!!";
	}
}
int main() {
	push();
	push();
	push();
	pop();
	pop();
	pop();
	pop();
}