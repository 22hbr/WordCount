#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
    // 检查参数数量
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [-c|-w] [input_file_name]\n", argv[0]);
        return 1;
    }

    // 初始化参数和变量
    char mode = argv[1][1]; // 提取-c或-w
    FILE* file = fopen(argv[2], "r"); // 打开文件
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    int char_count = 0;
    int word_count = 0;
    char current_char;
    int in_word = 0; // 标记是否在单词中

    // 读取文件并统计
    while ((current_char = fgetc(file)) != EOF) {
        // 更新字符数
        char_count++;

        // 判断是否为单词的开始或结束
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

    // 如果最后一个字符是单词的一部分，则增加单词数
    if (in_word) {
        word_count++;
    }

    // 输出结果
    if (mode == 'c') {
        printf("字符数：%d\n", char_count);
    }
    else if (mode == 'w') {
        printf("单词数：%d\n", word_count);
    }
    else {
        fprintf(stderr, "Invalid mode: %c\n", mode);
        return 1;
    }

    // 关闭文件并返回
    fclose(file);
    return 0;
}