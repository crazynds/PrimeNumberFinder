#ifndef BIGINT_H
    #define BIGINT_H

    #include <stdlib.h>

    #define BASE_TYPE unsigned long long

    class BigInt{
        unsigned long size;
        BASE_TYPE *integers;

        void increaseSize(unsigned long newSize){
            this->size=newSize;
            this->integers = (BASE_TYPE *)realloc(this->integers,sizeof(BASE_TYPE)*newSize);
        }

    public:

        BigInt(BASE_TYPE inicial){
            this->integers = (BASE_TYPE *) malloc(sizeof(BASE_TYPE));
            this->size = 1;
            this->integers[0] = inicial;
        }

        ~BigInt(){
            free(this->integers);
        }


        //Direct assignment
        BigInt &operator=(const BigInt &);
    
    
        //Addition and Subtraction
        BigInt &operator+=(const BigInt &);
        BigInt operator+(const BigInt &);
        BigInt operator-(const BigInt &);
        BigInt &operator-=(const BigInt &);
    
        //Comparison operators
        bool operator==(const BigInt &);
        bool operator!=(const BigInt &);
    
        bool operator>(const BigInt &);
        bool operator>=(const BigInt &);
        bool operator<(const BigInt &);
        bool operator<=(const BigInt &);
    
        //Multiplication and Division
        BigInt &operator*=(const BigInt &);
        BigInt operator*(const BigInt &);
        BigInt &operator/=(const BigInt &);
        BigInt operator/(const BigInt &);
    
        //Modulo
        BigInt operator%(const BigInt &);
        BigInt &operator%=(const BigInt &);
    
        //Power Function
        BigInt &operator^=(const BigInt &);
        BigInt operator^(const BigInt &);
        
        //Square Root Function
        BigInt sqrt(BigInt &a);


    };
#endif