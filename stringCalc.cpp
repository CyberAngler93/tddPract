#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <string>

int stringCalc( const std::string & userInput);


TEST_CASE("Testing empty string"){
    CHECK(stringCalc("") == 0);
}

TEST_CASE("Testing empty single number"){
    CHECK(stringCalc("1") == 1);
    CHECK(stringCalc("13") == 13);
    CHECK(stringCalc("10") == 10);
    CHECK(stringCalc("3000") == 3000);
}

TEST_CASE("Testing Two numbers seperated by a ,"){
    CHECK(stringCalc("1,1") == 2);
    CHECK(stringCalc("3,1") == 4);
    CHECK(stringCalc("1,3") == 4);
    CHECK(stringCalc("0,0") == 0);
    CHECK(stringCalc("2,3") == 5);
    CHECK(stringCalc("444,444") == 888);
}

TEST_CASE("Testing Two numbers sepereated by \\n"){
    CHECK(stringCalc("2\n2") == 4);
    CHECK(stringCalc("5\n5") == 10);
    CHECK(stringCalc("100\n2") == 102);
    CHECK(stringCalc("2\n6") == 8);
}

TEST_CASE("Testing three numbers sepereated by \\n or ,"){
    CHECK(stringCalc("2\n2,4") == 8);
    CHECK(stringCalc("5\n5\n5") == 15);
    CHECK(stringCalc("100\n2,100") == 202);
    CHECK(stringCalc("2,6,100") == 108);
    CHECK(stringCalc("2,2\n2") == 6);
}

TEST_CASE("Testing negative numbers"){

}



int stringCalc( const std::string & userInput){
    if(userInput == ""){
        return 0;
    }
    auto found = userInput.find_first_of(",\n");
    if(found != std::string::npos){
        std::string first,second,third = "";
        int delimcount = 0;
        for(auto i = 0; i < userInput.size(); i++){
            if(userInput[i] == ',' || userInput[i] == '\n'){
                delimcount++;
            }
            else if(delimcount< 1){
                first = first + userInput[i];
            }
            else if(delimcount == 1){
                second = second + userInput[i];
            }
            else if(delimcount == 2){
                third = third + userInput[i];
            }
        }
        if(delimcount >= 2){
            int total = std::stoi(first) + std::stoi(second) + std::stoi(third);
            return total;
        }
        if(delimcount == 1){
            int total = std::stoi(first) + std::stoi(second);
            return total;
        }
    }
    int count = std::stoi(userInput);
    return count;  
}