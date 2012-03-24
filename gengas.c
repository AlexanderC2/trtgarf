#include <iostream>
#include "MediumMagboltz.hh"
#include <TROOT.h>

using namespace Garfield;
using namespace std;

int main(int argc, char * argv[]){
    cout<<"Create Gas File "<<argv[1]<<endl;
    MediumMagboltz * gas=new MediumMagboltz();
    gas->SetTemperature(293.15);
    gas->SetPressure(760.0);
    gas->SetComposition("xe",70.,"co2",27.,"o2",3.);
    gas->GenerateGasTable(100);
    gas->WriteGasFile(argv[1]);
    return 0;
}
