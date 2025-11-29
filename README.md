**Project Overview**
A console-based personal finance tracker built in C to help users monitor incomes, expenses, budgets, and spending trends through a simple CLI menu. The program supports dynamic transaction storage, budget alerts, detailed monthly and category-wise reports, and CSV data export for spreadsheet use.

**Objective**
The primary objective of this project is to provide an automated, easy-to-use tool for individuals to record, analyze, and control their personal finances. It aims to:

Allow secure entry and storage of financial transactions with date, amount, category, and type.

Enable setting monthly budgets and alert users when spending exceeds budget limits.

Generate summary reports to help users understand their income and expenses.

Provide trend analyses over multiple months to aid in financial planning.

Export data for external financial review or reporting.

**Features**
Add transactions for income and expenses, specifying date, amount, category, and type.

Maintain budgets per category with automatic warnings on overspending.

Produce monthly financial summaries showing total income and expenses.

Display category-wise expenditure breakdown for a selected month.

Generate trend reports showing spending over user-selected past months.

Supports dynamic memory management for flexible transaction storage.

Export transaction history in CSV format compatible with Excel or Google Sheets.

Modular code structure with clear separation of concerns for maintainability.

**Example Usage**

*Compile Command*
gcc main.c transaction.c finance_utils.c -o prog

*Run Command*
./prog

Add Transaction: Enter date, amount, category (e.g., Food, Rent), and whether it is income or expense; the transaction is stored dynamically.

<img width="424" height="234" alt="image" src="https://github.com/user-attachments/assets/5e68190c-d2ad-4331-b831-43dbfec3738e" />

Set Budget: Define spending limits for various categories.

<img width="354" height="187" alt="Screenshot 2025-11-29 224914" src="https://github.com/user-attachments/assets/b3b91639-438f-49f0-9d51-4afa3922eb22" />

Monthly Summary: See total monthly incomes and expenses.

<img width="338" height="240" alt="Screenshot 2025-11-29 225157" src="https://github.com/user-attachments/assets/d98ac702-a0fb-492a-b82b-3d10e922ff33" />

Category Spending: View detailed spending by category for a month.

<img width="406" height="210" alt="Screenshot 2025-11-29 224929" src="https://github.com/user-attachments/assets/e7907d49-196a-4b3f-a5cf-a83c2248cfe2" />

Export CSV: Get a CSV file with the complete transaction data for spreadsheet analysis
<img width="450" height="197" alt="Screenshot 2025-11-29 225411" src="https://github.com/user-attachments/assets/b25deee7-833e-4b8e-ad12-b26a0c37e214" />

**Author**
Prince, Yuvraj, Umair, Prakhar
