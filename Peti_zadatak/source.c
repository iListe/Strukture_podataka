#include <stdio.h>
#include <stdlib.h>
#include "declarations.h"

Position CreateStackElement(double number)
{
	Position newElement = NULL;

	newElement = (Position)malloc(sizeof(StackElement));
	if (!newElement)
	{
		perror("Can't allocate memory!\n");
		return NULL;
	}
	newElement->number = number;
	newElement->next = NULL;
}

int InsertAfter(Position position, Position newElement)
{
	newElement->next = positiom->next;
	position->next = newElement;

	return EXIT_SUCCESS;
}

int Push(Position head, double number)
{
	Position newElement = NULL;
	newElement = CreateStackElement(number);
	if (!newElement)
	{
		return -1;
	}
	InsertAfter(head, newElement);
	return EXIT_SUCCES;
}
int DeleteAfter(Position position)
{
	Position temp = position->next;
	if (!temp)
	{
		return EXIT_SUCCESS;
	}
	position->next = temp->next;
	free(temp);
	return EXIT_SUCCESS;
}
int Pop(double* destination, Position head)
{
	Position first = head->next;

	if (!first)
	{
		perror("Postfix not valid! please check your file!\n");
		return -1;
	}
	*destination = first->number;
	DeleteAfter(head);

}
int PerfomOperation(Position head, char operation)
{
	double operand2 = 0;
	double operand1 = 0;
	int status1 = EXIT_SUCCESS;
	int status2 = EXIT_SUCCESS;

	status2 = Pop(&operand2, head);
	if (status2 != EXIT_SUCCESS)
	{
		return -1;
	}

	status1 = Pop(&operand1, head);
	if (status1 != EXIT_SUCCESS)
	{
		return -2;
	}
	switch (operation)
	{
	case '+':
	{

		result = operand1 + operand2;
		break;
	}
	case '-':
	{

		result = operand1 - operand2;
		break;

	}
	case '*':
	{

		result = operand1 * operand2;
		break;
	}
	case '/':
	{
		if (operand2 == 0)
		{
			printf("can not divide");
			return -3;
		}
		result = operand1 / operand2;
		break;
	}
	default:
		printf("This operation is not supported yet!\n");
		return -4;

	}
	Push(head, result);
	return EXIT_SUCCESS;
}
int CalculatePostfixFile(double* destination, char* fileName)
{
	FILE* file = NULL;
	file = fopen(fileName, "rb");
	if (!file)
	{
		perror("can't open file!\|n");
		return -1;
	}
	fseek(file, 0, SEEK_END);
	fileLength = ftell(file);
	buffer = (char*)calloc(fileLenght + 1, sizeof(char));
	if (!buffer)
	{
		perror("cannot allocate\n");
		return NULL;
	}
	rewind(file);
	fread(buffer, sizeof(char), fileLength, file);
	printf("%s\n", buffer);
	fclose(file);
	free(buffer);
	return EXIT_SUCCESS;
}