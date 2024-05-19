#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// 函数声明
int countChars(std::ifstream& file);
int countWords(std::ifstream& file);

int main(int argc, char* argv[]) {
    // 参数检查
    if (argc != 3) {
        std::cout << "用法: " << argv[0] << " [-c | -w] [input_file_name]\n";
        return 1;
    }

    // 打开文件
    std::ifstream file(argv[2]);
    if (!file.is_open()) {
        std::cerr << "无法打开文件 " << argv[2] << std::endl;
        return 1;
    }

    // 根据参数确定操作
    if (std::string(argv[1]) == "-c") {
        std::cout << "字符数：" << countChars(file) << std::endl;
    }
    else if (std::string(argv[1]) == "-w") {
        std::cout << "单词数：" << countWords(file) << std::endl;
    }
    else {
        std::cout << "无效参数，请使用 -c 或 -w。\n";
        return 1;
    }

    // 关闭文件
    file.close();
    return 0;
}

// 计算字符数
int countChars(std::ifstream& file) {
    int count = 0;
    char ch;
    while (file.get(ch)) {
        count++;
    }
    return count;
}

// 计算单词数
int countWords(std::ifstream& file) {
    int count = 0;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string word;
        while (iss >> word) {
            count++;
        }
    }
    return count;
}