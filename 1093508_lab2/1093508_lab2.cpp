#include <iostream>
#include <iomanip>
using namespace std;
class Time
{
public:
    Time(); // constructor, the name must be the same as class name
    void setTime( int, int, int ); // set hour, minute and second
    void printUniversal(); // print time in universal-time format
    void printStandard(); // print time in standard-time format
    void setT1toT2(Time);
    void compareTime(Time);
private:
    int hour; // 0 - 23 (24-hour clock format)
    int minute; // 0 - 59
    int second; // 0 - 59
}; // end class Time

Time::Time(/* args */)
{
    hour = minute = second = 0;
}
void Time::setTime( int h, int m, int s )
{
    hour = ( h >= 0 && h < 24 ) ? h : 0; // validate hour
    minute = ( m >= 0 && m < 60 ) ? m : 0; // validate minute
    second = ( s >= 0 && s < 60 ) ? s : 0; // validate second
} // end function setTime

// print Time in universal-time format (HH:MM:SS)
void Time::printUniversal() 
{
    cout << "Universal Time: ";
    cout << setfill( '0' ) << setw( 2 ) << hour << ":" << setw( 2 ) << minute << ":" << setw( 2 ) << second << '\n';
} // end function printUniversal
// print Time in standard-time format (HH:MM:SS AM or PM)
void Time::printStandard()
{
    cout << "Standard Time : ";
    cout << ( ( hour == 0 || hour == 12 ) ? 12 : hour % 12 ) << ":" << setfill( '0' ) << setw( 2 ) << minute << ":" << setw( 2 ) << second << ( hour < 12 ? " AM" : " PM" ) <<'\n';
} // end function printStandard
void Time::setT1toT2(Time t2)
{
    hour = t2.hour;
    minute = t2.minute;
    second = t2.second;
}
void Time::compareTime(Time t2)
{
    if(hour == t2.hour)
    {
        if(minute == t2.minute)
        {
            if(second == t2.second)
            {
                cout << "Same\n";
            }
            else if(second > t2.second)
            {
                cout << "Early\n";
            }
            else
            {
                cout << "Later\n";
            }
        }
        else if(minute > t2.minute)
        {
            cout << "Early\n";
        }
        else
        {
            cout << "Later\n";
        }
    }
    else if(hour > t2.hour)
    {
        cout <<"Early\n";
    }
    else
    {
        cout << "Later\n";
    }
}
int main()
{
    
    Time t; // instantiate object t of class Time

    Time &tRef = t;//######
    Time *tPtr; //######
    tPtr = &t; //#####
    Time t1,t2; //######
    
    // output Time object t's initial values
    t.printUniversal(); // 00:00:00
    t.printStandard(); // 12:00:00 AM

    t.setTime(18, 20 ,0); //#########

    // output Time object t's new values using object name as a handle
    t.printUniversal();
    t.printStandard();
    // output Time object t's new values using object reference as a handle
    tRef.printUniversal();
    tRef.printStandard();
    // output Time object t's new values using object pointer as a handle
    tPtr->printUniversal();
    tPtr->printStandard();
    t1.setTime( 13, 27, 6 ); // set a new time
    // output Time object t1's new values
    t1.printUniversal(); // 13:27:06
    t1.printStandard(); // 1:27:06 PM
    t2.setTime( 9, 9, 9);//************
    // output t2's values after specifying invalid values
    t2.printUniversal();//***********
    t2.printStandard();//************
    Time t3;
    t3.setT1toT2(t2);
    t3.compareTime(t2);
    t2.compareTime(t1);
    t1.compareTime(t);
    t.compareTime(t1);
} // end main