maxchain:libraries
	gcc -Wall -I../util -I../trie -L../util -L../trie maxchain.c  -lwordutils -ltrie
	export LD_LIBRARY_PATH"=../trie:../util";./a.out
subwords:libraries
	gcc -Wall -I../util -I../trie -L../util -L../trie subwords.c  -lwordutils -ltrie
	export LD_LIBRARY_PATH"=../trie:../util";./a.out
libraries:
	cd ..;make libraries
	