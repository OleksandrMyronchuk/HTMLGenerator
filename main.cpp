#include <iostream>
#include <fstream>

#include "tableTag.h"

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

	tag *html = new tag("html");

	html->_child.push_back( new tag("head") );
	html->_child.push_back( new tag("body") );
	html->_child.push_back( new tableTag(4, 8) );
	

	((tableTag*)(html->_child.at(2)))->setToCell(1, 1, "str");
	((tableTag*)(html->_child.at(2)))->setToCell(4, 8, "str");

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