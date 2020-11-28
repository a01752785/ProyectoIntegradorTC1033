#ifndef PRODUCTO_C
#define PRODUCTO_C

#include <iostream>
#include <string>
#include "entrega.h"
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
    Entrega& sigEntrega;
public:
    Producto(string nombre, double precio);
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
        if(sigEntrega == NULL){
            return "No existen siguientes entregas del producto " + getNombre();
        }
        return "Siguiente entrega para el producto " + getNombre() 
        + " el " + (*sigEntrega).getFecha();
    }
    double getPrecio() {
        return precio;
    }
    void setNombre(string nombre){
        this->nombre = nombre;
    }
    void setPeso(double peso){
        this->peso = peso;
    }
    void setLargo(double largo){
        this->largo = largo;
    }
    void setAncho(double ancho){
        this->ancho = ancho;
    }
    void setAlto(double alto){
        this->alto = alto;
    }
    void setPrecio(double precio){
        this->precio = precio;
    }
    void agregarStock(int cantidad){
        cout << "Stock agregado en " << cantidad << " unidades\n";
        cout << "Anterior disponible:" << disponibles << "\n";
        disponibles += cantidad;
        cout << "Nuevo disponible: " << disponibles << "\n";
    }
    void vender(int cantidad){
        if(getDisponibles >= cantidad){
            disponibles -= cantidad;
            cout << "Venta exitosa del producto " + getNombre();
            cout << " en cantidad de " << cantidad << "\n";
        }
        else{
            cout << "Imposible vender, no hay existencias suficientes "
            "para el producto" + getNombre() << "\n";
        }
    }
    void aplicarDescuento(double descuento){
        if(descuento < 0 || descuento > 1){
            cout << "Error: parametro de descuento no valido";
            return;
        }
        double factor = 1 - descuento;
        cout << "Descuento del " << descuento * 100 << "% agregado\n";
        cout << "Precio anterior: " << getPrecio() << "\n";
        setPrecio(precio * factor);
        cout << "Precio nuevo: " << getPrecio << "\n";
    }
};//Clase producto

#endif