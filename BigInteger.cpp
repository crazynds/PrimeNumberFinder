#include "BigInteger.h"
#include <string.h>
#include "immintrin.h"


//Direct assignment
BigInt &BigInt::operator=(const BigInt &bg){
    if(this->size!=bg.size){
        this->size = bg.size;
        free(this->integers);
        this->integers = (BASE_TYPE*) malloc(sizeof(BASE_TYPE)*this->size);
    }
    memcpy(this->integers,bg.integers,sizeof(BASE_TYPE)*this->size);
    return *this;
}


//Addition and Subtraction
BigInt &BigInt::operator+=(const BigInt &bg){
    int x=bg.size;
    if(this->size < bg.size){
        increaseSize(bg.size);
    }
    //sumVectorU64(this->integers,bg.integers,bg.size);
    while(x>4){
        __m256i v1=_mm256_loadu_epi64(&this->integers[x]);
        __m256i v2=_mm256_loadu_epi64(&bg.integers[x]);
        v1 = _mm256_add_epi64(v1,v2);
        _mm256_storeu_epi64(&this->integers[x],v1);
        x-=4;
    }
    for(;x>=0;x++){
        
    }



    return *this;
}
BigInt BigInt::operator+(const BigInt &bg){
    
    return *this;
}
BigInt BigInt::operator-(const BigInt &bg){

    return *this;
}
BigInt &BigInt::operator-=(const BigInt &bg){

    return *this;
}