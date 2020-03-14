#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

// Function converting from base 10 to base 3
vector<int> Convert10To3(int N) {
    vector<int> converted_number;
    while (N / 3 > 0) {
        converted_number.insert(converted_number.begin(),N % 3);
        N = N / 3;
    }
    converted_number.insert(converted_number.begin(),N % 3);
    while (converted_number.size() < 9) {
        converted_number.insert(converted_number.begin(),0);
    }
    return converted_number;
}

// Function that calculates the string
int CalculateString(string str) {
    int opers = count(str.begin(),str.end(),'+') + count(str.begin(),str.end(),'-'); //number of operations
    //cout << "Num opers: " << opers << endl;
    stringstream ss(str);
    int num1;
    ss >> num1; //Getting first number
    int result = num1;
    for (int i = 1; i <= opers; i++) {
        int num2;
        char operation;
        ss >> operation;
        ss >> num2;
        if (operation == '+') {
            result += num2;
        }
        else if (operation == '-') {
            result -= num2;
        }
    }
    //cout << "Result: " << result << endl;
    return result;
}

int main()
{
    int nums[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; //list of all digits by the given order
    string expr = "";
    for (int i = 0; i <= pow(3,9); i++) { //there are 3^9 possibilities
        expr = to_string(nums[0]); //first digit
        vector<int> operations = Convert10To3(i); //in this vector int equals 0 for +, 1 for -, 2 for void (combining);
        for (int num_oper = 0; num_oper < 9; num_oper++) {
            if (operations[num_oper] == 0) { // 9 8 -> 9+8
                expr += "+" + to_string(nums[num_oper+1]);
            }
            if (operations[num_oper] == 1) { // 9 8 -> 9-8
                expr += "-" + to_string(nums[num_oper+1]);
            }
            if (operations[num_oper] == 2) { // 9 8 -> 98
                expr += to_string(nums[num_oper+1]);
            }
        }
        if (CalculateString(expr) == 200) { //if expression gives us 200 -> print it
            cout << expr << "=200" << endl;
            //break;
        }
        expr.clear();
    }
    return 0;
}
