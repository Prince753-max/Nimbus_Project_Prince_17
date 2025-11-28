#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transaction.h"
#include "finance_utils.h"
int main(){
    Transaction *transactions=NULL;
    int transactionCount=0;
    Budget budgets[MAX_CATEGORY];
    int budgetCount=0;
    char input[10];

    int running=1;
    while(running){
        printMenu();
        scanf("%s", input);
        if(strcmp(input, "1")==0){
            Transaction t;
            printf("Enter date (DD MM YYYY): ");
            scanf("%d %d %d", &t.date.day, &t.date.month, &t.date.year);
            printf("Enter amount: ");
            scanf("%lf", &t.amount);
            printf("Enter category: ");
            scanf("%s", t.category);
            printf("Enter type (income/expense): ");
            scanf("%s", t.type);

            transactions= addTransaction(transactions, &transactionCount, t);
            if(strcmp(t.type, "expense")==0){
                double spent=0;
                for(int i=0; i< transactionCount; i++){
                    if(strcmp(transactions[i].category, t.category)==0 && transactions[i].date.month==t.date.month && transactions[i].date.year==t.date.year && strcmp(transactions[i].type, "expense")==0){
                        spent += transactions[i].amount;

                    }
                }
                if(checkBudgetAlert(budgets, budgetCount, spent, t.category)){
                    printf("Alert: Spending exceeded budget for category '%s'!\n", t.category);
                }
            }
        }else if(strcmp(input, "2")==0){
            if(budgetCount < MAX_CATEGORY){
                printf("Enter category name for budget: ");
                scanf("%s", budgets[budgetCount].category);
                printf("Enter budget amount: ");
                scanf("%lf", &budgets[budgetCount].budget);
                budgetCount++;
            }else{
                printf("Budget category limit reached.\n");
            }
        }else if(strcmp(input, "3")==0){
            int month, year;
            printf("Enter month and year(MM YYYY): ");
            scanf("%d %d", &month, &year);
            double incomeTotal=0, expenseTotal=0;
            monthlySummary(transactions, transactionCount, month, year, &incomeTotal, &expenseTotal);
            printf("Monthly Summary for %02d/%d\n", month, year);
            printf("Total Income: %.2lf\n", incomeTotal);
            printf("Total Expense: %.2lf\n", expenseTotal);
        }else if(strcmp(input, "4")==0){
            int month, year;
            printf("Enter month and year (MM YYYY): ");
            scanf("%d %d", &month, &year);
            printf("Category-wise spending for %02d/%d:\n", month, year);
            categorySpending(transactions, transactionCount, month, year);
        }else if(strcmp(input, "5")==0){
            int months, year;
            printf("Enter number of past months for trend report: ");
            scanf("%d", &months);
            printf("Enter current year: ");
            scanf("%d", &year);
            trendReport(transactions, transactionCount, months, year);
        }else if(strcmp(input, "6")==0){
            char filename[100];
            printf("Enter filename to export (e.g., data.csv): ");
            scanf("%s", filename);
            exportToCSV(transactions, transactionCount, filename);
            printf("Data exported successfully to %s\n", filename);

        }else if(strcmp(input, "7")==0){
            running=0;
        }else{
            printf("Invalid choice, try again\n");
        }
    }
    free(transactions);
    return 0;
}