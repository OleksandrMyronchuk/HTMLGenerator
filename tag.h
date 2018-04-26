#ifndef HTMLGENERATOR_H
#define HTMLGENERATOR_H

#include <string>
#include <vector>
#include <utility>
#include <string>
#include "defines.h"
#include "abstracttag.h"

class tag : public abstractTag
{
private:
	void _printHTMLDoc(tag *depth, __uint32 ind);
	std::string _printResult;
	unsigned int _id;
public:
	std::string _tagName;
	std::vector<std::pair<std::string, std::string>> _attributeName;
	std::string _textContent;
	std::vector<abstractTag*> _child;

	std::string printHTMLDoc();

	tag(std::string tagName);
	~tag();
};

#endif // HTMLGENERATOR_H
