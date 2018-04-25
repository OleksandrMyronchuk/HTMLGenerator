#include "htmlgenerator.h"

HTMLGenerator::HTMLGenerator(std::string tagName) : _tagName(tagName)
{
}

HTMLGenerator::~HTMLGenerator()
{
}

void HTMLGenerator::_printHTMLDoc(HTMLGenerator *depth, __uint32 ind = 0)
{
	/*Start Tag*/
	this->_printResult += "<" + depth->_tagName;
	if (!depth->_attributeName.empty()) //ATTRIBUTE
	{
		size_t attributeNameLength = depth->_attributeName.size();
		for (size_t i(0); i < attributeNameLength; i++)
		{
			this->_printResult += " " + depth->_attributeName.at(i).first + "=\"" +
				depth->_attributeName.at(i).second + "\" ";
		}
	}
	this->_printResult += ">";

	/*Content*/
	this->_printResult += depth->_textContent;

	/*Recursive sampling*/
	for (__uint32 i = 0; i < depth->_child.size(); i++)
	{
		if (!depth->_child.empty())
		{
			_printHTMLDoc(&(depth->_child.at(i)));
		}
	}

	/*End Tag*/
	this->_printResult += "</" + depth->_tagName + ">";
}

std::string HTMLGenerator::printHTMLDoc()
{
	_printResult.clear();
	this->_printHTMLDoc(this);
	return _printResult;
}