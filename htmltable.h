#ifndef HTMLTABLE_H
#define HTMLTABLE_H

#include "defines.h"
#include "htmlgenerator.h"

class HTMLTable : public HTMLGenerator
{
public:	
	void setToCell(
		__uint32 row,
		__uint32 col, 
		std::string val, 
		std::pair<std::string, 
		std::string> attributeName
	);
	void setToCell(
		__uint32 row,
		__uint32 col,
		std::string val
	);
	HTMLTable(__uint32 row, __uint32 col);
	~HTMLTable();
};

#endif // HTMLTABLE_H