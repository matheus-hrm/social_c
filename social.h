#ifndef SOCIAL_H
#define SOCIAL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_POST_LEN 300
#define MAX_NAME_LEN 50

typedef struct Post {
    char content[MAX_POST_LEN];
    struct Post *next;
    unsigned int id;
} Post;

typedef struct User {
    char name[MAX_NAME_LEN];
    Post *posts;
    struct User **friends;
    int count_friends;
    int max_friends;
    struct User *next;
} User;

extern User *users;

User *create_user(const char *name);
User *find_user(User *users, const char *name);
void add_post(User *user, const char *content);
void delete_post(User *user, unsigned int id);
void display_posts(User *user);
void add_friend(User *user, User *friend);
int count_posts(User *user);


#endif //SOCIAL_H