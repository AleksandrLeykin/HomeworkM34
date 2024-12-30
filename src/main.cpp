#include <iostream>
#include <string>

template <typename T>
concept ComplexConcept = requires(const T v) {
	{v.hash() }
	->std::convertible_to<long>;
	{ v.toString() }
	->std::convertible_to<std::string>;
} && !std::has_virtual_destructor_v<T> ;

struct Number {
	int m_num{ 0 };
	long hash() const {
		return (long)m_num;
	}
	std::string toString() const {
		return std::to_string(m_num);
	}
	//virtual ~Number() {}
};


void PrintType(ComplexConcept auto& t) {
	t.hash();
	std::cout << t.toString() << '\n';
}

int main() {	
	Number x{15};
	PrintType(x);	
	return 0;
}