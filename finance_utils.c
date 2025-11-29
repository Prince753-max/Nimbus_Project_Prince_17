#include <stdio.h>
#include "finance_utils.h"
#include "transaction.h"

void printMenu(void){
    printf("\nFinance Tracker Menu:\n");
    printf("1. Add Transaction\n");
    printf("2. Set Budget\n");
    printf("3. Monthly Summary\n");
    printf("4. Category-wise Spending\n");
    printf("5. Trend Report\n");
    printf("6. Export to CSV\n");
    printf("7. Exit\n");
    printf("Select option: ");
}