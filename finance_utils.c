#include <stdio.h>
#include "finance_utils.h"
#include "transsaction.h"

void printMenu(void){
    printf("\nFinanace Tracker Menu:\n");
    printf("1. Add Transaction\n");
    printf("2. Set Bedget\n");
    printf("3. Monthly Summary\n");
    printf("4. Category-Wise Spending\n");
    printf("5. Trend Report\n");
    printf("6. Export to CSV\n");
    printf("7. Exit\n");
    printf("Select option: ");
}