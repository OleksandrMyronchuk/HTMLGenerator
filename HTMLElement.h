#ifndef HTMLELEMENT_H
#define HTMLELEMENT_H

#include <string>
#include <vector>
#include <utility>

class HTMLElement
{
public:
	std::vector<std::pair<std::string, std::string>> attributeName;
	std::string textContent;
	std::vector<HTMLElement> child;
	unsigned int id;
	HTMLElement(std::string tagName);
	~HTMLElement();
};

#endif // HTMLELEMENT_H