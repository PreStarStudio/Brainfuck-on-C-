#include <iostream>
#include <vector>

int main() {
    std::vector<int> memory(30000, 0);
    int pointer = 0;
    std::string code;

    printf("Write code on Brainfuck");
    std::cin >> code;

    int codeLength = code.length();
    int loopCount = 0;

    for (int i = 0; i < codeLength; i++) {
        switch (code[i]) {
            case '>':
                pointer++;
                break;
            case '<':
                pointer--;
                break;
            case '+':
                memory[pointer]++;
                break;
            case '-':
                memory[pointer]--;
                break;
            case '.':
                std::cout << static_cast<char>(memory[pointer]);
                break;
            case ',':
                char input;
                std::cin >> input;
                memory[pointer] = static_cast<int>(input);
                break;
            case '[':
                if (memory[pointer] == 0) {
                    loopCount = 1;
                    while (loopCount > 0) {
                        i++;
                        if (code[i] == '[') {
                            loopCount++;
                        } else if (code[i] == ']') {
                            loopCount--;
                        }
                    }
                }
                break;
            case ']':
                if (memory[pointer] != 0) {
                    loopCount = 1;
                    while (loopCount > 0) {
                        i--;
                        if (code[i] == ']') {
                            loopCount++;
                        } else if (code[i] == '[') {
                            loopCount--;
                        }
                    }
                }
                break;
            default:
                break;
        }
    }

    return 0;
}
