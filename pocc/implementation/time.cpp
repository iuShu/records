#include <iostream>
#include <ctime>

using namespace std;

int main() {

    time_t now = time(0);
    char* date_time = ctime(&now);
    cout<< "local time is: " << date_time <<endl;

    tm *gmt_tm = gmtime(&now);
    date_time = asctime(gmt_tm);
    cout<< "UTC time is: " << date_time <<endl;

    tm *local_time = localtime(&now);
    cout<< "year: " << 1900 + local_time->tm_year <<endl;   // rectify
    cout<< "month: " << 1 + local_time->tm_mon <<endl;      // rectify
    cout<< "date: " << local_time->tm_mday <<endl;
    cout<< "hour: " << local_time->tm_hour <<endl;
    cout<< "min: " << local_time->tm_min <<endl;
    cout<< "sec: " << local_time->tm_sec <<endl;
    cout<< "year day: " << local_time->tm_yday <<endl;
    cout<< "week day: " << local_time->tm_wday <<endl;

    return 1;
}