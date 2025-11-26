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
void categorySpending(Transaction*transaction,int count,int main,int year);
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

            Transactions =addTransaction(transactions, &transactionCount, t);
            if(strcmp(t.type, "expenses")==0){
                //check budget alert
                double spent=0;
                for(int i=0; i<transactionCount; i++){
                    if(strcmp(transactions[i].category, t.category) == 0 && transaction[i].date.month == t.date.month && transactions[i].date.year == t.date.year && strcmp(transactions[i].type, "expenses")==0){
                        spent+= transactions[i].amount;
                    }
                }
                if(checkBudgetAlert(budgets, budgetCount, spent, t.category)){
                    printf("ALERT: Spending exceeded budget for category '%s'!\n ",t.category);
                }
            }    
        }else if(strcmp(input, "2")==0){
            if(budgetcount <MAX_CATEGORY){
                printf("Enter category name for budget: ");
                scanf("%s", budget[budgetCount].category);
                printf("Enter budget amount: ");
                scanf("%lf", &budgets[budgetCount].budget);
                budgetCount++;
            }else{
                printf("Budget category limit reached.\n");
            }
        }else if(strcmp(input, "3")==0){
            int month, year;
            printf("Enter month and year (MM YYYY): ");
            scanf("%d %d", &month, &year);
            double incomeTotal=0, expenseTotal=0;
            monthlySummary(transactions, transactionCount, month, year, &incomeTotal, &expenseTotal);
            printf("Monthly Summary for %02d/%d\n", month, year);
            printf("Total Income: %.2lf\n", incomeTotal);
            printf("Total Expense: %.2lf\n", expenseTotal);
        }else if(strcmp(input, "4")==0){
            int month, year;
            printf("Enter month and year(MM YYYY):");
            scanf("%d %d", &month, &year);
            printf("Category-wise spending for %02d/%d:\n",month,year);
           categorySpending(transaction,transactionCount, month,year);} 
           else if(strcmp(input,"5")==0){
            int months, year;
            printf("Enter number of past months for trend report:");
            scanf("%d", &months);
            printf("Enter current year: ");
            scanf("%d", &year);
            trendReport(transaction,transactionCount,months,year);
           } else if(strcmp(input,"6")==0){
            char filename[100];
            printf("Enter filename to export(e.g..data.csv):");
            scanf("%s",filename);
            exportToCSV(transaction, transactionCount,
                filename);
            printf("Data exported successfully to %s\n",
                filename);
           }else if(strcmp(input,"7")==0){
            running = 0;
           }else{
            printf("Invalid choice, try again.\n");
           }
        }
        free(transaction);
        return 0; 
    }
    Transaction*addTransaction(Transaction*transactions,int*count, Transaction newTrans){
        Transaction*temp = realloc(transaction,(*count + 1)*sizeof(Transaction));
        if(temp == NULL){
            printf("Memory allocation failed!\n");
            return transactions;
        }
        transactions = temp;
        transactions[*count]= newTrans;
        (*count)++;
        return transactions;
    }
    void monthlysummary(Transaction *transactions, int count, int month, int year,
    double *incomeTotal, double *expenseTotal){
        *incomeTotal = 0;
        *expenseTotal = 0;
        for(int i=0; i< count; i++){
            if(transactions[i].date.year == year){
                if(strcmp(transaction[i].type, "income")==0)
            {
                
            }}
        }
    }
}

