# C-Plus-Plus-Fixed-Point
A C++ implementation of fixed point data type.  This purpose of this project was to mimic a fixed point data type for projects that use fixed point in the hardware implementation.  Therefore, this implementation is for evaluation purposes in software.
The current implementation works as a wrapper around a floating point, rounding to achieve specificed precision.

Note 1: I assume that one bit is allocated for the sign bit and use 2's complement logic.
Note 2: Because this uses templates, it may be necessary to add a specific template to the bottom of fixedpoint.hpp:
'''c
	template class FixedPoint<YOUR_INT_BITS,YOUR_FRAC_BITS>;
'''


Format:
'''c
	FixedPoint<INT_BITS, FRAC_BTS>
'''

Basic Use:
'''c
	#include "fixedpoint.hpp"
	FixedPoint<2,2> myfixed;
'''

See fixedpoint_test.cpp for more specific use cases

## To Be Implemented:
- Shift and assign operation
- 2nd branch with Fixed Point mathematical operations
- Power of 2 rounding using log base 2
