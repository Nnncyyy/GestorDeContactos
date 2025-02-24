#include <stdio.h>

/*Programa que simula una agenda digital de 100 contactos*/
struct agenda
{
    char nombre[50];
    char telefono[15];
    char email[50];
    int id;
};

//Prototipos de funciones.
int guardarContacto(int num_contacto, struct agenda contacto[100]);

int main() {
    struct agenda contacto[100];
    int op, num_contacto=0, id_encontrado;
    char buscar_nombre[50];

    printf("Agenda Digital de 100 contactos. \n");

    do
    {
        printf("MENU: \n");
        //printf("1. Agregar contacto  \n");
        //printf("2. Mostrar contacto  \n");
        //printf("3. Buscar contacto   \n");
        //printf("4. Eliminar contacto \n");
        printf("5. Guardar contacto  \n");
        printf("0. Salir \n");
        printf("Seleccione una opcion\n");
        scanf("%d",&op);
        fflush(stdin);

        switch (op)
        {
        //casos anteriores
        case 5:
            printf("5. Guardar contacto  \n");
            if(num_contacto != 0){
                guardarContacto(num_contacto,contacto);
                printf("Contactos guardados con exito. \n");
            } else {
                printf("No se a registrado ningun contacto. \n");
            }
            break;    
            
        case 0:
            printf("Saliendo.... \n");
            break;
            
        default: 
            printf("Opcion no valida. \n");
        }

    } while (op != 0);
    
    return 0;
}

// Definición de funciones.

int guardarContacto(int num_contacto, struct agenda contacto[100]){
    FILE *archivo;
    archivo = fopen("contactos.txt", "w");
            
    if (archivo == NULL){
        printf("Error al abrir el archivo para escritura.\n");
        return 1;
        }
             
    for(int i=0; i<num_contacto; i++){
        fprintf(archivo, "------------ Contacto No.%d ------------\n", contacto[i].id+1);
        fprintf(archivo, "Nombre: %s\n", contacto[i].nombre);
        fprintf(archivo, "Telefono: %s\n", contacto[i].telefono);
        fprintf(archivo, "Email: %s\n", contacto[i].email);
        fprintf(archivo, "\n");
        }

        fclose(archivo);
}