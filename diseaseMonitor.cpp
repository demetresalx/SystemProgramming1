//MAIN ARXEIO. Apo edw trexei h efarmogh.
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h> //atoi
#include <cstring> //strcpy gia ta pathings. genika oxi idiaitera


int main(int argc, char *argv[]){

  //GIA TIS PARAMETROUS APO ARGC
  char dataset_path[256]; //to path tou patientRecordsFile poy tha parei apo to command line
  int diseaseHashtableNumOfEntries =0; //megethos disease hash table
  int countryHashtableNumOfEntries =0; //megethos countries hash table
  int bucketSize =0;
  for (int i = 0; i < argc; i++){
    if (strcmp("-p", argv[i]) == 0){
      strcpy(dataset_path, argv[i + 1]); //akoloythei to path
    }

    if (strcmp("-h1", argv[i]) == 0){
      diseaseHashtableNumOfEntries = atoi(argv[i + 1]); //akoloythei h timh
    }

    if (strcmp("-h2", argv[i]) == 0){
      countryHashtableNumOfEntries = atoi(argv[i + 1]); //akoloythei h timh
    }

    if (strcmp("-b", argv[i]) == 0){
      bucketSize = atoi(argv[i + 1]); //akoloythei h timh
    }

  } //telos for command line args
  std::cout << "params are: " << dataset_path << " " << diseaseHashtableNumOfEntries << " " << countryHashtableNumOfEntries << " " << bucketSize << "\n";

}
