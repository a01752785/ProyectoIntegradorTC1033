#ifndef PEDIDO_C
#define PEDIDO_C

#include <string>
#include <vector>
#include <iostream>
#include "producto.h"

class Pedido {
private:
    int idPedido;
    string nombreCliente;
    string direccion;
    string telefono;
    vector< pair<Producto, int> > productos;
public:
    Pedido(string, string, string, vector< pair<Producto, int> >);
    int getId() {
        return idPedido;
    }
    string getNombreCliente() {
        return nombreCliente;
    }
    string getDireccion() {
        return direccion;
    }
    string getTelefono() {
        return telefono;
    }
    vector< pair<Producto, int> > getProductos() {
        return productos;
    }
    string imprimirEtiqueta() {
        return "Numero de referencia: " + to_string(idPedido) +
            "\n" + "Cliente: " + nombreCliente + "\n" +
            "Direccion: " + direccion + "\n" +
            "Telefono: " + telefono + "\n";
    }
    string enviarCorreoConfirmacion() {
        string message = "Asunto: Confirmacion de compra en sade.com.mx\n" +
            "ID del pedido: " + idPedido + "\n" +
            "Nombre: " + nombreCliente + "\n" +
            "Direccion: " + direccion + "\n" +
            "Telefono: " + telefono + "\n" +
            "A continuacion se muestra un resumen de su pedido.\n";
        for (pair<Producto, int> concepto : productos) {
            message += concepto.first.getNombre();
            message += ", " + concepto.second + " unidad(es)\n";
        }
        return message;
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