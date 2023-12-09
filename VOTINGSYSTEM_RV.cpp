#include <stdio.h>
#include <string.h>

int main() {
    char name[100];
    char gender; 
    int a = 0, b = 0, c = 0, d = 0, choice, age;
    printf("--------------------VOTE FOR UTTAR PRADESH--------------------\n");

    while (1) {
        printf("\nEnter Voter's Name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = '\0'; 

        printf("Enter Voter's Age: ");
        if (scanf("%d", &age) != 1) {
            printf("Invalid age input!!!!\n");
            continue; 
        }

        while (1) {
            printf("Enter Voter's Gender (M/F): ");
            if (scanf(" %c", &gender) != 1 || (gender != 'M' && gender != 'F')) {
                printf("!!!Invalid Gender input!!! \nPlease enter 'M' for Male or 'F' for Female.\n");
                continue; 
            } else {
                break; 
            }
        }

        printf("\n******VERIFICATION******\n");
        if (gender == 'M') {
            printf(" NAME: Mr. %s ", name);
        } else if (gender == 'F') {
            printf(" Voter Name is : Ms. %s ", name);
        }

        printf("\n Voter Age is : %d \n", age);

        if (age < 18) {
            printf("Sorry, %s, you are not eligible to vote.\n", name);
        } else {
            printf("\nPolitical Parties:\n");
            printf("1-> (B.J.P)\n");
            printf("2-> (A.A.P)\n");
            printf("3-> (I.N.C)\n");
            printf("4-> (B.S.P)\n");
            
            printf("Give the vote : ");
            if (scanf("%d", &choice) != 1 || choice < 1 || choice > 4) {
                printf("Invalid choice! \nPlease choose a party from 1 to 4.\n");
                continue; 
            }

            switch (choice) {
                case 1:
                    a++;
                    break;
                case 2:
                    b++;
                    break;
                case 3:
                    c++;
                    break;
                case 4:
                    d++;
                    break;
                default:
                    printf("MISTAKEN!!!\n");
            }
        }

       while (1) {
            printf("Do you want to continue (Y/N): ");
            char ch;
            scanf(" %c", &ch);

            if (ch == 'Y' || ch == 'y') {
                getchar(); 
                break; 
            } else if (ch == 'N' || ch == 'n') {
                goto end; 
            } else {
                printf("Invalid input. Please enter 'Y' or 'N'.\n");
            }
        }
    }

end:

    printf("\n ----:VOTES SUMMARY:----  \n");
    printf("B.J.P: %d votes\n", a);
    printf("A.A.P: %d votes\n", b);
    printf("I.N.C: %d votes\n", c);
    printf("B.S.P: %d votes\n", d);
    
    printf("\n :~WINNER PARTY IS~:  ");
    if (a > b && a > c && a > d) {
        printf("(B.J.P)\n");
    } else if (b > a && b > c && b > d) {
        printf("(A.A.P)\n");
    } else if (c > a && c > b && c > d) {
        printf("(I.N.C)\n");
    } else if (d > a && d > b && d > c) {
        printf("(B.S.P)\n");
    } else {
        printf(" NO RESULTS ");
    }

    printf("\n-------Dhanyawad India---------\n");
   return 0;
}
