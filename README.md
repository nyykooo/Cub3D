# Cub3D

## Descrição do Projeto
Este projeto foi meu primeiro contato com desenvolvimento de jogos, utilizando a técnica de raycasting para renderização gráfica. 
O objetivo principal é criar um labirinto em 3D por onde o player possa caminhar. Aproveitamos esse primeiro contato com o mundo de game dev para explorar conceitos de programação orientada a objetos (OOP) e criar uma experiência de jogo interativa e envolvente.

## Qualidades do Projeto
- **Primeiro Contato com GameDev**: Este projeto foi minha introdução ao mundo do desenvolvimento de jogos.
- **Raycasting**: Utilizamos a técnica de raycasting para renderizar o ambiente do jogo, proporcionando uma experiência visual única e eficiente.
- **Programação Orientada a Objetos**: Ao executar o raycasting, tentamos aplicar conceitos de OOP, organizando o código de forma modular e reutilizável, principalmente para evitar "sobreposição" de pixeis tornando a impressão de frames mais rápida.

## Como Jogar

### Instalação

Clone o repositório e compile:
```sh
 git clone https://github.com/nyykooo/Cub3D && cd Cub3D && make
```

### Execução
Para iniciar o jogo, execute o seguinte comando:
```sh
 ./cub3D includes/maps/minimalist.cub
```
Obs: existem 2 opções de mapa atualmente, minimalist.cub e bruno.cub!

### Gameplay:
#### Controles
- **WASD**: Movimentação do personagem
  - `W`: Move para frente
  - `A`: Move para a esquerda
  - `S`: Move para trás
  - `D`: Move para a direita
- **E**: Abre portas
- **C**: Fecha portas
- **SHIFT + W**: Corre
- **Mouse1**: Ataca com a espada

#### Instruções
- **Movimentação**: Use as teclas WASD para mover seu personagem pelo ambiente do jogo.
- **Interação com Portas**: Pressione `E` para abrir portas e `C` para fechá-las.
- **Corrida**: Segure `SHIFT` enquanto pressiona `W` para correr.
- **Ataque**: Use o botão esquerdo do mouse (`Mouse1`) para atacar com a espada.

## Requisitos do Sistema
- **Sistema Operacional**: Windows (WSL), ou Linux
- **Minilib-x instalada: https://github.com/42Paris/minilibx-linux**

## Contribuição
Desenvolvido em parceiria com: https://github.com/gitbrunoh
Contribuições são bem-vindas! Sinta-se à vontade para abrir issues e pull requests para melhorias e correções.

---

