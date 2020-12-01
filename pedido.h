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
    Pedido() = default;
    Pedido(int idPedido, string nombreCliente, string direccion, string telefono, vector< pair<Producto, int> > productos) {
        for (int i = 0; i < productos.size(); i++) {
            if (productos[i].second < 0)
                productos[i].second = 0;
        }
        this->idPedido = idPedido;
        this->nombreCliente = nombreCliente;
        this->direccion = direccion;
        this->telefono = telefono;
        this->productos = productos;
    }
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
    double precioTotal() {
        double total = 0;
        for (int i = 0; i < productos.size(); i++) {
            total += productos[i].first.getPrecio() * productos[i].second;
        }
        return total;
    }
    string enviarCorreoConfirmacion() {
        string message = "";
        message += "Asunto: Confirmacion de compra en sade.com.mx\n";
        message +=
            "ID del pedido: " + to_string(idPedido) + "\n" +
            "Nombre: " + nombreCliente + "\n" +
            "Direccion: " + direccion + "\n" +
            "Telefono: " + telefono + "\n" +
            "A continuacion se muestra un resumen de su pedido.\n";
        for (pair<Producto, int> concepto : productos) {
            message += concepto.first.getNombre();
            message += ", " + to_string(concepto.second) + " unidad(es), precio unitario: $"
                + to_string(concepto.first.getPrecio()) + "\n";
        }
        message += "Precio total del pedido: $" + to_string(precioTotal());
        return message;
    }
};

#endif
