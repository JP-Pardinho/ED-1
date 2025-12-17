# ==========================================================
# Makefile - Ex6
# =========================================================

# 1️⃣ Variáveis (para facilitar manutenção)
CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -fsanitize=address,undefined,leak 
CLIBS=-lm
LDFLAGS = -fsanitize=address,undefined,leak # Flags usadas no linking (geram o executável)
EXECUTAVEL=Ex6.exe # nome do executável final

# ==========================================================
# 2️⃣ Alvo principal (primeiro alvo → padrão ao rodar "make")
# ==========================================================

all: $(EXECUTAVEL)

$(EXECUTAVEL): main.o Arvore.o No.o Util.o
	@echo "🔧 Ligando objetos e gerando executável..."
	@gcc main.o Arvore.o No.o Util.o $(CLIBS) $(LDFLAGS) -o $(EXECUTAVEL)
	@echo "✅ Compilação concluída."
	@echo "🚀 Para executar o programa digite ./$(EXECUTAVEL) no terminal."

# ==========================================================
# 3️⃣ Regras para gerar os arquivos objeto
# ==========================================================

main.o: main.c
	@echo "🧩 Compilando main.c"
	@gcc $(CFLAGS) -c main.c

Arvore.o: Arvore.c
	@echo "🧩 Compilando Arvore.c"
	@gcc $(CFLAGS) -c Arvore.c

No.o: No.c
	@echo "🧩 Compilando No.c"
	@gcc $(CFLAGS) -c No.c

Util.o: Util.c
	@echo "🧩 Compilando Util.c"
	@gcc $(CFLAGS) -c Util.c

# ==========================================================
# 4️⃣ Alvos auxiliares (não geram arquivos → PHONY)
# ==========================================================

.PHONY: clean run

# Limpa os arquivos temporários
clean: 
	@echo "🧹 Limpando arquivos compilados..."
	@rm -rf *.o $(EXECUTAVEL)
	@echo "🧼 Diretório limpo!"
	
# Executa o programa (compila antes se necessário)
run: $(EXECUTAVEL)
	@echo "🚀 Executando o programa com o arquivo 'Entrada1.txt':"
	./$(EXECUTAVEL) < Entrada1.txt
	@echo ""
	@echo "🚀 Executando o programa com o arquivo 'Entrada2.txt':"
	./$(EXECUTAVEL) < Entrada2.txt
	@echo ""
	@echo "🚀 Executando o programa com o arquivo 'Entrada3.txt':"
	./$(EXECUTAVEL) < Entrada3.txt


