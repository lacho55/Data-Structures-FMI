#pragma once
#include<string>
#include<iostream>


class Tokenizer{
    public:

    struct Token {
        enum TokenType{open_par, number, oper, close_par, error};
        TokenType type;
        char symbol;
        int val;
    };

        Tonkenizer(std::istream&);
        Token getNextToken();
        bool hasMoreToken();

        static bool isWhiteSpace(char);
        static bool isNumber(char);

    private:
        std::istream& in;
        void clearWhiteSpace();
        
};
