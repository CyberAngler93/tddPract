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
    CHECK(stringCalc("-1") == -1);
    CHECK(stringCalc("3000") == 3000);
}

TEST_CASE("Testing empty single number"){
    CHECK(stringCalc("1,1") == 2);

}

int stringCalc( const std::string & userInput){
    if(userInput == ""){
        return 0;
    }
    auto found = userInput.find(',');
    if(found == std::string::npos){
        std::string pre,post = "";
        int commacount = 0;
        for(auto i = 0; i < userInput.size(); i++){
            if(userInput[i] == ','){
                commacount++;
            }
            else if(commacount< 1){
                pre = pre + userInput[i];
            }
            else if(commacount == 1){
                post = post + userInput[i];
            }
        }
        int total = std::stoi(pre) + std::stoi(post);
        return total;
    }
    int count = std::stoi(userInput);
    return count;  
}