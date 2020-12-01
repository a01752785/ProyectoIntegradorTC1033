#ifndef PRODUCTO_C
#define PRODUCTO_C

#include <iostream>
#include <string>
using namespace std;
class Producto {
private:
    int idProducto;
    string nombre;
    double peso;
    double largo;
    double ancho;
    double alto;
    double precio;
    int disponibles;
    string sigEntrega;
public:
    Producto() = default;
    Producto(int idProducto, string nombre, double precio) {
        this->idProducto = idProducto;
        this->nombre = nombre;
        this->precio = (precio >= 0)? precio : 0;
        this->peso = 0.5;
        this->largo = 0.1;
        this->ancho = 0.1;
        this->alto = 0.1;
        this->disponibles = 0;
        this->sigEntrega = "";
    }
    Producto(const Producto& p) {
        idProducto = p.idProducto;
        nombre = p.nombre;
        peso = p.peso;
        largo = p.largo;
        alto = p.alto;
        ancho = p.ancho;
        alto = p.alto;
        precio = p.precio;
        disponibles = p.disponibles;
        sigEntrega = p.sigEntrega;
    }
    int getId() {
        return idProducto;
    }
    string getNombre() {
        return nombre;
    }
    double getPeso() {
        return peso;
    }
    double getLargo() {
        return largo;
    }
    double getAncho() {
        return ancho;
    }
    double getAlto() {
        return alto;
    }
    int getDisponibles() {
        return disponibles;
    }
    string getSigEntrega() {
        if (sigEntrega == "") {
            return "No existen siguientes entregas del producto " + getNombre();
        }
        return "Siguiente entrega para el producto " + getNombre()
            + " el " + sigEntrega;
    }
    double getPrecio() {
        return precio;
    }
    void setNombre(string nombre) {
        this->nombre = nombre;
    }
    void setPeso(double peso) {
        if(peso < 0){
            cout << "Error: peso no puede ser negativo\n";
            cout << "No se ha realizado ningun cambio en el parametro\n";
            return;
        }
        this->peso = peso;
    }
    void setLargo(double largo) {
        if(largo < 0){
            cout << "Error: largo no puede ser negativo\n";
            cout << "No se ha realizado ningun cambio en el parametro\n";
            return;
        }
        this->largo = largo;
    }
    void setAncho(double ancho) {
        if(ancho < 0){
            cout << "Error: ancho no puede ser negativo\n";
            cout << "No se ha realizado ningun cambio en el parametro\n";
            return;
        }
        this->ancho = ancho;
    }
    void setAlto(double alto) {
        if(alto < 0){
            cout << "Error: alto no puede ser negativo\n";
            cout << "No se ha realizado ningun cambio en el parametro\n";
            return;
        }
        this->alto = alto;
    }
    void setPrecio(double precio) {
        if(precio < 0){
            cout << "Error: precio no puede ser negativo\n";
            cout << "No se ha realizado ningun cambio en el parametro\n";
            return;
        }
        this->precio = precio;
    }
    void setSigEntrega(string sigEntrega) {
        this->sigEntrega = sigEntrega;
    }
    bool operator==(const Producto& p) {
        return idProducto == p.idProducto;
    }
    void agregarStock(int cantidad) {
        if(cantidad < 0){
            cout << "Error: cantidad negativa\n";
            cout << "No se ha realizado ningun cambio en el parametro\n";
            return;
        }
        cout << "Producto " << getNombre() << "\n";
        cout << "Stock agregado en " << cantidad << " unidades\n";
        cout << "Anterior disponible: " << disponibles << "\n";
        disponibles += cantidad;
        cout << "Nuevo disponible: " << disponibles << "\n";
    }
    void vender(int cantidad) {
        if(cantidad <= 0){
            cout << "Error: cantidad negativa o 0\n";
            cout << "No se ha realizado ningun cambio en el parametro\n";
            return;
        }
        if (disponibles >= cantidad) {
            disponibles -= cantidad;
            cout << "Venta exitosa del producto " + getNombre();
            cout << " en cantidad de " << cantidad << "\n";
        }
        else {
            cout << "Imposible vender, no hay existencias suficientes "
                "para el producto " + getNombre() << "\n";
        }
    }
    void aplicarDescuento(double descuento) {
        if (descuento < 0 || descuento > 1) {
            cout << "Error: parametro de descuento no valido\n";
            return;
        }
        double factor = 1 - descuento;
        cout << "Descuento del " << descuento * 100 << "% agregado\n";
        cout << "Precio anterior: " << getPrecio() << "\n";
        setPrecio(precio * factor);
        cout << "Precio nuevo: " << getPrecio() << "\n";
    }
};//Clase producto

#endif
