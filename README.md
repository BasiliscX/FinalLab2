# Changuito++

## Descripción

Este proyecto es un sistema de gestión de inventarios y ventas llamado "Changuito++" desarrollado en C++. El objetivo principal del proyecto es proporcionar una interfaz sencilla y eficaz para administrar y manipular una lista de productos, clientes, proveedores, y ventas.

## Características

- Almacena y gestiona información detallada de productos, clientes, proveedores, y ventas, incluyendo nombre, precio, cantidad, y cualquier otro atributo relevante.
- Permite agregar, eliminar, y actualizar productos, clientes, proveedores, y ventas de la lista.
- Permite buscar productos, clientes, proveedores, y ventas por diferentes criterios, como nombre, precio, y cantidad.
- Permite ordenar la lista de productos, clientes, proveedores, y ventas por diferentes atributos, como nombre, precio, y cantidad.
- Permite exportar la lista de productos, clientes, proveedores, y ventas a un archivo de texto plano y importar la lista de productos, clientes, proveedores, y ventas desde un archivo de texto plano.
- Permite generar informes y reportes detallados sobre la lista de productos, clientes, proveedores, y ventas.
- Permite gestionar y administrar usuarios con diferentes roles y permisos.

## Estructura de Archivos

- `main.cpp`: Archivo principal que contiene la función `main()` y el programa principal.
- `Producto/`: Carpeta que contiene los archivos relacionados con los productos.
  - `ArchivoProducto.h`: Archivo de cabecera que define la clase `ArchivoProducto`, que proporciona la funcionalidad de exportar y importar la lista de productos a un archivo de texto plano.
  - `FuncionesProductos.h`: Archivo de cabecera que define la clase `FuncionesProductos`, que proporciona la funcionalidad de gestión de productos.
  - `Producto.h`: Archivo de cabecera que define la clase `Producto`, que representa un producto individual.
- `Cliente/`: Carpeta que contiene los archivos relacionados con los clientes.
  - `ArchivoCliente.h`: Archivo de cabecera que define la clase `ArchivoCliente`, que proporciona la funcionalidad de exportar y importar la lista de clientes a un archivo de texto plano.
  - `FuncionesClientes.h`: Archivo de cabecera que define la clase `FuncionesClientes`, que proporciona la funcionalidad de gestión de clientes.
  - `Cliente.h`: Archivo de cabecera que define la clase `Cliente`, que representa un cliente individual.
- `Proveedor/`: Carpeta que contiene los archivos relacionados con los proveedores.
  - `ArchivoProveedor.h`: Archivo de cabecera que define la clase `ArchivoProveedor`, que proporciona la funcionalidad de exportar y importar la lista de proveedores a un archivo de texto plano.
  - `FuncionesProveedores.h`: Archivo de cabecera que define la clase `FuncionesProveedores`, que proporciona la funcionalidad de gestión de proveedores.
  - `Proveedor.h`: Archivo de cabecera que define la clase `Proveedor`, que representa un proveedor individual.
- `Venta/`: Carpeta que contiene los archivos relacionados con las ventas.
  - `ArchivoVentas.h`: Archivo de cabecera que define la clase `ArchivoVentas`, que proporciona la funcionalidad de exportar y importar la lista de ventas a un archivo de texto plano.
  - `FuncionesVentas.h`: Archivo de cabecera que define la clase `FuncionesVentas`, que proporciona la funcionalidad de gestión de ventas.
  - `ReportesVenta.h`: Archivo de cabecera que define la clase `ReportesVenta`, que proporciona la funcionalidad de generar informes y reportes sobre las ventas.
  - `Venta.h`: Archivo de cabecera que define la clase `Venta`, que representa una venta individual.
- `Usuario/`: Carpeta que contiene los archivos relacionados con los usuarios.
  - `ArchivoUsuario.h`: Archivo de cabecera que define la clase `ArchivoUsuario`, que proporciona la funcionalidad de exportar y importar la lista de usuarios a un archivo de texto plano.
  - `FuncionesUsuario.h`: Archivo de cabecera que define la clase `FuncionesUsuario`, que proporciona la funcionalidad de gestión de usuarios.
  - `Usuario.h`: Archivo de cabecera que define la clase `Usuario`, que representa un usuario individual.
- `Menus/`: Carpeta que contiene los archivos relacionados con los menús y submenús.
  - `MenuAdmin.h`: Archivo de cabecera que define la clase `MenuAdmin`, que proporciona la funcionalidad del menú de administración.
  - `MenuConfiguracion.h`: Archivo de cabecera que define la clase `MenuConfiguracion`, que proporciona la funcionalidad del menú de configuración.
  - `MenuEmpleado.h`: Archivo de cabecera que define la clase `MenuEmpleado`, que proporciona la funcionalidad del menú de empleado.
  - `MenuReportes.h`: Archivo de cabecera que define la clase `MenuReportes`, que proporciona la funcionalidad del menú de reportes.
  - `subMenuClientes.h`: Archivo de cabecera que define la clase `subMenuClientes`, que proporciona la funcionalidad del submenú de clientes.
  - `subMenuProductos.h`: Archivo de cabecera que define la clase `subMenuProductos`, que proporciona la funcionalidad del submenú de productos.
  - `subMenuProveedores.h`: Archivo de cabecera que define la clase `subMenuProveedores`, que proporciona la funcionalidad del submenú de proveedores.
  - `subMenuUsuarios.h`: Archivo de cabecera que define la clase `subMenuUsuarios`, que proporciona la funcionalidad del submenú de usuarios.
  - `subMenuVentas.h`: Archivo de cabecera que define la clase `subMenuVentas`, que proporciona la funcionalidad del submenú de ventas.
- `Recursos/`: Carpeta que contiene los archivos de recursos y bibliotecas adicionales.
  - `recursos.h`: Archivo de cabecera que contiene declaraciones y definiciones de recursos y bibliotecas adicionales.
  - `rlutil.h`: Archivo de cabecera que contiene la biblioteca rlutil, que proporciona funciones de utilidad para la consola.
  - `rlutilPlusPlus.h`: Archivo de cabecera que contiene la biblioteca rlutilPlusPlus, que proporciona funciones de utilidad adicionales para la consola.
- `claseDatos.h`: Archivo de cabecera que contiene la definición de la clase `claseDatos`, que proporciona la funcionalidad de almacenamiento y manipulación de datos genéricos.

## rlutilPlusPlus.h

El archivo `rlutilPlusPlus.h` contiene varias funciones y definiciones para mejorar la experiencia del usuario en la consola. A continuación se presenta una lista de las funciones y definiciones más importantes incluidas en este archivo:

- `textAnimation(const char* text = "TEXT", int velocity = 1)`: Esta función muestra el texto proporcionado en la consola con una animación de desplazamiento. El parámetro `velocity` controla la velocidad de la animación.

- `boxAnimation(int x, int y, int tipe = 1, int width = 20, int height = 10, int velocity = 10)`: Esta función dibuja un marco en la consola en la posición especificada por `x` y `y`. El parámetro `tipe` controla el estilo del marco, mientras que los parámetros `width` y `height` controlan el ancho y la altura del marco, respectivamente. El parámetro `velocity` controla la velocidad de la animación.

- `textBoxAnimation(int x, int y, const char* text = "text", int tipe = 2, int velocity = 1)`: Esta función muestra un cuadro de texto en la consola en la posición especificada por `x` y `y`. El parámetro `tipe` controla el estilo del cuadro de texto, mientras que el parámetro `velocity` controla la velocidad de la animación.

- `cls(int x, int y, int cls)`: Esta función limpia la pantalla de la consola en la posición especificada por `x` y `y`. El parámetro `cls` controla la cantidad de caracteres que se limpiarán.

Estas funciones y definiciones proporcionan una base para crear animaciones y diseños en la consola, lo que puede mejorar la experiencia del usuario en el sistema de gestión de inventarios y ventas.

## Compilación y Ejecución

Para compilar el proyecto utilizando Code::Blocks, siga los siguientes pasos:

1. Abra el archivo `.cbp` del proyecto en Code::Blocks.
2. Seleccione la opción "Build" en la barra de menú.
3. Seleccione la opción "Build project" o presione la tecla F9 para compilar el proyecto.

Una vez compilado el proyecto, puede ejecutarlo utilizando los siguientes pasos:

1. Seleccione la opción "Run" en la barra de menú.
2. Seleccione la opción "Run project" o presione la tecla F10 para ejecutar el proyecto.

Esto le abrirá una ventana de consola, donde podrá interactuar con el programa "ProyectoChanguito++".

Asegúrese de tener instalado el compilador GCC y que Code::Blocks esté configurado correctamente para compilar y ejecutar el proyecto.

Si tiene algún problema durante la compilación o ejecución del proyecto, asegúrese de revisar los errores y mensajes de error que se muestran en la consola y siga las instrucciones para solucionarlos.

## Contribuciones

Este proyecto fue desarrollado En la Universidad Tecnologica Nacional durante el curso de Laboratorio II. Los principales contribuidores son:

- [Guillermo Navarro.](https://github.com/BasiliscX)
- Mariel De Biase.
