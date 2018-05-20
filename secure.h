#include"GLOBAL.h"
#include <cmath>
#include<ctime>
#include <string>
#include <regex>
#include <string.h>

bool is_email_valid(const char* email)
{
    // define a regular expression
    const std::regex pattern
        ("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");

    // try to match the string with the regular expression
    return std::regex_match(email, pattern);
}

bool is_password_valid(const char*& pass)
{
    int size_=sizeof(pass)/sizeof(char);
    if(size_ >= 8)
    {
        return true;
    }
    return false;
}

void number_generator()
{
    srand(time(NULL));
    int a=(rand()%899999)+100000;
    if(a<100000 || a>999999)
    {
        ERROR_LOGS.insert( pair<const char*,const char* >("secure_number","Համակարգի սխալ կապված թվի գեներացման հետ"));
        ERROR_COUNT++;
    }
    SECURE.insert( pair<const char*,int>("number",a));
}
void get_minut()
{
    time_t theTime=time(NULL);
    struct tm *aTime=localtime(&theTime);
    SECURE.insert( pair<const char*,int>("time",(int)aTime->tm_min));
}

void password_generator()
{
    PASSWORD="";
     const char* str="0123456789!@#$%^&*ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
     const int str_length=strlen(str);
     char temp[50];
     int i=0;
     srand(time(NULL));
     while(1)
     {
        
         if(strlen(temp)>=8 && i>=8)
         {
            const char* pass=(const char*)temp;
            PASSWORD=pass;
            break;
         }
         else
         {
             
             temp[i]=str[rand()%(str_length-i)];
             i++;
         }

     }
}



