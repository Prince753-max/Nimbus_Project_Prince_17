#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "transaction.h"

Transaction* addTransaction(Transaction *transaction, int *count,
Transaction newTrans){
       Transaction *temp = realloc(transaction, (*count + 1 )*
       sizeof(Transaction));
if(temp == NULL){
    printf("Memory allocation failed!\n");
    return transaction;
}
transaction = temp;
transaction[*count] = newTrans;
(*count)++;
return transaction;

}

void monthlySummary(Transaction *transactions, int count, int month, int 
year, double *incomeTotal , double *expenseTotal) {
    *incomeTotal = 0;
    *expenseTotal = 0;
    for (int i=0; i< count; i++) {
        if(transactions[i].date.month == month && transactions[i].date.year
        == year){
                   if(strcmp(transactions[i].type, "income") == 0 ){
                    *incomeTotal += transactions[i].amount;
                  }else if(strcmp(transactions[i].type, "expense") == 0) {
                    *expenseTotal += transactions[i].amount;
                  }
                }
            }
        }

void categorySpending(Transaction *transactions, int count, int month, int year) {
    double categoryTotal[MAX_CATEGORY] = {0};
    #define MAX_LEN 50
    char categories[MAX_CATEGORY][MAX_LEN];
    int catCount = 0;

    for(int i=0; i < count; i++){
        if(transactions[i].date.month == month && transactions[i].date.year
        == year && strcmp(transactions[i].type, "expense") == 0){
            int found = -1;
            for(int j=0; j < catCount; j++) {
                if(strcmp(categories[j], transactions[i]. category) == 0){
                    found = j;
                    break;
                }
            }
if(found == -1 && catCount < MAX_CATEGORY){
    strcpy(categories[catCount], transactions[i].category);
    categoryTotal[catCount] = transactions[i].amount;
    catCount++;
} else if(found != -1){
    categoryTotal[found] += transactions[i].amount;
     }        
   }
 }
 for(int i=0; i < catCount; i++){
    printf("%s : %.21f\n", categories[i], categoryTotal[i]);
 }
}

int checkBudgetAlert(Budget *budgets, int budgetCount, double spent, char
    *category) {
        for(int i=0; i < budgetCount; i++) {
            if(strcmp(budgets[i].category , category) == 0){
                if(spent > budgets[i].budget){
                    return 1;
                }
            }
        }
        return 0;
    } 
    void trendReport(Transaction *transactions, int count, int months, int year)
    {
        double monthlyExpenses[MAX_MONTHS] = {0};
        for(int m=0; m < months; m++) {
            int month = MAX_MONTHS -m;
            for(int i=0; i < count; i++){
                if(transactions[i].date.year == year && 
                transactions[i].date.month == month && strcmp(transactions[i].type,"expense") == 0){
                    monthlyExpenses[m] += transactions[i].amount;
                }
            }
        }
    printf("Trend Report for last %d months of year %d:\n", months, year);
    for(int m=0; m < months; m++){
        printf("Month %d : %.21f\n", MAX_MONTHS - m, monthlyExpenses[m]);
    }
}
void exportToCSV(Transaction *transaction, int count, const char *filename)
{
    FILE *fp = fopen(filename, "w");
    if(fp == NULL){
        printf("Failed to open file %s for writing.\n", filename);
        return;
    }
    fprintf(fp, "Date,Amount,Category,Type\n");
    for(int i=0; i < count; i++){
        fprintf(fp, "%02d/%02d/%04d,%.21f,%s,%s\n",
        transaction[i].date.day,
    transaction[i].date.month,
    transaction[i].date.year,
transaction[i].amount,
transaction[i].category,
transaction[i].type);
    }
    fclose(fp);
}
