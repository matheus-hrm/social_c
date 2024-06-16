#include "social.h"

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
        printf("6. Sair\n");
        printf("Digite uma opcao: ");
        switch(c) {
            case '1':
                printf("Digite o nome do usuario: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strlen(name) - 1] = '\0';
                User *new_user = create_user(name);
                if (new_user == NULL) {
                    printf("Erro ao criar usuario\n");
                } else {
                    printf("Usuario criado com sucesso\n");
                }
                break;
            case '2':
                printf("Digite o nome do usuario: ");
                fgets(name, MAX_NAME_LEN, stdin);
                name[strlen(name) - 1] = '\0';
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
                    post[strlen(post) - 1] = '\0';
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
                    delete_post(current_user, id);
                    printf("Post deletado\n");
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
                return 0;
            default:
                printf("Opcao invalida\n");
        }
    }

    return 0;
}

