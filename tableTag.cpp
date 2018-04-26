#include "tableTag.h"

tableTag::tableTag(__uint32 row, __uint32 col) : tag("table")
{
#define defTbody ((tag*)(this))->_child
#define defRow ((tag*)(defTbody.at(0)))->_child
#define defCol(rowInd) ((tag*)(defRow.at(rowInd)))->_child

	defTbody.push_back( new tag("tbody") );/*table->tbody*/

	//del	
	this->_attributeName.push_back( std::make_pair("border", "1") );
	this->_attributeName.push_back(std::make_pair("class", "ex"));
	//del

	for (__uint32 i(0); i < row; i++)
	{
		defRow.push_back( new tag("tr") );/*table->tbody->row*/
		for (__uint32 j(0); j < col; j++)
		{			
			defCol(i).push_back( new tag("td") );/*table->tbody->row->col*/
		}
	}
#undef defTbody
#undef defRow
#undef defCol
}

tableTag::~tableTag()
{
}

#define thisCell(r, c) ((tag*)(((tag*)(((tag*)(this->_child.at(0)))->_child.at(r - 1)))->_child.at(c - 1)))

void tableTag::setToCell(
	__uint32 row,
	__uint32 col,
	std::string val
)
{
	thisCell(row, col)->_textContent = val;
}

void tableTag::setToCell(
	__uint32 row, 
	__uint32 col, 
	std::string val, 
	std::pair<std::string, std::string> attributeName
)
{
	thisCell(row, col)->_textContent = val;
	thisCell(row, col)->_attributeName.push_back(attributeName);
}

#undef thisCell