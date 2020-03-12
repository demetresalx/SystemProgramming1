#include "record.h"


record::record(std::string *params) //constructor basei twn gnwrismatwn poy ekshxthhsan apo grammh input
{
  std::cout << "i am construcotrrrrr";
  recordID = params[0];
  patientFirstName = params[1];
  patientLastName = params[2];
  diseaseID = params[3];
  country = params[4];
  entryDate = params[5];
  exitDate = params[6];
}
