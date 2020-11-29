#include <iostream>
#include "producto.h"

using namespace std;

ostream& operator<<(ostream& os, Producto p) {
    os << "ID producto: " << p.getId() << "\n";
    os << "Nombre producto: " << p.getNombre() << "\n";
    os << "Peso: " << p.getPeso() << "\n";
    os << "Largo: " << p.getLargo() << "\n";
    os << "Ancho: " << p.getAncho() << "\n";
    os << "Alto: " << p.getAlto() << "\n";
    os << "Precio: " << p.getPrecio() << "\n";
    os << "Unidades disponibles: " << p.getDisponibles() << "\n";
    os << "Siguiente entrega: " << p.getSigEntrega() << "\n";
    return os;
}

int main() {
    //Prueba de producto
    cout << "***PRUEBAS DE CLASE PRODUCTO***\n";
    cout << "Llamada a constructor con {23987,\"Taza decorativa Popocatepetl\",150}\n";
    Producto p1{23987,"Taza decorativa Popocatepetl",150};
    cout << "Producto p1\n";
    cout << p1;
    cout << "Llamada a constructor con {p1}\n";
    Producto p2{p1};
    cout << "Realizar cambios a p1\n";
    cout << "Cambio de nombre\n";
    p1.setNombre("Taza decorativa volcanes");
    cout << "Cambio de peso a -2\n";
    p1.setPeso(-2);
    cout << "Cambio de peso a 0.5\n";
    p1.setPeso(0.5);
    cout << "Cambio de largo a -5\n";
    p1.setLargo(-5);
    cout << "Cambio de largo a .12\n";
    p1.setLargo(0.12);
    cout << "Cambio de ancho a -0.12\n";
    p1.setAncho(-0.12);
    cout << "Cambio de ancho a 0.1\n";
    p1.setAlto(0.1);
    cout << "Cambio de alto a -0.2\n";
    p1.setAlto(-0.2);
    cout << "Cambio de alto a 0.15\n";
    p1.setAlto(0.15);
    cout << "Cambio de precio a -25.2\n";
    p1.setPrecio(-25.2);
    cout << "Cambio de precio a 180\n";
    p1.setPrecio(180);
    cout << "Cambio de fecha de siguiente entrega a \"05-12-2020\"\n";
    p1.setSigEntrega("05-12-2020");
    cout << "Agregar stock con 3 unidades\n";
    p1.agregarStock(3);
    cout << "Agregar stock con -2 unidades\n";
    p1.agregarStock(-2);
    cout << "Vender 5 unidades\n";
    p1.vender(5);
    cout << "Vender -2 unidades\n";
    p1.vender(-2);
    cout << "Vender 2 unidades\n";
    p1.vender(2);
    cout << "Aplicar descuento del 150% (1.5)\n";
    p1.aplicarDescuento(1.5);
    cout << "Aplicar descuento del -20% (-0.2)\n";
    p1.aplicarDescuento(-0.2);
    cout << "Aplicar descuento del 50% (0.5)\n";
    p1.aplicarDescuento(0.5);
    cout << "Comparar si p1 y p2 son iguales (dado por el ID)\n";
    cout << ((p1 == p2)? "true" : "false") << "\n";
    cout << "Crear producto p3 con diferente ID (2345)\n";
    Producto p3{2345,"Producto 3",50};
    cout << "Comparar si p1 y p3 son iguales (dado por el ID)\n";
    cout << ((p1 == p3)? "true" : "false") << "\n";
    cout << "Imprimir producto 1\n";
    cout << p1;
    cout << "Imprimir producto 2 (copia del 1 antes de hacer operaciones)\n";
    cout << p2;
    cout << "Imprimir producto 3\n";
    cout << p3;
    return 0;
}
