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
    T* compare(T* a, T* b) //5
    {
        if( a || b == nullptr ) 
            return nullptr;
        
        if( a->value < b->value ) return a;
        if( a->value > b->value ) return b;
        return nullptr;
    }
};

struct U
{
    float targetValue { 0.0f }, uValue { 0.0f };
    float uSquare(float* targetValueIn)      //12
    {
        if( targetValueIn == nullptr) 
            return 0;
      
        targetValue = *targetValueIn;
        while( std::abs(uValue - targetValue) > 0.001f )
        {
            uValue += -0.5f * (uValue - targetValue);
        }
        return uValue * uValue;
    }
};

struct W
{
    static float wSquare( U* that, float* targetValue )        //10
    {
        if(that  == nullptr) 
            return 0;
        if(targetValue == nullptr) 
            return 0;
        
        std::cout << "U's targetValue value: " << that->targetValue << std::endl;
        that->targetValue = *targetValue;
        std::cout << "U's targetValue updated value: " << that->targetValue << std::endl;
        while( std::abs( that->uValue - that->targetValue ) > 0.001f )
        {
            that->uValue += -0.5f * ( that->uValue - that->targetValue );
        }
        std::cout << "U's uValue updated value: " << that->uValue << std::endl;
        return that->uValue * that->uValue;
    }
};
        
/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH

 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.

 send me a DM to review your pull request when the project is ready for review.

 Wait for my code review.
 */

int main()
{
    T value1( 4, "four" );                                             //6
    T value2( 5, "five" );                                             //6
    
    T2 f;                                            //7
    auto* smaller = f.compare( &value1 , &value2 );
    if( smaller != nullptr )
    {//8
        std::cout << "the smaller one is << " << smaller << std::endl;
    }
    //9
    
    U u1;
    float updatedValue = 5.f;
    std::cout << "[static func] u1's multiplied values: " << W::wSquare( &u1, &updatedValue ) << std::endl;                  //11
    
    U u2;
    std::cout << "[member func] u2's multiplied values: " << u2.uSquare( &updatedValue ) << std::endl;
}
