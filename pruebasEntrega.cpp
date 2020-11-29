#include <iostream>
#include <vector>
#include "entrega.h"

using namespace std;

ostream& operator<<(ostream& os, Entrega e) {
    os << "ID entrega: " << e.getId() << "\n";
    os << "Direccion: " << e.getDireccion() << "\n";
    os << "Fecha: " << e.getFecha() << "\n";
    os << "Numero de productos: " << e.cuentaProductos() << "\n";
    os << "Productos: \n";
    vector< pair<Producto, int> > productos = e.getProductos();
    for (pair<Producto, int> p : productos) {
        os << p.first.getNombre() << ", cantidad: " << p.second << " unidad(es), ";
        os << "precio unitario: " << p.first.getPrecio() << "\n";
    }
    os << "Precio total de la entrega: " << e.precioTotal() << "\n";
    return os;
}

int main() {
    cout << "***PRUEBAS DE CLASE ENTREGA***\n";
    vector< pair<Producto, int> > v;
    v.push_back(make_pair(Producto{ 1,"Taza volcanes",200 }, 2));
    v.push_back(make_pair(Producto{ 2,"Llavero volcanes",50 }, 1));
    cout << "Se agrego al vector de productos el producto \"Taza volcanes\" de precio 200, con 2 unidades\n";
    cout << "Se agrego al vector de productos el producto \"Llavero volcanes\" de precio 50, con 1 unidad\n";
    cout << "Llamada al constructor con parametros "
        << "{432,v,\"Av de la luz 37, Cuautitlan, Mexico, 50000\",\"10-12-2020\"}\n";
    Entrega entrega1{ 432,v,"Av de la luz 37, Cuautitlan, Mexico, 50000","10-12-2020" };
    cout << "Datos de entrega1\n";
    cout << entrega1;
    cout << "Reprogramar entrega a 27-12-2020\n";
    entrega1.reprogramarEntrega("27-12-2020");
    cout << "La entrega lleva el producto \"Taza volcanes\" con ID 1?\n";
    cout << ((entrega1.llevaProducto(Producto{ 1,"Taza volcanes",200 })) ? "true" : "false") << "\n";
    cout << "La entrega lleva el producto \"Llavero de panda\" con ID 5?\n";
    cout << ((entrega1.llevaProducto(Producto{ 5,"Llavero de panda",30 })) ? "true" : "false") << "\n";
    cout << "Llamada al constructor con igual ID\n";
    Entrega entrega2{ 432,v,"Av de la luz,...", "10-12-2020" };
    cout << "Datos de entrega2\n";
    cout << entrega2;
    cout << "Comparar si entrega1 y entrega2 son iguales (por ID)\n";
    cout << ((entrega1 == entrega2) ? "true" : "false") << "\n";
    cout << "Llamada a constructor con diferente ID\n";
    Entrega entrega3{ 2334,v,"Av del sol,...", "05-12-2020" };
    cout << "Datos de entrega3\n";
    cout << entrega3;
    cout << "Comparar si entrega1 y entrega3 son iguales (por ID)\n";
    cout << ((entrega1 == entrega3) ? "true" : "false") << "\n";
    return 0;
}