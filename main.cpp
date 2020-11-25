//Sebastian Burgos Alanis
//David Damian Galan
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
      int idSigEntrega;
  public:
      Producto(string nombre, double precio);
      int getId();
      string getNombre();
      double getPeso();
      double getLargo();
      double getAncho();
      double getAlto();
      int getDisponibles();
      string getSigEntregas();
      double getPrecio();
      void setNombre(string);
      void setPeso(double);
      void setLargo(double);
      
};//Clase producto