all: clean ponteiro ponteiro_duplo linkedlist doublylinkedlist

ponteiro:
	@echo
	@echo ==========================
	@echo      PONTEIRO SIMPLES
	@echo ==========================
	@echo Compilando o programa ponteiros
	gcc ponteiro.c -o ponteiro
	@echo Tornando o arquivo executável
	chmod +x ponteiro
	@echo Executando o programa ponteiros
	@echo ======================================================
	@echo
	./ponteiro

ponteiro_duplo:
	@echo
	@echo ==========================
	@echo      PONTEIRO DUPLO
	@echo ==========================
	@echo Compilando o programa ponteiro duplo
	gcc ponteiro_duplo.c -o ponteiro_duplo
	@echo Tornando o arquivo executável
	chmod +x ponteiro_duplo
	@echo Executando o programa ponteiro duplo
	@echo ======================================================
	@echo
	./ponteiro_duplo

linkedlist:
	@echo
	@echo ==========================
	@echo      LISTA SIMPLES
	@echo ==========================
	@echo Compilando o programa linkedlist
	gcc --std=c99 -DLOG_USE_COLOR log.h log.c LinkedList.h LinkedList.c LinkedListTest.c -o linkedlist
	@echo Tornando o arquivo executável
	chmod +x linkedlist
	@echo Executando o programa linkedlist
	@echo ======================================================
	@echo
	./linkedlist

doublylinkedlist:
	@echo
	@echo ==========================
	@echo      LISTA DUPLA
	@echo ==========================
	@echo Compilando o programa linkedlist
	gcc --std=c99 -DLOG_USE_COLOR log.h log.c DoublyLinkedList.h DoublyLinkedList.c DoublyLinkedListTest.c -o doublylinkedlist
	@echo Tornando o arquivo executável
	chmod +x doublylinkedlist
	@echo Executando o programa linkedlist
	@echo ======================================================
	@echo
	./doublylinkedlist

generalizedlinkedlist:
	@echo
	@echo ==========================
	@echo      LISTA GENERALIZADA
	@echo ==========================
	@echo Compilando o programa generalizedlinkedlist
	gcc --std=c99 -DLOG_USE_COLOR log.h log.c GeneralizedLinkedList.h GeneralizedLinkedList.c GeneralizedLinkedListTest.c -o generalizedlinkedlist
	@echo Tornando o arquivo executável
	chmod +x generalizedlinkedlist
	@echo Executando o programa generalizedlinkedlist
	@echo ======================================================
	@echo
	./generalizedlinkedlist

clean:
	@echo
	@echo ==========================
	@echo APAGANDO TODOS OS PROGRAMAS
	@echo ==========================
	@echo Removendo o programa ponteiro
	rm -f ponteiro
	@echo Removendo o programa ponteiro duplo
	rm -f ponteiro_duplo
	@echo Removendo o programa linkedlist
	rm -f linkedlist
	@echo Removendo o programa doublylinkedlist
	rm -f doublylinkedlist
	@echo Removendo o programa generalizedlinkedlist
	rm -f generalizedlinkedlist