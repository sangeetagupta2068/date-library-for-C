/*
   *@description: It contains all the declarations for the date library including the user defined type date and boolean and
  the function prototypes for the date functions defined in Date.c.
   *@author: Sangeeta Gupta
   *@version:1.1
   *@date:9th January 2018
   */
#ifndef DATE_H

            #define DATE_H 1

            typedef enum
            {

                false=0,true=1

            }
            boolean;

            typedef struct{

                char day;
                char month;
                short year;
                boolean isvalid;

              }
              DATE;

              boolean set_date(char day_value,char month_value,short year_value,DATE *dt_ptr);

              boolean isleap(DATE date);

              boolean validate(DATE *dt_ptr);

              int year(DATE *dt_ptr);

              int month(DATE *dt_ptr);

              int day(DATE *dt_ptr);

              char* cmonth(DATE *dt_ptr);

#endif
