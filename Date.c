#include "Date.h"


char month_days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

char month_names[13][30]={"","January","February","March","April","May","June","July","August","September","October","November","December"};


boolean set_date(char day_value,char month_value,short year_value,DATE *dt_ptr)
{
  /*@description: the function accepts three numbers as components of a date and a date object reference,
   updates the corresponding members of the given date reference from the arguments supplied and
   also sets appreciate value in isvalid flag.The function returns true if the date is a valid date otherwise false
   *@version: 1.2
   *@author: Sangeeta Gupta
   *@date: 9th January 2018
   */
      dt_ptr->day=day_value;
      dt_ptr->month=month_value;
      dt_ptr->year=year_value;

      return (validate(dt_ptr)?true:false);


}

boolean validate(DATE* dt_ptr)
{
 /*@description: to check if a date is valid or not.
  *@version: 1.2
  *@author: Sangeeta Gupta
  *@date: 9th January 2018
  */
          char dd = dt_ptr->day;
          char mm = dt_ptr->month;
          int  yr = dt_ptr->year;

          dt_ptr->isvalid = false;


          if (dd < 1 || mm < 1 || mm > 12 || yr < 1)
                return false;

          if (mm != 2 && dd > month_days[mm])
                return false;

          if (mm == 2 && dd > month_days[mm] + isleap(*dt_ptr))
                return false;


          dt_ptr->isvalid = true;
          return true;

}

boolean isleap(DATE date)
{
  /*@description: to check if a date is leap or not.
   *@version: 1.2
   *@author: Sangeeta Gupta
   *@date: 9th January 2018
   */
          int yr = date.year;
          return ( yr%100  && !(yr % 4) || !(yr % 400) ? true:false);

}

int year(DATE date)
{
  /*@description: If a date is valid, it returns the year component,otherwise, returns 0.
  *@version: 1.2
  *@author: Sangeeta Gupta
  *@date: 9th January 2018
  */
          return (date.isvalid?date.year:false);
}

int month(DATE date)
{
  /*@description: If a date is valid, it returns the month component,otherwise, returns 0.
  *@version: 1.2
  *@author: Sangeeta Gupta
  *@date: 9th January 2018
  */
          return (date.isvalid?date.month:false);
}

int day(DATE date)
{
  /*@description: If a date is valid, it returns the day component,otherwise, returns 0.
  *@version: 1.2
  *@author: Sangeeta Gupta
  *@date:9th January 2018
  */
          return (date.isvalid?date.day:false);

}

char* cmonth(DATE date)
{
  /*@description: If a date is valid, it returns the month name,otherwise, returns null.
  *@version: 1.2
  *@author: Sangeeta Gupta
  *@date: 9th January 2018
  */
      return (date.isvalid==true?month_names[date.month]:month_names[0]);
}
