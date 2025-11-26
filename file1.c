#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CATEGORY 20
#define MAX_MONTHS 12
#define MAX_LEN 50

typedef struct {
    int day;
    int months;
    int year;
} Date;

typedef struct{
    Date date;
    double amount;
    char category[MAX_LEN];
    char type[10];//"income" or "expense"
    } Transaction;

typedef struct{
    char category[MAX_LEN];
    double budget;
} Budget;

//Function prototype
Transaction*addTransaction(Transaction*transaction,int*count, Transaction newTrans);
void monthlySummary(Transaction *transactions, int count, int month, int year, double *incomeTotal,
double *expenseTotal);
void categorySpending();
ho0wemembwjhdbdjvjdjcvbiudjfdwf 
