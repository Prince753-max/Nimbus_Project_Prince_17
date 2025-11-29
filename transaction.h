#ifndef TRANSATION_H
#define TRANSATION_H

#include <stdio.h>

#define MAX_CATEGORY 20
#define MAX_MONTHS 12
#define MAX_LEN 50

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    Date date;
    double amount;
    char category[MAX_LEN];
    char type[10];
} Transaction;

typedef struct {
    char category[MAX_LEN];
    double budget;
} Budget;

Transaction* addTransaction(Transaction *transactions, int *count, Transaction newTrans);
void monthlySummary(Transaction *transactions, int count, int month, int year, double *incomeTotal, double *expenseTotal);
void categorySpending(Transaction *transactions, int count, int month, int year);
int checkBudgetAlert(Budget *budgets, int budgetCount, double spent, char *category);
void trendReport(Transaction *transactions, int count, int months, int year);
void exportToCSV(Transaction *transactions, int count, const char *filename);

#endif