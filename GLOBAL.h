#include<map>
#include "csmtp.h"
using namespace std;

static int COLUM_COUNT=0;
static unsigned int SECURE_NUMBER=0;
static unsigned int LIMITE_DATE=20;
static unsigned int DATE;

static map<const char*,const char*> ERROR_LOGS;
static int   ERROR_COUNT=0;

static map<const char*,const char*> USER;
static map<const char*,int> ALGORITM;     

static map<const char*,int> SECURE;

static const char* PASSWORD;

// Constant   //
static map<const char*,const char*> tips = {
    {"check_email","Խնդրում ենք ստւգել ձեր էլ․ հասցեն"},
    {"reset_password","Նոր գաղտնաբառը ուղարկված է ձեր էլ․ հասցեին"}
    };