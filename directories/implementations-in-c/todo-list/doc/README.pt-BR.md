# Lista de Tarefas (Todo List)

## Índice
- **[Visão Geral](#visão-geral)**
- **[Descrição](#descrição)**
- **[Detalhes do Funcionamento](#detalhes-do-funcionamento)**
- **[Detalhes Técnicos](#detalhes-técnicos)**
- **[Referência](#referência)**
#

## **Visão Geral**

Neste trabalho deve ser implementado um gerenciador de listas de tarefas (conhecidas como TODO lists). A ideia é símples:
  - Uma lista de tarefas é uma **lista ordenada** de coisas para se fazer;
  - As **Tarefas** podem ser:
    - Adicionadas
    - Excluídas
    - Marcadas como feitas/não-feitas
  - As **Listas de Tarefas** podem ser:
    - Adicionadas
    - Excluídas
    - Visualizadas

Uma **Lista de Tarefas** possui um nome que a indentifica. Por exemplo, uma lista de tarefas com o nome "Compras" e outra lista de tarefas com o nome "TCC" podem facilitar a ida a um supermercado ou mesmo tornar sua vida acadêmica mais organizada.

## **Descrição**

Componentes dos elemntos desse trabalho:
  - **Lista de Tarefas:** deve conter um **nome**, uma **descrição** e **tarefas**
  - **Tarefa:** deve conter uma **descrição**, uma **data** e um **estado**. O estado da tarefa deve indicar se a mesma se encontra feita ou não-feita.

O sistema de gerenciamento de listas de tarefas deve suportar as seguintes funcionalidades, organizadas em dois níveis hierárquicos:

***1. Adicionar Lista de Tarefa***<br>
O usuário é capaz de cadastrar uma nova lista de tarefas vazia. Nesse caso, o usuário entra com as informações de uma lista (nome e descrição) e o sistema cria uma lista vazia.

***2. Remover Lista de Tarefa***<br>
O usuário é capaz de remover uma lista de tarefas existente. Nesse caso, o sistema mostra uma lista das listas cadastradas e o usuário escolhe qual delas deseja remover.

***3. Abrir Lista de Tarefa***<br>
O usuário é capaz de abrir uma lista de tarefas existente para visualização e edição. Nesse caso, o sistema mostra uma lista das listas cadastradas e o usuário escolhe qual delas deseja visualizar/ editar. Em seguida, o sistema mostra o conteúdo da lista de tarefas (nome, descrição e tarefas) e fornece as seguintes funcionalidades para o usuário:
  1. **Adicionar Tarefa**<br>
  O usuário é capaz de adicionar uma tarefa à lista de tarefas. Nesse caso, o sistema pergunta os campos da tarefa ao usuário (descrição e estado) e a nova tarefa é criada com o estado de não-feita. Além disso, a nova tarefa é adicionada com a prioridade mais baixa até então dentre as tarefas existentes na lista.

  2. **Remover Tarefa**<br>
  O usuário é capaz de remover uma tarefa da lista de tarefas. Nesse caso, remover uma tarefa implica em reorganizar a lista de tarefas. A decisão de como fazer isso é parte de seu trabalho.
  
  3. **Marcar Tarefa como Feita**<br>
  O usuário é capaz de marcar uma tarefa como feita.

  4. **Marcar Tarefa como Não-Feita**<br>
  O usuário é capaz de marcar uma tarefa como não-feita.
  
  5. **Mudar Prioridade do Item**<br>
  O usuário é capaz de alterar a prioridade (posição) de uma tarefa.

  6. **Voltar ao Início**<br>
  O usuário é capaz de voltar às funcionalidades da hierarquia anterior.

***4. Listar Tarefas de um Período***<br>
O usuário é capaz de visualizar as tarefas existentes dado um período: dia/mês/ano de início e dia/mês/ano de término. Nesse caso, o sistema deve buscar as ​ tarefas que se enquadram nesse período de todas as listas de tarefas​ e exibir o resultado para o usuário.

## **Detalhes do Funcionamento**

O usuário interage com o sistema na forma de menus de opções, seguindo a hierarquia apresentada na seção anterior. Você pode representar a escolha do usuário por uma sequência de números. Assim, considerando o menu inicial:

**1 - Adicionar Lista de Tarefas**<br>
**2 - Remover Lista de Tarefas**<br>
**3 - Abrir Lista de Tarefas**<br>
**4 - Listar Tarefas de um Período**<br>

Ao pressionar **1**, o sistema ativa a inclusão de uma lista de tarefas que espera a entrada por parte do usuário dos respectivos nome e descrição da lista. Da mesma forma, ao pressionar **3**, o sistema mostra uma lista de listas existentes que podem ser escolhidas e gerenciadas através do novo menu de funcionalidades para tarefas abertas, construído de forma similar.<br>

A prioridade das tarefas também pode ser representada por números. Assim como descrito anteriormente, as tarefas são adicionadas com a prioridade mais baixa até então na lista. Entretanto, como a prioridade das tarefas podem mudar ou podem ser excluídas, a ordem de aparição delas também deve ser alterada de acordo.

## **Detalhes Técnicos**

Seu sistema será testado em ambiente **Linx**, com linguagem de terminal **Bash**. A compilação deve ser através de um [Makefile][1].

A compilação deverá ser feita utiliando o make:

```sh
$ make
```

Em seguida, o seu sistema deve ser iniciado com o seguinte comando:

```sh
$ ./todolist
```

## **Referência**

**Universidade Federal de Ouro Preto - UFOP**<br>
**Disciplina de Programação de Computadores I - CSI030**<br>
**Trabalho Prático: Gerenciamento de Listas de Tarefas**<br>
**Professor: Vinicius Dias**

[1]: ​https://www.cs.swarthmore.edu/~newhall/unixhelp/howto_makefiles.html
