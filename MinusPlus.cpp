#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'plusMinus' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void plusMinus(vector<int> arr) {
    //  calculate len arr
    // iterate over arr numbers and count positive, negative, zero
    // divide the positive count by len arr
    // divide the negative count by len arr
    // divide the count zero by len arr
    int length_arr = arr.size();
    int positiveCount = 0;
    int negativeCount = 0;
    int zeroCount = 0;
    
    for (int value : arr){
        if(value > 0){
            ++positiveCount;
        }
        else if(value < 0){
            ++negativeCount;
        }
        else{
            ++zeroCount;
        }
    }
    
    double positiveRatio = 0;
    double negativeRatio = 0;
    double zeroRatio = 0;
    
    if(positiveCount > 0){
        positiveRatio = static_cast<double>(positiveCount)/length_arr;
    }
    if(negativeCount > 0){
        negativeRatio = static_cast<double>(negativeCount)/length_arr;
    }
    if(zeroCount > 0){
        zeroRatio = static_cast<double>(zeroCount)/length_arr;
    }
    cout << std::fixed << std::setprecision(6) << positiveRatio << endl;
    cout << std::fixed << std::setprecision(6) << negativeRatio << endl;
    cout << std::fixed << std::setprecision(6) << zeroRatio << endl;
    

}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    plusMinus(arr);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
