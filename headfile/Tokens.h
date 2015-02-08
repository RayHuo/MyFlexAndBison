/* 
 * File:   Tokens.h
 * Author: ray
 *
 * Created on March 17, 2014, 7:53 PM
 */
#ifndef TOKENS_H
#define	TOKENS_H
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>

using namespace std;

class Tokens {
private:
    vector<int> _tokens;
    Tokens();
    Tokens(const Tokens& t);
    Tokens operator =(const Tokens& t);
    ~Tokens();
public:
    static Tokens& Instance();
    void addToken(int a);
    vector<int> getTokens() const;
    void print();
};



#endif	/* TOKENS_H */

