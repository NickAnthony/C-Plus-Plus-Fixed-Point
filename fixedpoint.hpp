#ifndef FIXEDPOINT_H__
#define FIXEDPOINT_H__


#include <iostream>
#include <cstdlib>
#include <cmath>
#include <iomanip>      // std::setprecision
#include <cassert>
#include <cfloat>

template <int INT_BITS, int FRAC_BITS>
class FixedPoint {
    public:
        FixedPoint(){
            Init();
            raw_ = 0;
            raw_ = RoundToFixedPoint(raw_);
        }
        //FixedPoint(const FixedPoint& rhs);
        //FixedPoint(FixedPoint& rhs);
        FixedPoint(int rhs){
            Init();
            raw_ = (float) rhs;
            raw_ = RoundToFixedPoint(raw_);
        }
        FixedPoint(float rhs){
            Init();
            raw_ = rhs;
            raw_ = RoundToFixedPoint(raw_);
        }
        FixedPoint(double rhs){
            Init();
            raw_ = (float) rhs;
            raw_ = RoundToFixedPoint(raw_); 
        }
        FixedPoint(long rhs){
            Init();
            raw_ = (float) rhs;
            raw_ = RoundToFixedPoint(raw_); 
        }
        FixedPoint(unsigned int rhs){
            Init();
            raw_ = (float) rhs;
            raw_ = RoundToFixedPoint(raw_); 
        }

        template <int INT_BITS_R, int FRAC_BITS_R>
        FixedPoint(FixedPoint<INT_BITS_R, FRAC_BITS_R> rhs){
            Init();
            raw_ = rhs.raw_;
            raw_ = RoundToFixedPoint(raw_); 
        }

        ~FixedPoint(){};

        float raw_;

        /* Comparison operators: */
        template<typename datatype>
        inline bool operator==(datatype other) {
            return(raw_ == (float) other);
        }
        template<typename datatype>
        inline bool operator!=(datatype other) {
            return(raw_ != (float) other);
        }
        template<typename datatype>
        inline bool operator<(datatype other) {
            return(raw_ < (float) other);
        }
        template<typename datatype>
        inline bool operator>(datatype other) {
            return(raw_ > (float) other);
        }
        template<typename datatype>
        inline bool operator<=(datatype other) {
            return(raw_ <= (float) other);
        }
        template<typename datatype>
        inline bool operator>=(datatype other) {
            return(raw_ >= (float) other);
        }

        template<typename datatype>
        inline bool operator==(datatype other) const {
            return(raw_ == (float) other);
        }
        template<typename datatype>
        inline bool operator!=(datatype other) const {
            return(raw_ != (float) other);
        }
        template<typename datatype>
        inline bool operator<(datatype other) const {
            return(raw_ < (float) other);
        }
        template<typename datatype>
        inline bool operator>(datatype other) const {
            return(raw_ > (float) other);
        }
        template<typename datatype>
        inline bool operator<=(datatype other) const {
            return(raw_ <= (float) other);
        }
        template<typename datatype>
        inline bool operator>=(datatype other) const {
            return(raw_ >= (float) other);
        }
        

        // Reciprocal operators: primitive types
        template<typename datatype>
        inline FixedPoint& operator=(datatype rhs){
            raw_ = FixedPoint(rhs).raw_;
            check_sign();
            return *this;
        }
        template<typename datatype>
        inline FixedPoint& operator+=(datatype rhs){
            raw_ += FixedPoint(rhs).raw_;
            check_sign();
            return *this;
        }
        template<typename datatype>
        inline FixedPoint& operator-=(datatype rhs){
            raw_ -= FixedPoint(rhs).raw_;
            check_sign();
            return *this;
        }
        template<typename datatype> 
        inline FixedPoint& operator*=(datatype rhs){
            raw_ *= FixedPoint(rhs).raw_;
            check_sign();
            return *this;
        }
        template<typename datatype>
        inline FixedPoint& operator/=(datatype rhs){
            if(rhs == 0){
                raw_ = 0;
            }
            else{
                raw_ /= FixedPoint(rhs).raw_;
            }
            check_sign();
            return *this;
        }
        

        /* TO DO: Shift and assign operators */
        // FixedPoint& operator<<=(int shift);
        // FixedPoint& operator>>=(int shift);


        /* Binary Arithmatic Operators: Primitives */
        template<typename datatype>
        inline FixedPoint<INT_BITS, FRAC_BITS> operator+(datatype other){
            float new_val = raw_ + (float) other;
            return(FixedPoint<INT_BITS,FRAC_BITS>(new_val));
        }
        template<typename datatype>
        inline FixedPoint<INT_BITS, FRAC_BITS> operator-(datatype other){
            float new_val = raw_ - (float) other;
            return(FixedPoint<INT_BITS,FRAC_BITS>(new_val));
        }
        template<typename datatype>
        inline FixedPoint<INT_BITS, FRAC_BITS> operator*(datatype other){
            float new_val = raw_ * (float) other;
            return(FixedPoint<INT_BITS,FRAC_BITS>(new_val));
        }
        template<typename datatype>
        FixedPoint<INT_BITS, FRAC_BITS> operator/(datatype other){
            if(other == 0.0){
                printf("PROBLEM: divide by zero\n");
                return(FixedPoint<INT_BITS,FRAC_BITS>(raw_));
            }
            else{
                float new_val = raw_ / (float) other;
                return(FixedPoint<INT_BITS,FRAC_BITS>(new_val));
            }    
        }

        /* Binary Arithmatic Operators: Primitives */
        template<typename datatype>
        inline const FixedPoint<INT_BITS, FRAC_BITS> operator+(datatype other) const {
            float new_val = raw_ + (float) other;
            return(FixedPoint<INT_BITS,FRAC_BITS>(new_val));
        }
        template<typename datatype>
        inline const FixedPoint<INT_BITS, FRAC_BITS> operator-(datatype other) const {
            float new_val = raw_ - (float) other;
            return(FixedPoint<INT_BITS,FRAC_BITS>(new_val));
        }
        template<typename datatype>
        inline const FixedPoint<INT_BITS, FRAC_BITS> operator*(datatype other) const {
            float new_val = raw_ * (float) other;
            return(FixedPoint<INT_BITS,FRAC_BITS>(new_val));
        }
        template<typename datatype>
        const FixedPoint<INT_BITS, FRAC_BITS> operator/(datatype other) const {
            if(other == 0.0){
                printf("PROBLEM: divide by zero\n");
                return(FixedPoint<INT_BITS,FRAC_BITS>(raw_));
            }
            else{
                float new_val = raw_ / (float) other;
                return(FixedPoint<INT_BITS,FRAC_BITS>(new_val));
            }   
        }


        FixedPoint<INT_BITS,FRAC_BITS> operator+(){
            return (raw_ >= 0) ? FixedPoint<INT_BITS,FRAC_BITS>(raw_) : FixedPoint<INT_BITS,FRAC_BITS>(-raw_);
        }
        FixedPoint<INT_BITS,FRAC_BITS> operator-(){
            return (raw_ < 0) ? FixedPoint<INT_BITS,FRAC_BITS>(raw_) : FixedPoint<INT_BITS,FRAC_BITS>(-raw_);
        }

        const FixedPoint<INT_BITS,FRAC_BITS> operator+() const{
            return (raw_ >= 0) ? FixedPoint<INT_BITS,FRAC_BITS>(raw_) : FixedPoint<INT_BITS,FRAC_BITS>(-raw_);
        }
        const FixedPoint<INT_BITS,FRAC_BITS> operator-() const {
            return (raw_ < 0) ? FixedPoint<INT_BITS,FRAC_BITS>(raw_) : FixedPoint<INT_BITS,FRAC_BITS>(-raw_);
        }


        /* REFERENCE AND DEREFERENCE OPERATORS: */
        inline const FixedPoint* operator->() const {
            return(this);
        }
        inline const FixedPoint& operator*() const {
            return(*this);
        }
        inline FixedPoint* operator->() {
            return(this);
        }
        inline FixedPoint& operator*() {
            return(*this);
        }

        // Reciprocal operators: FixedPoint

        // overloaded prefix ++ operator
        inline FixedPoint& operator++(){
            //*this += 1;
            return((*this += 1));
        }
        // overloaded postfix ++ operator
        inline FixedPoint operator++(int){
            FixedPoint<INT_BITS, FRAC_BITS> temp = *this;
            ++*this;
            return(temp);
        }
        // overloaded prefix ++ operator
        inline FixedPoint& operator--(){
            //*this -= 1;
            return((*this -= 1));
        }
        // overloaded postfix ++ operator
        inline FixedPoint operator--(int){
            FixedPoint<INT_BITS, FRAC_BITS> temp = *this;
            --*this;
            return(temp);
        }



        /* Convert to othe primitive types */
        inline operator bool() const { return(raw_ != 0); }
        inline bool operator!() const { return(raw_ == 0); }
        inline operator bool()  { return(raw_ != 0); }
        inline bool operator!()  { return(raw_ == 0); }
        operator void*() const {
            return *this ? (void *)*this : nullptr;
        }

        inline operator char()      { return (char) int_part_; }
        inline operator char() const{ return (char) int_part_; }
        inline operator int()       { return int_part_; }
        inline operator int() const { return int_part_; }

        inline operator float()         { return (raw_); }
        inline operator float() const   { return (raw_); }
        inline operator double()        { return((double) raw_); }
        inline operator double() const  { return((double) raw_); }

        inline operator long double()   { return((long double) int_part_); }
        inline operator long double()  const { return((long double) int_part_); }
        inline operator unsigned __int128(){ return((unsigned __int128) raw_); }
        inline operator unsigned __int128() const { return((unsigned __int128) raw_); }

        inline operator int16_t()       { return((int16_t) int_part_); }
        inline operator int16_t() const { return((int16_t) int_part_); }
        inline operator int8_t()        { return((int8_t) int_part_); }
        inline operator int8_t() const  { return((int8_t) int_part_); }

        inline operator FixedPoint*()    { return(this); }
        inline operator const FixedPoint *()   { return((const FixedPoint<INT_BITS,FRAC_BITS>*) this); }

        inline FixedPoint<INT_BITS, FRAC_BITS> abs(){
            return(FixedPoint<INT_BITS,FRAC_BITS>(*this) *= sign_);
        }

        inline const FixedPoint<INT_BITS, FRAC_BITS> abs() const {
            return(FixedPoint<INT_BITS,FRAC_BITS>(raw_ * sign_));
        }


        inline int frac_bits() const { return FRAC_BITS; }
        inline int int_bits() const { return INT_BITS; }
        inline int size() const { return bit_size_; }
        inline float max_int() const { return max_int_; }
        inline float min_int() const { return min_int_; }
        inline float delta() const { return delta_; }

        inline int frac_bits() { return FRAC_BITS; }
        inline int int_bits() { return INT_BITS; }
        inline int size() { return bit_size_; }
        inline float max_int() { return max_int_; }
        inline float min_int() { return min_int_; }
        inline float delta() { return delta_; }

        /// Write to an output stream
        inline std::ostream& emit(std::ostream& os) const
        {
            return os << std::fixed << std::setprecision(FRAC_BITS) << raw_;
        }

        void Init();
        float RoundToFixedPoint(float x);
        int RoundInt(float y);
        float RoundFrac(float y);
        void check_sign();
        float RoundToPower2(float x);
        FixedPoint<INT_BITS, FRAC_BITS> nextafter() const;

        inline void SetPower2(bool value) { 
            round_power_2 = value;
            if(round_power_2){
                raw_ = RoundToPower2(raw_);
            }
            else{
                raw_ = RoundToFixedPoint(raw_);
            }
            return;
        }


    private:
        static const int frac_bits_ = FRAC_BITS;
        static const int int_bits_ = INT_BITS;
        static const int bit_size_ = INT_BITS + FRAC_BITS;

        int max_int_;
        int min_int_;
        float delta_;
        float max_num_;
        float min_num_;
        float max_frac_;

        bool round_power_2;
       
        int int_part_;
        float frac_part_;
        int sign_;
    protected:
};

template <int INT_BITS, int FRAC_BITS>
void FixedPoint<INT_BITS,FRAC_BITS>::Init() {
     // Calculate maximum integer for number of integer bits
    max_int_ = 1;
    for (int i = 0; i < INT_BITS-1; i++){
        max_int_ *= 2;
    }
    max_int_ -= 1;

    // Calculate minimum integer for number of integer bits
    min_int_ = -(max_int_ + 1);

    // Calculate minimum delta for number of fraction bits
    delta_ = 1;
    for (int i = 0; i < frac_bits_; i++){
        delta_ /= 2;
    }

    max_frac_ = 1- delta_;
    max_num_ = max_int_ + 1 - delta_;
    min_num_ = min_int_ - 1 + delta_;

    check_sign();

    round_power_2 = false;
}

float q_fmod(float x,float y) { 
    float a = x/y;
    return (a-(int)a)*y;
}

// Rounds input float to the Fixed Point Number specified by INT_BITS and FRAC_BITS
template <int INT_BITS, int FRAC_BITS>
float FixedPoint<INT_BITS, FRAC_BITS>::RoundToFixedPoint(float x) {
    sign_ = 1;
    if (x < 0){
        sign_ = -1;
    }      
           
    if(round_power_2){
        return(RoundToPower2(x));
    }

    if(x == 0.0){
        frac_part_ = 0;
        int_part_ = 0;
        return(0.0);
    }
    if(x < min_num_){
        frac_part_ = max_frac_;
        int_part_ = min_int_;
        return(min_num_);
    }
    if(x > max_num_){
        frac_part_ = max_frac_;
        int_part_ = max_int_;
        return(max_num_);
    }

    float int_part_float;
    // Extract int_Part and Frac_part from raw_
    frac_part_ = std::modf(x , &int_part_float);
    // eliminate the sign from the fraction part
    frac_part_ *= sign_;

    int_part_ = (int) RoundInt(int_part_float);
    frac_part_ = RoundFrac(frac_part_);
    return(int_part_+frac_part_*sign_);
}

// Helper for RoundToFixedPoint()
template <int INT_BITS, int FRAC_BITS>
int FixedPoint<INT_BITS, FRAC_BITS>::RoundInt(float y){
    if(y > max_int_){
        return max_int_;
    }
    if(y < min_int_){
        return min_int_;
    }
    return((int) y);
}
// Helper for RoundToFixedPoint()
template <int INT_BITS, int FRAC_BITS>
float FixedPoint<INT_BITS, FRAC_BITS>::RoundFrac(float y){
    if (y == 0.0){
        return 0.0;
    }

    float low = 0;
    float high = 0;
    float diff;

    if (y > 0){
        diff = fmod(y, delta_);
        low = y - diff;
        high = low + delta_;
    }
    else{ //(y < 0)
        diff = fmod(y, (-delta_));
        low = y + diff;
        high = low + delta_;
    }
    float highDiff = high - y;
    float lowDiff = y - low;
    if(highDiff < lowDiff){
        return(high);
    }
    else{
        return(low);
    }
}

template <int INT_BITS, int FRAC_BITS>
float FixedPoint<INT_BITS, FRAC_BITS>::RoundToPower2(float x){
    float low;
    float high;
    int i = 0;
    if (x == 0.0){
        frac_part_ = 0;
        int_part_ = 0;
        return 0.0;
    }
    if (x == 1.0){
        frac_part_ = 0;
        int_part_ = 1;
        return 1.0;
    }

    if(x <= 1 && x >= -1){
        // Round Fraction Part:
        low = 1;
        high = 1;
        float frac_x = std::abs(x) - std::abs((int) x);
        while(low > frac_x){
            if(i == FRAC_BITS){
                if(low > frac_x){
                    high = low;
                    low = 0;
                }
                break;
            }
            high = low;
            low /= 2;
            i++;
        }
        if(x < 0){
            low *= -1;
            high *= -1;
        }

        if((high - x) < (x - low)){
            frac_part_ = high;
            int_part_ = 0;
            return(high);
        }
        else{
            frac_part_ = low;
            int_part_ = 0;
            return(low);
        }
    }
    else{
        // Round integer part
        low = 1;
        high = 1;
        i = 1;
        float int_x = std::abs((int) x);
        while(high < int_x){
            if(i == INT_BITS){
                break; 
            }
            low = high;
            high *= 2;
            i++;
        }
        if(x < 0){
            low *= -1;
            high *= -1;
        }

        if((high - x) < (x - low)){
            int_part_ = high;
            frac_part_ = 0;
            return(high);
        }
        else{
            int_part_ = low;
            frac_part_ = 0;
            return(low);
        }
    }
}

template <int INT_BITS, int FRAC_BITS>
void FixedPoint<INT_BITS, FRAC_BITS>::check_sign() {
    sign_ = 1;
    if(raw_ < 0){ 
        sign_ = -1; 
    }
    return;
}

template <int INT_BITS, int FRAC_BITS>
FixedPoint<INT_BITS, FRAC_BITS> FixedPoint<INT_BITS, FRAC_BITS>::nextafter() const {
    float next = raw_ + delta_;
    return(FixedPoint<INT_BITS, FRAC_BITS>(next));
}

template <int INT_BITS, int FRAC_BITS>
std::ostream& operator<< (std::ostream& stream, const FixedPoint<INT_BITS, FRAC_BITS>& fixedPoint)
{
    return fixedPoint.emit(stream);
}

namespace fixedpoint{
    template <typename datatype>
    datatype max(datatype x, datatype y) {
        if(x >= y){
            return(x);
        }
        else{
            return(y);
        }
    }
    template <typename datatype>
    datatype min(datatype x, datatype y) {
        if(x < y){
            return(x);
        }
        else{
            return( y);
        }
    }

    template <typename datatype>
    datatype sqrt(datatype x) {
        return(datatype(std::sqrt((double) x)));
    }

    template <int INT_BITS, int FRAC_BITS>
    bool isnan(FixedPoint<INT_BITS, FRAC_BITS> x) {
        return(std::isnan(x.raw_));
    }
} // End fixedpoint namespace

template <int INT_BITS, int FRAC_BITS>
bool isnan(FixedPoint<INT_BITS, FRAC_BITS> x) {
    return(std::isnan(x.raw_));
}
template <int INT_BITS, int FRAC_BITS>
bool isinf(FixedPoint<INT_BITS, FRAC_BITS> x) {
    return(std::isinf(x.raw_));
}
template <typename datatype>
datatype abs(datatype x) {
    if (x < 0){
        return(datatype(x * -1));
    }
    else{
        return(x);
    }
}


template class FixedPoint<5,32>;
template class FixedPoint<4,32>;
template class FixedPoint<3,32>;
template class FixedPoint<2,32>;
template class FixedPoint<1,32>;
template class FixedPoint<0,32>;

template class FixedPoint<4,16>;
template class FixedPoint<4,15>;
template class FixedPoint<4,14>;
template class FixedPoint<4,13>;
template class FixedPoint<4,12>;
template class FixedPoint<4,11>;
template class FixedPoint<4,10>;
template class FixedPoint<4,9>;
template class FixedPoint<4,8>;
template class FixedPoint<4,7>;
template class FixedPoint<4,6>;

#endif /* end of include guard: FIXEDPOINT_H__ */


