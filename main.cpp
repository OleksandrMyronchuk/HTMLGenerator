#include <iostream>
#include <fstream>

#include "htmltable.h"

int main(int argc, char *argv[])
{
	std::cout << "Start\n\n\n";

	//

	std::filebuf* fout = new std::filebuf;
	std::streambuf* backup = std::cout.rdbuf();
	if (!fout->open("A:\\qtProject\\text.html", std::ios::out | std::ios::trunc))
		throw std::runtime_error("File A:\\qtProject\\text.txt cannot be opened");
	std::cout.rdbuf(fout);

	//

	HTMLGenerator *html = new HTMLGenerator("html");

	html->_child.push_back( HTMLGenerator("head") );
	html->_child.push_back( HTMLGenerator("body") );
	html->_child.push_back( HTMLTable(4, 8) );
	//HTMLTable *tab = new HTMLTable(4, 8);

	//static_cast<HTMLTable*>(html->_child.at(0)).
	/*html->_child.at(0)->setToCell(1, 1, "str");
	html->_child.at(0)->setToCell(4, 8, "str");*/
	/*tab->setToCell(1, 1, "str");
	tab->setToCell(4, 8, "str");
	
	std::cout << tab->printHTMLDoc();*/
	
	std::cout << html->printHTMLDoc();

	//
	fout->close();
	delete fout;
	std::cout.rdbuf(backup);

	std::cout << "\n\n\nEnd";
	//
	
	//delete tab;
	delete html;

	getchar(); 
	return 0;
}