#pragma once
#include "Ptr.h"

/*****************************************************************************
* class base pic
*****************************************************************************/
class BasePic {
	typedef std::vector<std::string>::size_type vec_size;
	typedef std::string::size_type str_size;
public:
	virtual vec_size height() const = 0;
	virtual str_size width() const = 0;
	virtual void display(std::ostream&, vec_size, bool) const = 0;

	virtual ~BasePic() {}
};

/*****************************************************************************
* class frame picture
*****************************************************************************/
class FramePic: public BasePic {
	friend Picture frame(const Picture&);
	Ptr<BasePic> ptr;
	FramePic(const Ptr<BasePic>& pic): ptr(pic) {}

	vec_size height() const { return ptr->height() + 4; }
	str_size width() const { return ptr->width() + 4; }
	void display(std::ostream&, vec_size, bool) const;
};

/*****************************************************************************
* class Vertical connection picture
*****************************************************************************/
class VConnPic : public BasePic {
	Ptr<BasePic> upper, lower;
	VConnPic(const Ptr<BasePic>& up, const Ptr<BasePic>& low) :
		upper(up), lower(low) {}

	vec_size height() const { return upper->height() + lower->height(); }
	str_size width() const { return upper->width() + lower->width(); }
	void display(std::ostream&, vec_size, bool) const;
};

/*****************************************************************************
* class horizontal connection picture
*****************************************************************************/
class HConnPic : public BasePic {
	Ptr<BasePic> left, right;
	HConnPic(const Ptr<BasePic>& l, const Ptr<BasePic>& r) :
		left(l), right(r) {}

	vec_size height() const { return max(left->height(), right->height()); }
	str_size width() const { return left->width() + right->width(); }
	void display(std::ostream&, vec_size, bool) const;
};

/*****************************************************************************
* class string picture
*****************************************************************************/
class StringPic : public BasePic {
	std::vector<std::string> data;
	StringPic(const std::vector<std::string>& v): data(v) {}

	vec_size height() const;
	str_size width() const;
	void display(std::ostream&, vec_size, bool) const;
};

class Picture {
public:
	Picture(const std::vector<std::string>& = std::vector<std::string>());
private:
	Picture(BasePic* p): ptr(p) {}
	Ptr<BasePic> ptr;
};

/***************************************************************************
* aux Picture interface fc 
***************************************************************************/
Picture frame(const Picture& pic)
{
	BasePic* bp = new FramePic(pic.ptr);
}
Picture hConn(const Picture&, const Picture&);
Picture vConn(const Picture&, const Picture&);
std::ostream operator<<(std::ostream&, const Picture&);
