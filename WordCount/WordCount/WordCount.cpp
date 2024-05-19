#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    // ����������
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [-c|-w] [input_file_name]\n", argv[0]);
        return 1;
    }

    // ��ʼ�������ͱ���
    char mode = argv[1][1]; // ��ȡ-c��-w
    FILE* file = fopen(argv[2], "r"); // ���ļ�
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int char_count = 0;
    int word_count = 0;
    char current_char;
    int in_word = 0; // ����Ƿ��ڵ�����

    // ��ȡ�ļ���ͳ��
    while ((current_char = fgetc(file)) != EOF) {
        // �����ַ���
        char_count++;

        // �ж��Ƿ�Ϊ���ʵĿ�ʼ�����
        if (isspace(current_char) || current_char == ',' || current_char == '\t' || current_char == '\n') {
            if (in_word) {
                word_count++;
                in_word = 0;
            }
        }
        else {
            if (!in_word) {
                in_word = 1;
            }
        }
    }

    // ������һ���ַ��ǵ��ʵ�һ���֣������ӵ�����
    if (in_word) {
        word_count++;
    }

    // ������
    if (mode == 'c') {
        printf("�ַ�����%d\n", char_count);
    }
    else if (mode == 'w') {
        printf("��������%d\n", word_count);
    }
    else {
        fprintf(stderr, "Invalid mode: %c\n", mode);
        return 1;
    }

    // �ر��ļ�������
    fclose(file);
    return 0;
}