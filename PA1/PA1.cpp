/*
    Michael Capetillo
    mjc223
    2/26/2022
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "lex.h"
#include <vector>

using namespace std;
vector<string> tokenVector = { "PROGRAM", "WRITELN", "INTEGER", "BEGIN", "END", "IF", "REAL", "STRING", "VAR", "ELSE", "FOR",
                "THEN", "DO", "TO", "DOWNTO", "IDENT", "ICONST", "RCONST", "SCONST", "PLUS", "MINUS", "MULT", "DIV", "ASSOP",
                "LPAREN", "RPAREN", "COMMA", "EQUAL", "GTHAN", "LTHAN", "SEMICOL", "COLON", "ERR", "DONE" };

map <string, Token> tokenMap =
{
    {"PROGRAM", Token::PROGRAM},
    {"WRITELN", Token::WRITELN},
    {"INTEGER", Token::INTEGER},
    {"BEGIN", Token::BEGIN},
    {"END", Token::END},
    {"IF", Token::IF},
    {"REAL", Token::REAL},
    {"STRING", Token::STRING},
    {"VAR", Token::VAR},
    {"ELSE", Token::ELSE},
    {"FOR", Token::FOR},
    {"THEN", Token::THEN},
    {"DO", Token::DO},
    {"TO", Token::TO},
    {"DOWNTO", Token::DOWNTO}
};
int lineCount = 0;
int tokenCount = 0;
LexItem getNextToken(istream& in, int& linenum)
{
    char c = ' ';
    string currentLexeme = "";
    string previousLexeme = "";
    while (in.get(c))
    {
        if (c == '\n')
            lineCount++;
        //currentLexeme += c;
    }
    return LexItem();
}

LexItem id_or_kw(const string& lexeme, int linenum)
{
    Token t;
    if (tokenMap.find(lexeme) != tokenMap.end())
        t = tokenMap[lexeme];
    else
        t = Token::IDENT;
    LexItem lexItem = LexItem(t, lexeme, linenum);
    return lexItem;
}

ostream& operator<<(ostream& out, const LexItem& tok)
{
    out << tokenVector[tok.GetToken()] << " (" << tok.GetLexeme() << ") Line #: " << tok.GetLinenum() << endl;
    return out;
}

/*
string lineTok()
{
    string s = "";
    if (lineCount >= 1)
        s += "Lines: " + lineCount + '\n';
    if (tokenCount >= 1)
        s += "Tokens: " + tokenCount + '\n';
    return s;
}
*/