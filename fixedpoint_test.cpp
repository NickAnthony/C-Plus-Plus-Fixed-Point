#include "fixedpoint.hpp"


void test_init(){
	FixedPoint<2,2> myfixed;
	FixedPoint<6,12> fixed_max(-FLT_MAX);
	FixedPoint<6,6> fixed_a = NULL;
	FixedPoint<6,6> fixed_b(NULL);

	float r = 12.45678;
	
	FixedPoint<5,32> fixed;
	int a = 3;
	fixed = a;

	int b = 140;
	fixed = b;

	float c = 0.00000000001;
	fixed = c;
	assert(fixed == 0.0);
	

	float d = 134.23;
	fixed = d;

	double e = -3.98;
	fixed = e;

	double f = 134.23;
	fixed = f;

	float g = -3.95;
	FixedPoint<3,3> fixed1 = g;
	FixedPoint<3,4> fixed2 = g;
	FixedPoint<3,5> fixed3 = g;
	FixedPoint<3,6> fixed4 = g;

	FixedPoint<10,10> fixed10((int) 5);
	assert(fixed10 == 5);
	FixedPoint<10,10> fixed10a((float) 5);
	assert(fixed10a == 5);
	FixedPoint<10,10> fixed10b((double) 5);
	assert(fixed10b == 5);
	FixedPoint<10,10> fixed10c;
	assert(fixed10c == 0);
	fixed10c = 10;

	FixedPoint<10,10> *ptr = &fixed10c;

	const FixedPoint<10,10>* fixed10d = const_cast<FixedPoint<10,10>* >(ptr);

}

void test_unary_fixed(){
	FixedPoint<5,5> fixed_base = 10;
	FixedPoint<4,4> fixed4 = (float) -5.0;
	FixedPoint<5,5> fixed5 = (double) 5.0;
	FixedPoint<6,6> fixed6 = (int) 5;

	fixed_base = fixed4;
	fixed_base = 10;
	fixed_base += fixed4;
	fixed_base -= fixed4;
	fixed_base /= fixed4;
	fixed_base *= fixed4;
	assert(fixed_base == 10);

	fixed_base = fixed5;
	fixed_base = 10;
	fixed_base += fixed5;
	fixed_base -= fixed5;
	fixed_base /= fixed5;
	fixed_base *= fixed5;
	assert(fixed_base == 10);

	fixed_base = fixed6;
	fixed_base = 10;
	fixed_base += fixed6;
	fixed_base -= fixed6;
	fixed_base /= fixed6;
	fixed_base *= fixed6;
	assert(fixed_base == 10);

	printf("test_unary_fixed passed.\n");
}

void test_unary_primitives(){
	FixedPoint<5,5> fixed_base = 10;
	int int_a = -5;
	float float_b = 5.0;
	double double_c = 5;

	fixed_base = int_a;
	fixed_base = 10;
	fixed_base += int_a;
	fixed_base -= int_a;
	assert(fixed_base == 10);
	fixed_base /= int_a;
	fixed_base *= int_a;
	assert(fixed_base == 10);

	fixed_base = float_b;
	fixed_base = 10;
	fixed_base += float_b;
	fixed_base -= float_b;
	assert(fixed_base == 10);
	fixed_base /= float_b;
	fixed_base *= float_b;
	assert(fixed_base == 10);

	fixed_base = double_c;
	fixed_base = 10;
	fixed_base += double_c;
	fixed_base -= double_c;
	assert(fixed_base == 10);
	fixed_base /= double_c;
	fixed_base *= double_c;
	assert(fixed_base == 10);

	assert(+fixed_base == 10);
	assert(-fixed_base == -10);
	fixed_base *= -1;
	assert(+fixed_base == 10);
	assert(-fixed_base == -10);


	printf("test_unary_primitives passed.\n");
}

void test_comparison_fixed(){
	FixedPoint<5,5> fixed_base = 10;
	FixedPoint<4,4> fixed4 = (float) -5.0;
	FixedPoint<5,5> fixed5 = (double) 5.0;
	FixedPoint<6,6> fixed6 = (int) 5;

	if(fixed_base == fixed4 || fixed_base == fixed5 || fixed_base == fixed6){
		printf("== operator failed: primitives.\n");
		exit(1);
	}
	if(!(fixed_base != fixed4 || fixed_base != fixed5 || fixed_base != fixed6)){
		printf("!= operator failed: fixed.\n");
		exit(1);
	}
	if(!(fixed_base >= fixed4 || fixed_base >= fixed5 || fixed_base >= fixed6)){
		printf(">= operator failed: fixed.\n");
		exit(1);
	}
	if(fixed_base <= fixed4 || fixed_base <= fixed5 || fixed_base <= fixed6){
		printf("<= operator failed: fixed.\n");
		exit(1);
	}
	if(!(fixed_base > fixed4 || fixed_base > fixed5 || fixed_base > fixed6)){
		printf("> operator failed: fixed.\n");
		exit(1);
	}
	if(fixed_base < fixed4 || fixed_base < fixed5 || fixed_base < fixed6){
		printf("< operator failed: fixed.\n");
		exit(1);
	}

	printf("test_comparison_fixed passed.\n");
}


void test_comparison_primitives(){
	FixedPoint<5,5> fixed_base = 10;
	int int_a = -5;
	float float_b = 5.0;
	double double_c = 5;

	if(fixed_base == int_a || fixed_base == float_b || fixed_base == double_c){
		printf("== operator failed: primitives.\n");
		exit(1);	
	}
	if(!(fixed_base != int_a || fixed_base != float_b || fixed_base != double_c)){
		printf("!= operator failed: fixed.\n");
		exit(1);	
	}
	if(!(fixed_base >= int_a || fixed_base >= float_b || fixed_base >= double_c)){
		printf(">= operator failed: fixed.\n");
		exit(1);	
	}
	if(fixed_base <= int_a || fixed_base <= float_b || fixed_base <= double_c){
		printf("<= operator failed: fixed.\n");
		exit(1);	
	}
	if(!(fixed_base > int_a || fixed_base > float_b || fixed_base > double_c)){
		printf("> operator failed: fixed.\n");
		exit(1);	
	}
	if(fixed_base < int_a || fixed_base < float_b || fixed_base < double_c){
		printf("< operator failed: fixed.\n");
		exit(1);	
	}
	printf("test_comparison_primitives passed.\n");
}

void test_type_casting(){
	FixedPoint<5,5> fixed_base = (int) 10.2;
	const FixedPoint<6,6> fixed_const = (double) 12.25;
	// std::cout << "fixed_base: " << fixed_base << std::endl;

	int int_a = static_cast<int>(fixed_base);
	assert(int_a == 10);
	int_a = static_cast<int>(fixed_const);
	assert(int_a == 12);

	int int_a1 = (int) fixed_base;
	assert(int_a1 == 10);
	int_a1 = (int) fixed_const;
	assert(int_a1 == 12);

	float float_b = static_cast<float>(fixed_base);
	assert(float_b == 10.0);
	float_b = static_cast<float>(fixed_const);
	assert(float_b == 12.25);

	float float_b1 = (float) fixed_base;
	assert(float_b1 == 10.0);
	float_b1 = (float) fixed_const;
	assert(float_b1 == 12.25);

	double double_c = static_cast<double>(fixed_base);
	assert(double_c == 10.0);
	double_c = static_cast<double>(fixed_const);
	assert(double_c == 12.25);

	double double_c1 = (double) fixed_base;
	assert(double_c1 == 10.0);
	double_c1 = (double) fixed_const;
	assert(double_c1 == 12.25);

	int_a = 10;

	const int int_a2 = (const int) fixed_base;
	const float float_b2 = (const float) fixed_base;
	const double double_c2 = (const double) fixed_base;

	void* ptr = (void *) (&fixed_base);
	const void* ptr_2 = (const void *) (&fixed_base);
	assert(ptr_2 == ptr);
	int* ptr_3 = (int*) ptr;
	assert(ptr_3 == ptr);
	float* ptr_4 = (float*) ptr;
	assert(ptr_4 == ptr);
	double* ptr_5 = (double*) ptr;
	assert(ptr_5 == ptr);
	const int* ptr_6 = (const int*) ptr;
	assert(ptr_6 == ptr);
	const float* ptr_7 = (const float*) ptr;
	assert(ptr_7 == ptr);
	const double* ptr_8 = (const double*) ptr;
	assert(ptr_8 == ptr);
	int* ptr_9 = (int*) ptr_4;
	assert(ptr_9 == ptr);
	float* ptr_10 = (float*) ptr_3;
	assert(ptr_10 == ptr);
	double* ptr_11 = (double*) ptr_3;
	assert(ptr_11 == ptr);

	FixedPoint<5,5>* ptr_12 = (FixedPoint<5,5>*) ptr;
	assert(ptr_12 == ptr);
	const FixedPoint<5,5>* ptr_13 = (const FixedPoint<5,5>*) ptr;
	assert(ptr_13 == ptr);
	FixedPoint<5,5>* ptr_14 = (FixedPoint<5,5>*) ptr_3;
	assert(ptr_14 == ptr);
	FixedPoint<5,5>* ptr_15 = (FixedPoint<5,5>*) ptr_4;
	assert(ptr_15 == ptr);
	FixedPoint<5,5>* ptr_16 = (FixedPoint<5,5>*) ptr_5;
	assert(ptr_16 == ptr);
	const FixedPoint<5,5>* ptr_17 = (const FixedPoint<5,5>*) ptr_7;
	assert(ptr_17 == ptr);
	
	printf("test_type_casting passed.\n");
}

void test_adding_fixed(){
	FixedPoint<6,5> fixed_base = 10;
	FixedPoint<5,4> fixed4 = (float) -5.0;
	FixedPoint<6,5> fixed5 = (double) 5.0;
	FixedPoint<7,6> fixed6 = (int) 5;

	fixed_base = fixed4 + fixed4;
	assert(fixed_base == -10);
	fixed_base = fixed4 - fixed4;
	assert(fixed_base == 0);
	fixed_base = fixed4 / fixed4;
	assert(fixed_base == 1);
	fixed_base = fixed4 * fixed4;

	fixed_base = fixed4 + fixed5;
	assert(fixed_base == 0);
	fixed_base = fixed4 - fixed5;
	assert(fixed_base == -10);
	fixed_base = fixed4 / fixed5;
	assert(fixed_base == -1);
	fixed_base = fixed4 * fixed5;

	fixed_base = fixed4 + fixed6;
	assert(fixed_base == 0);
	fixed_base = fixed4 - fixed6;
	assert(fixed_base == -10);
	fixed_base = fixed4 / fixed6;
	assert(fixed_base == -1);
	fixed_base = fixed4 * fixed6;

	fixed_base = 10;

	fixed_base = fixed5;
	fixed_base = 10;
	fixed_base += fixed5;
	fixed_base -= fixed5;
	fixed_base /= fixed5;
	fixed_base *= fixed5;
	assert(fixed_base == 10);

	fixed_base = fixed6;
	fixed_base = 10;
	fixed_base += fixed6;
	fixed_base -= fixed6;
	fixed_base /= fixed6;
	fixed_base *= fixed6;
	assert(fixed_base == 10)

	printf("test_adding_fixed passed.\n");
}

void test_adding_primitives(){
	FixedPoint<6,5> fixed_base = 10;
	FixedPoint<5,4> fixed4 = (float) 10;
	int int_a = -5;
	float float_b = -5.0;
	double double_c = -5;

	fixed_base = fixed4 + int_a;
	assert(fixed_base == 5);
	fixed_base = fixed4 - int_a;
	assert(fixed_base == 15);
	fixed_base = fixed4 / int_a;
	assert(fixed_base == -2);
	fixed_base = fixed4 * int_a;

	fixed_base = fixed4 + float_b;
	assert(fixed_base == 5);
	fixed_base = fixed4 - float_b;
	assert(fixed_base == 15);
	fixed_base = fixed4 / float_b;
	assert(fixed_base == -2);
	fixed_base = fixed4 * float_b;

	fixed_base = fixed4 + double_c;
	assert(fixed_base == 5);
	fixed_base = fixed4 - double_c;
	assert(fixed_base == 15);
	fixed_base = fixed4 / double_c;
	assert(fixed_base == -2);
	fixed_base = fixed4 * double_c;

	fixed_base = int_a + (int) fixed4;
	fixed_base = int_a - (int) fixed4;
	fixed_base = int_a / (int) fixed4;
	fixed_base = int_a * (int) fixed4;

	fixed_base = float_b + (float) fixed4;
	fixed_base = float_b - (float) fixed4;
	fixed_base = float_b / (float) fixed4;
	fixed_base = float_b * (float) fixed4;

	fixed_base = double_c + (double) fixed4;
	fixed_base = double_c - (double) fixed4;
	fixed_base = double_c / (double) fixed4;
	fixed_base = double_c * (double) fixed4;

	printf("test_adding_primitives passed.\n");
}

void test_abs(){
	FixedPoint<6,2> fixed6 = 10;
	FixedPoint<4,5> fixed4 = (float) -10;
	FixedPoint<4,12> fixed0 = (double) 0;

	int a = -5;
	float b = -10;
	double c = -12;

	assert(abs(fixed6) >= 0);
	assert(abs(fixed4) >= 0);
	assert(abs(fixed0) == 0);

	assert(abs(a) == 5);
	assert(abs(b) == 10);
	assert(abs(c) == 12);
	printf("test_abs passed.\n");
}

void test_increments(){
	FixedPoint<6,2> fixed6 = 10;

	assert(++fixed6 == 11);
	assert(--fixed6 == 10);

	assert(fixed6++ == 10);
	assert(fixed6 == 11);

	assert(fixed6-- == 11);
	assert(fixed6 == 10);

	printf("test_increments passed.\n");
}

void test_pointer(){
	FixedPoint<10,10> fixed_base = 10;
	FixedPoint<10,10> *fixed_ptr = &fixed_base;


	assert(fixed_base == *fixed_ptr);
	assert(fixed_base.raw_ == fixed_ptr->raw_);
	assert(fixed_base.frac_bits() == fixed_ptr->frac_bits());

	assert(&fixed_base == fixed_ptr);
	assert(fixed_base.raw_ == (*fixed_ptr).raw_);
	printf("test_pointer passed.\n");
}

void test_iteration(){
	FixedPoint<10,10> array[10];

	for(int i = 0; i < 10; i++){
		assert(array[i] == 0);
		array[i] = 9;
	}
	for(int j = 0; j < 10; j++){
		assert(array[j] == 9);
	}

	FixedPoint<10,10>* array_ptr = array;
	for(int j = 0; j < 10; j++){
		assert(array_ptr[j] == 9);
	}

	FixedPoint<10,10>** array_ptr_ptr = &array_ptr;
	for(int j = 0; j < 10; j++){
		assert(((FixedPoint<10,10>*) array_ptr[0])[j] == 9);
	}

	printf("test_iteration passed.\n");
}

void test_max_min(){
	FixedPoint<10,10> high = 14.5;
	FixedPoint<10,10> mid = 10.2;
	FixedPoint<10,10> low = 5.5;

	assert(fixedpoint::max(high, low) == high);
	assert(fixedpoint::max(mid, low) == mid);
	assert(fixedpoint::max(low, low) == low);

	assert(fixedpoint::max(high, mid) == high);
	assert(fixedpoint::max(mid, mid) == mid);
	assert(fixedpoint::max(low, mid) == mid);

	assert(fixedpoint::max(high, high) == high);
	assert(fixedpoint::max(mid, high) == high);
	assert(fixedpoint::max(low, high) == high);

	assert(fixedpoint::min(high, low) == low);
	assert(fixedpoint::min(mid, low) == low);
	assert(fixedpoint::min(low, low) == low);

	assert(fixedpoint::min(high, mid) == mid);
	assert(fixedpoint::min(mid, mid) == mid);
	assert(fixedpoint::min(low, mid) == low);

	assert(fixedpoint::min(high, high) == high);
	assert(fixedpoint::min(mid, high) == mid);
	assert(fixedpoint::min(low, high) == low);

	assert(fixedpoint::isnan(low) == false);
	assert(fixedpoint::isnan(high) == false);

	float low1 = 5;
	float low2 = 6;
	float mid1 = 10.2;
	float mid2 = 12.3;
	float high1 = 21.2;
	float high2 = 24.3;

	assert(fixedpoint::max(low1, low2) == low2);
	assert(fixedpoint::max(low2, low1) == low2);

	assert(fixedpoint::max(mid1, mid2) == mid2);
	assert(fixedpoint::max(mid2, mid1) == mid2);

	assert(fixedpoint::max(high1, high2) == high2);
	assert(fixedpoint::max(high2, high1) == high2);

	assert(fixedpoint::max(low1, mid1) == mid1);
	assert(fixedpoint::max(mid1, high1) == high1);

	printf("test_max_min passed.\n");
}


void test_extra_functions(){
	FixedPoint<6,4> high = 25;
	FixedPoint<10,10> mid = 4.84;
	int a = 25;
	float b = 4.84;
	double c = 4.84;

	assert(fixedpoint::sqrt(high) == 5);
	assert(fixedpoint::sqrt(mid) == 2.2001953125);
	assert(fixedpoint::sqrt(a) == 5);
	assert(fixedpoint::sqrt(b) == (float) 2.2);
	assert(fixedpoint::sqrt(c) == (double) 2.2);

	printf("test_extra_functions passed.\n");
}

void test_power_2(){
	FixedPoint<6,4> high = 25;
	FixedPoint<2,4> mid = 0.071;
	FixedPoint<4,6> low = 0.0003;
	high.SetPower2(true);
	mid.SetPower2(true);
	low.SetPower2(true);
	assert(high == 32.0);
	assert(mid == 0.0625);
	assert(low == 0.0);
	printf("test_power_2 passed.\n");
}




int main(){
	test_init();
	test_unary_fixed();
	test_unary_primitives();
	test_comparison_fixed();
	test_comparison_primitives();
	test_type_casting();
	test_adding_fixed();
	test_adding_primitives();
	test_abs();
	test_increments();
	test_pointer();
	test_iteration();
	test_max_min();
	test_extra_functions();
	test_power_2();

	return 0;
}
