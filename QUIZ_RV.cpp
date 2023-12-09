#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

#define MAX_QUESTIONS 5
#define QUESTION_LENGTH 100
#define ANSWER_LENGTH 50

typedef struct {
    char question[QUESTION_LENGTH];
    char options[4][ANSWER_LENGTH];
    int correctOption;
} Question;

void displayWelcome() {
    printf("Welcome to the Quiz Program!\n");
    printf("----------------------------\n");
    printf("Choose an option:\n");
    printf("1. Quiz\n");
    printf("2. Help\n");
    printf("3. Quit\n");
}

void displayHelp() {
    printf("\nQuiz Help:\n");
    printf("------------\n");
    printf("A. This quiz consists of multiple-choice questions.\n");
    printf("B. You will be presented with a question and four options.\n");
    printf("C. Choose the correct option by entering the corresponding number.\n");
    printf("D. You will have a limited total quiz time.\n");
    printf("E. Try to answer as many questions as you can!\n\n");

    int helpOption;
    while (1) {
        printf("Menu:\n");
        printf("1. Back to Main Menu\n");
        printf("2. Start Quiz\n");
        printf("3. Quit\n");
        printf("Enter your choice (1-3): ");
        if (scanf("%d", &helpOption) != 1 || (helpOption < 1 || helpOption > 3)) {
            while (getchar() != '\n');
            printf("!!!Invalid input!!! \nPlease enter a number between 1 and 3.\n");
        } else {
            break;
        }
    }

    switch (helpOption) {
        case 1:
            break; 
        case 2:
            break;
        case 3:
            printf("-------Goodbye!-------\n");
            exit(0); 
    }
}

int askQuestion(Question *question) {
    printf("%s\n", question->question);
    for (int i = 0; i < 4; ++i) {
        printf("%d. %s\n", i + 1, question->options[i]);
    }

    int userAnswer;
    printf("Your answer (1-4): ");
    if (scanf("%d", &userAnswer) != 1 || userAnswer < 1 || userAnswer > 4) {
        while (getchar() != '\n');
        userAnswer = -1; 
    }
    return userAnswer;
}
int main() {
    srand(time(NULL)); 

    int userChoice;
    while (1) {
        displayWelcome();
        printf("Enter your choice (1-3): ");
        if (scanf("%d", &userChoice) != 1 || (userChoice < 1 || userChoice > 3)) {
            while (getchar() != '\n');
            printf("!!!Invalid choice!!!! \nPlease enter a number between 1 and 3.\n");
        } else {
            break;
        }
    }

    switch (userChoice) {
        case 1:
            break;
        case 2:
            displayHelp();
            break;
        case 3:
            printf("------Goodbye!-------\n");
            return 0;
    }

    int startQuiz;
    while (1) {
        printf("\nWould you like to start the quiz?\n");
        printf("1. Yes\n");
        printf("2. No\n");
        printf("Enter your choice (1/2): ");
        if (scanf("%d", &startQuiz) != 1 || (startQuiz != 1 && startQuiz != 2)) {
            
            while (getchar() != '\n');
            printf("!!!Invalid input!!! \nPlease enter 1 or 2.\n");
        } else {
            break;
        }
    }

    if (startQuiz != 1) {
        printf("-----!!!!Quiz aborted!!!!-----\n");
        return 0;
    }

    Question questions[MAX_QUESTIONS] = {
        {"What is the capital of France?", {"Paris", "Berlin", "London", "Madrid"}, 1},
        {"Which programming language is this quiz written in?", {"C", "Java", "Python", "JavaScript"}, 1},
        {"What is the largest planet in our solar system?", {"Earth", "Jupiter", "Mars", "Venus"}, 2},
        {"Who wrote 'Romeo and Juliet'?", {"Charles Dickens", "William Shakespeare", "Jane Austen", "Mark Twain"}, 2},
        {"What is the square root of 81?", {"9", "6", "7", "8"}, 1},
    };

    int score = 0;
    time_t startTime = time(NULL);
    int totalTime = 10; 
    time_t endTime = startTime + totalTime;

    for (int i = 0; i < MAX_QUESTIONS; ++i) {
        printf("\nQuestion %d:\n", i + 1);

        int userAnswer = askQuestion(&questions[i]);
        if (userAnswer != -1) {
            if (userAnswer == questions[i].correctOption) {
                printf("Correct!\n");
                score++;
            } else {
                printf("!!!!Incorrect!!!! \nCorrect answer is: %d. %s\n", questions[i].correctOption, questions[i].options[questions[i].correctOption - 1]);
            }
        } else {
            printf("!!!Invalid input!!! \nPlease enter a number between 1 and 4.\n");
            i--; 
            continue;
        }
        if (time(NULL) >= endTime) {
            printf("\n----Time's up! Auto-submitting quiz.----\n");
            break;
        }
    }
    printf("\n--------Quiz completed!---------\n");
    printf("Your score: %d/%d\n", score, MAX_QUESTIONS);
    return 0;
}
