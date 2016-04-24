/*
GPS Checksum function and testing
Author(s): Skye Mceowen
*/

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

//global variable so you can print its value outside of the checksum fxn
int tmpChecksum;

//Function comparing GPS checksum with your checksum
bool checksum(char* gpsData, int gpsChecksum){
   //int length = 82; //double check
   tmpChecksum = 0; //double check
   int i = 1;
   //for(int i=0; i<length; i++){
   while(gpsData[i] != '*'){
      tmpChecksum ^= gpsData[i];
      i++;}
   
   if(tmpChecksum == gpsChecksum){return true;}
   else{return false;}
}

/*MAIN
Takes a gps packet and valid gps checksum to compare
NOTE: MUST put "\" in front of gps packet so format is "\$"[bunch of shit]"*"[2 char checksum in DECIMAL]
*/
int main( int argc, char *argv[] ){
   argc = 2;
   
   char* packet = argv[1]; //gps checksum
   int gpsChecksum = (atoi)(argv[2]);
   
   bool compatible;

   compatible = checksum(packet, gpsChecksum);

   cout << "Checksum compatibility was " << compatible << endl;
   cout << "GPS checksum: " << gpsChecksum << endl;
   cout << "Your checksum: " << tmpChecksum << endl;
   
   return 0;
}
