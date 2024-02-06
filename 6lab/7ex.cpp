#include <iostream>
#include <map>
#include <string>
using namespace std;
template <typename KeyType, typename ValueType>
typename std::map<KeyType, ValueType>::iterator findValue(std::map<KeyType, ValueType>& myMap, const ValueType& valueToFind) {
    for (auto it = myMap.begin(); it != myMap.end(); ++it) {
        if (it->second == valueToFind) {
            return it; 
        }
    }
    return myMap.end(); 
}
int main() {
    int n;
    cin >> n;
    map<string,string> nicknameMap;
    for (int i = 0; i < n; ++i){
        string oldNickname, newNickname;
        cin >> oldNickname >> newNickname;
        auto it = findValue(nicknameMap,oldNickname);
        if ( it != nicknameMap.end()){
            it->second = newNickname;
        }else{
            nicknameMap[oldNickname] = newNickname;
        }
    }
    cout << nicknameMap.size() << std::endl;
    for (const auto& entry : nicknameMap) {
        std::cout << entry.first << " " << entry.second << std::endl;
    }
    

    return 0;
}