#ifndef POINT_HPP
#define POINT_HPP

#include <bits/stdc++.h>
using namespace std;

template<class T>
class Point {
public:
	T x, y;
	Point(): x(0), y(0) {}	
	Point(T x, T y): x(x), y(y) {}
	
	template<class U>
	operator Point<U> () {return Point<U>(x, y);}

	template<class U>
	Point& operator =(Point<U> v) {
		return x = v.x, y = v.y, *this;
	}
};

template<class U> Point<U> mkPoint(U x, U y) {return Point<U>(x, y);}

template<class U, class V> 
auto operator +(Point<U> p, Point<V> q) {return mkPoint(p.x+q.x, p.y+q.y);}

template<class U, class V>
auto operator -(Point<U> p, Point<V> q) {return mkPoint(p.x-q.x, p.y-q.y);}

template<class U>
auto operator -(Point<U> u) {return mkPoint(-u.x, -u.y);}

template<class U, class V>
auto operator *(Point<U> p, Point<V> q) {return p.x*q.x + p.y*q.y;}

template<class U, class V> 
auto operator ^(Point<U> p, Point<V> q) {return p.x*q.y - p.y*q.x;}

template<class U, class F>
auto operator *(Point<U> p, F f) {return mkPoint(p.x * f, p.y * f);}

template<class U, class F>
auto operator /(Point<U> p, F f) {return mkPoint(p.x / f, p.y / f);}

template<class U, class V> 
auto& operator +=(Point<U>& u, Point<V> v) {return u = u + v;}

template<class U, class V>
auto& operator -=(Point<U>& u, Point<V> v) {return u = u - v;}

template<class U, class F>
auto& operator *=(Point<U>& u, F f) {return u = u * f;}

template<class U, class F>
auto& operator /=(Point<U> u, F f) {return u = u / f;}

template<class F>
istream& operator >>(istream& in, Point<F>& p) {return in >> p.x >> p.y;}

template<class F>
ostream& operator <<(ostream& out, Point<F>& p) {return out << p.x << ' ' << p.y;}

template<class U, class V>
bool operator ==(Point<U> u, Point<V> v) {return u.x == v.x and u.y == v.y;}

template<class U, class V>
bool operator !=(Point<U> u, Point<V> v) {return not (u == v);}

template<class U, class V>
bool operator <(Point<U> u, Point<V> v) {
	return u.x < v.x or (u.x == v.x and u.y < v.y);
}

template<class U, class V>
bool operator <=(Point<U> u, Point<V> v) {
	return u < v or u == v;
}

template<class U, class V>
bool operator >(Point<U> u, Point<V> v) {
	return v < u;
}

template<class U, class V>
bool operator >=(Point<U> u, Point<V> v) {
	return v <= u;
}

//angles and rotation

template<class U>
auto angle(Point<U>& u) {return atan2(u.y, u.x);}

template<class U, class V>
auto angle(Point<U>& u, Point<V>& v) {return atan2(u ^ v, u * v);}

template<class U, class V, class W>
auto angle(Point<W>& w, Point<U>& u, Point<V>& v) {return angle(u-w, v-w);}

template<class U, class F>
auto rotate(Point<U>& u, const F& angleSin, const F& angleCos) {
	return mkPoint(angleCos*u.x - angleSin*u.y, angleSin*u.x + angleCos*u.y);
}

template<class U, class F> 
auto rotate(Point<U>& u, const F& angle) {
	return rotate(u, sin(angle), cos(angle));
}

template<class U, class V, class F>
auto rotate(Point<U>& u, Point<V>& v, const F& angle) {
	return u + rotate(v-u, angle);
}

template<class U>
auto perp(Point<U>& u) {return mkPoint(-u.y, u.x);}

template<class U>
auto abs(Point<U>& u) {return u * u;} 

template<class U>
auto norm(Point<U>& u) {return sqrt(abs(u));}

template<class U, class V>
auto dist(Point<U>& u, Point<V>& v) {return norm(u-v);}

template<class U, class V>
auto dist2(Point<U>& u, Point<V>& v) {return abs(u-v);}

template<class U, class V>
auto bisector(Point<U>& u, Point<V>& v) {return u * norm(v) + v * norm(u);}

#endif
