#ifndef DECLARATIONS_H
#define DECLARATIONS_H

struct _stackElement;
typedef struct _StackElement* Position;
typedef struct _stackelement {
	double number;
	Position next;

} StackElement;

Position CreateStackElement(double number);
int InsertAfter(Position position, Position newElement);
int Push(Position head, double number);
int DeleteAfter(Position position);
int Pop(double* destination, Position head);
int PerfomOperation(Position head, char operation);
int CalculatePostfixFile(double* destination, char* fileName);
#endif // !DECLARATIONS_H
