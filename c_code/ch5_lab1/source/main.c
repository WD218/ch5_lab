#include<stdlib.h>
#include<stdio.h>

#define STUDENT 3
#define EXAMS 4

void minimum(int grade[][EXAMS], int pupils, int tests);
void maximum(int grade[][EXAMS], int pupils, int tests);
void average(int grade[][EXAMS], int pupils, int tests);
void printarray(int grade[][EXAMS], int pupils, int tests);
void printmenu();

int main()
{
	//initial std grades
	int studentGrades[STUDENT][EXAMS] = { {77,68,86,73},
										  {96,87,89,78},
										  {70,90,86,81} };

	void(*processgrages[4])(int[STUDENT][EXAMS], int, int)
		= { printarray,minimum,maximum,average };

	int choice = 0;

	while (choice != 4)
	{
		do
		{
			printmenu();
			scanf_s("%d", &choice);
		} while (choice < 0 || choice>4);

		if (choice != 4)
		{
			(*processgrages[choice])(studentGrades, STUDENT, EXAMS);
		}
		else
		{
			printf("\tprogram Ended. \n");
		}
	}
	system("pause");
	return 0;
}

void minimum(int grades[][EXAMS], int pupils, int tests)
{
	int i, j;
	int lowgrade = 100;

	for ( i = 0; i < pupils; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grades[i][j]<lowgrade)
			{
				lowgrade = grades[i][j];
			}
		}
	}
	printf("\n\tThe lowest grade is %d", lowgrade);
	printf("\n");
}

void maximum(int grades[][EXAMS], int pupils, int tests)
{
	int i, j;
	int hightgrade = 0;

	for ( i = 0; i < pupils; i++)
	{
		for (j = 0; j < tests; j++)
		{
			if (grades[i][j]>hightgrade)
			{
				hightgrade = grades[i][j];
			}
		}
	}
	printf("\n\tThe highest grade is %d", hightgrade);
	printf("\n");
}

void average(int grades[][EXAMS], int pupils, int tests)
{
	int i, j,total;
	for ( i = 0; i < pupils; i++)
	{
		total = 0;
		for ( j = 0; j < tests; j++)
		{
			total += grades[i][j];
		}
		printf("\n\tThe average grade for student %d is %.1f"
			, i + 1, (double)total / tests);
	}
	printf("\n");
}

void printarray(int grades[][EXAMS], int puplis, int tests)
{
	int i, j;

	printf("\n\t\t\t[0]    [1]     [2]     [3]");
	for ( i = 0; i < puplis; i++)
	{
		printf("\n\tstudentGrade[%d]", i);
		for ( j = 0; j < tests; j++)
		{
			printf("%-7d", grades[i][j]);
		}
	}
	printf("\n");
}

void printmenu()
{
	printf("\n");
	printf("\tEnter a choice:\n");
	printf("\t0 Ptint the array of grades\n");
	printf("\t1 Find the minimum grade\n");
	printf("\t2 Find the maximum grade\n");
	printf("\t3 Print the average on all tests for each student\n");
	printf("\t4 End program\n");
	printf("Choice:");
}