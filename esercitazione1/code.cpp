#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, const char *argv[]) {
    
    string nome_file = argv[1];
    ifstream file(nome_file);
    if (file.is_open())
    {
        while(!file.eof())
        {
            string città;
            double temp1, temp2, temp3, temp4;
            file >> città >> temp1 >> temp2 >> temp3 >> temp4;
            if (città == "") //cioè se il file è finito
            {
                break;
            }
            double media = (temp1+temp2+temp3+temp4)/4;
            cout << città << " "<< media << "\n";
        }
    }
    
    else {
        if (argc<2)
        {cerr<<"Non è stato inserito il nome del file\n";
            return 1;
        }
        else{
        cerr << "errore nell'apertura file\n";
        return 1;
        }
    }

    return 0;

}