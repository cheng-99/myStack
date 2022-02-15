#include<stdio.h>
#include<stdbool.h>

typedef struct node node;
typedef struct stack stack;

struct node
{
	int val;
	node* next;
};

struct stack
{
	node* top;
};


stack* create()
{
	return calloc(1, sizeof(stack));
}

void push(stack* s, int val)
{
	node* t = calloc(1, sizeof(node));
	if (!t)
	{
		printf("Error:calloc node push fault!");
		return;
	}
	t->val = val;
	if (!s->top)
	{
		s->top = t;
	}
	else
	{
		t->next = s->top;
		s->top = t;
	}
}

void pop(stack* s)
{
	node* t = s->top;
	s->top = s->top->next;
	free(t);
}


bool isEmpty(stack* s)
{
	return !s->top;
}


int peek(stack* s)
{
	return s->top->val;
}

int size(stack* s)
{
	if (!s->top)
		return 0;
	int count = 0;
	node* t = s->top;
	while (t)
	{
		count++;
		t = t->next;
	}
	return count;
}


void destroy(stack* s)
{
	if (isEmpty(s))
		free(s);
	node* cur = s->top;
	while (cur)
	{
		node* t = cur;
		cur = cur->next;
		free(t);
	}
	free(s);
}


int main()
{
	stack* s = create();
	printf("%d\n", isEmpty(s));
	push(s, 1);
	push(s, 2);
	printf("%d\n", size(s));
	printf("%d\n", peek(s));
	pop(s);
	printf("%d\n", isEmpty(s));
	pop(s);
	printf("%d\n", size(s));
	printf("%d\n", isEmpty(s));
	push(s, 3);
	push(s, 4);
	destroy(s);

}