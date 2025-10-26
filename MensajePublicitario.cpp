#include "MensajePublicitario.h"

MensajePublicitario::MensajePublicitario() : contenido(""), categoria(C) {}

MensajePublicitario::MensajePublicitario(const string &mensaje, CategoriaPublicidad cat)
    : contenido(mensaje), categoria(cat) {}

int MensajePublicitario::prioridad() const
{
    switch (categoria)
    {
    case A:
        return 1;
    case B:
        return 2;
    case C:
        return 3;
    default:
        return 1;
    }
}

void MensajePublicitario::mostrar() const
{
    cout << "\n"
         << string(60, '*') << endl;
    cout << "*" << string(22, ' ') << "PUBLICIDAD" << string(26, ' ') << "*" << endl;
    cout << "*" << string(58, ' ') << "*" << endl;
    string categoriaStr = (categoria == C ? "C" : (categoria == B ? "B" : "AAA"));
    cout << "* Categoria: " << categoriaStr << string(44, ' ') << "*" << endl;
    cout << "*" << string(58, ' ') << "*" << endl;

    // Dividir el contenido en lineas para ajustarlo
    string linea = contenido;
    if (linea.length() > 56)
    {
        cout << "* " << linea.substr(0, 56) << " *" << endl;
        if (linea.length() > 56)
        {
            cout << "* " << linea.substr(56) << string(56 - linea.substr(56).length(), ' ') << " *" << endl;
        }
    }
    else
    {
        cout << "* " << linea << string(56 - linea.length(), ' ') << " *" << endl;
    }

    cout << "*" << string(58, ' ') << "*" << endl;
    cout << string(60, '*') << endl;
    cout << "\nPresiona ENTER para continuar..." << flush;
    cin.clear();
    cin.ignore(10000, '\n');
    cin.get();
}
