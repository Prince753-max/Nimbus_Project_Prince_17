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
void categorySpending(transaction*transaction,int count,int main,int year);
int checkBudgetalert(Budget *budgets, int budgetCount, double spent, char *category);
void trendReport(Transaction *transactions, int count, int months, int year);
void exportToCSV(Transaction *transactions, int count, const char *filename);

int main(){
    Transaction *transaction=NULL;
    int transactionCount=0;
    Budget budgets[MAX_CATEGORY];
    int budgetCount=0;
    char input[10];
    
    int running=1;
    while(running){
        printf("\nFinance Tracker Menu:\n");
        printf("1. Add Transaction\n2. Set Budget\n3. Monthly Summary\n4. Category-wise Spendings\n5. Trend Report\n6. Export to CSV\n7. Exit\n");
        printf("Select option: ");
        scanf("%s",input);

        if(strcmp(input,"1")==0){
            Transaction t;
            printf("Enter date (DD MM YYYY): ");
            scanf("%d %d %d",&t.date.day, &t.date.month, &t.date.year);
            printf("Enter amount: ");
            scanf("%lf", &t.amount);
            printf("Enter category: ");
            scanf("%s", t.category);
            printf("Enter type (income/expense): ");
            scanf("%s", t.type);

            transactions = addTransaction(transactions, &transactioncount, t);
            if(strcmp(transactions[i].category, t.category)==0 && transactions[i].date.month==t.date.month && transactions[i].date.year==t.date.year && strcmp(transactions[i].type, "expense")==0){
                spent+=transaction[i].amount;
            }
        }
        
    }
}

