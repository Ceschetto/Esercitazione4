#include "library/car_list.h"
#include <stdio.h>
#include <stdlib.h>


#define ID_SIZE 10
#define MODEL_SIZE 20


struct Car_Node
{
    char ID[ID_SIZE];
    char model[MODEL_SIZE];
    int engine_size;
    int production_year;
    struct Car_Node * Next_Node;
};

typedef struct Car_Node car_node;

void insert_car(car_node_ptr *head_node_ptr)
{
    car_node_ptr new_node = NULL;
    new_node = malloc(sizeof(car_node));

    printf("Input engine_size\n: ");
    scanf("%d", &(new_node->engine_size));

    printf("Input production year\n: ");
    scanf("%d", &(new_node->production_year));

    printf("Input Model\n: ");
    scanf("%d", (new_node->model));

    printf("Input id\n: ");
    scanf("%d", (new_node->ID));
}
