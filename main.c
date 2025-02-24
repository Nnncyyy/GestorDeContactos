#include <stdio.h>

/*Programa que simula una agenda digital de 100 contactos*/
struct agenda
{
    char nombre[50];
    char num_movil[15];
    char email[50];
    int id;
};

//Prototipos de funciones.
void ingresarContacto(int, struct agenda contacto[100]);


int main() {
    struct agenda contacto[100];
    int op, i, j, k, num_contacto=0, buscar_id, id_encontrado;
    char buscar_nombre[30];

    printf("Agenda Digital de 100 contactos. \n");

    do
    {
        printf("MENU: \n");
        printf("1. Agregar contacto  \n");
        
        printf("0. Salir \n");
        printf("Seleccione una opcion\n");
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            __fpurge(stdin);
            printf("1. Nuevo contacto. \n");

            if (num_contacto<100){
                printf("Ingrese la informacion solicitada: \n");

                ingresarContacto(num_contacto,contacto);

                printf("Contacto agregado con exito.\n");
                contacto[num_contacto].id = num_contacto;
                num_contacto++;
            } else {
                printf("La agenda está llena.\n");
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
// Función que solicita la infomación de un nuevo contacto.
void ingresarContacto(int num_contacto, struct agenda contacto[100]){
    printf("Nombre: \n");
    scanf("%[^\n]",contacto[num_contacto].nombre);
    __fpurge(stdin);
    printf("Numero movil: \n");
    scanf("%[^\n]",contacto[num_contacto].num_movil);
    __fpurge(stdin);
    printf("Email: \n");
    scanf("%[^\n]",contacto[num_contacto].email);
    __fpurge(stdin);

}
