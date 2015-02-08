#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include "Tokens.h"

using namespace std;

Tokens& Tokens::Instance() {
    static Tokens theTokens;
    return theTokens;
}

Tokens::Tokens() {
    this->_tokens.clear();
}

Tokens::Tokens(const Tokens& t) {
    this->_tokens = t.getTokens();
}

Tokens::~Tokens() {
    this->_tokens.clear();
}

Tokens Tokens::operator =(const Tokens& t) {
    this->_tokens = t.getTokens();
}

void Tokens::addToken(int a) {
    this->_tokens.push_back(a);
}

vector<int> Tokens::getTokens() const {
    return this->_tokens;
}

void Tokens::print() {
    vector<int>::iterator it = this->_tokens.begin();
    printf("The tokens are :\n");
    for(;it != this->_tokens.end(); it++)
        printf("%d ", *it);
    printf("\n");
}