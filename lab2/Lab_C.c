#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


//������� ���������� ������ � �����
char* Read_line(FILE* file) {
    char* line = malloc(sizeof(char));
    if (line == NULL) {
        free(line);
        printf("������ ��������� ������");
        return NULL;
    }
    char c;
    int i = 1;
    while (fscanf(file, "%c", &c) != EOF) {
        if (c == '\n' || c == '\0') {
            break;
        }
        line[i - 1] = c;
        i++;
        line = realloc(line, i * sizeof(char));
        if (line == NULL) {
            free(line);
            printf("������ ��������� ������");
            return NULL;
        }
    }
    line[i-1] = '\0';
    return line;
}

// ������� ��� ������������ ������, ���������� ��� �������
void Free_Matrix_adj(int** Matrix, int vertices) {
    for (int i = 0; i < vertices; i++) {
        free(Matrix[i]);
        Matrix[i] = NULL;
    }
    free(Matrix);
    Matrix = NULL;
}

// ������� ��� ����������� ���������� ������ (�� ���������� ����� � �����)
int Count_Vertices(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("������ �������� �����\n");
        return -1;
    }

    int vertices = 0;
    int u;

    // ������� ���������� ����� � ������� fscanf
    while (1) {
        char* line = Read_line(file);
        if (line[0] == '\0') {
            free(line);
            break;
        }
        vertices++;
        free(line);
    }

    fclose(file);
    return vertices;
}

// ������� ��� �������� ������� ��������� � ������������� � ������
int** Create_Matrix_adj(int vertices) {
    int** Matrix_adj = (int**)malloc(vertices * sizeof(int*));
    if (Matrix_adj == NULL) {
        free(Matrix_adj);
        return NULL;
    }
    int flag = 0;
    for (int i = 0; i < vertices; i++) {
        Matrix_adj[i] = (int*)malloc(vertices * sizeof(int));
        if (Matrix_adj[i] == NULL) {
            flag = 1;
        }
        if (flag == 0) {
            for (int j = 0; j < vertices; j++) {
                Matrix_adj[i][j] = 0; // �������������� ������
            }
        }  
    }
    if (flag == 1) {
        Free_Matrix_adj(Matrix_adj, vertices);
        return NULL;
    }
    return Matrix_adj;
}

// ������� ��� ���������� ������� ��������� �� ������ �����
void Parsing_Matrix_adj(const char* filename, int** Matrix_adj, int vertices) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("������ �������� �����\n");
        return;
    }

    int i, j;
    
    while (1) {
        char* line = Read_line(file);
        if (line[0] == '\0') {
            free(line);
            break;
        }
        char* line_cp = line;
        char* token;

        // ������ ��������� ������� (����� ����� ����������)
        sscanf(line, "%d:", &j);

        // �������� ������ ������� ������ (���������� ���������)
        token = strtok(
            line, " "); // ������ ������� ����� ����� ������� j, ��� ����������
        token = strtok(NULL, " "); // ��������� ������ � ��� ������� �������

        while (token != NULL) {
            i = atoi(token); // ����������� ������ � �����
            Matrix_adj[j][i] = 1;
            Matrix_adj[i][j] = 1;
            token = strtok(NULL, " "); // ��������� � ���������� ������
        }
        free(line_cp);
    }

    fclose(file);
}

// ������� ��� ������ ���������� ������� 
void Print_Matrix(int** Matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", Matrix[i][j]);
        }
        printf("\n");
    }
}
