#include <bits/stdc++.h>
#include <iostream>
#include <string>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s){
 // 12:01:00PM input
 // 12:01:00 output
    string hour_12rtime = s.substr(0, 2);
    string minutes_seconds = s.substr(2, 6);
    string pm_am_str = s.substr(8, 2);
    int hour = stoi(hour_12rtime);
    if( hour == 12 && pm_am_str == "AM"){
        hour_12rtime = "00";
        cout << "in the 12AM condition!" << endl;
    }
    else if(hour != 12 && pm_am_str == "PM"){
        hour += 12;
        hour_12rtime = to_string(hour);
    }
    
    return hour_12rtime + minutes_seconds;
 
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
