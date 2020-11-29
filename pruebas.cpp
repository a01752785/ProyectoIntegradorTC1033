#include <iostream>
#include "producto.h"
#include "entrega.h"
#include "proveedor.h"
#include "pedido.h"

using namespace std;

ostream& operator<<(ostream& os, Producto p) {
    os << "ID producto: " << p.getId() << "\n";
    os << "Nombre producto: " << p.getNombre() << "\n";
    os << "Peso: " << p.getPeso() << "\n";
    os << "Largo: " << p.getLargo() << "\n";
    os << "Ancho: " << p.getAncho() << "\n";
    os << "Alto: " << p.getAncho() << "\n";
    os << "Precio: " << p.getPrecio() << "\n";
    os << "Unidades disponibles: " << p.getDisponibles() << "\n";
}

int main() {
    //Prueba de producto
    Producto p1{23987,"Taza decorativa Popocatepetl",150};
    cout << p1;
}
