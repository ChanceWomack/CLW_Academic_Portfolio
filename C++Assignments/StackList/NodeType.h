#ifndef NODET_H
#define NODET_H

template <typename T>
class NodeType {
	public:
		T data;
		NodeType<T> *next;
		NodeType<T>() { next = nullptr; data = 0;}
		NodeType(T d) { data = d; next = nullptr; }
};//end class
#endif
