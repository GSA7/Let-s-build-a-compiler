#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "ctype.h"
/* Constant Declarations */

/* Variable Declarations */
char Look;	// look ahead character
char message[100];	// for sending message

/* Read New Character From Input Stream */
void GetChar() {
	Look = getchar();
}

/* Report an Error */
void Error(char* s) {
	printf("\nError: %s.\n", s);
}

/* Report Error and Halt */
void Abort(char* s) {
	Error(s);
	exit(0);
}

/* Report What Was Expected */
void Expected(char* s) {
	sprintf(message, "%s Expected", s);
	Abort(message);
}

/* Match a Specific Input Character */
void Match(char x) {
	if (Look == x) {
		GetChar();
	} else {
		sprintf(message, "\"%c\"", x);
		Expected(message);
	}
}

/* Recognize an Alpha Character */
bool IsAlpha(char c) {
	return isalpha(c);
}

/* Recognize a Decimal Digit */
bool IsDigit(char c) {
	return isdigit(c);
}

/* Get an Identifier */
char GetName() {
	if (!IsAlpha(Look)) {
		Expected("Name");
	}
	char name = toupper(Look);
	GetChar();
	return name;
}

/* Get a Number */
char GetNum() {
	if (!IsDigit(Look)) {
		Expected("Integer");
	}
	char num = Look;
	GetChar();
	return num;
}

/* Output a String with Tab */
void Emit(char* s) {
	printf("\t%s", s);
}

/* Output a String with Tab and CRLF */
void EmitLn(char* s) {
	Emit(s);
	printf("\n");
}

/* Initialize */
void Init() {
	GetChar();
}

/* Main Program */
int main() {
	Init();
	return 0;
}