#ifndef _RECORD_H_
#define _RECORD_H_

#include <iostream>
#include <string> //EPITREPETAI EIPWTHHKE STO PIAZZA

class record{

  private: //dedomena ekfwnhshs
    std::string recordID;
    std::string patientFirstName;
    std::string patientLastName;
    std::string diseaseID;
    std::string country;
    std::string entryDate;
    std::string exitDate;

  public:
    record(){}; //enas empty contrusctor
    record(std::string *);                            // o conustructor basei pinaka strings
    //setters & getters!!!
    ~record(); //destructor

};


#endif
