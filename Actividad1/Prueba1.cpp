#include <iostream>
#include <string>
using namespace std;

class Cliente;
class Vendedor;
class Usuario {
protected:
    string nombre = "Mario";
    string telefono = "3313183113";
    string contrasena = "MaUnoDos";
    int edad = 30;

public:
    void LogIn(string nombre, string contrasena);
    void LogOut(){}
    void CambiarContrasena(string contrasena, string contrNueva){}
};

class Cliente : public Usuario {
public:
    void Comprar();
    void Reclamar();
    void Devolver();
};

class Vendedor : public Usuario {
public:
    void Vender();
    void ActuaInventario();
};

void Usuario::LogIn(string nombre, string contrasena) {
    string respuestaRol;
    if (nombre == this->nombre && contrasena == this->contrasena) {
        cout << "Bienvenido " << nombre << endl;
        cout << "¿Eres un Vendedor o un Cliente? Escribe la respuesta: \n";
        cin >> respuestaRol;
        if (respuestaRol == "Vendedor" || respuestaRol == "vendedor") {
            string respAccionVend;
            cout << "¿Que deseas hacer?\n";
            cout << "Vender - Actualizar El Inventario \n";
            cout << "Escribe 'Vender' o 'Inventario': ";
            cin >> respAccionVend;
            Vendedor vendedor;
            if (respAccionVend == "Vender" || respAccionVend == "vender") {
                vendedor.Vender();
            } else if (respAccionVend == "Inventario" || respAccionVend == "inventario") {
                vendedor.ActuaInventario();
            } else {
                cout << "Error en la opcion";
            }
        } else if (respuestaRol == "Cliente" || respuestaRol == "cliente") {
            string respAccionCliente;
            cout << "¿Que deseas hacer?\n";
            cout << "Comprar - Reclamar - Devolver\n";
            cout << "Escribe tu eleccion: ";
            cin >> respAccionCliente;
            Cliente cliente;
            if (respAccionCliente == "Comprar" || respAccionCliente == "comprar") {
                cliente.Comprar();
            } else if (respAccionCliente == "Reclamar" || respAccionCliente == "reclamar") {
                cliente.Reclamar();
            } else if (respAccionCliente == "Devolver" || respAccionCliente == "devolver") {
                cliente.Devolver();
            } else {
                cout << "Error en la opcion";
            }
        } else {
            cout << "Error en la opción";
        }
    } else {
        cout << "Los datos son erroneos...";
    }
}

void Cliente::Comprar() {
    cout << "Has comprado unos pares de calcetines, son los mas calientitos que has sentido";
}
void Cliente::Reclamar() {
    cout << "¡Esos malditos calcetines estaban tenian un hoyo en el dedo chiquito! ¡INACEPTABLE!";
}
void Cliente::Devolver() {
    cout << "Menos mal que te han devuelto tus 'Sinko Peso' por ese par de calcetines, has podido devolver los calcetines";
}
void Vendedor::Vender() {
    cout << "Has vendido unos pares de calcetines... tus ganancias son increibles, felicidades";
}
void Vendedor::ActuaInventario() {
    cout << "En este momento tienes Veinte mil trescientos ochenta y ocho (20,388) pares de calcetines";
}

int main(int argc, char const* argv[]) {
    string respuestaNom, respuestaContr;
    cout << "Bienvenido...\n";
    cout << "Ingrese su nombre: ";
    cin >> respuestaNom;
    cout << "Ingrese su contrasena: ";
    cin >> respuestaContr;
    Usuario usuario;
    usuario.LogIn(respuestaNom, respuestaContr);
    return 0;
};