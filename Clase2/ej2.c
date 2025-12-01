#include "stdio.h"
#include "stdlib.h"

typedef struct node{
    int num;
    struct node* next;
}node;

void add(node* root,int pos){
    node* aux = root->next;
    node* prev = root;
    int num;
    printf("Pon el número a añadir:  \n");
    scanf("%d",&num);
    while(pos){
        prev = aux;
        aux = aux->next;
        pos--;
    }
    node *new_node = malloc(sizeof(node));
    new_node->num = num;
    prev->next = new_node;
    new_node->next = aux;
}
void delete(node* root,int pos){
    node *aux = root->next;
    node *prev = root;
    while(pos){
        prev = aux;
        aux = aux->next;
        pos--;
    }
    node *node_to_delete = aux;
    printf("Eliminado nodo con valor: %d\n",node_to_delete->num);
    prev->next = aux->next;
    free(node_to_delete);
}
int delete_value(node* root,int value){
    node *aux = root->next;
    node *prev = root;
    while(aux != NULL && aux->num != value){
        prev = aux;
        aux = aux->next;
    }
    if(aux == NULL) return 0;
    node *node_to_delete = aux;
    printf("Eliminado nodo con valor: %d\n",node_to_delete->num);
    prev->next = aux->next;
    free(node_to_delete);
    return 1;
}
int size(node* root){
    node* aux = root->next;
    int size = 0;
    while(aux != NULL){
        size++;
        aux = aux->next;
    }
    return size;
}

void add_element(node* root){
    int action = 0;
    printf("ELige donde añadir el elemento:\n 1.Al principio\n 2.Al final\n 3.En posicion intermedia\n");
    scanf("%d",&action);
    if(action == 1){
        add(root,0);
    }else if(action == 2){
        add(root,size(root));
    }else if(action == 3){
        int n = size(root);
        printf("Pon la posicion que quieras añadir de [0,%d]",n);
        scanf("%d",&action);
        if(action <= n) add(root,action);
        else printf("Quieres añadir un elemento en una posción invalida\n");
    }else printf("Un numero del 1 al 3 inutil\n");
}
void delete_element(node* root){
    int action = 0;
    printf("Elige que elemento eliminar:\n 1.Al principio\n 2.Al final\n 3.En posicion intermedia\n4.Eliminar primer elemento por valor\n 5.Eliminar todos los elementos por valor\n");
    scanf("%d",&action);
    if(action == 1){
        delete(root,0);
    }else if(action == 2){
        delete(root,size(root) - 1);
    }else if(action == 3){
        int n = size(root);
        printf("Pon la posicion que quieras eliminar de [0,%d]\n",n - 1);
        scanf("%d",&action);
        if(action < n) delete(root,action);
        else printf("Quieres eliminar un elemento que no existe imbecil\n");
    }else if(action == 4 || action == 5){
        int num;
        printf("Elige el valor a eliminar: \n");
        scanf("%d",&num);
        int find_num; 
        do{
            find_num = delete_value(root,num);
        }while(action == 5 && find_num);
    }
}
void print_lista(node* root){
    printf("[");
    node* aux = root->next;
    while(aux != NULL){
        if(aux->next) printf("%d->",aux->num);
        else printf("%d",aux->num);
        aux = aux->next;
    }
    printf("]\n");
}
void print_size(node* root){
    printf("El tamaño de la lista es %d\n",size(root));
}
int main(){
    node dummy;
    node* root = &dummy;
    root->next = NULL;
    int action = 0;
    do{
        printf("pulsa el numero de la acción a realizar:\n 1.Añadir un elemento\n 2.Eliminar un elemento\n 3.Printear la lista\n 4.Saber el tamaño de la lista\n 5.Salir del programa\n");
        scanf("%d",&action);
        switch (action)
        {
        case 1:
            add_element(root);
            break;
        case 2:
            delete_element(root);
            break;
        case 3:
            print_lista(root);
            break;
        case 4:
            print_size(root);
            break;
        default:
            break;
        }
    }while(action > 0 && action <= 4);
    return 0;
}