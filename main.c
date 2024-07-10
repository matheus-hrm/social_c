#include "social.h"

void clear_terminal();

int main(void){
    char c;
    char name[MAX_NAME_LEN];
    char post[MAX_POST_LEN];
    User *current_user = NULL;

    while(1) {
        
        printf("=====Rede Social=====\n");
        printf("1. Criar usuario\n");
        printf("2. Selecionar usuario\n");
        printf("3. Adicionar post\n");
        printf("4. Deletar post\n");
        printf("5. Exibir posts\n");
        printf("6. Adicionar amigo\n");
        printf("7. Exibir informacoes do usuario\n");
        printf("8. Sair\n");
        printf("Digite uma opcao: "); 

        c = getchar();
        while (getchar() != '\n');
        clear_terminal();
        switch(c) {
            case '1':
                printf("Digite o nome do usuario: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0; 
                User *new_user = create_user(name);
                if (new_user == NULL) {
                    printf("Erro ao criar usuario\n");
                } else {
                    if (users == NULL) {
                        users = new_user;
                    } else {
                        new_user->next = users;
                        users = new_user;
                    }
                    printf("Usuario criado com sucesso\n");
                }
                break;
            case '2':
                printf("Digite o nome do usuario: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strcspn(name, "\n")] = 0;
                current_user = find_user(users, name);
                if (current_user == NULL) {
                    printf("Usuario nao encontrado\n");
                } else {
                    printf("Usuario selecionado\n");
                }
                break;
            case '3':
                if (current_user == NULL) {
                    printf("Nenhum usuario selecionado\n");
                } else {
                    printf("Digite o post: ");
                    fgets(post, MAX_POST_LEN, stdin);
                    post[strcspn(post, "\n")] = 0;
                    add_post(current_user, post);
                    printf("Post adicionado\n");
                }
                break;
            case '4':
                if (current_user == NULL) {
                    printf("Nenhum usuario selecionado\n");
                } else {
                    printf("Digite o id do post: ");
                    unsigned int id;
                    scanf("%d", &id);
                    while (getchar() != '\n');
                    delete_post(current_user, id);
                }
                break;
            case '5':
                if (current_user == NULL) {
                    printf("Nenhum usuario selecionado\n");
                } else {
                    display_posts(current_user);
                }
                break;
            case '6':
                if (current_user == NULL) {
                    printf("Nenhum usuario selecionado\n");
                } else {
                    printf("Digite o nome do amigo: ");
                    fgets(name, MAX_NAME_LEN, stdin);
                    name[strcspn(name, "\n")] = 0;
                    User *friend = find_user(users, name);
                    if (friend == NULL) {
                        printf("Amigo nao encontrado\n");
                    } else {
                        add_friend(current_user, friend);
                        printf("Amigo adicionado\n");
                    }
                }
                break;
            case '7':
                if (current_user == NULL) {
                    printf("Nenhum usuario selecionado\n");
                } else {
                    printf("Numero de posts: %d\n", count_posts(current_user));
                    display_posts(current_user);
                    for (int i = 0; i < current_user->count_friends; i++) {
                        printf("Amigo %d: %s\n\n\n", i, current_user->friends[i]->name);
                    }
                }
                break;
            case '8':
                printf("Saindo...\n");
                return 0;
            default:
                printf("Opcao invalida\n");
        }
    }

    return 0;
}

void clear_terminal() {
    printf("\033[H\033[J");
}