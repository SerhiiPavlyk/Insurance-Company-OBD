#pragma once
using namespace System;
#define connectionString "Data Source=SQL8003.site4now.net;Initial Catalog=db_a87207_support;User Id=db_a87207_support_admin;Password=Df123456"
//#define connectionString "Data Source = DESKTOP - 54FNADR\SQL_OBD; Initial Catalog = SUPPORT; Persist Security Info = True; User ID = Serhii; Password = 16092003; Pooling = False"
#using <system.dll>
#include<iostream>
using namespace System::Text::RegularExpressions;
ref class User
{
public: 
	int id;
	String^ name;
};

