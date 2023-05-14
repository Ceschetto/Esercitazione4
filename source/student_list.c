#include "library/student_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node_Student
{
    char * Id;
    char * Birth_date;
    char * Name;
    char * Surname;
    struct Node_Student * Next_Student;
};

typedef struct Node_Student node_student;

size_t list_len(node_student_ptr head_node);
bool swap_condition(int choice, node_student_ptr node1, node_student_ptr node2);

order_by_id(node_student_ptr * head_node_ptrr, int choice)
{
    node_student_ptr prv_node_ptr = NULL;
    node_student_ptr current_node_ptr = NULL;
    node_student_ptr next_node_ptr = NULL;

    //se rimane solo un elemento è inutile procedere, non si potrà scambiare con nessun'altro
    for (size_t i = list_len(head_node_ptrr); i != 1; i--)
    {


        prv_node_ptr = NULL;
        current_node_ptr = *head_node_ptrr;
        next_node_ptr = (*head_node_ptrr)->Next_Student;

        //se l'elemento successivo è nullo, non si può scambiare con nulla e quindi è inutile procedere.
        while (next_node_ptr != NULL)
        {


            if (swap_condition(choice, current_node_ptr, next_node_ptr))
            {


                if (prv_node_ptr == NULL)
                {

                    *head_node_ptrr = next_node_ptr;
                    node_student_ptr temp_ptr = next_node_ptr->Next_Student; 
                    next_node_ptr->Next_Student = current_node_ptr;
                    current_node_ptr->Next_Student = temp_ptr;

                }
                else
                {

                    prv_node_ptr->Next_Student = next_node_ptr;
                    node_student_ptr temp_ptr = next_node_ptr->Next_Student;
                    next_node_ptr->Next_Student = current_node_ptr;
                    current_node_ptr->Next_Student = temp_ptr;

                }
                prv_node_ptr = next_node_ptr;
                next_node_ptr = current_node_ptr->Next_Student;

            }else
            {

                prv_node_ptr = current_node_ptr; 
                current_node_ptr = next_node_ptr;
                next_node_ptr = next_node_ptr;

            }
            
        }

    }
    
}

size_t list_len(node_student_ptr current_node_ptr)
{
    size_t i;
    while (current_node_ptr != NULL)
    {
        i++;
        current_node_ptr = current_node_ptr->Next_Student;
    }
    return i;
}


//aggiungere l'ordine
bool swap_condition(int choice, node_student_ptr node1, node_student_ptr node2)
{
    switch (choice)
    {

    case '1': //order_by_id
        if (strcmp(node1->Id, node2->Id) < 0) return true;
        break;


    case '2': //order_by_birth_date
        if (strcmp(node1->Birth_date, node2->Birth_date) < 0) return true;
        break;


    case '3': //order_by_name
        if (strcmp(node1->Name, node2->Name) < 0) return true;
        break;


    case '4': //order_by_surname
        if (strcmp(node1->Surname, node2->Surname) < 0) return true;
        break;


    default:
        return false;
        break;
    }
}

