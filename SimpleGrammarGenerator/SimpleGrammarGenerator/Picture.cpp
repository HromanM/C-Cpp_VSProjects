#include "stdafx.h"

#include "Picture.h"

using std::vector;
using std::string;
using std::ostream;
using std::endl;

Picture frame(const Picture& pic)
{
	return new FramePic(pic.ptr);
}

Picture hConn(const Picture& up, const Picture& lw)
{
	return new HConnPic(up.ptr, lw.ptr);
}

Picture vConn(const Picture& l, const Picture& r)
{
	return new VConnPic(l.ptr, r.ptr);
}

ostream operator<<(ostream& os, const Picture& pic)
{
	const BasePic::vec_size vv = pic.ptr->height();
	for (BasePic::vec_size i = 0; i != vv; i++)
	{
		pic.ptr->display(os, i, false);
		os << endl;
	}
	return os;
}

Picture::Picture(const vector<string>& v): ptr(new StringPic(v)) {}
