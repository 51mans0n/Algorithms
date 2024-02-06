#include <iostream>
#include <string>
#include <algorithm>

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

bool customCompare(char a, char b) {
    if (isVowel(a) && isVowel(b)) {
        return a < b;
    } else if (!isVowel(a) && !isVowel(b)) {
        return a < b;
    } else {
        return isVowel(a);
    }
}

int main() {
    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;

    std::sort(s.begin(), s.end(), customCompare);

    std::cout << s << std::endl;

    return 0;
}