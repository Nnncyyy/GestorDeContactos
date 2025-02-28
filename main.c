#include <stdio.h>
#include <string.h>

/* Programa que simula una agenda digital de 100 contactos */

struct agenda {
    char nombre[50];
    char telefono[15];
    char email[50];
    int id;
};

// Prototipos de funciones.
void ingresarContacto(int, struct agenda contacto[100]);
int buscarID(char[50], struct agenda contacto[100]);
void informacionContacto(int, struct agenda contacto[100]);
void eliminarContacto(int, struct agenda contacto[100]);
int guardarContacto(int num_contacto, struct agenda contacto[100]);
int cargarContactos(struct agenda contacto[100], char nombreArchivo[100]);

int main() {
    struct agenda contacto[100];
    int op, num_contacto = 0, id_encontrado;
    char buscar_nombre[50];
    char nombreArchivo[100];

    printf("------------ Agenda Digital de 100 contactos ------------ \n");

    do {
        printf("MENU: \n");
        printf("1. Agregar contacto  \n");
        printf("2. Mostrar contacto  \n");
        printf("3. Buscar contacto   \n");
        printf("4. Eliminar contacto \n");
        printf("5. Guardar contacto  \n");
        printf("6. Cargar contactos desde archivo\n");
        printf("0. Salir \n");
        printf("Seleccione una opcion: ");
        scanf("%d", &op);
        fflush(stdin);

        switch (op) {
            case 1:
                if (num_contacto < 100) {
                    printf("Ingrese la informacion solicitada: \n");
                    ingresarContacto(num_contacto, contacto);
                    printf("Contacto agregado con exito.\n\n");
                    contacto[num_contacto].id = num_contacto;
                    num_contacto++;
                } else {
                    printf("La agenda está llena.\n\n");
                }
                break;

            case 2:
                printf("Ingrese el nombre del contacto que desea mostrar: \n");
                scanf(" %[^"]", buscar_nombre);
                fflush(stdin);
                id_encontrado = buscarID(buscar_nombre, contacto);
                if (id_encontrado != 200) {
                    printf("Contacto encontrado: \n\n");
                    informacionContacto(id_encontrado, contacto);
                    printf("ID: %d \n", id_encontrado);
                } else {
                    printf("Contacto NO encontrado. \n\n");
                }
                break;

            case 3:
                printf("Ingrese el nombre del contacto que desea buscar: \n");
                scanf(" %[^"]", buscar_nombre);
                fflush(stdin);
                id_encontrado = buscarID(buscar_nombre, contacto);
                if (id_encontrado != 200) {
                    printf("Contacto encontrado: \n\n");
                    informacionContacto(id_encontrado, contacto);
                    printf("ID: %d \n", id_encontrado);
                } else {
                    printf("Contacto NO encontrado. \n\n");
                }
                break;

            case 4:
                printf("Ingrese el nombre del contacto que desea eliminar: \n");
                scanf(" %[^"]", buscar_nombre);
                fflush(stdin);
                id_encontrado = buscarID(buscar_nombre, contacto);
                if (id_encontrado != 200) {
                    eliminarContacto(id_encontrado, contacto);
                    printf("Contacto eliminado con exito. \n\n");
                } else {
                    printf("Contacto NO encontrado. \n\n");
                }
                break;

            case 5:
                if (num_contacto != 0) {
                    guardarContacto(num_contacto, contacto);
                    printf("Contactos guardados con exito. \n\n");
                } else {
                    printf("No se ha registrado ningun contacto. \n\n");
                }
                break;

            case 6:
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
                printf("Opcion no valida. \n\n");
        }

    } while (op != 0);

    return 0;
}

void ingresarContacto(int num_contacto, struct agenda contacto[100]) {
    printf("Nombre: ");
    scanf(" %[^"]", contacto[num_contacto].nombre);
    printf("Telefono: ");
    scanf(" %[^"]", contacto[num_contacto].telefono);
    printf("Email: ");
    scanf(" %[^"]", contacto[num_contacto].email);
}

int buscarID(char buscar_nombre[30], struct agenda contacto[100]) {
    for (int i = 0; i < 100; i++) {
        if (strcmp(contacto[i].nombre, buscar_nombre) == 0) {
            return i;
        }
    }
    return 200;
}

void informacionContacto(int id_encontrado, struct agenda contacto[100]) {
    printf("Nombre: %s \n", contacto[id_encontrado].nombre);
    printf("Telefono: %s \n", contacto[id_encontrado].telefono);
    printf("Email: %s \n", contacto[id_encontrado].email);
}

void eliminarContacto(int id_encontrado, struct agenda contacto[100]) {
    for (int i = id_encontrado; i < 99; i++) {
        contacto[i] = contacto[i + 1];
    }
}

int guardarContacto(int num_contacto, struct agenda contacto[100]) {
    FILE *archivo = fopen("contactos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para escritura.\n");
        return 1;
    }
    for (int i = 0; i < num_contacto; i++) {
        fprintf(archivo, "%s,%s,%s\n", contacto[i].nombre, contacto[i].telefono, contacto[i].email);
    }
    fclose(archivo);
    return 0;
}

int cargarContactos(struct agenda contacto[100], char nombreArchivo[100]) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        printf("No se pudo abrir el archivo '%s'.\n", nombreArchivo);
        return 0;
    }
    int num_contacto = 0;
    while (fscanf(archivo, "%49[^,],%14[^,],%49[^\n]\n", contacto[num_contacto].nombre, contacto[num_contacto].telefono, contacto[num_contacto].email) == 3) {
        contacto[num_contacto].id = num_contacto;
        num_contacto++;
    }
    fclose(archivo);
    return num_contacto;
}
