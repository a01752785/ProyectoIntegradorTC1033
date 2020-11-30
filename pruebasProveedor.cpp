#include <iostream>
#include <vector>
#include "proveedor.h"
#include "producto.h"
#include "entrega.h"

using namespace std;

ostream& operator<<(ostream& os, Proveedor p) {
    os << "ID proveedor: " << p.getId() << "\n";
    os << "Nombre proveedor: " << p.getNombre() << "\n";
    os << "Telefono: " << p.getTelefono() << "\n";
    os << "Productos que proporciona: \n";
    vector<Producto> productos = p.getProductos();
    for (Producto prod : productos) {
        os << "ID: " << prod.getId() << " Nombre: " << prod.getNombre() << "\n";
    }
    os << "Entregas pendientes: \n";
    vector<Entrega> entregas = p.getEntregasPendientes();
    for (Entrega e : entregas) {
        os << "ID: " << e.getId() << " Fecha: " << e.getFecha() << " Direccion: " << e.getDireccion() << "\n";
    }
    return os;
}

int main() {
    cout << "***PRUEBAS DE CLASE PROVEEDOR***\n";
    cout << "Llamada a constructor con {274,\"Tazas cool S.A. de C.V.\",\"5528391650\"}\n";
    Proveedor p1{ 274,"Tazas cool S.A. de C.V.","5528391650" };
    cout << "Datos de p1\n";
    cout << p1;
    cout << "Crear una entrega con ID 56987\n";
    Entrega entrega1{ 56987,vector< pair<Producto,int> >(),"Av de la luz,...","27-12-2020" };
    cout << "Agregar la entrega a la lista de entregas de proveedor\n";
    p1.agregarEntrega(entrega1);
    cout << "Eliminar la entrega con ID 3452\n";
    p1.eliminarEntrega(Entrega{ 3452,vector< pair<Producto,int> >(),"","01-12-2020" });
    cout << "Crear un producto con ID 4538\n";
    Producto producto1{ 4538,"Taza de panda",150 };
    cout << "Agregar el producto a la lista de productos del proveedor\n";
    p1.agregarProducto(producto1);
    cout << "Eliminar el producto con ID 4590\n";
    p1.eliminarProducto(Producto{ 4590,"Taza volcanes",140 });
    cout << "Datos de p1\n";
    cout << p1;
    cout << "Eliminar la entrega con ID 56987\n";
    p1.eliminarEntrega(entrega1);
    cout << "Eliminar el producto con ID 4538\n";
    p1.eliminarProducto(producto1);
    cout << "Datos de p1\n";
    cout << p1;
}