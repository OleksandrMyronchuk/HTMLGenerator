#ifndef HTMLGENERATOR_H
#define HTMLGENERATOR_H

#include <string>
#include <vector>
#include <utility>
#include <string>
#include "defines.h"
#include "abstracttag.h"

class HTMLGenerator //: public abstractTag
{
private:
	void _printHTMLDoc(HTMLGenerator *depth, __uint32 ind);
	std::string _printResult;
	unsigned int _id;
public:
	std::string _tagName;
	std::vector<std::pair<std::string, std::string>> _attributeName;
	std::string _textContent;
	std::vector<HTMLGenerator> _child;

	std::string printHTMLDoc();

	HTMLGenerator(std::string tagName);
	~HTMLGenerator();
};

#endif // HTMLGENERATOR_H
