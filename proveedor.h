#ifndef PROVEEDOR_C
#define PROVEEDOR_C

#include <string>
#include <vector>
#include <iostream>
#include "producto.h"
#include "entrega.h"

class Proveedor {
private:
    int idProveedor;
    string nombre;
    vector<Producto> productos;
    vector<Entrega> entregasPendientes;
    string telefono;
public:
    Proveedor() = default;
    Proveedor(int idProveedor, string nombre, string telefono) {
        this->idProveedor = idProveedor;
        this->telefono = telefono;
        this->nombre = nombre;
        productos = vector<Producto>();
        entregasPendientes = vector<Entrega>();
    }
    int getId() {
        return idProveedor;
    }
    string getNombre() {
        return nombre;
    }
    vector<Producto> getProductos() {
        return productos;
    }
    vector<Entrega> getEntregasPendientes() {
        return entregasPendientes;
    }
    string getTelefono() {
        return telefono;
    }
    void agregarEntrega(Entrega entrega) {
        int index = -1;
        for (int i = 0; i < entregasPendientes.size(); i++) {
            if (entregasPendientes[i] == entrega) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            cout << "Error: no es posible agregar, la entrega ya existe\n";
            return;
        }
        entregasPendientes.push_back(entrega);
        cout << "La entrega se ha agregado\n";
    }
    void agregarProducto(Producto producto) {
        int index = -1;
        for (int i = 0; i < productos.size(); i++) {
            if (productos[i] == producto) {
                index = i;
                break;
            }
        }
        if (index != -1) {
            cout << "Error: no es posible agregar, el producto ya existe\n";
            return;
        }
        productos.push_back(producto);
        cout << "El producto se ha agregado\n";
    }
    void eliminarProducto(Producto producto) {
        vector<Producto> tmp;
        int index = -1;
        for (int i = 0; i < productos.size(); i++) {
            if (productos[i] == producto) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Error: no es posible eliminar, producto no encontrado\n";
            return;
        }
        int i = productos.size() - 1;
        while (i >= index) {
            productos.pop_back();
            i--;
        }
        i = index + 1;
        while (i < tmp.size()) {
            productos.push_back(tmp[i]);
            i++;
        }
        cout << "El producto se ha eliminado\n";
    }
    void eliminarEntrega(Entrega entrega) {
        vector<Entrega> tmp;
        int index = -1;
        for (int i = 0; i < entregasPendientes.size(); i++) {
            if (entregasPendientes[i] == entrega) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Error: no es posible eliminar, entrega no encontrada\n";
            return;
        }
        int i = entregasPendientes.size() - 1;
        while (i >= index) {
            entregasPendientes.pop_back();
            i--;
        }
        i = index + 1;
        while (i < tmp.size()) {
            entregasPendientes.push_back(tmp[i]);
            i++;
        }
        cout << "La entrega se ha eliminado\n";
    }
};

#endif
