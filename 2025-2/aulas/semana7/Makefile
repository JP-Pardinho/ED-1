# ==========================================================
# Makefile - TADListaGenerica
# =========================================================

# 1️⃣ Variáveis (para facilitar manutenção)
CFLAGS=-O0 -std=c11 -Wall -Werror -Wextra -Wno-sign-compare -Wno-unused-parameter -Wno-unused-variable -Wshadow -fsanitize=address,undefined,leak 
CLIBS=-lm
LDFLAGS = -fsanitize=address,undefined,leak # Flags usadas no linking (geram o executável)
EXECUTAVEL=TADListaGenerica.exe # nome do executável final

# ==========================================================
# 2️⃣ Alvo principal (primeiro alvo → padrão ao rodar "make")
# ==========================================================

$(EXECUTAVEL): main.o Lista.o
	@echo "🔧 Ligando objetos e gerando executável..."
	@gcc main.o Lista.o $(CLIBS) $(LDFLAGS) -o $(EXECUTAVEL)
	@echo "✅ Compilação concluída."
	@echo "🚀 Para executar o programa digite ./$(EXECUTAVEL) no terminal."


# ==========================================================
# 3️⃣ Regras para gerar os arquivos objeto
# ==========================================================

main.o: main.c
	@echo "🧩 Compilando main.c"
	@gcc -c $(CFLAGS) main.c

Lista.o: Lista.c
	@echo "🧩 Compilando Lista.c"
	@gcc -c $(CFLAGS) Lista.c


# ==========================================================
# 4️⃣ Alvos auxiliares (não geram arquivos → PHONY)
# ==========================================================

.PHONY: clean run memcheck

# Executa o programa (compila antes se necessário)
run: $(EXECUTAVEL)
	@echo "🚀 Executando o programa:"
	./$(EXECUTAVEL)

# Limpa os arquivos temporários
clean: 
	@echo "🧹 Limpando arquivos compilados..."
	@rm -rf *.o $(EXECUTAVEL)
	@echo "🧼 Diretório limpo!"
	
