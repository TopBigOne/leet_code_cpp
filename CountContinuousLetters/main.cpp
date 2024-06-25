#include <iostream>

#include <string>
std::string countContinuousLetters(const std::string& str){
    if(str.empty()){
        return "";
    }
    std::string result;
    int count = 1;
    char preChar = str[0];
    for (const auto &item: str){
        if(item==preChar){
            count++;
        } else{
            result +=preChar+std::to_string(count);
            count=1;
            preChar = item;
        }
    }

    result +=preChar+std::to_string(count);
    return result;

}

int main() {
    std::string input = "qqqyyyyyavvveqqs";
    std::cout << "输入的字符串: " << input << std::endl;

    std::string output = countContinuousLetters(input);
    std::cout << "输出结果: " << output << std::endl;
    return 0;
}
