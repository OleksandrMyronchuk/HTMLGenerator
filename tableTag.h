#ifndef HTMLTABLE_H
#define HTMLTABLE_H

#include "defines.h"
#include "tag.h"

class tableTag : public tag
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
	tableTag(__uint32 row, __uint32 col);
	~tableTag();
};

#endif // HTMLTABLE_H