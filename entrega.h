#ifndef ENTREGA_C
#define ENTREGA_C

#include <vector>
#include <string>
#include <iostream>
#include "producto.h"
using namespace std;
class Entrega {
private:
    int idEntrega;
    vector< pair<Producto, int> > productos;
    string direccion;
    string fecha;
public:
    Entrega() = default;
    Entrega(int idEntrega, vector< pair<Producto, int> > productos, string direccion, string fecha) {
        for (int i = 0; i < productos.size(); i++) {
            if (productos[i].second < 0)
                productos[i].second = 0;
        }
        this->idEntrega = idEntrega;
        this->productos = productos;
        this->direccion = direccion;
        this->fecha = fecha;
    }
    int getId() {
        return idEntrega;
    }
    string getDireccion() {
        return direccion;
    }
    string getFecha() {
        return fecha;
    }
    vector< pair<Producto, int> > getProductos() {
        return productos;
    }
    bool operator==(const Entrega& e) {
        return idEntrega == e.idEntrega;
    }
    void reprogramarEntrega(string fecha) {
        cout << "La fecha se ha cambiado\n";
        cout << "Fecha anterior: " << this->fecha << "\n";
        this->fecha = fecha;
        cout << "Fecha actual: " << fecha << "\n";
    }
    bool llevaProducto(Producto p) {
        for (int i = 0; i < productos.size(); i++) {
            if (productos[i].first == p)
                return true;
        }
        return false;
    }
    int cuentaProductos() {
        int total = 0;
        for (int i = 0; i <
            productos.size(); i++) {
            total += productos[i].second;
        }
        return total;
    }
    double precioTotal() {
        double total = 0;
        for (int i = 0; i < productos.size(); i++) {
            total += productos[i].first.getPrecio() * productos[i].second;
        }
        return total;
    }
};

#endif
