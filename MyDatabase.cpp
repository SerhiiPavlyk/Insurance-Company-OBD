#include "MyDatabase.h"

SqlConnection MyDatabase::load()
{
	SqlConnection sqlCon(conecctionString);
	sqlCon.Open();
	return 0;
}
