#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void Addition();
void Substraction();
void Multiplication();
void Division();

void ExecuteAdd(int pRes);
void ExecuteSub(int pRes);
void ExecuteMultiply(int pRes);
void ExecuteDivide(int pRes);
void Exiting();

int StringToInteger(char a[]);

int gCounter1;
int gCounter2;
int gNum1 = 0;
int gNum2 = 0;
int flagmain;
int flagadd;

int gFlagCheck = 0;
char gStr1[10];
char gStr2[10];


//for nulling the array
void ArrayNull(int pIndex) {

	if (pIndex == 1) {

		for (int i = 0; i < 10; i++) {

			gStr1[i] = '\0';

		}

	} else if (pIndex == 2) {

		for (int i = 0; i < 10; i++) {

			gStr2[i] = '\0';

		}

	}

}

//stringlength
int StringLength(char *str)
{
		int i = 0;

	while (*(str + i)!='\0') {

		i++;

	}

	return i;

}

//reading input
void ReadingInput(int pNum,int pRes)
{

		int ch;
		int m = 0;
		int i = 0;
	
	if (pRes == 0) {
	
		m = StringLength(gStr1);
		
		for (;;) {

			ch = _getch();

			if (m == 8 && ch == '\b') {

				printf("\b \b");
				--m;

			}if ((m == 0) && (ch == '-') && (m < 8)) {

				gStr1[m] = '-';
				printf("%c", ch);
				++m;

			} else if ((ch >= '0') && (ch <= '9') && (m < 8)) {

				gStr1[m] = ch;
				printf("%c", ch);
				++m;

			} else if ((m != 0) && (ch == '\b') && (m < 8)) {

				--m;
				printf("\b");
				printf(" ");
				printf("\b");

			} else if ((m == 0) && (ch == '\b')) {

				if (m > 0) {
					printf("\b");
					printf(" ");
					printf("\b");
					--m;
				}

			} else if (ch == '\r') {

				gStr1[m] = '\0';
				gNum1 = StringToInteger(gStr1);
				return;

			} else if ((ch == 27) && (m == 0)) {

				system("CLS");
				return;

			} else if ((ch == 27) && (m != 0)) {

				for (int i = 0; i < m; i++) {
					printf("\b");
				}
				for (int i = 0; i < m; i++) {
					printf(" ");
				}
				for (int i = 0; i < m; i++) {
					printf("\b");
				}

				m = 0;

			}
		}
	}

	else if (pRes == 1) {

		m = StringLength(gStr2);
		
		for (;;) {

			ch = _getch();

			if (m == 8 && ch == '\b') {
				printf("\b \b");
				--m;

			} if ((m == 0) && (ch == '-') && (m < 8)) {

				gStr2[m] = '-';
				printf("%c", ch);
				++m;

			} else if ((ch >= '0') && (ch <= '9') && (m < 8)) {

				gStr2[m] = ch;
				printf("%c", ch);
				++m;

			} else if ((m != 0) && (ch == '\b') && (m < 8)) {

				--m;
				printf("\b");
				printf(" ");
				printf("\b");

			} else if ((m == 0) && (ch == '\b')) {

				if (m > 0) {

					printf("\b");
					printf(" ");
					printf("\b");
					--m;

				}

			} else if (ch == '\r') {

				gStr2[m] = '\0';
				gNum2 = StringToInteger(gStr2);
				return;

			} else if ((ch == 27) && (m == 0)) {

				system("CLS");
				return;

			} else if ((ch == 27) && (m != 0)) {

				for (int i = 0; i < m; i++) {
					printf("\b");
				}
				for (int i = 0; i < m; i++) {
					printf(" ");
				}
				for (int i = 0; i < m; i++) {
					printf("\b");
				}

				m = 0;

			}

		}

	}
	
}


int StringToInteger(char a[]) {

	int c, sign = 0, offset, n;

	if (a[0] == '-') {  // Handle negative integers
		sign = -1;
	}

	if (sign == -1) {  // Set starting position to convert
		offset = 1;

	} else {
		offset = 0;
	}

	n = 0;

	for (c = offset; a[c] != '\0'; c++) {
		n = n * 10 + a[c] - '0';
	}

	if (sign == -1) {
		n = -n;
	}

	return n;
}


//main menu part
void PrintMainMenu(int pCh) {

	if (pCh == 0) {

		system("CLS");
		printf("\nCalculator\n");
		printf("==========\n\n");
		printf("Menu Options:\n");
		printf("------------\n");
		printf("-> Addition\n");
		printf("   Subtraction\n");
		printf("   Multiplication\n");
		printf("   Division\n");
		printf("   exit\n");

	}
	else if (pCh == 1) {

		system("CLS");
		printf("\nCalculator\n");
		printf("==========\n\n");
		printf("Menu Options:\n");
		printf("------------\n");
		printf("   Addition\n");
		printf("-> Subtraction\n");
		printf("   Multiplication\n");
		printf("   Division\n");
		printf("   exit\n");

	}
	else if (pCh == 2) {

		system("CLS");
		printf("\nCalculator\n");
		printf("==========\n\n");
		printf("Menu Options:\n");
		printf("------------\n");
		printf("   Addition\n");
		printf("   Subtraction\n");
		printf("-> Multiplication\n");
		printf("   Division\n");
		printf("   exit\n");

	}
	else if (pCh == 3) {

		system("CLS");
		printf("\nCalculator\n");
		printf("==========\n\n");
		printf("Menu Options:\n");
		printf("------------\n");
		printf("   Addition\n");
		printf("   Subtraction\n");
		printf("   Multiplication\n");
		printf("-> Division\n");
		printf("   exit\n");

	}
	else if (pCh == 4) {

		system("CLS");
		printf("\nCalculator\n");
		printf("==========\n\n");
		printf("Menu Options:\n");
		printf("------------\n");
		printf("   Addition\n");
		printf("   Subtraction\n");
		printf("   Multiplication\n");
		printf("   Division\n");
		printf("-> exit\n");
	}
}

int MyMod(int pNum, int pNoOfChoice) {

		int retnum = 0;

	retnum = abs(pNum % pNoOfChoice);
	return retnum;

}

void ExecuteChoiceMenu(int pRes) {

	if (pRes == 0) {

		Addition();
		return;

	} else if (pRes == 1) {

		Substraction();
		return;

	} else if (pRes == 2) {

		Multiplication();
		return;

	} else if (pRes == 3) {

		Division();
		return;

	} else if (pRes == 4) {

		Exiting();
		return;

	}

}

//addition
void PrintAddMenu(int pRes)
{
	if (pRes == 0) {

		system("CLS");
		printf("Addition\n");
		printf("========\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("-> Enter First Operand\n");
		printf("   Enter Second Operand\n");
		printf("   Perform Addition\n");
		printf("   Exit\n");

	} else if (pRes == 1) {

		system("CLS");
		printf("Addition\n");
		printf("========\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("   Enter First Operand\n");
		printf("-> Enter Second Operand\n");
		printf("   Perform Addition\n");
		printf("   Exit\n");

	} else if (pRes == 2) {

		system("CLS");
		printf("Addition\n");
		printf("========\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("   Enter First Operand\n");
		printf("   Enter Second Operand\n");
		printf("-> Perform Addition\n");
		printf("   Exit\n");

	} else if (pRes == 3) {

		system("CLS");
		printf("Addition\n");
		printf("========\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("   Enter First Operand\n");
		printf("   Enter Second Operand\n");
		printf("   Perform Addition\n");
		printf("-> Exit\n");
	}

}

void Addition()
{
		int	ch;
		int res   = 0;
		int f     = 0;
		gNum1     = 0;
		gNum2     = 0;
		flagadd   = 0;
		gCounter2 = 3;

	PrintAddMenu(0);
	for (;;) {

		f = 0;
		ch = _getch();
		if (ch == 80) {
			++gCounter2;

			if (gCounter2 == 0) {
				gCounter2 = 4;
			}
			if (flagadd == 0) {
				gCounter2 = 1;
				flagadd = 1;
			}
			res = MyMod(gCounter2, 4);
			PrintAddMenu(res);
			printf("\n\n");
			//printf("\n%d\n", gCounter2);
		}
		if (ch == 72) {

			--gCounter2;
			if (gCounter2 == 0) {
				gCounter2 = 4;
			}
			if (flagadd == 0) {
				gCounter2 = 3;
				flagadd = 1;
			}

			res = MyMod(gCounter2, 4);
			PrintAddMenu(res);
			printf("\n\n");
			//printf("\n%d\n", gCounter2);
		}
		if ((ch == 13) && (res != 3)) {
			ExecuteAdd(res);
			system("CLS");
			PrintAddMenu(res);
		}

		if (ch == 27) {
			flagmain = 0;
			return;
		}
		if ((ch == 13) && (res == 3)) {
			flagmain = 0;
			return;
		}

	}

}

void ExecuteAdd(int pRes)
{
	if (pRes == 0) {
		system("CLS");
		PrintAddMenu(pRes);
		printf("\n\nEnter the operand's value:");
		int i = 0;
		while (gStr1[i] != '\0') {
			printf("%c", gStr1[i]);
			++i;
		}
		//readinput
		ReadingInput(gNum1 , pRes);

	} else if (pRes == 1) {
		system("CLS");
		PrintAddMenu(pRes);
		printf("\n\nEnter the operand's value:");
		int i = 0;
		while (gStr2[i] != '\0') {
			printf("%c", gStr2[i]);
			++i;
		}
		//readinput
		ReadingInput(gNum2,pRes);

	} else if (pRes == 2) {
		system("CLS");
		PrintAddMenu(pRes);
		printf("\n\nThe sum of %d and %d is : %d", gNum1, gNum2, gNum1 + gNum2);
		printf("\n\npress any key to continue . . .");
		_getch();
	}

}


//subtraction

void PrintSubstractionMenu(int pRes)
{
	if (pRes == 0) {

		system("CLS");
		printf("Subtraction\n");
		printf("========\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("-> Enter First Operand\n");
		printf("   Enter Second Operand\n");
		printf("   Perform Subtraction\n");
		printf("   Exit\n");

	} else if (pRes == 1) {

		system("CLS");
		printf("Subtraction\n");
		printf("========\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("   Enter First Operand\n");
		printf("-> Enter Second Operand\n");
		printf("   Perform Subtraction\n");
		printf("   Exit\n");

	} else if (pRes == 2) {

		system("CLS");
		printf("Subtraction\n");
		printf("========\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("   Enter First Operand\n");
		printf("   Enter Second Operand\n");
		printf("-> Perform Subtraction\n");
		printf("   Exit\n");

	} else if (pRes == 3) {

		system("CLS");
		printf("Subtraction\n");
		printf("========\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("   Enter First Operand\n");
		printf("   Enter Second Operand\n");
		printf("   Perform Subtraction\n");
		printf("-> Exit\n");
	}

}

void Substraction()
{

	gNum1 = 0;
	gNum2 = 0;
	ArrayNull(1);
	ArrayNull(2);

	int ch;
	flagadd = 0;
	gCounter2 = 3;
	int res = 0;
	int f = 0;

	PrintSubstractionMenu(0);
	for (;;) {

		f = 0;
		ch = _getch();
		if (ch == 80) {
			++gCounter2;

			if (gCounter2 == 0) {
				gCounter2 = 4;
			}
			if (flagadd == 0) {
				gCounter2 = 1;
				flagadd = 1;
			}
			res = MyMod(gCounter2, 4);
			PrintSubstractionMenu(res);
			printf("\n\n");
			//printf("\n%d\n", gCounter2);
		}
		if (ch == 72) {

			--gCounter2;
			if (gCounter2 == 0) {
				gCounter2 = 4;
			}
			if (flagadd == 0) {
				gCounter2 = 3;
				flagadd = 1;
			}

			res = MyMod(gCounter2, 4);
			PrintSubstractionMenu(res);
			printf("\n\n");
			//printf("\n%d\n", gCounter2);
		}
		if ((ch == 13) && (res != 3)) {
			ExecuteSub(res);
			system("CLS");
			PrintSubstractionMenu(res);
		}

		if (ch == 27) {
			flagmain = 0;
			return;
		}
		if ((ch == 13) && (res == 3)) {
			flagmain = 0;
			return;
		}

	}

}

void ExecuteSub(int pRes)
{
	if (pRes == 0) {

		system("CLS");
		PrintSubstractionMenu(pRes);
		printf("\n\nEnter the operand's value:");
		int i = 0;
		while (gStr1[i] != '\0') {
			printf("%c", gStr1[i]);
			++i;
		}
		//readinput
		ReadingInput(gNum1, pRes);

	} else if (pRes == 1) {

		system("CLS");
		PrintSubstractionMenu(pRes);
		printf("\n\nEnter the operand's value:");
		int i = 0;
		while (gStr2[i] != '\0') {
			printf("%c", gStr2[i]);
			++i;
		}
		//readinput
		ReadingInput(gNum2, pRes);

	} else if (pRes == 2) {

		system("CLS");
		PrintSubstractionMenu(pRes);
		printf("\n\nthe substraction of %d and %d is : %d", gNum1, gNum2, gNum1 - gNum2);
		printf("\n\npress any key to continue . . .");
		_getch();

	}

}

//multiplication
void PrintMultiplicationMenu(int pRes)
{
	if (pRes == 0) {

		system("CLS");
		printf("Multiplication\n");
		printf("==============\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("-> Enter First Operand\n");
		printf("   Enter Second Operand\n");
		printf("   Perform Multiplication\n");
		printf("   Exit\n");
	}
	else if (pRes == 1) {

		system("CLS");
		printf("Multiplication\n");
		printf("==============\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("   Enter First Operand\n");
		printf("-> Enter Second Operand\n");
		printf("   Perform Multiplication\n");
		printf("   Exit\n");
	}
	else if (pRes == 2) {

		system("CLS");
		printf("Multiplication\n");
		printf("==============\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("   Enter First Operand\n");
		printf("   Enter Second Operand\n");
		printf("-> Perform Multiplication\n");
		printf("   Exit\n");
	}
	else if (pRes == 3) {

		system("CLS");
		printf("Multiplication\n");
		printf("==============\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("   Enter First Operand\n");
		printf("   Enter Second Operand\n");
		printf("   Perform Multiplication\n");
		printf("-> Exit\n");
	}
}

void Multiplication()
{

	gNum1 = 0;
	gNum2 = 0;
	ArrayNull(1);
	ArrayNull(2);
	int ch;
	flagadd = 0;
	gCounter2 = 3;
	int res = 0;
	int f = 0;

	PrintMultiplicationMenu(0);
	for (;;) {

		f = 0;
		ch = _getch();
		if (ch == 80) {
			++gCounter2;

			if (gCounter2 == 0) {
				gCounter2 = 4;
			}
			if (flagadd == 0) {
				gCounter2 = 1;
				flagadd = 1;
			}
			res = MyMod(gCounter2, 4);
			PrintMultiplicationMenu(res);
			printf("\n\n");
			//printf("\n%d\n", gCounter2);
		}
		if (ch == 72) {

			--gCounter2;
			if (gCounter2 == 0) {
				gCounter2 = 4;
			}
			if (flagadd == 0) {
				gCounter2 = 3;
				flagadd = 1;
			}

			res = MyMod(gCounter2, 4);
			PrintMultiplicationMenu(res);
			printf("\n\n");
			//printf("\n%d\n", gCounter2);
		}
		if ((ch == 13) && (res != 3)) {
			ExecuteMultiply(res);
			system("CLS");
			PrintMultiplicationMenu(res);
		}

		if (ch == 27) {
			flagmain = 0;
			return;
		}
		if ((ch == 13) && (res == 3)) {
			flagmain = 0;
			return;
		}

	}

}

void ExecuteMultiply(int pRes)
{
	if (pRes == 0) {

		system("CLS");
		PrintMultiplicationMenu(pRes);
		printf("\n\nEnter the operand's value:");
		int i = 0;
		while (gStr1[i] != '\0') {
			printf("%c", gStr1[i]);
			++i;
		}
		//readinput
		ReadingInput(gNum1, pRes);

	} else if (pRes == 1) {

		system("CLS");
		PrintMultiplicationMenu(pRes);
		printf("\n\nEnter the operand's value:");
		int i = 0;
		while (gStr2[i] != '\0') {
			printf("%c", gStr2[i]);
			++i;
		}
		//readinput
		ReadingInput(gNum2, pRes);

	} else if (pRes == 2) {

		system("CLS");
		PrintMultiplicationMenu(pRes);
		printf("\n\nthe product of %d and %d is : %d", gNum1, gNum2, gNum1 * gNum2);
		printf("\n\npress any key to continue . . .");
		_getch();

	}
}


//division
void PrintDivisionMenu(int pRes)
{
	if (pRes == 0) {

		system("CLS");
		printf("Division\n");
		printf("========\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("-> Enter First Operand\n");
		printf("   Enter Second Operand\n");
		printf("   Perform Division\n");
		printf("   Exit\n");

	} else if (pRes == 1) {

		system("CLS");
		printf("Division\n");
		printf("========\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("   Enter First Operand\n");
		printf("-> Enter Second Operand\n");
		printf("   Perform Division\n");
		printf("   Exit\n");

	} else if (pRes == 2) {

		system("CLS");
		printf("Division\n");
		printf("========\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("   Enter First Operand\n");
		printf("   Enter Second Operand\n");
		printf("-> Perform Division\n");
		printf("   Exit\n");

	} else if (pRes == 3) {

		system("CLS");
		printf("Division\n");
		printf("========\n\n");
		printf("Operand Info\n");
		printf("-------------\n");
		printf("First Operand : %d\n", gNum1);
		printf("Second Operand: %d\n\n", gNum2);
		printf("Menu Options:\n");
		printf("-------------\n");
		printf("   Enter First Operand\n");
		printf("   Enter Second Operand\n");
		printf("   Perform Division\n");
		printf("-> Exit\n");
	}

}

void Division()
{

	gNum1 = 0;
	gNum2 = 0;
	ArrayNull(1);
	ArrayNull(2);

	int ch;
	flagadd = 0;
	gCounter2 = 3;
	int res = 0;
	int f = 0;

	PrintDivisionMenu(0);
	for (;;) {

		f = 0;
		ch = _getch();
		if (ch == 80) {
			++gCounter2;

			if (gCounter2 == 0) {
				gCounter2 = 4;
			}
			if (flagadd == 0) {
				gCounter2 = 1;
				flagadd = 1;
			}
			res = MyMod(gCounter2, 4);
			PrintDivisionMenu(res);
			printf("\n\n");
			//printf("\n%d\n", gCounter2);
		}
		if (ch == 72) {

			--gCounter2;
			if (gCounter2 == 0) {
				gCounter2 = 4;
			}
			if (flagadd == 0) {
				gCounter2 = 3;
				flagadd = 1;
			}

			res = MyMod(gCounter2, 4);
			PrintDivisionMenu(res);
			printf("\n\n");
			//printf("\n%d\n", gCounter2);
		}
		if ((ch == 13) && (res != 3)) {
			ExecuteDivide(res);
			system("CLS");
			PrintDivisionMenu(res);
		}

		if (ch == 27) {
			flagmain = 0;
			return;
		}
		if ((ch == 13) && (res == 3)) {
			flagmain = 0;
			return;
		}

	}

}

void ExecuteDivide(int pRes)
{
	if (pRes == 0) {

		system("CLS");
		PrintDivisionMenu(pRes);
		printf("\n\nEnter the operand's value:");
		int i = 0;
		while (gStr1[i] != '\0') {
			printf("%c", gStr1[i]);
			++i;
		}
		//readinput
		ReadingInput(gNum1, pRes);

	} else if (pRes == 1) {

		system("CLS");
		PrintDivisionMenu(pRes);
		printf("\n\nEnter the operand's value:");
		int i = 0;
		while (gStr2[i] != '\0') {
			printf("%c", gStr2[i]);
			++i;
		}
		//readinput
		ReadingInput(gNum2, pRes);

	} else if (pRes == 2) {

		system("CLS");
		PrintDivisionMenu(pRes);
		if (gNum2 == 0) {
			printf("\n\nDivision by 0 is undefined");
		}
		else {
			printf("\n\nThe quotient of %d when divided by %d is : %d", gNum1, gNum2, gNum1 / gNum2);
		}
		printf("\n\npress any key to continue");
		_getch();

	}

}


//Exiting
void Exiting()
{
	exit(0);
}

//driver main function
int main()
{
		gNum1 = 0;
		gNum2 = 0;
		int ch;
		flagmain = 0;
		gCounter1 = 4;
		int res = 0;
		ArrayNull(1);
		ArrayNull(2);

	for (;;) {

		if (flagmain == 0) {
			PrintMainMenu(0);
		}

		ch = _getch();
		if (ch == 80) {
			++gCounter1;

			if (gCounter1 == 0) {
				gCounter1 = 5;
			}
			if (flagmain == 0) {
				gCounter1 = 1;
				flagmain = 1;
			}
			res = MyMod(gCounter1, 5);
			PrintMainMenu(res);
			printf("\n\n");
			//printf("\n%d\n", gCounter1);
		}
		if (ch == 72) {

			--gCounter1;
			if (gCounter1 == 0) {
				gCounter1 = 5;
			}
			if (flagmain == 0) {
				gCounter1 = 4;
				flagmain = 1;
			}
			res = MyMod(gCounter1, 5);
			PrintMainMenu(res);
			printf("\n\n");
			//printf("\n%d\n", gCounter1);
		}
		if (ch == 13) {
			ExecuteChoiceMenu(res);
		}

		if (ch == 27) {
			exit(0);
		}

	}

	system("pause");
	return 0;

}




