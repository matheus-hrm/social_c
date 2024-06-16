#include "social.h"

User *create_user(const char *name) {
    User *new_user = (User *)malloc(sizeof(User));
    if (new_user == NULL) {
        return NULL;
    }
    strcpy(new_user->name, name);
    new_user->posts = NULL;
    new_user->friends = (User **)malloc(sizeof(User *) * 10);
    new_user->count_friends = 0;
    new_user->max_friends = 10;
    new_user->next = NULL;
    return new_user;
}

User *find_user(User *users, const char *name) {
    User *current = users;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void add_post (User *user, const char *content) {
    Post *new_post = (Post *)malloc(sizeof(Post));
    strcpy(new_post->content, content);
    new_post->id = count_posts(user); 
    new_post->next = user->posts;
    user->posts = new_post;
}

void delete_post (User *user, unsigned int id) {
    Post *current = user->posts;
    Post *prev = NULL;
    while (current != NULL) {
        if (current->id == id) {
            if (prev == NULL) {
                user->posts = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

void display_posts (User *user) {
    Post *current = user->posts;
    while (current != NULL) {
        printf("@%s: %s\n", user->name, current->content);
        printf("id: %d \n", current->id);
        printf("====================================\n");
        current = current->next;
    }
}

void add_friend(User *user, User *friend) {
    if (user->count_friends == user->max_friends) {
        user->max_friends *= 2;
        user->friends = (User **)realloc(user->friends, sizeof(User *) * user->max_friends);
    }
    user->friends[user->count_friends++] = friend;
}

int count_posts (User *user) {
    int count = 0;
    Post *current = user->posts;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}