#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct musica {
    int id;

    char nome[30];
    int min_duracao;
}Musica;

typedef struct album {
    int id;

    char nome[20];
    int num_musicas;
    char musica_top1[20];
    int ano_lanc;

    Musica musicas[20];
    int numMusicas;
}Album;

typedef struct artista {
    int id;

    char nome[20];
    int ano_nasc;
    char pais_nasc[20];

    Album albuns[10];
    int numAlbuns;
}Artista;

Artista cadastrarArtista(int idArtista){
    Artista novoArtista;

    novoArtista.id = idArtista;
    printf("Nome do Artista: ");
    scanf(" %[^\n]s", novoArtista.nome);
    printf("Pais do Artista: ");
    scanf(" %[^\n]s", novoArtista.pais_nasc);
    printf("Ano de Nascimento do Artista: ");
    scanf(" %d", &novoArtista.ano_nasc);

    novoArtista.numAlbuns = 0;

    return novoArtista;
}

void listarArtistas(Artista artistas[], int numArtistas){
    int i;

    printf("\n");
    for(i = 0; i < numArtistas; i++){
        printf("Nome do artista: %s\n", artistas[i].nome);
        printf("Pais de nascimento: %s\n", artistas[i].pais_nasc);
        printf("Ano de nascimento: %d\n", artistas[i].ano_nasc);
        printf("id = %d\n\n", artistas[i].id);
    }
}

Album cadastrarAlbum(int idAlbum){
    Album novoAlbum;

    novoAlbum.id = idAlbum;
    printf("Nome do album: ");
    scanf(" %[^\n]s", &novoAlbum.nome);
    printf("Numero de musicas: ");
    scanf(" %d", &novoAlbum.num_musicas);
    printf("Musica mais ouvida: ");
    scanf(" %[^\n]s", novoAlbum.musica_top1);
    printf("Ano de lancamento do Album: ");
    scanf("%d", &novoAlbum.ano_lanc);

    novoAlbum.numMusicas = 0; //musicas cadastradas

    return novoAlbum;
}

void listarAlbuns(Artista artistas[], int numArtistas){
    int i, j;

    printf("\n");
    for(i = 0; i < numArtistas; i++){
        for (j = 0; j < artistas[i].numAlbuns; j++){
            printf("Nome do album: %s\n", artistas[i].albuns[j].nome);
            printf("Artista: %s\n", artistas[i].nome);
            printf("Numero de musicas: %d\n", artistas[i].albuns[j].num_musicas);
            printf("Musica mais ouvida: %s\n", artistas[i].albuns[j].musica_top1);
            printf("Ano de lancamento do album: %d\n", artistas[i].albuns[j].ano_lanc);
            printf("id = %d\n\n", artistas[i].albuns[j].id);
        }
    }
}

void listarAlbunsArtista(Artista artistas[], int idArtista){
    int i;

    printf("\n");
    for(i = 0; i < artistas[idArtista].numAlbuns; i++){
        printf("Nome do album: %s\n", artistas[idArtista].albuns[i].nome);
        printf("Artista: %s\n", artistas[idArtista].nome);
        printf("Numero de musicas: %d\n", artistas[idArtista].albuns[i].num_musicas);
        printf("Musica mais ouvida: %s\n", artistas[idArtista].albuns[i].musica_top1);
        printf("Ano de lancamento do album: %d\n", artistas[idArtista].albuns[i].ano_lanc);
        printf("id = %d\n\n", artistas[idArtista].albuns[i].id);
    }
}

Musica cadastrarMusica(int idMusica){
    Musica novaMusica;

    novaMusica.id = idMusica;
    printf("Nome da musica: ");
    scanf(" %[^\n]s", &novaMusica.nome);
    printf("Duracao media(minutos): ");
    scanf("%d", &novaMusica.min_duracao);

    return novaMusica;
}

void listarMusicas(Artista artistas[], int numArtistas){
    int i, j, k;

    printf("\n");
    for(i = 0; i < numArtistas; i++){
        for (j = 0; j < artistas[i].numAlbuns; j++){
            for(k = 0; k < artistas[i].albuns[j].numMusicas; k++){
                printf("Nome da musica: %s\n", artistas[i].albuns[j].musicas[k].nome);
                printf("Duracao: %d\n", artistas[i].albuns[j].musicas[k].min_duracao);
                printf("Artista: %s\n", artistas[i].nome);
                printf("Album: %s\n\n", artistas[i].albuns[j].nome);
            }
        }
    }
}

int main(){
    Artista artistas[5];
    int op = 1, numArtistas = 0, idArtista = 0, idAlbum = 0, idMusica = 0, albunsCadastrados = 0, musicasCadastradas = 0;

    while(op!=0){
        printf("\n0 - Sair\n");
		printf("1 - Inserir novo artista\n");
		printf("2 - Listar os artistas cadastrados\n");
		printf("3 - Inserir novo album\n");
		printf("4 - Listar os albuns cadastrados\n");
		printf("5 - Inserir nova musica\n");
		printf("6 - Listar musicas cadastradas\n");

		printf("\nDigite a opcao desejada: ");
		scanf("%d",&op);

		switch(op){
            case 0:
                system("cls");

                break;
            case 1:
                system("cls");

                artistas[numArtistas] = cadastrarArtista(numArtistas);

                numArtistas ++;
                printf("\nOperacao realizada com sucesso!\n\n\n");

                break;
            case 2:
                if (numArtistas == 0) {
                    system("cls");

                    printf("Nenhum artista foi cadastrado!\n\n");

                    break;
                } else {
                    system("cls");

                    printf("ARTISTAS CADASTRADOS:\n");
                    listarArtistas(artistas, numArtistas);

                    break;
                }
            case 3:
                if (numArtistas == 0) {
                    system("cls");

                    printf("Voce nao pode cadastrar um album sem ter cadastrado um artista!\n\n");

                    break;
                } else {
                    system("cls");

                    listarArtistas(artistas, numArtistas);
                    printf("\nDigite o id do artista: ");
                    scanf("%d", &idArtista);

                    idAlbum = artistas[idArtista].numAlbuns;
                    artistas[idArtista].albuns[idAlbum] = cadastrarAlbum(idAlbum);

                    artistas[idArtista].numAlbuns ++;
                    printf("\nOperacao realizada com sucesso!\n\n\n");

                    albunsCadastrados ++;

                    break;
                }
            case 4:
                if (albunsCadastrados == 0) {
                    system("cls");

                    printf("Nenhum album foi cadastrado!\n\n");

                    break;
                } else {
                    system("cls");

                    printf("ALBUNS CADASTRADOS:\n");
                    listarAlbuns(artistas, numArtistas);

                    break;
                }
            case 5:
                if (albunsCadastrados == 0) {
                        system("cls");

                        printf("Voce nao pode cadastrar uma musica sem ter cadastrado um album!\n\n");

                        break;
                } else {
                    system("cls");

                    listarArtistas(artistas, numArtistas);
                    printf("\nDigite o id do artista: ");
                    scanf("%d", &idArtista);

                    if (artistas[idArtista].numAlbuns == 0) {
                        system("cls");

                        printf("\nO artista selecionado nao tem nenhum album cadastrado. Nao e possivel realizar esta operacao!\n\n");

                        break;
                    } else {
                        listarAlbunsArtista(artistas, idArtista);
                        printf("\nDigite o id do album: ");
                        scanf("%d", &idAlbum);

                        idMusica = artistas[idArtista].albuns[idAlbum].numMusicas;
                        artistas[idArtista].albuns[idAlbum].musicas[idMusica] = cadastrarMusica(idMusica);

                        artistas[idArtista].albuns[idAlbum].numMusicas ++;

                        printf("\nOperacao realizada com sucesso!\n\n\n");

                        musicasCadastradas ++;

                        break;
                    }
                }
            case 6:
                if (musicasCadastradas == 0) {
                        system("cls");

                        printf("Nenhuma musica foi cadastrada!\n\n");

                        break;
                } else {
                    system("cls");

                    printf("MUSICAS CADASTRADAS:\n");
                    listarMusicas(artistas, numArtistas);

                    break;
                }
            default:
                system("cls");

				printf("\nOpcao invalida!\n\n");

				break;
        }
    }

    return 0;
}
