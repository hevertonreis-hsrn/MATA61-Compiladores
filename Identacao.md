Resumo da estratégia (visão geral)

Manter uma pilha de níveis de indentação (indent_stack). O topo da pilha é o nível de colunas (número de espaços) do bloco corrente.

No início de cada linha (BOL, begin-of-line) contar quantos espaços/tabs existem antes do primeiro caractere não-whitespace → new_indent.

Se new_indent > top → empilha new_indent e EMITE INDENT.

Se new_indent == top → nada de indent/dedent (a linha continua normalmente).

Se new_indent < top → desempilha até que topo ≤ new_indent; para cada desempilhada emitir um DEDENT.
Como pode ser necessário emitir mais de um DEDENT, usamos uma fila/contagem de DEDENTs pendentes para que chamadas subsequentes ao scanner devolvam os DEDENTs um por um antes de continuar a análise normal.

Ignorar regras de indentação quando estivermos dentro de parênteses/colchetes/chaves (paren_level > 0), isto é, novaslines dentro de parênteses NÃO devem gerar NEWLINE / INDENT / DEDENT.

No EOF emitir todos os DEDENTs necessários até voltar ao nível 0, depois emitir EOF.

Pontos importantes:

Precisamos tratar tabs (convém mapear tab para N espaços; por exemplo TABSTOP = 8 — escolha do grupo).

O scanner deve poder retornar INDENT e DEDENT antes de consumir o próximo caractere da linha (não queremos perder o caractere atual). Para isso utilizaremos um start condition do Flex para devolver repetidamente DEDENT sem consumir entrada.

Passo a passo detalhado
1) Variáveis necessárias (globais do scanner)

int indent_stack[1000]; int indent_top; — pilha de níveis.

int paren_level; — contador de (, [ e {.

int pending_dedents; — quantos DEDENT ainda devem ser emitidos.

int tabsize; — quantos espaços representa um \t (ex.: 8).

int at_bol; — opcional: flag se estamos no início de linha (padrão 1 quando iniciamos).

2) Contabilizar colunas / tratamento de tabs

Ao contar indentação, não conte \t como 1, expanda-o:
col = col + (tabsize - (col % tabsize)) — típico.

3) Detectar BOL e espaços iniciais

Use uma regra com ^ (borda da linha) para capturar os espaços iniciais:

```
^[ \t]*  { /* calcula new_indent a partir de yytext */ }
```

Dentro dessa ação:

Se paren_level > 0: ignore (não gerar INDENT/DEDENT).

Caso contrário compare com indent_stack[indent_top] e faça o fluxo descrito (push/emit INDENT / calcular dedents e setar pending_dedents).

4) Emitir múltiplos DEDENTs

Quando precisar emitir K DEDENTs:

Defina pending_dedents = K - 1; (porque você já pode retornar um DEDENT imediatamente).

Retorne T_DEDENT na mesma ação.

Antes de analisar qualquer input normal, precisamos garantir que as próximas chamadas ao scanner devolvam os DEDENTs restantes. Para isso, troque para uma start condition DEDENT_MODE e crie uma regra vazia nessa condição que retorna um DEDENT até pending_dedents == 0, então volte ao INITIAL.

Exemplo da regra vazia em DEDENT_MODE:

<DEDENT_MODE>"" {
    if (pending_dedents > 0) { pending_dedents--; return T_DEDENT; }
    else { BEGIN(INITIAL); /* não consumir input, continue scanning */ }
}


A regra com padrão "" não consome input — ela permite emitir tokens sem avançar no texto.

Observação: usar "" exige cuidado para evitar loops infinitos — aqui é seguro porque a ação altera pending_dedents e eventualmente muda o start condition.

5) Parênteses multilinha

Ao ver (, [ ou { incrementa paren_level++.

Ao ver ), ], } decrementa paren_level-- (nunca deixar negativo).

Se paren_level > 0 então no \n não emita NEWLINE e ignore indent/dedent. Caso contrário, \n emite NEWLINE e ativa o BOL logic.

6) EOF

Regra <<EOF>> deve:

Se indent_top > 0 gerar DEDENTs até retornar ao nível 0 (ex.: set pending_dedents = indent_top; retornar um DEDENT e as próximas chamadas farão o resto).

Depois dos dedents, devolver T_EOF.