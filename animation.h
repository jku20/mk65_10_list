#ifndef ANIMATION_H
#define ANIMATION_H

struct animation {
    char name[256]; 
    int length;

    struct animation* next;
};

void print_animation(struct animation *an);
void print_list(struct animation *an);
struct animation *free_list(struct animation *an);
struct animation *new_animation(char* name, int length);
void change_length(struct animation *an, int length);
void change_name(struct animation *an, char* name);
struct animation *insert_front(struct animation *lst, char* name, int length);
struct animation *remove_node(struct animation *lst, char* name, int length);

#endif
