#include <iostream>
#include <cstring>
#include <stdlib.h>
using namespace std;

struct Item
{
    int id;
    std::string nombre;
    std::string composicion;
    float precio;
    Item *next;
};

struct Menu
{
    Item *top;
    // MAX STACK
};

std::string MenuPrincipal();
void CrearMenu(Menu *menu);
void imprimirMenu(Menu *menu);

int main(void)
{
    std::string op;
    // Initialize Menu entry
    Menu *menu = new Menu;
    menu->top = NULL;

    do
    {
        op = MenuPrincipal();
        switch (std::stoi(op))
        {
        case 1:
            system("cls");
            CrearMenu(menu);
            break;
        case 2:
            imprimirMenu(menu);
            break;
        case 3:
            system("cls");
            printf("\nGracias por visitar nuestro restaurante.");
            break;
        }
    } while (std::stoi(op) != 3);

    return 0;
}

std::string MenuPrincipal()
{
    std::string op;
    system("cls");
    // cout
    printf("\n1. Ingresar Platos nuevos del dia .");
    printf("\n2. Mostrar menu del dia . ");
    printf("\n3. Terminar");
    printf("\n Ingrese opcion:--> ");
    std::cin >> op;

    //if(){}

    // validate option out of range

    return op;
}

void CrearMenu(Menu *menu)
{
    std::string option;

    do{
        std:cout << "Ingrese 1 para ingresar un plato, cualquier otro numero para salir \n";
        std::cin >> option;
        Item *item = new Item;
        Item * auxItem = NULL;
        switch (std::stoi(option))
        {
        case 1:          
            
            std::cout << "Ingrese el id del plato" << endl;
            std::cin >> item->id;

            std::cout << "Ingrese el precio del plato"<< endl;
            std::cin >> item->precio;


            std::cout << "Ingrese la composicion del plato"<< endl;
            std::cin >> item->composicion;

            std::cout << "Ingrese el nombre del plato"<< endl;
            std::cin >> item->nombre;

            item->next = NULL;

            if (menu->top == NULL)
            {
                menu->top = item;
            } 
            else 
            {                
                auxItem = menu->top;
                
                menu->top = item;
                menu->top->next = auxItem;
            }
            break;
        
        default:
            break;
        }
    } while(std::stoi(option) == 1);

}

void imprimirMenu(Menu *menu){

    Item *aux = menu->top;

    while (aux != NULL)
    {
        cout << "==================================" << endl;
        cout << "Nombre del plato: " << aux->nombre << endl;
        cout << "Precio del plato: " << aux->precio << endl;
        cout << "Composicion del plato: " << aux->composicion << endl;
        cout << "Id del plato: " << aux->id << endl;

        aux = aux->next;
    }
    
}
