#include <stdio.h>
#include <string.h>

/* Programa que simula una agenda digital de 100 contactos */

struct agenda {
    char nombre[50];
    char telefono[15];
    char email[50];
    int id;
};

// Prototipos de funciones

int cargarContactos(struct agenda contacto[100], char nombreArchivo[100]);

int main() {
    struct agenda contacto[100];
    int op, num_contacto = 0, id_encontrado;
    char buscar_nombre[50];
    char cargar_archivo;
    char nombreArchivo[100];

    printf("Agenda Digital de 100 contactos. \n");

    // Preguntar al usuario si desea cargar los contactos desde un archivo
    printf("¿Desea cargar los contactos desde un archivo? (s/n): ");
    scanf(" %c", &cargar_archivo);
    fflush(stdin);

    if (cargar_archivo == 's' || cargar_archivo == 'S') {
        printf("Ingrese el nombre del archivo: ");
        scanf("%s", nombreArchivo);
        fflush(stdin);
        num_contacto = cargarContactos(contacto, nombreArchivo);
        printf("Contactos cargados desde el archivo '%s'.\n", nombreArchivo);
    }

    do {
        printf("MENU: \n");
        //printf("1. Agregar contacto  \n");
        //printf("2. Mostrar contacto  \n");
        //printf("3. Buscar contacto   \n");
        //printf("4. Eliminar contacto \n");
        //printf("5. Guardar contacto  \n");
        printf("6. Cargar contactos desde archivo\n");
        printf("0. Salir \n");
        printf("Seleccione una opcion: ");
        scanf("%d", &op);
        fflush(stdin);

        switch (op) {

        case 6:
            printf("6. Cargar contactos desde archivo\n");
            printf("Ingrese el nombre del archivo: ");
            scanf("%s", nombreArchivo);
            fflush(stdin);
            num_contacto = cargarContactos(contacto, nombreArchivo);
            printf("Contactos cargados desde el archivo '%s'.\n", nombreArchivo);
            break;

        case 0:
            printf("Saliendo.... \n");
            break;

        default:
            printf("Opción no válida. \n");
        }

    } while (op != 0);

    return 0;
}


// Función para cargar los contactos desde un archivo proporcionado por el usuario.
int cargarContactos(struct agenda contacto[100], char nombreArchivo[100]) {
    FILE *archivo;
    archivo = fopen(nombreArchivo, "r");
    int num_contacto = 0;

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo '%s'.\n", nombreArchivo);
        return 0;
    }

    while (fscanf(archivo, "%49[^,],%14[^,],%49[^\n]\n", 
                  contacto[num_contacto].nombre, 
                  contacto[num_contacto].telefono, 
                  contacto[num_contacto].email) == 3) {
        contacto[num_contacto].id = num_contacto;
        num_contacto++;
    }

    fclose(archivo);
    return num_contacto;
}
