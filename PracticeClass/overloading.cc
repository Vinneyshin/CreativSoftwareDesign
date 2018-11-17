class Complex {
	public: 
			Complex() : real(0.0), imag(0.0) {} 
				Complex(double v) : real(v), imag(0.0) {} 
					// Constructor for a single v. 
					Complex(double r, double i) : real(r), imag(i) {} 
						Complex(const Complex& c) : real(c.real), imag(c.imag) {} 
							Complex& operator=(const Complex& c) {
										real = c.real;
												imag = c.imag;
														return *this;
															}

	private: 
								double real, imag; 
}; 

Complex operator+(const Complex& lhs, const Complex& rhs) 
{ 
		return Complex(lhs.real + rhs.real, lhs.imag + rhs.imag); 
} 
void Test() { 
		
		Complex a(1.0, 2.0), b(2.0, 5.0), c; 

		c = a + b; // OK. 
		//c = a + 3.0; // Error. 
		//c = 2.0 + b; // Error, but a different kind. 
}

int main() {
		Test();
			return 0;
}

