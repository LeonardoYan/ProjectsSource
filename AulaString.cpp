// aula-04022020.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.
//
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <ctype.h>
#include <locale>

using namespace std;

class String { // Classe String com os metodos e atributos criados nela.
private:
    char varChar;
    const char* varString;
    //String* varString1;
public:
    int sizeChar();
    int sizeChar(char* var);
    int indiceChar(char var);
    void lengthChar(const char* var);
    char* upperChar(int a, int b);
    char* lowerChar(int a, int b);
    char* toggleChar(int a, int b);
    String();
    String(char);
    String(const char*);

}; //Fim da classe String
    
String::String() {
    cout << "Chamada de contrutor nulo String()" << endl;
}// (Item a - i ) 

String::String(char var) { // (Item a - ii )
        //cout << "Chamada de contrutor com paramentro char String(char var)" << endl; 
        varChar = var; 
}//Construtor com paramentro char

String::String(const char* var) { // (Item a - iii )
        //cout << "Chamada de contrutor com paramentro string String(char* var)" << endl;
        varString = var;
        //varString1 = new String(var);
}//Construtor com paramentro string

char* String::lowerChar(int a, int b) {

    String* varString1 = new String(varString);
    char* var = new char[varString1->sizeChar()];
    int i;

    for (i = 0; i <= varString1->sizeChar(); i++) {
        var[i] = varString[i];
        if (i >= a && i < b) {
            if (var[i] >= 'A' && var[i] <= 'Z') { // >= 66 && <= 90 pela tabela ascii
                var[i] = var[i] - ('A' - 'a');
                //var[i] += 32; // pela tabela ASCii
            }
        }
    }
    return var;
}

char* String::upperChar(int a, int b) {

    String* varString1 = new String(varString);
    char* var = new char[varString1->sizeChar()];
    int i;

    for (i = 0; i <= varString1->sizeChar(); i++) {
        var[i] = varString[i];
        if (i >= a && i < b) {
            if (var[i] >= 'a' && var[i] <= 'z') // >= 97 && <= 122 pela tabela ascii
            {
                var[i] = var[i] + ('A' - 'a');
                //var[i] -= 32; // pela tabela ASCii
            }
        }
    }
    return var;
}

char* String::toggleChar(int a, int b) {
    
    String* varString1 = new String(varString);
    char* var = new char[varString1->sizeChar()];
    int i;

    for (i = 0; i <= varString1->sizeChar(); i++) {
        var[i] = varString[i];
        if (i >= a && i < b) {
            if (var[i] >= 'a' && var[i] <= 'z') // >= 97 && <= 122 pela tabela ascii
            {
                var[i] = var[i] + ('A' - 'a');
                //var[i] -= 32; // pela tabela ASCii
            }
            else if(var[i] >= 'A' && var[i] <= 'Z'){ // >= 66 && <= 90 pela tabela ascii
                var[i] = var[i] - ('A' - 'a');
                //var[i] += 32; // pela tabela ASCii
            }
        }
    }
    return var;
}

int String::sizeChar() { // (Item e )
    int i;

    for (i = 0; varString[i] != '\0'; i++);

    return i;
 }

int String::sizeChar(char* var) { // (Item e )
    int i;
    //cout << varString;
    for (i = 0; varString[i] != '\0'; i++) {
        //cout << "Letter: " << varString[i] << endl;
    }
    return i;
}

int String::indiceChar(char var) { // (Item f )
    int i;
    bool verifica = false;
    for (i = 0; varString[i] != '\0'; i++) {
        if (varString[i] == var) {
            cout << "indice " << i + 1 << " - caractere: '"<< varString[i] << "'" << endl;
            verifica = true;
            return i;
        }
        else {
            verifica = false;
        }
    }
    if (verifica == false) {
        cout << "caractere '" << var << "' nao pertence a String '" << varString << "'" << endl;
    }
}

void begin(String* var) {
    int sizeString, indiceString, resposta = 0, a = 0, b = 0;
    char r;

    
        

        while (resposta != 9) {
            system("cls");
            cout << "String: " << var << endl;
            cout << " ---------------------------------------------------------------------------" << endl;
            cout << "| 1 - size()                                                                |" << endl;
            cout << "| 2 - indice()                                                              |" << endl;
            cout << "| 3 - upperCase()                                                           |" << endl;
            cout << "| 4 - lowerCase()                                                           |" << endl;
            cout << "| 5 - toggleCase()                                                          |" << endl;
            cout << "| 9 - Exit                                                                  |" << endl;
            cout << " ---------------------------------------------------------------------------" << endl;
            cout << "\nQual operacao deseja fazer com a string selecionada ?: ";
            cin >> resposta;
        switch (resposta)
        {
        case 1:
            cout << "\nSelecionado: "<< resposta << endl;
            sizeString = var->sizeChar();
            cout << "O tamanho da string e : " << sizeString << endl;
            _getch();
            break;
        case 2:
            cout << "\nSelecionado: "<< resposta << endl;
            cout << "Qual o caractere voce deseja retornar o indice? ";
            cin >> r;
            indiceString = var->indiceChar(r);
            cout << "\nO indice retonardo e : " << indiceString << endl;
            _getch();
            break;
        case 3:
            cout << "\nSelecionado: " << resposta << endl;
            cout << "informe o intervalo que deseja fazer" << endl;
            cout << "1º indice: ";
            cin >> a;
            cout << "2º indice: ";
            cin >> b;
            cout << var->upperChar(a, b);
            _getch();
            break;
        case 4:
            cout << "\nSelecionado: " << resposta << endl;
            cout << "informe o intervalo que deseja fazer" << endl;
            cout << "informe o intervalo que deseja fazer" << endl;
            cout << "1º indice: ";
            cin >> a;
            cout << "2º indice: ";
            cin >> b;
            cout << var->lowerChar(a, b);
            _getch();
            break;
        case 5:
            cout << "\nSelecionado: " << resposta << endl;
            cout << "informe o intervalo que deseja fazer" << endl;
            cout << "informe o intervalo que deseja fazer" << endl;
            cout << "1º indice: ";
            cin >> a;
            cout << "2º indice: ";
            cin >> b;
            cout << var->toggleChar(a, b);
            _getch();
            break;
        case 9: 
            break;
        default:
            break;
        }
    }
}

int main()
{
   /* String* var;
    char* primeiroNome = new char[100];
    cout << "Qual seu primeiro nome ? ";
    cin >> primeiroNome;
    const char* a = primeiroNome;
    var = new String(a);
    cout << "size: "<< var->sizeChar() << endl;
    cout << a << endl;
    cout <<"upperCase => " << var->upperChar(0, var->sizeChar()) << endl;
    cout <<"lowerCase => " << var->lowerChar(0, var->sizeChar()) << endl;
    cout <<"toggleCase => " << var->toggleChar(0, var->sizeChar()) << endl;
    */


    // mudança na questão "c" String a = b + "qualquer coisa"
    
    //setlocale(LC_ALL, "pt-br");

    String* var;
    char* primeiroNome = new char[100];
    cout << "Qual seu primeiro nome ? ";
    cin >> primeiroNome;
    const char* a = primeiroNome;
    var = new String(a);
    begin(var);
}
