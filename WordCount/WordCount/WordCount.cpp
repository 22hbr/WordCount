#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// ��������
int countChars(std::ifstream& file);
int countWords(std::ifstream& file);

int main(int argc, char* argv[]) {
    // �������
    if (argc != 3) {
        std::cout << "�÷�: " << argv[0] << " [-c | -w] [input_file_name]\n";
        return 1;
    }

    // ���ļ�
    std::ifstream file(argv[2]);
    if (!file.is_open()) {
        std::cerr << "�޷����ļ� " << argv[2] << std::endl;
        return 1;
    }

    // ���ݲ���ȷ������
    if (std::string(argv[1]) == "-c") {
        std::cout << "�ַ�����" << countChars(file) << std::endl;
    }
    else if (std::string(argv[1]) == "-w") {
        std::cout << "��������" << countWords(file) << std::endl;
    }
    else {
        std::cout << "��Ч��������ʹ�� -c �� -w��\n";
        return 1;
    }

    // �ر��ļ�
    file.close();
    return 0;
}

// �����ַ���
int countChars(std::ifstream& file) {
    int count = 0;
    char ch;
    while (file.get(ch)) {
        count++;
    }
    return count;
}

// ���㵥����
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