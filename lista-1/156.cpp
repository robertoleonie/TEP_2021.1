#include <cctype>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <map>

std::string Index(std::string s);

int main(){
    std::string word;
    std::set<std::string> words;
    std::map<std::string, int> count;
    while(std::cin >> word && word != "#"){
        words.insert(word);
        ++count[Index(word)];
    }
    for(auto &i : words){
        if(count[Index(i)] == 1) std::cout << i << '\n';
    }
    return 0;
}
std::string Index(std::string s){
    for(auto &i : s){
        if (i < 'a') i = tolower(i);
    }
    std::sort(s.begin(), s.end());
    return s;
}
