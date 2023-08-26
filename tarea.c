#include <stdio.h>

typedef struct {
    char titulo[100];
    char descripcion[500];
    char fecha_limite[11]; // Formato YYYY-MM-DD
} Tarea;

void agregarTarea(Tarea tareas[], int *numTareas) {
    printf("Introduce el título de la tarea: ");
    fgets(tareas[*numTareas].titulo, sizeof(tareas[*numTareas].titulo), stdin);

    printf("Introduce la descripción de la tarea: ");
    fgets(tareas[*numTareas].descripcion, sizeof(tareas[*numTareas].descripcion), stdin);

    printf("Introduce la fecha límite (YYYY-MM-DD): ");
    fgets(tareas[*numTareas].fecha_limite, sizeof(tareas[*numTareas].fecha_limite), stdin);

    (*numTareas)++;
}

void verTareas(Tarea tareas[], int numTareas) {
    for(int i = 0; i < numTareas; i++) {
        printf("Tarea %d:\n", i+1);
        printf("Título: %s", tareas[i].titulo);
        printf("Descripción: %s", tareas[i].descripcion);
        printf("Fecha Límite: %s\n", tareas[i].fecha_limite);
    }
}

void eliminarTarea(Tarea tareas[], int *numTareas) {
    int index;
    printf("Introduce el número de tarea a eliminar: ");
    scanf("%d", &index);
    getchar();  // Limpiar buffer

    if(index >= 1 && index <= *numTareas) {
        for(int i = index - 1; i < *numTareas - 1; i++) {
            tareas[i] = tareas[i+1];
        }
        (*numTareas)--;
    } else {
        printf("Número de tarea inválido.\n");
    }
}

void editarTarea(Tarea tareas[], int numTareas) {
    int index;
    printf("Introduce el número de tarea a editar: ");
    scanf("%d", &index);
    getchar();  // Limpiar buffer

    if(index >= 1 && index <= numTareas) {
        printf("Introduce el nuevo título: ");
        fgets(tareas[index-1].titulo, sizeof(tareas[index-1].titulo), stdin);

        printf("Introduce la nueva descripción: ");
        fgets(tareas[index-1].descripcion, sizeof(tareas[index-1].descripcion), stdin);

        printf("Introduce la nueva fecha límite (YYYY-MM-DD): ");
        fgets(tareas[index-1].fecha_limite, sizeof(tareas[index-1].fecha_limite), stdin);
    } else {
        printf("Número de tarea inválido.\n");
    }
}

int main() {
    Tarea tareas[100];
    int numTareas = 0;
    int opcion;

    do {
        printf("\n--- Gestor de Tareas ---\n");
        printf("1. Agregar tarea\n");
        printf("2. Ver tareas\n");
        printf("3. Eliminar tarea\n");
        printf("4. Editar tarea\n");
        printf("5. Salir\n");
        printf("Selecciona una opción: ");
        scanf("%d", &opcion);
        getchar();  // Limpiar buffer

        switch(opcion) {
            case 1:
                agregarTarea(tareas, &numTareas);
                break;
            case 2:
                verTareas(tareas, numTareas);
                break;
            case 3:
                eliminarTarea(tareas, &numTareas);
                break;
            case 4:
                editarTarea(tareas, numTareas);
                break;
        }

    } while(opcion != 5);

    return 0;
}

