                                                                                                /* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   docs.c											 :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: cress <cress@student.42.fr>				+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2025/07/23 09:45:00 by cress			 #+#	#+#			 */
/*   Updated: 2025/07/23 12:05:38 by cress			###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

/*
** DOCUMENTACIÓN DE MINILIBX SIMPLIFICADA PARA SO_LONG
** ===================================================
** 
** MiniLibX simplificada con solo las funciones esenciales para so_long.
** Se eliminaron funciones innecesarias (texto, XPM, píxeles, colores).
** 
** Para compilar con MiniLibX:
** gcc programa.c -lmlx -lXext -lX11 -lm -lbsd
*/

#include "minilibx/mlx.h"

/* ========================================================================== */
/*						   FUNCIONES BÁSICAS							   */
/* ========================================================================== */

/*
** mlx_init()
** ----------
** DESCRIPCIÓN: Inicializa la conexión con el servidor gráfico X11.
**			  Debe ser la primera función llamada antes que cualquier otra.
** 
** PARÁMETROS: Ninguno
** 
** RETORNO: 
**   - void* : Puntero al identificador de conexión MLX
**   - NULL  : Si falla la inicialización
** 
** EJEMPLO:
**   void *mlx_ptr = mlx_init();
**   if (!mlx_ptr)
**	   return (1); // Error
*/
void	*mlx_init(void);

/*
** mlx_new_window()
** ----------------
** DESCRIPCIÓN: Crea una nueva ventana con las dimensiones y título especificados.
** 
** PARÁMETROS:
**   - mlx_ptr : Puntero MLX obtenido de mlx_init()
**   - size_x  : Ancho de la ventana en píxeles
**   - size_y  : Alto de la ventana en píxeles  
**   - title   : Título de la ventana (string)
** 
** RETORNO:
**   - void* : Puntero al identificador de ventana
**   - NULL  : Si falla la creación
** 
** EJEMPLO:
**   void *win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Mi Ventana");
*/
void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);

/*
** mlx_clear_window()
** ------------------
** DESCRIPCIÓN: Limpia completamente el contenido de la ventana (la pone en negro).
** 
** PARÁMETROS:
**   - mlx_ptr : Puntero MLX
**   - win_ptr : Puntero a la ventana
** 
** RETORNO: int (código de estado)
** 
** EJEMPLO:
**   mlx_clear_window(mlx_ptr, win_ptr);
*/
int mlx_clear_window(void *mlx_ptr, void *win_ptr);

/* ========================================================================== */
/*						   MANEJO DE IMÁGENES							  */
/* ========================================================================== */

/*
** mlx_new_image()
** ---------------
** DESCRIPCIÓN: Crea una nueva imagen en memoria con las dimensiones especificadas.
**			  Las imágenes son más eficientes que mlx_pixel_put para dibujar muchos píxeles.
** 
** PARÁMETROS:
**   - mlx_ptr : Puntero MLX
**   - width   : Ancho de la imagen en píxeles
**   - height  : Alto de la imagen en píxeles
** 
** RETORNO:
**   - void* : Puntero al identificador de imagen
**   - NULL  : Si falla la creación
** 
** EJEMPLO:
**   void *img_ptr = mlx_new_image(mlx_ptr, 800, 600);
*/
void *mlx_new_image(void *mlx_ptr, int width, int height);

/*
** mlx_get_data_addr()
** -------------------
** DESCRIPCIÓN: Obtiene la dirección de memoria de los datos de la imagen para 
**			  manipulación directa de píxeles.
** 
** PARÁMETROS:
**   - img_ptr		 : Puntero a la imagen
**   - bits_per_pixel  : Puntero donde se almacenará los bits por píxel
**   - size_line	   : Puntero donde se almacenará el tamaño de línea en bytes
**   - endian		  : Puntero donde se almacenará el endianness (0=little, 1=big)
** 
** RETORNO: char* : Puntero a los datos de la imagen
** 
** USO TÍPICO:
**   char *data = mlx_get_data_addr(img, &bpp, &line_len, &endian);
**   // Para poner un píxel en (x,y):
**   *(int*)(data + (y * line_len + x * (bpp / 8))) = color;
** 
** EJEMPLO:
**   int bpp, line_len, endian;
**   char *img_data = mlx_get_data_addr(img_ptr, &bpp, &line_len, &endian);
*/
char *mlx_get_data_addr(void *img_ptr, int *bits_per_pixel, int *size_line, int *endian);

/*
** mlx_put_image_to_window()
** --------------------------
** DESCRIPCIÓN: Muestra una imagen en la ventana en las coordenadas especificadas.
** 
** PARÁMETROS:
**   - mlx_ptr : Puntero MLX
**   - win_ptr : Puntero a la ventana
**   - img_ptr : Puntero a la imagen
**   - x	   : Coordenada X donde colocar la imagen
**   - y	   : Coordenada Y donde colocar la imagen
** 
** RETORNO: int (código de estado)
** 
** EJEMPLO:
**   mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
*/
int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);

/* ========================================================================== */
/*						   MANEJO DE EVENTOS							   */
/* ========================================================================== */

/*
** mlx_key_hook()
** --------------
** DESCRIPCIÓN: Registra una función que se ejecutará cuando se presione una tecla.
** 
** PARÁMETROS:
**   - win_ptr   : Puntero a la ventana
**   - funct_ptr : Puntero a la función callback
**   - param	 : Parámetro que se pasará a la función
** 
** PROTOTIPO DE LA FUNCIÓN CALLBACK:
**   int key_function(int keycode, void *param);
** 
** CÓDIGOS DE TECLA COMUNES:
**   53	= ESC
**   0	 = A
**   13	= W  
**   1	 = S
**   2	 = D
**   123   = Flecha izquierda
**   124   = Flecha derecha
**   125   = Flecha abajo  
**   126   = Flecha arriba
** 
** EJEMPLO:
**   int key_press(int keycode, void *param)
**   {
**	   if (keycode == 53) // ESC
**		   exit(0);
**	   return (0);
**   }
**   mlx_key_hook(win_ptr, key_press, NULL);
*/
int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);

/*
** mlx_mouse_hook()
** ----------------
** DESCRIPCIÓN: Registra una función que se ejecutará cuando se haga clic con el ratón.
** 
** PARÁMETROS:
**   - win_ptr   : Puntero a la ventana
**   - funct_ptr : Puntero a la función callback
**   - param	 : Parámetro que se pasará a la función
** 
** PROTOTIPO DE LA FUNCIÓN CALLBACK:
**   int mouse_function(int button, int x, int y, void *param);
** 
** CÓDIGOS DE BOTÓN:
**   1 = Botón izquierdo
**   2 = Botón central/rueda
**   3 = Botón derecho
**   4 = Rueda hacia arriba
**   5 = Rueda hacia abajo
** 
** EJEMPLO:
**   int mouse_click(int button, int x, int y, void *param)
**   {
**	   printf("Clic en (%d, %d) con botón %d\n", x, y, button);
**	   return (0);
**   }
**   mlx_mouse_hook(win_ptr, mouse_click, NULL);
*/
int mlx_mouse_hook(void *win_ptr, int (*funct_ptr)(), void *param);

/*
** mlx_expose_hook()
** -----------------
** DESCRIPCIÓN: Registra una función que se ejecutará cuando la ventana necesite 
**			  ser redibujada (por ejemplo, después de minimizar/maximizar).
** 
** PARÁMETROS:
**   - win_ptr   : Puntero a la ventana
**   - funct_ptr : Puntero a la función callback
**   - param	 : Parámetro que se pasará a la función
** 
** PROTOTIPO DE LA FUNCIÓN CALLBACK:
**   int expose_function(void *param);
** 
** EJEMPLO:
**   int expose_win(void *param)
**   {
**	   // Redibujar todo el contenido de la ventana
**	   return (0);
**   }
**   mlx_expose_hook(win_ptr, expose_win, NULL);
*/
int mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);

/*
** mlx_loop_hook()
** ---------------
** DESCRIPCIÓN: Registra una función que se ejecutará continuamente en el bucle principal.
**			  Útil para animaciones o actualizaciones constantes.
** 
** PARÁMETROS:
**   - mlx_ptr   : Puntero MLX
**   - funct_ptr : Puntero a la función callback
**   - param	 : Parámetro que se pasará a la función
** 
** PROTOTIPO DE LA FUNCIÓN CALLBACK:
**   int loop_function(void *param);
** 
** EJEMPLO:
**   int animation_loop(void *param)
**   {
**	   // Actualizar animación
**	   return (0);
**   }
**   mlx_loop_hook(mlx_ptr, animation_loop, NULL);
*/
int mlx_loop_hook(void *mlx_ptr, int (*funct_ptr)(), void *param);

/*
** mlx_loop()
** ----------
** DESCRIPCIÓN: Inicia el bucle principal de eventos. Este bucle maneja todos los 
**			  eventos (teclado, ratón, etc.) y debe ser la última función llamada.
**			  El programa permanecerá en este bucle hasta que termine.
** 
** PARÁMETROS:
**   - mlx_ptr : Puntero MLX
** 
** RETORNO: int (código de estado)
** 
** NOTA: Esta función bloquea la ejecución. Todo debe estar configurado antes.
** 
** EJEMPLO:
**   mlx_loop(mlx_ptr); // El programa se queda aquí hasta terminar
*/
int mlx_loop(void *mlx_ptr);

/*
** mlx_loop_end()
** --------------
** DESCRIPCIÓN: Termina el bucle principal de eventos iniciado por mlx_loop().
** 
** PARÁMETROS:
**   - mlx_ptr : Puntero MLX
** 
** RETORNO: int (código de estado)
*/
int mlx_loop_end(void *mlx_ptr);

/* ========================================================================== */
/*						   FUNCIONES DE LIMPIEZA						   */
/* ========================================================================== */

/*
** mlx_destroy_image()
** -------------------
** DESCRIPCIÓN: Libera la memoria de una imagen.
** 
** PARÁMETROS:
**   - mlx_ptr : Puntero MLX
**   - img_ptr : Puntero a la imagen a destruir
** 
** RETORNO: int (código de estado)
** 
** EJEMPLO:
**   mlx_destroy_image(mlx_ptr, img_ptr);
*/
int mlx_destroy_image(void *mlx_ptr, void *img_ptr);

/*
** mlx_destroy_window()
** --------------------
** DESCRIPCIÓN: Cierra y libera una ventana.
** 
** PARÁMETROS:
**   - mlx_ptr : Puntero MLX
**   - win_ptr : Puntero a la ventana a destruir
** 
** RETORNO: int (código de estado)
** 
** EJEMPLO:
**   mlx_destroy_window(mlx_ptr, win_ptr);
*/
int mlx_destroy_window(void *mlx_ptr, void *win_ptr);

/*
** mlx_destroy_display()
** ---------------------
** DESCRIPCIÓN: Cierra la conexión con el servidor gráfico y libera todos los recursos.
**			  Debe ser la última función llamada.
** 
** PARÁMETROS:
**   - mlx_ptr : Puntero MLX
** 
** RETORNO: int (código de estado)
** 
** EJEMPLO:
**   mlx_destroy_display(mlx_ptr);
*/
int mlx_destroy_display(void *mlx_ptr);

/* ========================================================================== */
/*						   FUNCIONES AVANZADAS							 */
/* ========================================================================== */

/*
** mlx_hook()
** ----------
** DESCRIPCIÓN: Sistema de hooks genérico para todos los eventos X11.
**			  Más flexible que los hooks específicos.
** 
** PARÁMETROS:
**   - win_ptr : Puntero a la ventana
**   - x_event : Tipo de evento X11
**   - x_mask  : Máscara de evento X11
**   - funct   : Función callback
**   - param   : Parámetro para la función
** 
** EVENTOS X11 COMUNES:
**   2  = KeyPress
**   3  = KeyRelease
**   4  = ButtonPress
**   5  = ButtonRelease
**   6  = MotionNotify
**   12 = Expose
**   17 = DestroyNotify (cierre de ventana)
** 
** EJEMPLO:
**   int close_win(void *param)
**   {
**	   exit(0);
**	   return (0);
**   }
**   mlx_hook(win_ptr, 17, 0, close_win, NULL); // Hook de cierre
*/
int mlx_hook(void *win_ptr, int x_event, int x_mask, int (*funct)(), void *param);

/* ========================================================================== */
/*						   EJEMPLO DE USO BÁSICO PARA SO_LONG			  */
/* ========================================================================== */

/*
** PROGRAMA MÍNIMO PARA SO_LONG:
** 
** #include "minilibx/mlx.h"
** 
** int main(void)
** {
**	 void *mlx_ptr;
**	 void *win_ptr;
**	 void *img_ptr;
**	 
**	 // 1. Inicializar MLX
**	 mlx_ptr = mlx_init();
**	 if (!mlx_ptr)
**		 return (1);
**	 
**	 // 2. Crear ventana
**	 win_ptr = mlx_new_window(mlx_ptr, 800, 600, "so_long");
**	 if (!win_ptr)
**		 return (1);
**	 
**	 // 3. Crear imagen para sprites
**	 img_ptr = mlx_new_image(mlx_ptr, 32, 32);
**	 
**	 // 4. Configurar eventos
**	 mlx_key_hook(win_ptr, key_press, NULL);
**	 mlx_hook(win_ptr, 17, 0, close_win, NULL); // X roja
**	 
**	 // 5. Iniciar bucle de eventos
**	 mlx_loop(mlx_ptr);
**	 
**	 return (0);
** }
** 
** int key_press(int keycode, void *param)
** {
**	 if (keycode == 53) // ESC
**		 exit(0);
**	 // Agregar W,A,S,D para movimiento
**	 return (0);
** }
** 
** int close_win(void *param)
** {
**	 exit(0);
**	 return (0);
** }
*/

/* ========================================================================== */
/*						   CONSEJOS PARA SO_LONG						   */
/* ========================================================================== */

/*
** CONSEJOS ESPECÍFICOS PARA SO_LONG:
** 
** 1. FUNCIONES ESENCIALES DISPONIBLES:
**	- mlx_init(), mlx_new_window(), mlx_destroy_window()
**	- mlx_new_image(), mlx_destroy_image(), mlx_put_image_to_window()
**	- mlx_key_hook(), mlx_mouse_hook(), mlx_hook()
**	- mlx_loop(), mlx_clear_window()
**	- mlx_get_data_addr() para manipular píxeles de imágenes
** 
** 2. FUNCIONES NO DISPONIBLES (eliminadas):
**	- mlx_pixel_put(), mlx_string_put() (usar imágenes en su lugar)
**	- mlx_xpm_*() (usar otros formatos de imagen)
**	- Funciones de colores avanzadas, texto, sistema
** 
** 3. PARA EL JUEGO SO_LONG:
**	- Usar imágenes para sprites (jugador, objetos, paredes)
**	- Manejar teclas W,A,S,D para movimiento 
**	- ESC para salir, X roja para cerrar ventana
**	- Mostrar contador de movimientos en terminal (no en ventana)
** 
** 4. MANEJO DE MEMORIA:
**	- Liberar imágenes con mlx_destroy_image()
**	- Cerrar ventana con mlx_destroy_window()
**	- Terminar con mlx_destroy_display()
** 
** 5. COMPILACIÓN:
**	gcc so_long.c -lmlx -lXext -lX11 -lm -lbsd
*/