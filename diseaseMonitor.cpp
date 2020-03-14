//MAIN ARXEIO. Apo edw trexei h efarmogh.
#include <iostream>
#include <string> //EPITREPETAI EIPWTHHKE STO PIAZZA
#include <fstream>
#include <stdlib.h> //atoi
#include <cstring> //strcpy gia ta pathings. genika oxi idiaitera
#include "record.h"
#include "record_HT.h"
#include "utils.h"
#include "cdHashTable.h"


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
  record_HT records_htable(diseaseHashtableNumOfEntries+countryHashtableNumOfEntries); //o DIKOS MOU HT gia tis eggrafes basei recordID megethous h1+h2. KALUTEROS APO APLH LISTA
  diseaseHashTable diseases_htable(diseaseHashtableNumOfEntries, bucketSize); //O ZHTOUMENOS HT GIA DISEASE
  countryHashTable countries_htable(countryHashtableNumOfEntries, bucketSize); //O ZHTOUMENOS HT GIA COUNTRY
  //std::cout << "params are: " << dataset_path << " " << diseaseHashtableNumOfEntries << " " << countryHashtableNumOfEntries << " " << bucketSize << "\n";
  std::ifstream infile(dataset_path); //diabasma apo tis grammes tou arxeiou
  std::string line; //EPITREPETAI H STRING EIPAN STO PIAZZA
  while (std::getline(infile, line)){ //read file
    //https://stackoverflow.com/questions/49201654/splitting-a-string-with-multiple-delimiters-in-c
    std::string const delims{ " \t," }; //delimiters einai ta: space,tab,comma. TELOS.
    size_t beg, pos = 0;
    int params_count =0;
    std::string record_parts[7]; //mia thesi gia kathe melos tou record wste na ta valw eukola se object meta
    while ((beg = line.find_first_not_of(delims, pos)) != std::string::npos){
        pos = line.find_first_of(delims, beg + 1);
        record_parts[params_count] = line.substr(beg, pos - beg);
        params_count++;
    }//telos while eksagwghs gnwrismatwn apo grammh
    if(params_count != 7) //problhmatiko input, prepei na akoloythei motivo ekfwnhshs. Tha faei skip auth h eggrafh
      continue;
    if(dates_compare(record_parts[5], record_parts[6]) != "smaller") //ean h entrydate einai megaluterh h ish ths exitdate
      continue;
    record * new_rec_ptr = new record(record_parts); //dhmiourgia eggrafhs
    if(records_htable.insert_record(new_rec_ptr) <0){ //brethhke diplotyph eggrafh. termatismos!
      std::cout << "brethhke diplotyph eggrafh. termatismos!\n";
      exit(EXIT_FAILURE);
    }
    diseases_htable.insert_record(new_rec_ptr); //eisagwgh ston dis HT
    countries_htable.insert_record(new_rec_ptr); //eisagwgh ston countries HT
    //std::cout << "\n";
  }//telos while read file
  //records_htable.print_contents();
  //diseases_htable.print_contents();
  //countries_htable.print_contents();
  return 0;
}
