/*
 Project 6: Part 2 / 2
 Video: Chapter 3 Part 3

Create a branch named Part2

 References
 
 
 1) convert all of the pointer usage (except for 'const char*') to reference types or 
    const reference types **>>> WHERE POSSIBLE <<<**
        hint: There is no reference equivalent to nullptr.  
        if a pointer (including nullptr) is being returned anywhere, don't try to convert it to a reference.
 
 2) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 */

#include <cmath>
#include <iostream>
#include <string>
struct T
{
    T(float v, const char* name_) : value(v), name(name_) {}  //1
    float value;
    std::string name;
};

struct T2                                //4
{
    const T* compare(const T& a, const T& b) //5
    {
        if( a.value < b.value ) return &a;
        if( a.value > b.value ) return &b;
        return nullptr;      
    }
};

struct U
{
    float targetValue { 0.0f }, uValue { 0.0f };
    float uSquare(const float& targetValueIn)      //12
    {
        targetValue = targetValueIn;
        while( std::abs(uValue - targetValue) > 0.001f )
        {
            uValue += -0.5f * (uValue - targetValue);
        }
        return uValue * uValue;
    }
};

struct W
{
    static float wSquare( U& that, const float& targetValue )        //10
    {

        std::cout << "U's targetValue value: " << that.targetValue << std::endl;
        that.targetValue = targetValue;
        std::cout << "U's targetValue updated value: " << that.targetValue << std::endl;
        while( std::abs( that.uValue - that.targetValue ) > 0.001f )
        {
            that.uValue += -0.5f * ( that.uValue - that.targetValue );
        }
        std::cout << "U's uValue updated value: " << that.uValue << std::endl;
        return that.uValue * that.uValue;
    }
};
        

int main()
{
    T value1( 4, "four" );                                             //6
    T value2( 5, "five" );                                             //6
    
    T2 f;                                            //7
    const auto* smaller = f.compare( value1 , value2 );
    if( smaller != nullptr )
    {//8
        std::cout << "the smaller one is << " << smaller->name << std::endl;
    }
    //9
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << W::wSquare( u1, updatedValue ) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.uSquare( updatedValue ) << std::endl;
}
