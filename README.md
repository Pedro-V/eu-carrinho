# Relatório - Eu, Carrinho

* Computação Gráfica - T01 2023.2
* Profª Beatriz Trinchão Andrade
* Grupo 1
  * Pedro Vinícius de Araújo Barreto

## O que foi feito

Foi construído um simulador de carrinho simples, usando a API OpenGL 1.1 para
trabalhar as técnicas aprendidas ao longo da disciplina. O grupo conseguiu
concluir por completo a etapa 1 e parcialmente as etapas 2 e 4.

## Soluções para problemas encontrados

* Rotinas primitivas usando `GL_TRIANGLE_STRIP` para desenhar a malha.
* Desenhar no papel e desenhar eixos no simulador para poder ter melhor noção do
  controle da câmera.
* Criação de classes que mantêm estado de cada componente do simulador
  (Carrinho, Terreno, Câmera, etc).
* Fazer uso de normalização e escala de vetores para implementar zoom.
* Implementamos um parser simples de arquivos .obj (não sabíamos se podia usar
  alguma dependência externa) para poder ler um modelo de carrinho 3D.
* A implementação do modo de visualização ficou consideravelmente mais simples
  ao movermos a cena pelas coordenadas negativas do carrinho.

## Problemas que não conseguimos resolver

* Shading: Conseguimos atribuir materiais ao terreno e ao carro, mas mesmo com
  a iluminação habilitada, a cena ficou sem noção de profundidade. Não
  conseguimos identificar o porquê.
* Z-buffer: A habilitação do Z-buffer causava um comportamento estranho na cena,
  com alguns triângulos escurecendo. Decidimos não ativá-la.

## Instruções de compilação

```sh
$ make        # Compila
$ make run    # Executa
$ make clean  # Limpa
```
## Instruções de uso

O simulador consiste em dois modos. Alteração entre os modos é feito com a tecla `M`.

- Simulação: controle e mova o carrinho, com a câmera seguindo. Esse é o modo inicial.
  Os comandos disponíveis são:
  - Up: Carrinho avança uma posição
  - Left/Right: Carrinho vira numa direção.
- Visualização: rotacione e dê zoom na câmera, podendo visualizar melhor o terreno.
  Os comandos disponívels são:
  - Left/Right: Rotaciona ao redor do carrinho.
  - Up/Down: Aproxima ou distancia a câmera do carrinho.
  - F1: Reseta o nível de zoom.

