#include <iostream>
using namespace std;

const int STACK_SIZE = 20;

typedef struct {
	int data[STACK_SIZE];
	int top;
	int min;
} Stack;

Stack minCache;

void init(Stack *s);
int push(Stack *s, unsigned int value);
int pop(Stack *s);
int min(Stack *s);

int main() {
	Stack *s = new Stack();
	init(s);
	push(s, 5);
	cout << "min value in stack:" << min(s) << endl;
	push(s, 6);
	cout << "min value in stack:" << min(s) << endl;
	push(s, 4);
	cout << "min value in stack:" << min(s) << endl;
	push(s, 3);
	cout << "min value in stack:" << min(s) << endl;
	pop(s);
	cout << "min value in stack:" << min(s) << endl;
	push(s, 1);
	cout << "min value in stack:" << min(s) << endl;
	return 0;
}

void init(Stack *s) {
	s->min = -1;
	s->top = -1;
	minCache.top = -1;
}

int push(Stack *s, unsigned int value) {

	if (s->top == STACK_SIZE - 1) {
		cout << "Stack full" << endl;
		return -1;
	} else if (s->top == -1 || s->min > value) {
		s->min = value;
		minCache.data[++minCache.top] = value;
	}

	s->data[++s->top] = value;
	return 0;
}

int pop(Stack *s) {
	if (s->top == -1) {
		cout << "Stack empty" << endl;
		return -1;
	}

	int data = s->data[s->top--];
	if (s->min == data) {
		s->min = minCache.data[--minCache.top];
	}

	return data;
}

int min(Stack *s) {
	return s->min;
}

