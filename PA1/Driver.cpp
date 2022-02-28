#include <iostream>
#include <map>
#include <fstream>
#include <vector>
#include "lex.h"


/*
 * CS280 - Spring 2022
*/

#include <cctype>
#include <map>
//#include "PA1.cpp"
using std::map;

using namespace std;

int main(int argc, char* argv[])
{
	LexItem	tok;
	LexItem kwtok;
	ifstream file;

	vector<LexItem> idtoks = {
		LexItem(IDENT,"WRITELN",3),
		LexItem(IDENT,"circle",3),
		LexItem(IDENT,"square",11),
		LexItem(IDENT,"rectangle",12),
		LexItem(IDENT,"ellipse",14),
		LexItem(IDENT, "PROGRAM", 1),
		LexItem(IDENT, "REPEAT", 8),
		LexItem(IDENT, "INTEGER",2),
		LexItem(IDENT, "REAL",3),
		LexItem(IDENT, "STRING",4),
		LexItem(IDENT, "IF", 5),
		LexItem(IDENT, "THEN", 5),
		LexItem(IDENT, "END", 25),
		LexItem(IDENT, "TO", 26),
		LexItem(IDENT, "DOWNTO", 27),
		LexItem(IDENT, "FOR", 28),
		LexItem(IDENT, "ELSE", 28),

	};

	LexItem toks[] = {
		LexItem(END,"END",15),
		LexItem(ICONST,"579",5),
		LexItem(SCONST,"hello NJIT",6),
		LexItem(RCONST,"5.79",7),
		LexItem(PLUS,"+",3),
		LexItem(MINUS,"-",3),
		LexItem(MULT,"*",3),
		LexItem(DIV,"/",3),
		LexItem(ASSOP,":=",3),
		LexItem(LPAREN,"(",3),
		LexItem(RPAREN,")",3),
		LexItem(SEMICOL,";",3),
		LexItem(COMMA,",",3),
		LexItem(EQUAL, "=", 4),
		LexItem(GTHAN, ">", 4),
		LexItem(ERR, "ERR", 3),
		LexItem(COLON,":",3),
		LexItem(ASSOP,":=",3),
		LexItem(DONE,"DONE",3),
	};
	bool visFlag = false;
	bool iconstFlag = false;
	bool rconstFlag = false;
	bool sconstFlag = false;
	bool identFlag = false;
	bool multiFileFlag = false;

	if (argc == 1)
	{
		cerr << "No Specified arguments." << endl;
		return 0;
	}
	for (int i = 1; i < argc; i++) {
		string arg(argv[i]);
		if (arg == "-v")
			visFlag = !visFlag;
		else if (arg == "-iconst")
			iconstFlag = !iconstFlag;
		else if (arg == "-rconst")
			rconstFlag = !rconstFlag;
		else if (arg == "-sconst")
			sconstFlag = !sconstFlag;
		else if (arg == "-ident")
			identFlag = !identFlag;
		else if (arg[0] == '-') {
			cerr << "UNRECOGNIZED FLAG " << arg << endl;
			return 0;
		}
		else {
			if (multiFileFlag)
			{
				cout << "ONLY ONE FILE NAME ALLOWED" << endl;
				return 0;
			}
			file.open(arg);
			multiFileFlag = true;
			if (file.is_open() == false) {
				cerr << "CANNOT OPEN the File " << arg << endl;
				return 0;
			}
		}
	}
	
	//string count = lineTok();
	//cout << count;
	/*
	if (idsflag)
	{
		cout << "Identifiers and Keywords:" << endl;
		for (i = 0; i < idtoks.size(); i++)
		{
			kwtok = id_or_kw(idtoks[i].GetLexeme(), toks[i].GetLinenum());
			cout << kwtok;
		}
		//kwtok = id_or_kw(idtoks[i].GetLexeme(), toks[i].GetLinenum());
		//cout << kwtok;
	}
	if (tokflag)
	{
		cout << "Other tokens:" << endl;
		for (i = 0; toks[i] != DONE; i++)
		{
			cout << toks[i];
		}
		cout << toks[i];
	}
	return 0;4
	*/

	
}
