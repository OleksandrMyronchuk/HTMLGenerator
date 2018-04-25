#include "htmltable.h"

HTMLTable::HTMLTable(__uint32 row, __uint32 col) : HTMLGenerator("table")
{
#define defTbody this->_child
#define defRow defTbody.at(0)._child
#define defCol(rowInd) defRow.at(rowInd)._child

	defTbody.push_back( HTMLGenerator("tbody") );/*table->tbody*/

	//del	
	this->_attributeName.push_back( std::make_pair("border", "1") );
	this->_attributeName.push_back(std::make_pair("class", "ex"));
	//del

	for (__uint32 i(0); i < row; i++)
	{
		defRow.push_back( HTMLGenerator("tr") );/*table->tbody->row*/
		for (__uint32 j(0); j < col; j++)
		{			
			defCol(i).push_back( HTMLGenerator("td") );/*table->tbody->row->col*/
		}
	}
#undef defTbody
#undef defRow
#undef defCol
}

HTMLTable::~HTMLTable()
{
}

#define thisCell this->_child.at(0)._child.at(row - 1)._child.at(col - 1)

void HTMLTable::setToCell(
	__uint32 row,
	__uint32 col,
	std::string val
)
{
	thisCell._textContent = val;
}

void HTMLTable::setToCell(
	__uint32 row, 
	__uint32 col, 
	std::string val, 
	std::pair<std::string, std::string> attributeName
)
{
	thisCell._textContent = val;
	thisCell._attributeName.push_back(attributeName);
}

#undef thisCell