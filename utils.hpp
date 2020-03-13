#include <string>
#include <sstream>
#include <iostream>
#include <cstring>

//h sunarthsh epistrefei to katallhlo apotelesma gia to an to date1 einai megalutero, iso h mikrotero tou date2
std::string dates_compare(std::string date1, std::string date2){

  int params_count =0;
  std::string intermediate;
  std::stringstream check1(date1);
  int date1_parts[3]; //mia thesh gia mera, mia gia mhna mia gia xronia.
  while(getline(check1, intermediate, '-')) {
        date1_parts[params_count] = stoi(intermediate);
        params_count++;
  } //telos while eksagwghs gnwrismatwn apo date1
  //date2
  int params_count2 =0;
  std::stringstream check2(date2);
  int date2_parts[3]; //mia thesh gia mera, mia gia mhna mia gia xronia.
  while(getline(check2, intermediate, '-')) {
        date2_parts[params_count2] = stoi(intermediate);
        params_count2++;
  }//telos while eksagwghs gnwrismatwn apo date2

  if(params_count2 != params_count)//problhmatiko input. de tha eprepe na dothei etsi sumfwna me ekfwnhsh
    std::cout << "kakws orismena dates. shouldn't happen kata ekfwnhsh";

  if(date1_parts[2] > date2_parts[2]) //megaluterh xronia
    return "bigger";
  if(date1_parts[2] == date2_parts[2]){ //ish xronia
    if(date1_parts[1] > date2_parts[1]) //megaluteros mhnas me ish xronia
      return "bigger";
    if(date1_parts[1] == date2_parts[1]){ //isos mhnas me ish xronia
      if(date1_parts[0] > date2_parts[0]) //megaluterh mera me iso mhna kai xronia
        return "bigger";
      if(date1_parts[0] == date2_parts[0]) //ola isa
        return "equal";
      if(date1_parts[0] < date2_parts[0]) //ish xronia isos mhnas mikroterh mera
        return "smaller";
    }
    if(date1_parts[1] < date2_parts[1]) //mikroteros mhnas me ish xronia
      return "smaller";
  }
  if(date1_parts[2] < date2_parts[2]) //mikroterh xronia
    return "smaller";
}

//https://stackoverflow.com/questions/8317508/hash-function-for-a-string - hash function gia strings
//prosarmosmenh sta dika moy dedomena
#define APRIME 54059 /* a prime */
#define BPRIME 76963 /* another prime */
#define CPRIME 86969 /* yet another prime */
#define FIRSTH 37 /* also prime */
unsigned hash_str(std::string str)
{
   int n = str.length();
   char char_array[n + 1];
   strcpy(char_array, str.c_str());
   char * s = char_array;
   unsigned h = FIRSTH;
   while (*s) {
     h = (h * APRIME) ^ (s[0] * BPRIME);
     s++;
   }
   return h; // or return h % CPRIME;
}
