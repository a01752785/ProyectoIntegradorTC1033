#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <iomanip>
#include "producto.h"
#include "pedido.h"
#include "proveedor.h"
#include "entrega.h"

using namespace std;

ostream& operator<<(ostream& os, Entrega e) {
    os << "ID entrega: " << e.getId() << "\n";
    os << "Direccion: " << e.getDireccion() << "\n";
    os << "Fecha: " << e.getFecha() << "\n";
    os << "Numero de productos: " << e.cuentaProductos() << "\n";
    os << "Productos: \n";
    vector< pair<Producto, int> > productos = e.getProductos();
    for (pair<Producto, int> p : productos) {
        os << p.first.getNombre() << ", cantidad: " << p.second << " unidad(es), ";
        os << "precio unitario: " << p.first.getPrecio() << "\n";
    }
    os << "Precio total de la entrega: " << e.precioTotal() << "\n";
    return os;
}

ostream& operator<<(ostream& os, Pedido p) {
    os << "ID entrega: " << p.getId() << "\n";
    os << "Nombre cliente: " << p.getNombreCliente() << "\n";
    os << "Direccion: " << p.getDireccion() << "\n";
    os << "Telefono: " << p.getTelefono() << "\n";
    os << "Productos: \n";
    vector< pair<Producto, int> > productos = p.getProductos();
    for (pair<Producto, int> prod : productos) {
        os << prod.first.getNombre() << ", cantidad: " << prod.second << " unidad(es), ";
        os << "precio unitario: " << prod.first.getPrecio() << "\n";
    }
    os << "Precio total de la entrega: " << p.precioTotal() << "\n";
    return os;
}

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

void listaProductos(map<int, Producto>& productos) {
    cout << "Lista de productos registrados\n";
    for (pair<int, Producto> producto : productos) {
        cout << "ID: " << producto.second.getId() << " Nombre: "
            << producto.second.getNombre() << " Precio: $"
            << producto.second.getPrecio() << " Unidades disponibles: "
            << producto.second.getDisponibles() << "\n";
    }
}

void listaProveedores(map<int, Proveedor>& proveedores) {
    cout << "Lista de proveedores registrados\n";
    for (pair<int, Proveedor> proveedor : proveedores) {
        cout << "ID: " << proveedor.second.getId() << " Nombre: "
            << proveedor.second.getNombre() << " Telefono: "
            << proveedor.second.getTelefono() << "\n";
    }
}

void listaEntregas(map<int, Entrega>& entregas) {
    cout << "Lista de entregas registradas\n";
    for (pair<int, Entrega> entrega : entregas) {
        cout << "ID: " << entrega.second.getId() << " Fecha: "
            << entrega.second.getFecha() << " Direccion: "
            << entrega.second.getDireccion() << "\n";
    }
}

void listaPedidos(map<int, Pedido>& pedidos) {
    cout << "Lista de pedidos registrados\n";
    for (pair<int, Pedido> pedido : pedidos) {
        cout << "ID: " << pedido.second.getId() << " Nombre cliente: "
            << pedido.second.getNombreCliente() << " Precio total: $"
            << pedido.second.precioTotal() << "\n";
    }
}

void registrarProducto(int& idDispProductos, map<int, Producto>& productos) {
    cout << "Registro de producto\n";
    cout << "ID asignado: " << idDispProductos << "\n";
    cout << "Introduzca el nombre del producto: ";
    string nombre;
    cin >> nombre;
    cout << "Introduzca el precio del producto en pesos: ";
    double precio;
    cin >> precio;
    Producto producto{ idDispProductos, nombre, precio };
    cout << "Introduzca las dimensiones del producto en cm...\n";
    double largo, ancho, alto;
    cout << "Largo: ";
    cin >> largo;
    cout << "Ancho: ";
    cin >> ancho;
    cout << "Alto: ";
    cin >> alto;
    producto.setLargo(largo);
    producto.setAncho(ancho);
    producto.setAlto(alto);
    cout << "Introduzca el peso del producto en kg: ";
    double peso;
    cin >> peso;
    producto.setPeso(peso);
    productos[idDispProductos] = producto;
    idDispProductos++;
    cout << "Producto registrado\n";
}

void registrarProveedor(int& idDispProveedores, map<int, Proveedor>& proveedores) {
    cout << "Registro de proveedor\n";
    cout << "ID asignado: " << idDispProveedores << "\n";
    cout << "Introduzca el nombre del proveedor: ";
    string nombre;
    cin >> nombre;
    cin.ignore();
    cout << "Introduzca el telefono del proveedor: ";
    string telefono;
    cin >> telefono;
    Proveedor proveedor{ idDispProveedores,nombre,telefono };
    proveedores[idDispProveedores] = proveedor;
    idDispProveedores++;
    cout << "Proveedor registrado\n";
}

void registrarEntrega(int& idDispEntregas, map<int, Entrega>& entregas, map<int, Producto>& productos, map<int, Proveedor>& proveedores) {
    if (proveedores.empty()) {
        cout << "Error: no es posible agregar entregas porque no existen proveedores\n";
        cout << "No se ha realizado ningun cambio\n";
        return;
    }
    if (productos.empty()) {
        cout << "Error: no es posible agregar entregas porque no existen productos\n";
        cout << "No se ha realizado ningun cambio\n";
        return;
    }
    cout << "Registro de entrega\n";
    cout << "ID asignado: " << idDispEntregas << "\n";
    cout << "Introduzca la fecha de entrega en formato DD-MM-AAAA: ";
    string fecha;
    cin >> fecha;
    cout << "Introduzca la direccion de entrega: ";
    string direccion;
    cin >> direccion;
    cout << "Introduzca el numero de tipos de producto que tiene la entrega: ";
    int n;
    cin >> n;
    if (productos.size() < n) {
        cout << "Error: ha introducido una cantidad mayor de los productos disponibles\n";
        cout << "No se ha realizado ningun cambio\n";
        return;
    }
    vector< pair<Producto, int> > prodAsignados;
    for (int i = 1; i <= n; i++) {
        cout << "Si desconoce el ID del producto introduzca -1 para mostrar la lista de productos\n";
        cout << "Introduzca el ID del producto " << i << ": ";
        int idProducto;
        cin >> idProducto;
        if (idProducto == -1) {
            listaProductos(productos);
        }
        if (productos.find(idProducto) == productos.end()) {
            if (idProducto != -1)
                cout << "El producto no existe\n";
            i = i - 1;
        }
        else {
            int cantidad = -1;
            while (cantidad < 0) {
                cout << "Ingrese la cantidad de unidades: ";
                cin >> cantidad;
                if (cantidad < 0) {
                    cout << "Error: la cantidad no puede ser negativa\n";
                }
            }
            prodAsignados.push_back(make_pair(productos[idProducto], cantidad));
            cout << "Producto ID " << idProducto << " agregado exitosamente\n";
        }
    }
    bool tieneProveedor = false;
    int idProveedor;
    while (!tieneProveedor) {
        cout << "Si desconoce el ID del proveedor introduzca -1 para mostrar la lista de proveedores\n";
        cout << "Introduzca el ID del proveedor: ";
        cin >> idProveedor;
        if (idProveedor == -1) {
            listaProveedores(proveedores);
        }
        if (proveedores.find(idProveedor) == proveedores.end()) {
            if (idProveedor != -1)
                cout << "El proveedor no existe\n";
        }
        else {
            tieneProveedor = true;
            cout << "Proveedor ID " << idProveedor << " asignado\n";
        }
    }
    Entrega nuevaEntrega{ idDispEntregas,prodAsignados,direccion,fecha };
    entregas[idDispEntregas] = nuevaEntrega;
    proveedores[idProveedor].agregarEntrega(nuevaEntrega);
    idDispEntregas++;
    cout << "A continuacion se agregaran los productos al stock\n";
    for (int i = 0; i < prodAsignados.size(); i++) {
        int idProducto = prodAsignados[i].first.getId();
        int cantidad = prodAsignados[i].second;
        productos[idProducto].setSigEntrega(fecha);
        productos[idProducto].agregarStock(cantidad);
    }
}

void eliminarProducto(map<int, Producto>& productos, int idProducto) {
    if (productos.find(idProducto) == productos.end()) {
        cout << "El producto no existe\n";
        cout << "No se ha realizado ningun cambio\n";
    }
    else {
        productos.erase(idProducto);
        cout << "El producto se ha eliminado\n";
    }
}

void eliminarEntrega(map<int, Entrega>& entregas, map<int, Proveedor>& proveedores, int idEntrega, int idDispProveedores) {
    if (entregas.find(idEntrega) == entregas.end()) {
        cout << "La entrega no existe\n";
        cout << "No se ha realizado ningun cambio";
    }
    else {
        for (int idProveedor = 1; idProveedor < idDispProveedores; idProveedor++) {
            vector<Entrega> entregasPendientes = proveedores[idProveedor].getEntregasPendientes();
            for (Entrega entrega : entregasPendientes) {
                if (idEntrega == entrega.getId()) {
                    proveedores[idProveedor].eliminarEntrega(entrega);
                }
            }
        }
        entregas.erase(idEntrega);
        cout << "La entrega se ha eliminado\n";
    }
}

void eliminarProveedor(map<int, Proveedor>& proveedores, map<int, Entrega>& entregas, int idProveedor) {
    if (proveedores.find(idProveedor) == proveedores.end()) {
        cout << "El Proveedor no existe\n";
        cout << "No se ha realizado ningun cambio\n";
    }
    else {
        vector<Entrega> entregasPendientes;
        for (int i = 0; i < entregasPendientes.size(); i++) {
            eliminarEntrega(entregas, proveedores, entregasPendientes[i].getId(), idProveedor);
        }
        proveedores.erase(idProveedor);
        cout << "El Proveedor se ha eliminado\n";
    }
}

void eliminarPedido(map<int, Pedido>& pedidos, map<int, Producto>& productos, int idPedido) {
    if (pedidos.find(idPedido) == pedidos.end()) {
        cout << "El pedido no existe\n";
        cout << "No se ha realizado ningun cambio\n";
    }
    else {
        vector< pair<Producto,int> > venta;
        for(pair<Producto, int> producto: venta) {
            int idProducto = producto.first.getId();
            productos[idProducto].agregarStock(producto.second);
        }
        pedidos.erase(idPedido);
        cout << "El pedido se ha eliminado\n";
    }
}

void realizarVenta(map<int, Producto>& productos, map<int, Pedido>& pedidos, int& idDispPedidos) {
    if (productos.empty()) {
        cout << "Error: no es posible realizar ventas porque no hay productos disponibles\n";
    }
    cout << "A continuacion se muestra la lista de productos disponibles\n";
    listaProductos(productos);
    bool ventaCompleta = false;
    double precioTotal = 0;
    vector< pair<Producto, int> > venta;
    set<int> idProductosAdquiridos;
    while (!ventaCompleta) {
        cout << "Precio total: $" << fixed << setprecision(2) << precioTotal << "\n";
        cout << "Introduzca el ID del producto que desea agregar a la compra: ";
        int idProducto;
        cin >> idProducto;
        if (productos.find(idProducto) == productos.end()) {
            cout << "Producto no existente\n";
        }
        else {
            if (idProductosAdquiridos.find(idProducto) != idProductosAdquiridos.end()) {
                cout << "Error: ese tipo de producto ya se encuentra en su compra\n";
            }
            else {
                cout << "Ingrese la cantidad de unidades a comprar: ";
                int cantidad;
                cin >> cantidad;
                bool suficiente = (productos[idProducto].getDisponibles() >= cantidad);
                productos[idProducto].vender(cantidad);
                if (suficiente) {
                    venta.push_back(make_pair(productos[idProducto], cantidad));
                    idProductosAdquiridos.insert(idProducto);
                    precioTotal += productos[idProducto].getPrecio() * cantidad;
                }
            }
        }
        cout << "Agregar otro producto? s/n ";
        char answer;
        cin >> answer;
        ventaCompleta = (answer != 's');
    }
    cout << "Precio total del pedido: $" << precioTotal << "\n";
    cout << "ID asignado al pedido: " << idDispPedidos << "\n";
    cout << "Ingrese el nombre del cliente: ";
    string nombreCliente;
    cin >> nombreCliente;
    cout << "Ingrese el telefono del cliente: ";
    string telefono;
    cin >> telefono;
    cout << "Ingrese la direccion de envio: ";
    string direccion;
    cin >> direccion;
    Pedido nuevoPedido{ idDispPedidos, nombreCliente, direccion, telefono, venta };
    pedidos[idDispPedidos] = nuevoPedido;
    cout << "Pedido agregado exitosamente\n";
    cout << "Generando etiqueta de envio...\n";
    cout << pedidos[idDispPedidos].imprimirEtiqueta();
    cout << "Generando correo de confirmacion...\n";
    cout << pedidos[idDispPedidos].enviarCorreoConfirmacion() << "\n";
    idDispPedidos++;
}

int main() {
    map<int, Producto> productos;
    map<int, Entrega> entregas;
    map<int, Proveedor> proveedores;
    map<int, Pedido> pedidos;
    int idDispProductos = 1;
    int idDispEntregas = 1;
    int idDispProveedores = 1;
    int idDispPedidos = 1;
    bool ending = false;
    cout << "Sistema de control de inventario sade.com.mx\n";
    while (!ending) {
        cout << "Seleccione una opcion escribiendo el numero\n";
        int op = 0;
        cout << "1. Registrar un producto/proveedor/entrega/pedido\n";
        cout << "2. Eliminar un producto/proveedor/entrega/pedido\n";
        cout << "3. Visualizar producto/proveedor/entrega/pedido\n";
        cout << "4. Salir\n";
        cin >> op;
        int tipo = 0;
        if (op >= 1 && op <= 3) {
            cout << "Seleccione la opcion deseada\n";
            cout << "1. Producto\n";
            cout << "2. Proveedor\n";
            cout << "3. Entrega\n";
            cout << "4. Pedido\n";
            cout << "Cualquier otro numero para regresar\n";
            cin >> tipo;
        }
        switch (op) {
        case 1:
            if(tipo == 1) {
                cout << "\n";
                registrarProducto(idDispProductos, productos);
            }
            else if(tipo == 2) {
                cout << "\n";
                registrarProveedor(idDispProveedores, proveedores);
            }
            else if(tipo == 3) {
                cout << "\n";
                registrarEntrega(idDispEntregas, entregas, productos, proveedores);
            }
            else if(tipo == 4) {
                cout << "\n";
                realizarVenta(productos, pedidos, idDispPedidos);
            }
            else {
                cout << "Operacion no reconocida\n";
            }
            break;
        case 2:
            if(tipo == 1) {
                cout << "\n";
                listaProductos(productos);
                cout << "Introduzca el ID del producto que desea eliminar: ";
                int idProducto;
                cin >> idProducto;
                eliminarProducto(productos, idProducto);
            }
            else if(tipo == 2) {
                cout << "\n";
                listaProveedores(proveedores);
                cout << "Introduzca el ID del proveedor que desea eliminar: ";
                int idProveedor;
                cin >> idProveedor;
                eliminarProveedor(proveedores, entregas, idProveedor);
            }
            else if(tipo == 3) {
                cout << "\n";
                listaEntregas(entregas);
                cout << "Introduzca el ID de la entrega que desea eliminar: ";
                int idEntrega;
                cin >> idEntrega;
                eliminarEntrega(entregas, proveedores, idEntrega, idDispProveedores);
            }
            else if(tipo == 4) {
                cout << "\n";
                listaPedidos(pedidos);
                cout << "Introduzca el ID del pedido que desea eliminar: ";
                int idPedido;
                cin >> idPedido;
                eliminarPedido(pedidos, productos, idPedido);
            }
            else {
                cout << "Operacion no reconocida\n";
            }
            break;
        case 3:
            if(tipo == 1) {
                listaProductos(productos);
                cout << "Introduzca el ID del producto del cual quiere obtener informacion: ";
                int idProducto;
                cin >> idProducto;
                if(productos.find(idProducto) == productos.end()) {
                    cout << "El producto no existe\n";
                }
                else{
                    cout << productos[idProducto];
                }
            }
            else if(tipo == 2) {
                listaProveedores(proveedores);
                cout << "Introduzca el ID del proveedor del cual quiere obtener informacion: ";
                int idProveedor;
                cin >> idProveedor;
                if(proveedores.find(idProveedor) == proveedores.end()) {
                    cout << "El proveedor no existe\n";
                }
                else {
                    cout << proveedores[idProveedor];
                }
            }
            else if(tipo == 3) {
                listaEntregas(entregas);
                cout << "Introduzca el ID de la entrega de la cual quiere obtener informacion: ";
                int idEntrega;
                cin >> idEntrega;
                if(entregas.find(idEntrega) == entregas.end()) {
                    cout << "La entrega no existe\n";
                }
                else {
                    cout << entregas[idEntrega];
                }
            }
            else if(tipo == 4) {
                listaPedidos(pedidos);
                cout << "Introduzca el ID del pedido del cual quiere obtener informacion: ";
                int idPedido;
                cin >> idPedido;
                if(pedidos.find(idPedido) == pedidos.end()) {
                    cout << "El pedido no existe\n";
                }
                else {
                    cout << pedidos[idPedido];
                }
            }
            else {
                cout << "Operacion no reconocida\n";
            }
            break;
        case 4:
            ending = true;
            break;
        default:
            cout << "Opcion no reconocida\n";
            break;
        }
    }
    cout << "Gracias por utilizar el sistema de control de inventario\n";
    cout << "Hasta luego\n";
    return 0;
}
