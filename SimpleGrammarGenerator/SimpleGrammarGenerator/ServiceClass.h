#pragma once

template <class T> class ServiceClass
{
public:
	ServiceClass() : ptr(0) {}
	ServiceClass(const ServiceClass& s) : p(0) { if (s.ptr) ptr = s.ptr->cloneSt(); }
	ServiceClass& operator=(const ServiceClass&);
	~ServiceClass() { delete ptr; }

	ServiceClass(T* t) : ptr(t) {}

	operator bool() const { return ptr; }
	T& operator*() const;
	T* operator->() const;
	
private:
	T* ptr;
};

/*
template <class T> class RefService
{
public:
	RefService(): refPtr(new size_t(1)), ptr(0) {}
	RefService(T* t): refPtr(new size_t(1)), ptr(t) {}
	RefService(const RefService& o) : refPtr(o.refPtr), p(o.ptr) {
		++*refPtr;
	}

	/*RefService& operator=(const RefSerice&);
	~RefService();

	operator bool() const { return ptr; }
	T& operator*() const {
		if (ptr)
			return *ptr;
		throw std::runtime_error("uninitialized object RefService");
	}
	T* operator->() const {
		if (ptr)
			return ptr;
		throw std::runtime_error(" uninitialized object RefService");
	}

private:
	std::size_t* refPtr;
	T* ptr;
};*/