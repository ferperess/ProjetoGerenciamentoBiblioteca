# Manual do Usuário - Sistema de Gerenciamento de Biblioteca

## Introdução
Este sistema permite o gerenciamento completo de uma biblioteca, incluindo cadastro de livros e leitores, empréstimos e devoluções.

## Instalação
1. Verifique o Compilador C: Antes de começar, certifique-se de ter um compilador C instalado no seu sistema. Recomendamos o GCC.
   - Para verificar, execute 'gcc --version' no terminal; se o GCC estiver instalado, a versão será exibida. Caso contrário, instale-o através do gerenciador de pacotes do seu sistema.
2. Obtenha os Arquivos:
   Opção A - Usando Git:
   - Instale o Git se necessário (verifique com 'git --version')
   - Clone o repositório:
     git clone https://github.com/ferperess/ProjetoGerenciamentoBiblioteca
   - Navegue até o diretório: cd ProjetoGerenciamentoBiblioteca

   Opção B - Download Direto:
   - Visite https://github.com/ferperess/ProjetoGerenciamentoBiblioteca
   - Clique no botão "Code" e selecione "Download ZIP"
   - Extraia o arquivo ZIP para uma pasta de sua escolha
   - Abra um terminal e navegue até a pasta extraída
3. o terminal, dentro da pasta do projeto, execute:  gcc main.c bibliotecaLivros.c bibliotecaLeitores.c -o biblioteca
4. Após a compilação bem-sucedida, você terá um executável chamado `biblioteca`, basta inicializá-lo

## Como Executar
No terminal ou prompt de comando, execute: './biblioteca'

## Funcionalidades Detalhadas

### 1. Cadastrar Leitor
- Selecione a opção 1 no menu principal
- Informe o nome completo do leitor
- Digite o número de telefone (formato: 11 dígitos)

### 2. Listar Leitores
- Selecione a opção 2 no menu principal
- O sistema exibirá todos os leitores cadastrados

### 3. Adicionar Livro
- Selecione a opção 3 no menu principal
- Informe o título do livro
- Digite o nome do autor
- Informe o ano de publicação
- Digite a quantidade total de exemplares

### 4. Listar Livros
- Selecione a opção 4 no menu principal
- O sistema exibirá todos os livros cadastrados

### 5. Buscar Livro
- Selecione a opção 5 no menu principal
- Digite o título ou autor do livro que deseja buscar

### 6. Emprestar Livro
- Selecione a opção 6 no menu principal
- Informe se o leitor já está cadastrado
- Se não estiver, você será direcionado para o cadastro de leitor
- Digite o nome do autor ou título do livro que deseja emprestar
- Confirme o empréstimo

### 7. Devolver Livro
- Selecione a opção 7 no menu principal
- Digite o autor ou título do livro que deseja devolver

### 8. Remover Livro
- Selecione a opção 8 no menu principal
- Digite o nome do autor ou título do livro que deseja remover
- Confirme a remoção

### 9. Remover Leitor
- Selecione a opção 9 no menu principal
- Digite o nome completo do leitor que deseja remover
- Confirme a remoção

### 10. Sair
- Selecione a opção 10 para sair do sistema
- Os dados serão automaticamente salvos

## Solução de Problemas Comuns
1. Erro ao salvar dados:
   - Verifique se você tem permissões de escrita no diretório
   - Certifique-se de que há espaço suficiente no disco

2. Erro na compilação:
   - Verifique se todos os arquivos do projeto estão presentes no diretório
   - Confirme se você tem um compilador C instalado e configurado corretamente

3. Livro ou leitor não encontrado:
   - Certifique-se de que o livro ou leitor foi cadastrado anteriormente
  
4. Pausa inesperada ao emprestar livro:
   - Ao selecionar a opção 6 (Emprestar livro), confirmar que o leitor tem cadastro e inserir o nome do leitor, 
     o sistema está processando informações e pode parecer pausado após exibir "Dados encontrados!"
   - Solução: Pressione Enter uma vez para continuar o processo de empréstimo
