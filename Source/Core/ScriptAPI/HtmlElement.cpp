#include "HtmlElement.h"

#include <Core/Squirrelnc.h>

#ifdef _WIN32
#include "HtmlElementPrivate_win.h"
#else
// Not implemented
#endif

using namespace ScriptAPI;


namespace ScriptAPI {

HtmlElement::HtmlElement()
{
	//d_.reset(new HtmlElementPrivate());
}

HtmlElement::HtmlElement(HtmlElementPrivate* pr)
{
	d_.reset(pr);
}



const std::string HtmlElement::getAttribute(const std::string& name)
{
	if ( !checkNull("getAttribute") ) {
		return std::string();
	}
	return d_->getAttribute(name);
}

void HtmlElement::setAttribute(const std::string& name, const std::string& value)
{
	if ( !checkNull("setAttribute") ) {
		return;
	}
	d_->setAttribute(name, value);
}

void HtmlElement::removeAttribute(const std::string& name)
{	
	if ( !checkNull("removeAttribute") ) {
		return;
	}
	d_->removeAttribute(name);
}

const std::string HtmlElement::getId()
{
	if ( !checkNull("getId") ) {
		return std::string();
	}
	return d_->getId();
}

void HtmlElement::setId(const std::string& id)
{
	if ( !checkNull("setId") ) {
		return;
	}
	d_->setId(id);
}

const std::string HtmlElement::getInnerHTML()
{
	if ( !checkNull("getInnerHTML") ) {
		return std::string();
	}
	return d_->getInnerHTML();
}

void HtmlElement::setInnerHTML(const std::string& html)
{
	if ( !checkNull("setInnerHTML") ) {
		return;
	}
	d_->setInnerHTML(html);
}

const std::string HtmlElement::getInnerText()
{
	if ( !checkNull("getInnerText") ) {
		return std::string();
	}
	return d_->getInnerText();
}

void HtmlElement::setInnerText(const std::string& text)
{
	if ( !checkNull("setInnerText") ) {
		return;
	}
	d_->setInnerText(text);
}

const std::string HtmlElement::getOuterHTML()
{
	if ( !checkNull("getOuterHTML") ) {
		return std::string();
	}
	return d_->getOuterHTML();
}

void HtmlElement::setOuterHTML(const std::string& html)
{
	if ( !checkNull("setOuterHTML") ) {
		return;
	}
	d_->setOuterHTML(html);
}

const std::string HtmlElement::getOuterText()
{
	if ( !checkNull("getOuterText") ) {
		return std::string();
	}
	return d_->getOuterText();
}

void HtmlElement::setOuterText(const std::string& text)
{
	if ( !checkNull("setOuterText") ) {
		return;
	}
	d_->setOuterText(text);
}

void HtmlElement::setValue(const std::string& value)
{
	if ( !checkNull("setValue") ) {
		return;
	}
	d_->setValue(value);
}

const std::string HtmlElement::getValue()
{
	if ( !checkNull("getValue") ) {
		return std::string();
	}
	return d_->getValue();
}

const std::string HtmlElement::getTagName()
{
	if ( !checkNull("getTagName") ) {
		return std::string();
	}
	return d_->getTagName();
}


ScriptAPI::HtmlElement HtmlElement::getParentElement()
{
	if ( !checkNull("parentElement") ) {
		return HtmlElement();
	}
	return d_->getParentElement();
}

void HtmlElement::scrollIntoView()
{
	if ( !checkNull("scrollIntoView") ) {
		return;
	}
	d_->scrollIntoView();
}

void HtmlElement::click()
{
	if ( !checkNull("click") ) {
		return;
	}
	d_->click();
}

void HtmlElement::insertHTML(const std::string& name, bool atEnd /*= false */)
{
	if ( !checkNull("insertHTML") ) {
		return;
	}
	d_->insertHTML(name, atEnd /*= false */);
}

void HtmlElement::insertText(const std::string& name, bool atEnd /*= false */)
{
	if ( !checkNull("insertText") ) {
		return;
	}
	d_->insertText(name, atEnd /*= false */);
}

ScriptAPI::HtmlElement HtmlElement::querySelector(const std::string& query)
{
	if ( !checkNull("querySelector") ) {
		return HtmlElement();
	}
	return d_->querySelector(query);
}

SquirrelObject HtmlElement::querySelectorAll(const std::string& query)
{
	if ( !checkNull("querySelectorAll") ) {
		return HtmlElement();
	}
	return d_->querySelectorAll(query);
}

SquirrelObject HtmlElement::getFormElements()
{
	if ( !checkNull("getFormElements") ) {
		return HtmlElement();
	}
	return d_->getFormElements(); 
}

bool HtmlElement::submitForm()
{
	if ( !checkNull("submitForm") ) {
		return false;
	}
	return d_->submitForm();
}

bool HtmlElement::isNull()
{
	return !d_ || d_->isNull();
}

SquirrelObject HtmlElement::getChildren()
{
	if ( !checkNull("getChildren") ) {
		return SquirrelObject();
	}
	return d_->getChildren();
}

bool HtmlElement::checkNull(const char * func)
{
	if ( isNull() ) {
		LOG(WARNING) << func << " : " << "HtmlElement is null";
		return false;
	}
	return true;
}

}

