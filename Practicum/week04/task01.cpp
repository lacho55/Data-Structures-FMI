#include<iostream>
#include<string>
#include<stack>

bool isTrue(const std::string& brackets){

    std::stack<char> stack;
    size_t length = brackets.length();

    for(size_t i = 0; i < length; ++i){

        if(brackets[i] == '(' || brackets[i] == '{' || brackets[i] == '['){
            stack.push(brackets[i]);
            continue;
        }

        if(brackets[i] == ')' || brackets[i] == ']' || brackets[i] == '['){

            if(stack.empty()){
                return false;
            }

            char temp = stack.top();

            if(temp == '(' && brackets[i] == ')'){
                stack.pop();
            }
            else if(temp == '{' && brackets[i] == '}'){
                stack.pop();
            }
            else if(temp == '[' && brackets[i] == ']'){
                stack.pop();
            }
            else{
                return false;
            }
        }
    }

    return !stack.empty();
}

int main(){
    std::string arr1= "{[(()[])]}}";
    std::string arr2 = "(()()))";

    std::cout << isTrue(arr1) << std::endl;
    std::cout << isTrue(arr2) << std::endl;


    return 0;
}