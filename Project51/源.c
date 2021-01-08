#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#define inisize 100
#define increment 10
#define data char
#define len sizeof(data)

typedef struct
{
	data *base;
	data *top;
	data stacksize;
}stack;
stack *s;


void init(stack *s)
{
	s->base = (data*)malloc(inisize*len);
	if (!s->base)
	{
		printf("error");
		exit(1);
	}
	s->top = s->base;
	s->stacksize = inisize;
}

void push(stack *s, data e)
{
	if (s->top - s->base == inisize)
	{
		printf("full");
		exit(1);
	}
	*s->top = e;
	printf("%c ", *s->top);
	s->top++;
	//printf("%c ", s->top);
}


void input(stack *s)
{
	data x;

	printf("input the data: ");
	for (int i = 0;; i++)
	{
		scanf_s("%c", &x);
		if (x == '\n') break;
		push(s, x);
	}
	//printf("%c ", s->base);
	//printf("%c ", s->top);


}
void pop(stack *s)
{
	data e;
	if (s->top == s->base)
	{
		printf("error");
		exit(-1);
	}
	s->top--;
	e = *s->top;
	printf("%c ", e);
}
void clear(stack*s)
{
	while (s->top != s->base)
	{
		pop(s);
	}
	printf('\n');
}

void output(stack *s)
{

	while (s->top != s->base)
	{
		s->top--;

		printf("%c ", *s->top);
	}

}

void line(stack *s)
{
	init(s);
	data ch = getchar();
	
		while (ch != '\n')
		{
			switch (ch)
			{
			case'#':pop(s); break;
			case'@':clear(s); break;
			default: push(s, ch); break;
			}
			ch = getchar();
		}
		
}

int main()
{
	stack p;
	stack *s = &p;
	
	line(s);
	output(s);
    
	


	return 0;
}