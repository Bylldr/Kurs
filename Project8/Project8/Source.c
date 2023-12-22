#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <locale.h>
#define _CRT_SECURE_NO_WARNINGS
#define ROWS 7
#define COLUMNS 7

char gameBoard[ROWS][COLUMNS] = {
    {'_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_'},
    {'_','_','_','_','_','_','_'},

};
char answers[ROWS][COLUMNS] = {
    {'B','C','E','_','D','_','A'},
    {'_','D','C','A','_','E','B'},
    {'C','_','A','B','_','D','E'},
    {'_','A','B','D','E','C','_'},
    {'A','B','D','E','C','_','_'},
    {'E','_','_','C','B','A','D'},
    {'D','E','_','_','A','B','C'},

};
void menu();
int printFileData();
void printGameBoard();
int game(int a);
int readUserData(char* uname, int* save, int* attempts);
int saveUserData(char* uname, int save, int* attempts);
void saveProgress();
int installProgress();
int aMatricesEqual(char matrix1[ROWS][COLUMNS], char matrix2[ROWS][COLUMNS]);

int gamelevels();
int main()
{
   
    menu();
    return 0;
}


void menu()
{
    int Complexity;
    int choose;
    char finish = '+';
    setlocale(LC_CTYPE, "RUS");
    while (finish != '!')
    {
        puts("*****************************************");
        puts("������������ � ���� ������ ���������, ����������� �������� ��������:\n1)������������ � ��������� ����\n2)���������� � ����\n3)����������� ������ ���������\n4)���������� ���������� ���������� ���\n5)��������� ����");
        puts("*****************************************\n");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
            puts("\t\t\t\t||�������||\n���������� ��������� ����������� �������, ������ ��������� ���������:\n1)� ������ ���� � ������� ����� ������ ����������� ���� ��������\n2)��������� ������ ����� ���� �������\n3)�����,������� �� ������� �����,����������,����� ����� ������ ���������� ������\n");
            break;
        case 2:
        {
            puts("������ ������� ��������� ����:\n1)������\n2)�������\n3)�������\n");

            scanf("%d", &Complexity);
            game(Complexity);
            break;
        }
        case 3:
        {
            puts("������ ���������:\n1)������,���� ����������� ��������� 5 ���\n2)�������,���� ����������� ��������� 3 ���\n3)��������,���� ����������� ��������� 1 ���\n");

            break;
        }
        case 4:
        {
            printFileData();
            break;
        }
        case 5:
        {
            finish = '!';
        }
        }
    }
    puts("���� ��� �����!");
}
int printFileData() {
    char username[50];
    int balance = 0;
    FILE* file = fopen("user.txt", "r");
    if (file == NULL) {
        printf("�� ������� ������� ����\n");
        return 0;
    }
    fscanf(file, "%s %d", &username, &balance);
    printf("��� ������������: %s ", username);
    printf("������: %d\n", balance);
    fclose(file);
}
void printGameBoard()
{
    char str1[7] = { 'B','D', 'C', 'A', 'A',' ','D' };
    char str2[7] = { 'A','B', 'E', 'C', ' ','D',' ' };
    printf("        B     E  A  D  E  A\n");
    printf("        0  1  2  3  4  5  6 \n");

    for (int i = 0; i < ROWS; i++)
    {
        printf("   %d  %c", i, str1[i]);
        for (int j = 0; j < ROWS; j++)
        {
            printf("|%c|", gameBoard[i][j]);
            if (j == 6)
                printf("%c", str2[i]);
        }
        puts("\n");

    }
    printf("        D  E  D  C  A     C\n");
}
int game(int a)
{
    int x, y, attempts, choose, exit, score = 0;
    char temp;
    char username[50];
    switch (a)
    {
    case 1:
        gamelevels(5);
        break;
    case 2:
        gamelevels(3);
        break;

    case 3:
        gamelevels(1);
        break;
    }
    return 0;
}



int readUserData(char* uname, int* save, int* attempts)
{
    FILE* userFile = fopen("user.txt", "r");
    if (userFile == NULL) {
        printf("��� ������ � ���������� �����\n");
        return 0;
    }
    fscanf(userFile, "%s %d %d", &uname, &save, &attempts);
    printf("������ ������� �������: ��� ������������: %s, ������: %d, ���������� �������: %d\n", &uname, save, attempts);
    fclose(userFile);
}
int saveUserData(char* uname, int save, int attempts) {
    FILE* userFile = fopen("user.txt", "w");
    if (userFile == NULL) {
        printf("�� ������� ������� ���� user.txt\n");
        return 0;
    }
    fprintf(userFile, "%s %d %d", uname, save, attempts);
    printf("������ ������� ���������: ��� ������������: %s, ������: %d, ���������� �������: %d\n", uname, save, attempts);
    fclose(userFile);
    return 1;
}
void saveProgress()
{
    FILE* file = fopen("GameBoard", "w");
    if (file != NULL) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLUMNS; j++) {
                fprintf(file, "%c ", gameBoard[i][j]);
            }
        }
        fclose(file);
    }
    else {
        printf("������ �������� ����� ��� ������.");
    }
    fclose(file);
}
int installProgress()
{
    char temp;

    FILE* file;

    file = fopen("GameBoard", "r");
    if (file == NULL) {
        printf("��� ������ � ���������� �����\n");
        return 0;
    }
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLUMNS; j++)
        {
            fscanf(file, " %c", &temp);
            gameBoard[i][j] = temp;
        }

    }
    fclose(file);
    return 1;

}
int MatricesEqual(char matrix1[ROWS][COLUMNS], char matrix2[ROWS][COLUMNS]) {

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if (matrix1[i][j] != matrix2[i][j]) {
                return 0;
            }
        }
    }


    return 1;
}
int gamelevels(int attempts)
{
    int x, y, choose, exit, score = 0;
    char temp;
    char username[50];
    puts("������� ���������� ����?\n1)��\n2)���\n");
    scanf("%d", &choose);
    if (choose == 1)
    {
        readUserData(username,score,attempts);
        installProgress();

    }
    else
    {
        printf("������� ���� ���: ");
        scanf("%s", username);
    }
    while (attempts > 0)
    {
        printGameBoard();
        puts("������� ����� ������: ");
        scanf("%d", &x);
        puts("������� ����� �������: ");
        scanf("%d", &y);
        puts("������� �������: ");
        getchar();
        scanf("%c", &temp);
        if (temp == answers[x][y])
        {
            gameBoard[x][y] = temp;
            printGameBoard();
            score++;
            if (MatricesEqual(answers, gameBoard) == 1) {
                printf("�����������,%s, �� �������� ��� ���������: %d", username, score);
                saveUserData(username, score, attempts);
                return 0;
            }
        }
        else
        {
            puts("��������� ���\n");
            attempts--;
            printf("� ��� �������� �������: %d\n", attempts);
        }
        if (attempts > 0)
        {
            puts("������� ����� �� ����?\n1)��\n2)���");
            scanf("%d", &exit);
            if (exit == 1)
            {
                puts("��������� ��������?\n1)��\n2)���\n");
                scanf("%d", &exit);
                if (exit == 1)
                {

                    saveProgress(gameBoard);
                    saveUserData(username, score, attempts);

                    return 0;
                }


            }
               
                



        
        }
        
    }
    printf("� ��������� �� ���������,��� ���������:%d\n", score);
    puts("\n");
    return 2;
}

