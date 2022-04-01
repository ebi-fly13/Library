#pragma once

#include <iostream>
#include <string>
#include <cctype>

/*
    reference: https://gist.github.com/draftcode/1357281
*/

namespace ebi {

typedef std::string::const_iterator State;
class ParseError {};

bool expect(State &begin, char expected) {
    if(*begin == expected) {
        return true;
    }
    else {
        return false;
    }
}

// beginがexpectedを指していたらbeginを一つ進める。
void consume(State &begin, char expected) {
    if (*begin == expected) {
        begin++;
    } else {
        std::cerr << "Expected '" << expected << "' but got '" << *begin << "'"
            << std::endl;
        std::cerr << "Rest string is '";
        while (*begin) {
            std::cerr << *begin++;
        }
        std::cerr << "'" << std::endl;
        throw ParseError();
    }
}

bool isdigit(char c) {
    return '0' <= c && c <= '9';
}

bool isAlpha(char c) {
    return 'A' <= c && c <= 'Z';
}

bool isalpha(char c) {
    return 'a' <= c && c <= 'z';
}

}
