## Sistema de Rede Social Em C

A proposta para esse trabalho e utilizar da Estrutura de Dados de grafos para implementar um programa CRUD, onde ha usuarios e postagens, os usuarios podem se seguir e se relacionam uns aos outros em um grafo, estando conectado como um usuario, e possivel escrever posts, deletar, mostrar na tela e seguir outras pessoas. 

### Posts

A estrutura de postagem sera uma lista encadeada onde cada no representa uma postagem feita por um usuario. Cada no contem o conteudo e um ponteiro para a proxima postagem da lista.

### User

A estrutura de User representa um vertice no grafo, cada usuario possui um nome, uma lista de postagem, uma lista de amigos e um ponteiro para o proximo usuario na lista de amigos.

A proposta inicial do trabalho seria uma implementacao nao exaustiva dessas funcoes, podendo estar apto parasugestoes e incremento de novas funcionalidades 
