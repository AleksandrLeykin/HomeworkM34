#include <iostream>
#include <string>

template <typename T>
concept SignedIntegral = std::is_integral<T>::value && std::is_signed<T>::value;

template <SignedIntegral T>
void funcOnlyForSignedInts(T val) {
	val + val;
	val * (-1);
}

template <typename T>
concept HasToString = requires(const T v) {
	{v.hash() }
	->std::convertible_to<long>;
	{ v.toString() }
	->std::convertible_to<std::string>;
} && !std::has_virtual_destructor_v<T> ;

struct Number {
	int m_num{ 0 };
	std::string toString() const {
		return std::to_string(m_num);
	}
};

struct myChar {
	char ch;
	std::string toString() const {
		return std::to_string(ch);
	}
};

void PrintType(HasToString auto& t) {
	std::cout << t.toString() << '\n';
}

int main() {
	//std::cout << "Hello!" << std::endl;
	funcOnlyForSignedInts(5);
	//funcOnlyForSignedInts(5U);
	//funcOnlyForSignedInts(5.0);
	//funcOnlyForSignedInts("go");

	Number x{15};
	PrintType(x);
	
	return 0;
}