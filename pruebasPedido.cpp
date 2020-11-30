#include <iostream>
#include <vector>
#include "producto.h"
#include "pedido.h"

using namespace std;

ostream& operator<<(ostream& os, Pedido p) {
    os << "ID entrega: " << p.getId() << "\n";
    os << "Nombre cliente: " << p.getNombreCliente() << "\n";
    os << "Direccion: " << p.getDireccion() << "\n";
    os << "Telefono: " << p.getTelefono() << "\n";
    os << "Productos: \n";
    vector< pair<Producto, int> > productos = p.getProductos();
    for (pair<Producto, int> prod : productos) {
        os << prod.first.getNombre() << ", cantidad: " << prod.second << " unidad(es), ";
        os << "precio unitario: " << prod.first.getPrecio() << "\n";
    }
    os << "Precio total de la entrega: " << p.precioTotal() << "\n";
    return os;
}

int main() {
    cout << "***PRUEBAS DE LA CLASE PEDIDO***\n";
    vector< pair<Producto, int> > v;
    v.push_back(make_pair(Producto{ 1,"Taza volcanes",200 }, 2));
    v.push_back(make_pair(Producto{ 2,"Llavero volcanes",50 }, 1));
    cout << "Se agrego al vector de productos el producto \"Taza volcanes\" de precio 200, con 2 unidades\n";
    cout << "Se agrego al vector de productos el producto \"Llavero volcanes\" de precio 50, con 1 unidad\n";
    cout << "Llamada a constructor con {4562,\"Av de la luz\",\"Av de la luz\",\"5583961086\",v}\n";
    Pedido p1{ 4562,"Jose Hernandez","Av de la luz","5583961086",v };
    cout << "Datos del pedido\n";
    cout << p1;
    cout << "Imprimir etiqueta del pedido\n";
    cout << p1.imprimirEtiqueta();
    cout << "Imprimir correo de confirmacion\n";
    cout << p1.enviarCorreoConfirmacion();
}