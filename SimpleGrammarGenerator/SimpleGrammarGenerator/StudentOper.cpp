#include "stdafx.h"
#include "StudentOper.h"
#include "iostream"

using std::istream;

istream& StudentOper::readStOper(istream& is)
{
	char ch;
	is >> ch;

	if (ch == 'Z')
		zu = new BasicSt(is);
	else
		zu = new CertSt(is);
	return is;
}

