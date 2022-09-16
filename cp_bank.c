#include <stdio.h>
#include <string.h>
#include <conio.h>

//******* function declarations ******//

int hide_pass(char *);
void new_acc();
void view_list();
void edit_phone(void);
void transact(void);
void delete (void);
void display(void);
int close(void);
void menu(void);

int i, j;
int opt;
struct    //******Customer structure*****//
{
    char name[60];
    int acc_no, age;
    char pass[55];
    char gender;
    double adhar;
    double phone;
    char acc_type[10];
    float amt;
} add, upd, check, rem, transaction;

//******** add account function *********//

void new_acc()
{
    int ch;
    char pass[50];
    FILE *fptr;
    fptr = fopen("record.dat", "a+");
account_no:
    printf("ADD RECORD\n");
    printf("Enter the account number : ");
    scanf("%d", &check.acc_no);
    while (fscanf(fptr, "%d %s %s %d %c %lf %lf %s %g\n", &add.acc_no, add.name, add.pass, &add.age, &add.gender, &add.adhar, &add.phone, add.acc_type, &add.amt) != EOF)
    {
        if (check.acc_no == add.acc_no)
        {
            printf("Account number already in use ! Try another one.");
            goto account_no;
        }
    }
    add.acc_no = check.acc_no;
    printf("\nEnter the name : ");
    scanf("%s", add.name);
    printf("\nEnter password : ");
    scanf("%s", add.pass);
    printf("\nEnter the age : ");
    scanf("%d", &add.age);
    printf("\nEnter the gender : ");
    scanf(" %c", &add.gender);
    printf("\nEnter the aadhar number : ");
    scanf("%lg", &add.adhar);
    printf("\nEnter the phone number : ");
    scanf("%lg", &add.phone);
    printf("\nEnter the amount to deposit : ");
    scanf("%g", &add.amt);
    printf("\nType of account : \n");
    printf("#Saving\n#Current\n");
    printf("Enter your choice : ");
    scanf("%s", add.acc_type);
    fprintf(fptr, "%d %s %s %d %c %lf %lf %s %g\n", add.acc_no, add.name, add.pass, add.age, add.gender, add.adhar, add.phone, add.acc_type, add.amt);
    fclose(fptr);
    printf("\nAccount created successfully!\n");
add_invalid:
    printf("Enter : \n0 - exit\n1 - go to the main menu : ");
    scanf("%d", &opt);
    if (opt == 1)
        menu();
    else if (opt == 0)
        close();
    else
    {
        printf("Invalid Option ! Please select again");
        goto add_invalid;
    }
}

//******** view details function *********//

void view_list()
{
    FILE *view;
    view = fopen("record.dat", "r");
    int test = 0;
    printf("\nACC. NO.\tNAME\t\t\tADHAR\t\t\tPHONE\n");
    printf("\n--------\t----\t\t\t------\t\t\t-----\n");
    while (fscanf(view, "%d %s %s %d %c %lf %lf %s %g", &add.acc_no, add.name, add.pass, &add.age, &add.gender, &add.adhar, &add.phone, add.acc_type, &add.amt) != EOF)
    {
        printf("\n%6d\t %10s\t\t\t%.0lf\t\t%.0lf\n", add.acc_no, add.name, add.adhar, add.phone);
        test++;
    }
    fclose(view);
    if (test == 0)
    {

        printf("NO RECORDS !!");
    }
view_list_invalid:
    printf("Enter : \n0 - exit\n1 - go to the main menu : ");
    scanf("%d", &opt);
    if (opt == 1)
        menu();
    else if (opt == 0)
        close();
    else
    {
        printf("Invalid Option ! Please select again.");
        goto view_list_invalid;
    }
}

//******** edit detail function *********//

void edit_phone(void)
{
    int ch, test = 0;
    FILE *old, *new;
    old = fopen("record.dat", "r");
    new = fopen("new.dat", "w");
    printf("Enter the account no. of the customer whose info you want to change : ");
    scanf("%d", &upd.acc_no);
    while (fscanf(old, "%d %s %s %d %c %lf %lf %s %g", &add.acc_no, add.name, add.pass, &add.age, &add.gender, &add.adhar, &add.phone, add.acc_type, &add.amt) != EOF)
    {
        if (add.acc_no == upd.acc_no)
        {
            test = 1;

            printf("Enter the new phone number : ");
            scanf("%lf", &upd.phone);
            fprintf(new, "%d %s %s %d %c %lf %lf %s %g\n", add.acc_no, add.name, add.pass, add.age, add.gender, add.adhar, upd.phone, add.acc_type, add.amt);
            printf("Phone number Updated \n!");
        }
        else
            fprintf(new, "%d %s %s %d %c %lf %lf %s %g\n", add.acc_no, add.name, add.pass, add.age, add.gender, add.adhar, add.phone, add.acc_type, add.amt);
    }
    fclose(old);
    fclose(new);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test != 1)
    {

        printf("Record not found !! \n");
    edit_invalid:
        printf("Enter : \n0 - try again\n1 - return to main menu\n2 - exit : ");
        scanf("%d", &opt);
        if (opt == 1)
            menu();
        else if (opt == 2)
            close();
        else if (opt == 0)
            edit_phone();
        else
        {
            printf("Invalid Option ! Please select again. ");
            goto edit_invalid;
        }
    }
    else
    {
        printf("Enter : \n0 - exit\n1 - go to the main menu  : ");
        scanf("%d", &opt);

        if (opt == 1)
            menu();
        else
        {
            close();
        }
    }
}

//******** transaction function *********//

void transact(void)
{
    int choice, test = 0;
    FILE *old, *new;
    old = fopen("record.dat", "r");
    new = fopen("new.dat", "w");
    printf("Enter the account no. of the customer:");
    scanf("%d", &transaction.acc_no);
    while (fscanf(old, "%d %s %s %d %c %lf %lf %s %g", &add.acc_no, add.name, add.pass, &add.age, &add.gender, &add.adhar, &add.phone, add.acc_type, &add.amt) != EOF)
    {
        if (add.acc_no == transaction.acc_no)
        {
            test = 1;
            printf("Do you want to\n1.Deposit\n2.Withdraw?\n");
            printf("Enter your choice : ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                printf("Enter the amount you want to deposit : ");
                scanf("%f", &transaction.amt);
                add.amt += transaction.amt;
                fprintf(new, "%d %s %s %d %c %lf %lf %s %g\n", add.acc_no, add.name, add.pass, add.age, add.gender, add.adhar, add.phone, add.acc_type, add.amt);
                printf("Cash deposited successfully!");
            }
            else
            {
                printf("Enter the amount you want to withdraw : ");
                scanf("%f", &transaction.amt);
                add.amt -= transaction.amt;
                fprintf(new, "%d %s %s %d %c %lf %lf %s %g\n", add.acc_no, add.name, add.pass, add.age, add.gender, add.adhar, add.phone, add.acc_type, add.amt);
                printf("Cash withdrawn successfully!");
            }
        }
        else
        {
            fprintf(new, "%d %s %s %d %c %lf %lf %s %g\n", add.acc_no, add.name, add.pass, add.age, add.gender, add.adhar, add.phone, add.acc_type, add.amt);
        }
    }
    fclose(old);
    fclose(new);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test != 1)
    {
        printf("\nRecord not found !! \n");
    transact_invalid:
        printf("\nEnter : \n0 - try again\n1 - return to main menu\n2 - exit : ");
        scanf("%d", &opt);
        if (opt == 0)
            transact();
        else if (opt == 1)
            menu();
        else if (opt == 2)
            close();
        else
        {
            printf("Invalid Option !Please select again.");
            goto transact_invalid;
        }
    }
    else
    {
        printf("\nEnter : \n0 - exit\n1 - go to the main menu :");
        scanf("%d", &opt);
        if (opt == 1)
            menu();
        else
        {
            close();
        }
    }
}

//******** delete account function *********//

void delete (void)
{
    FILE *old, *new;
    int test = 0;
    old = fopen("record.dat", "r");
    new = fopen("new.dat", "w");
    printf("Enter the account no. of the customer you want to delete:");
    scanf("%d", &rem.acc_no);
    while (fscanf(old, "%d %s %s %d %c %lf %lf %s %g", &add.acc_no, add.name, add.pass, &add.age, &add.gender, &add.adhar, &add.phone, add.acc_type, &add.amt) != EOF)
    {
        if (add.acc_no != rem.acc_no)
            fprintf(new, "%d %s %s %d %c %lf %lf %s %g\n", add.acc_no, add.name, add.pass, add.age, add.gender, add.adhar, add.phone, add.acc_type, add.amt);
        else
        {
            test++;
            printf("Account deleted successfully!");
        }
    }
    fclose(old);
    fclose(new);
    remove("record.dat");
    rename("new.dat", "record.dat");
    if (test == 0)
    {
        printf("Account not found !!");
    erase_invalid:
        printf("Enter : \n0 - try again\n1 - return to main menu\n2 - exit : ");
        scanf("%d", &opt);
        if (opt == 1)
            menu();
        else if (opt == 2)
            close();
        else if (opt == 0)
            delete ();
        else
        {
            printf("Invalid Option !");
            goto erase_invalid;
        }
    }
    else
    {
        printf("Enter : \n0 - exit\n1 - go to the main menu : ");
        scanf("%d", &opt);
        if (opt == 1)
            menu();
        else
            close();
    }
}

//******** search and display function *********//

void display(void)
{
    FILE *ptr;
    int test = 0, rate;
    int ch;
    float time;
    float intrst;
    ptr = fopen("record.dat", "r");
    printf("Enter the account number:");
    scanf("%d", &check.acc_no);
    while (fscanf(ptr, "%d %s %s %d %c %lf %lf %s %g", &add.acc_no, add.name, add.pass, &add.age, &add.gender, &add.adhar, &add.phone, add.acc_type, &add.amt) != EOF)
    {
        if (add.acc_no == check.acc_no)
        {
            test = 1;
            printf("\nAccount No. : %d\nName : %s\nPassword : %d\nAge : %d\nGender : %c\nAdhar No: %.0lf\nPhone number : %.0lf \nType Of Account : %s \nAmount deposited : %.2f\n", add.acc_no, add.name, add.pass, add.age, add.gender, add.adhar, add.phone, add.acc_type, add.amt);
        }
    }

    fclose(ptr);
    if (test != 1)
    {
        printf("Record not found !! \n");
    see_invalid:
        printf("Enter : \n0 - try again\n1 - return to main menu\n2 - exit : ");
        scanf("%d", &opt);
        if (opt == 1)
            menu();
        else if (opt == 2)
            close();
        else if (opt == 0)
            display();
        else
        {
            printf("Invalid Option !");
            goto see_invalid;
        }
    }
    else
    {
        printf("Enter : \n0 - exit\n1 - go to the main menu : ");
        scanf("%d", &opt);
    }
    if (opt == 1)
    {
        menu();
    }
    else
    {
        close();
    }
}

//******** exit function *********//

int close(void)
{
    printf("THANK YOU");
}

//******** MAIN MENU *********//

void menu(void)
{
    int ch;
    printf("\n*****CUSTOMER ACCOUNT BANKING MANAGEMENT SYSTEM*****\n*****WELCOME TO THE MAIN MENU*****\n");
    printf("1.Create new account\n2.Update phone number\n3.Transactions\n4.View Detailst\n5.Delete Account\n6.View customer's list\n7.Exit\n\n");
    printf("Enter your choice : ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        new_acc();
        break;
    case 2:
        edit_phone();
        break;
    case 3:
        transact();
        break;
    case 4:
        display();
        break;
    case 5:
        delete ();
        break;
    case 6:
        view_list();
        break;
    case 7:
        close();
        break;
    }
}

//******** hide_pass pass *********//

int hide_pass(char *password)
{

    printf("Enter password : ");
    int p = 0;
    do
    {
        password[p] = getch();
        if (password[p] != '\r')
        {
            printf("*");
        }
        p++;
    } while (password[p - 1] != '\r');
    password[p - 1] = '\0';
}

//******** main function *********//

int main()
{
    char key[10] = "123";
    char password[55];
    int i = 0;
    hide_pass(password);
    if (strcmp(password, key) == 0)
    {
        printf("\nPassword Matched!\n");
        menu();
    }
    else
    {
        printf("\nWrong password!!");
    login_try:
        printf("\nEnter 1 - try again , 0 - exit : ");
        scanf("%d", &opt);
        if (opt == 1)
        {
            main();
        }
        else if (opt == 0)
        {
            close();
        }
        else
        {
            printf("Invalid Option ! Please select again. ");
            goto login_try;
        }
    }
    return 0;
}
