#define _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_DEPRECATE  
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// дополнительная проверка паролей при регистрации
// порверка ФИО при регистрации
// бесконечная программа при выборе опционала
// сделать опцию выхода из программы ?
// Безопасность пароля при логине
// Переписать на функции

struct User {
    char phone_num[20];
    char acс_num[50];
    char password[32];
    float balance;
};

int main(void) {

    struct User user, user_copy;

    FILE* fp;
    char filename[50], reg_phone[20], reg_password[32], change_password[32];

    int option, choice, amount;
    char cont = 'y';

    printf("\n\tChoose the option:\n");
    printf("\n\t\t1. Register an account.");
    printf("\n\t\t2. Login to an account.\n");
    printf("\n\t\tType any other key to exit the terminal.\n");
    printf("\n\tType '1' or '2' and press 'Enter' to the console: ");

    scanf("%d", &option);

    if (option == 1) {
        system("cls");
        printf("\n\tEnter your account number: ");
        scanf("%s", user.acс_num);
        printf("\n\tEnter your phone number: ");
        scanf("%s", user.phone_num);
        printf("\n\tEnter your password: ");
        scanf("%s", user.password);
        user.balance = 0;
        strcpy(filename, user.phone_num); //copy a phone to a filename
        fp = fopen(strcat(filename, ".dat"), "w"); //concat filename with dat 
        fwrite(&user, sizeof(struct User), 1, fp);

        (fwrite != 0) ? printf("\n\n\nAccount registered successfully!") : printf("\n\n\nSomething went wrong: plese try again.");
        fclose(fp);
    }
    else if (option == 2) {
        system("cls");
        printf("To create your account, please:");
        printf("\n\tEnter your phone number: ");
        scanf("%s", reg_phone);
        printf("\n\tEnter your password: ");
        scanf("%s", reg_password);
        strcpy(filename, reg_phone);
        fp = fopen(strcat(filename, ".dat"), "r");
        if (fp == NULL) {
            printf("\n\tAccount number is not registered");
        }
        else {
            fread(&user, sizeof(struct User), 1, fp);
            fclose(fp);

            if (!strcmp(user.password, reg_password)) {
                while (cont = 'y') {
                    system("cls");
                    printf("\n\tPress '1' to check your balance.");
                    printf("\n\tPress '2' to deposit money.");
                    printf("\n\tPress '3' to withdraw money.");
                    printf("\n\tPress '4' to transfer money.");
                    printf("\n\tPress '5' to change the password.");
                    printf("\n\n\tEnter your choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            printf("\n\tYour current balance is %.2f", user.balance);
                            break;
                        case 2:
                            printf("\n\tEnter the amount to be added: ");
                            scanf("%d", &amount);
                            user.balance += amount;
                            fp = fopen(filename, "w");
                            fwrite(&user, sizeof(struct User), 1, fp);
                            if (fwrite != NULL) printf("\n\tSuccesfully deposited! Your current balance is %.2f.", user.balance);
                            fclose(fp);
                            break;
                        case 3:
                            printf("\n\tEnter the amount to be withdrawn: ");
                            scanf("%d", &amount);
                            if (amount > user.balance) {
                                printf("\n\tInsufficeint balance! Your desired withdrawn is %d", amount);
                                printf("\n\tYour current balance is %.2f", user.balance);
                            }
                            else {
                                user.balance -= amount;
                                fp = fopen(filename, "w");
                                fwrite(&user, sizeof(struct User), 1, fp);
                                if (fwrite != NULL) printf("\n\tSuccesfully withdrawn! Your current balance is %.2f.", user.balance);
                                fclose(fp);
                            }
                            break;
                        case 4:
                            printf("\n\tPlease enter the phone number to transfer the balance:");
                            scanf("%s", reg_phone);
                            fp = fopen(strcat(filename, ".dat"), "r");
                            printf("\n\tPlease enter the amount to transfer:");
                            scanf("%d", &amount);
                            strcpy(filename, reg_phone);
                            if (fp == NULL) {
                                printf("\nAccount number is not registered. Please, try again.");
                            }
                            else {
                                fread(&user_copy, sizeof(struct User), 1, fp);
                            }
                            fclose(fp);
                            if (amount > user.balance) {
                                printf("\n\tInsufficeint balance! Your desired transfer is %d", amount);
                                printf("\n\tYour current balance is %.2f", user.balance);
                            }
                            else {
                                strcpy(filename, reg_phone);
                                fp = fopen(strcat(filename, ".dat"), "r");
                                fread(&user_copy, sizeof(struct User), 1, fp);
                                fclose(fp);
                                fp = fopen(filename, "w");
                                user_copy.balance += amount;
                                fwrite(&user_copy, sizeof(struct User), 1, fp);
                                fclose(fp);
                                if (fwrite != NULL) {
                                    printf("\n\tYou have succesfully transfered %d to %s",amount, reg_phone);
                                    strcpy(filename, user.phone_num);
                                    fp = fopen(strcat(filename, ".dat"), "w");
                                    fwrite(&user, sizeof(struct User), 1, fp);
                                    fclose(fp);
                                }
                            }
                            break; 
                        case 5:
                            printf("\n\tPlease enter your OLD password: ");
                            scanf("%s", change_password);
                            if (strcmp(change_password, user.password)) {
                                printf("\n\tEntered password is wrong!");
                            }
                            else {
                                printf("\n\tPlease enter your NEW password: ");
                                scanf("%s", change_password);
                                fp = fopen(filename, "w");
                                strcpy(user.password, change_password);
                                fwrite(&user_copy, sizeof(struct User), 1, fp);
                                if (fwrite != NULL) {
                                    printf("\n\tYour password was successfully updated.");
                                }
                                else {
                                    printf("You can not use empty password!");
                                }
                            }
                            break;
                        default:
                            printf("\n\tINVALID OPTION.");
                    }

                    printf("\n\tDo you want to continue? [y/n]...");
                    scanf("%s", &cont);
                }
            }
            else {
                printf("\n\tINVALID PASSWORD!");
            }
        }


    }
    else {
        exit(0);
    }



    return 0;
}